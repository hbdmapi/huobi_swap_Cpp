#ifndef WSREQUESTCLIENTIMPL_H
#define WSREQUESTCLIENTIMPL_H

#include <list>
#include "HuobiSwap/SubscriptionOptions.h"
#include "WebSocketApiImpl.h"
#include "WebSocketRequest.h"
#include "WebSocketConnection.h"
#include "WebSocketWatchDog.h"
#include "HuobiSwap/RequestOptions.h"
#include "GetHost.h"
#include "RestApiImpl.h"
#include "HuobiSwap/WsRequestClient.h"
#include "SubscriptionClientImpl.h"
#include "WebSocketRequest.h"
namespace HuobiSwap {

    class WsRequestClientImpl : public WsRequestClient {
    private:
        SubscriptionClientImpl* impl;
    public:
        //  void startService() override;

        WsRequestClientImpl() {
            SubscriptionOptions op;
            op.isAutoReconnect = false;
            impl = new SubscriptionClientImpl(op);
        }

        WsRequestClientImpl(
                std::string apiKey,
                std::string secretKey) {
            SubscriptionOptions op;
            op.isAutoReconnect = false;
            impl = new SubscriptionClientImpl(apiKey, secretKey, op);
        }

        ~WsRequestClientImpl() {
            delete impl;
        }


        void requestCandlestickEvent(
                const char* symbols,
                CandlestickInterval interval,
                const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
                const std::function<void(Error&)>& errorHandler) override;

        void requestCandlestickEvent(
                bool autoClose,
                const char* symbols,
                CandlestickInterval interval,
                const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
                const std::function<void(Error&)>& errorHandler) override;

        void requestCandlestickEvent(
                const char* symbols,
                CandlestickInterval interval,
                long startTime,
                long endTime,
                const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
                const std::function<void(Error&)>& errorHandler) override;

        void requestCandlestickEvent(
                bool autoClose,
                const char* symbols,
                CandlestickInterval interval,
                long startTime,
                long endTime,
                const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
                const std::function<void(Error&)>& errorHandler) override;


    };
}

#endif /* WSREQUESTCLIENTIMPL_H */

