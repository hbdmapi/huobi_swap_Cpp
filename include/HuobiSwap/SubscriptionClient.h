/*******************************************************************************
* File name： SubscriptionClient.h
* Description: HuobiSwap api SubscriptionClient header files.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/

#ifndef SUBSCRIPTIONCLIENT_H
#define SUBSCRIPTIONCLIENT_H

#include <string>
#include <functional>
#include "HuobiSwap/Enums.h"
#include "HuobiSwap/Error.h"
#include "HuobiSwap/CandlestickEvent.h"
#include "HuobiSwap/OrderUpdateEvent.h"
#include "SubscriptionOptions.h"


namespace HuobiSwap {

    /***
     * The subscription client interface, it is used for subscribing any market data update and
     * account change, it is asynchronous, so you must implement the SubscriptionListener interface.
     * The server will push any update to the client. if client get the update, the onReceive method
     * will be called.
     */
    struct SubscriptionClient {
        /**
         * Subscribe candlestick/kline event. If the candlestick/kline is updated, server will send the
         * data to client and onReceive in callback will be called.
         *
         * \param symbols    The symbols, like "BTC-USD". Use comma to separate multi symbols, like
         * "BTC-USD,EOS-USD".
         * \param interval The candlestick/kline interval, 1min, 5min, 15min, 30min, 60min,4hour,1day,1week, 1mon.
         * \param callback The implementation is required. onReceive will be called if receive server's
         * update.
         * \param errorHandler The error handler will be called if subscription failed or error happen
         * between client and HuobiSwap server.
         */
        virtual void subscribeCandlestickEvent(
                const char* symbols,
                CandlestickInterval interval,
                const std::function<void(const CandlestickEvent&) >& callback,
                const std::function<void(Error&)>& errorHandler = std::function<void(Error&)>()) = 0;
        
        /**
         * Subscribe order changing event. If a order is created, canceled etc, server will send the data
         * to client and onReceive in callback will be called.
         *
         * \param symbols    The symbols, like "BTC-USD". Use comma to separate multi symbols, like
         * "BTC-USD,EOS-USD".
         * \param errorHandler The error handler will be called if subscription failed or error happen
         * between client and HuobiSwap server.
         */
        virtual void subscribeOrderUpdateEvent(
                const char* symbols,
                const std::function<void(const OrderUpdateEvent&) >& callback,
                const std::function<void(Error&)>& errorHandler = std::function<void(Error&)>()) = 0;

        /*
         * start sub,must excute after sub-function.
         */
        virtual void startService() = 0;
    };

    SubscriptionClient* createSubscriptionClient(const char* apiKey, const char* secretKey, SubscriptionOptions&op);
    SubscriptionClient* createSubscriptionClient(SubscriptionOptions&op);
    SubscriptionClient* createSubscriptionClient();
    SubscriptionClient* createSubscriptionClient(const char* apiKey, const char* secretKey);

}
#endif /* SUBSCRIPTIONCLIENT_H */

