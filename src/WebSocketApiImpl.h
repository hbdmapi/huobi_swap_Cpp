#ifndef WEBSOCKETAPIIMPL_H
#define WEBSOCKETAPIIMPL_H

#include <string>
#include <vector>
#include <list>
#include "WebSocketRequest.h"
#include "HuobiSwap/CandlestickEvent.h"
#include "HuobiSwap/OrderUpdateEvent.h"
#include "HuobiSwap/Enums.h"

namespace HuobiSwap {

    class WebSocketApiImpl {
    private:
        std::string accessKey;
        std::string secretKey;

    public:

        WebSocketApiImpl() {
        }

        WebSocketApiImpl(std::string accessKey,
                std::string secretKey) {
            this->accessKey = accessKey;
            this->secretKey = secretKey;
        }

        std::string getAccessKey() {
            return accessKey;
        }

        WebSocketRequest* subscribeCandlestickEvent(
                const std::list<std::string>& symbols,
                CandlestickInterval interval,
                const std::function<void(const CandlestickEvent&) >& callback,
                const std::function<void(Error&)>& errorHandler);


        WebSocketRequest* subscribeOrderUpdateEvent(
                const std::list<std::string>& symbols,
                const std::function<void(const OrderUpdateEvent&) >& callback,
                const std::function<void(Error&)>& errorHandler);

        WebSocketRequest* requestCandlestickEvent(
                bool autoClose,
                const std::list<std::string>& symbols,
                CandlestickInterval interval,
                long startTime,
                long endTime,
                const std::function<void(const std::vector <CandlestickEvent>&) >& callback,
                const std::function<void(Error&)>& errorHandler);

    };


}
#endif /* WEBSOCKETAPIIMPL_H */

