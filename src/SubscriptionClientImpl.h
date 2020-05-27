#ifndef WEBSOCKETIMPL_H
#define WEBSOCKETIMPL_H

#include <list>
#include "HuobiSwap/SubscriptionClient.h"
#include "HuobiSwap/SubscriptionOptions.h"
#include "WebSocketApiImpl.h"
#include "WebSocketRequest.h"
#include "WebSocketConnection.h"
#include "WebSocketWatchDog.h"
#include "HuobiSwap/RequestOptions.h"
#include "GetHost.h"
#include "RestApiImpl.h"

namespace HuobiSwap {

    class SubscriptionClientImpl : public SubscriptionClient {
    private:

        std::string apiKey;
        std::string secretKey;
        WebSocketApiImpl *impl;
        std::list<WebSocketConnection*> connectionList;
        SubscriptionOptions op;
        std::string host = "api.hbdm.vn";
        WebSocketWatchDog* dog = nullptr;

        struct lws_context* context = nullptr;
    public:
        void startService() override;
        void startReq(WebSocketRequest* webSocketRequest);

        void init_context();

        SubscriptionClientImpl() {
            apiKey = "";
            secretKey = "";
            impl = new WebSocketApiImpl(apiKey, secretKey);
        }

        SubscriptionClientImpl(SubscriptionOptions& op) {
            apiKey = "";
            secretKey = "";
            impl = new WebSocketApiImpl(apiKey, secretKey);
            this->op = op;
        }

        SubscriptionClientImpl(
                std::string apiKey,
                std::string secretKey, SubscriptionOptions& op) {
            this->apiKey = apiKey;
            this->secretKey = secretKey;
            this->op = op;
            impl = new WebSocketApiImpl(apiKey, secretKey);
            if (!op.url.empty()) {
                host = GetHost(op.url);
                RequestOptions resop;
                resop.url = op.url;
                RestApiImpl* restimpl = new RestApiImpl(apiKey.c_str(), secretKey.c_str(), resop);
                delete restimpl;
            } else {
                RestApiImpl* restimpl = new RestApiImpl(apiKey.c_str(), secretKey.c_str());
                delete restimpl;
            }
        }

        ~SubscriptionClientImpl() {
            delete dog;
            delete impl;
        }
        void createConnection(WebSocketRequest* request);

        void subscribeCandlestickEvent(
                const char* symbols,
                CandlestickInterval interval,
                const std::function<void(const CandlestickEvent&) >& callback,
                const std::function<void(Error&)>& errorHandler = std::function<void(Error&)>()) override;
        
        void subscribeOrderUpdateEvent(
                const char* symbols,
                const std::function<void(const OrderUpdateEvent&) >& callback,
                const std::function<void(Error&)>& errorHandler = std::function<void(Error&)>()) override;

        WebSocketRequest* requestCandlestickEvent(
                bool autoClose,
                const char* symbols,
                CandlestickInterval interval,
                long startTime,
                long endTime,
                const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
                const std::function<void(Error&)>& errorHandler);


    private:
        std::list<std::string> parseSymbols(const char* symbols);
    };
}



#endif /* WEBSOCKETIMPL_H */

