/*******************************************************************************
* File name： WsRequestClient.h
* Description: HuobiSwap api WsRequestClient header files.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/
#ifndef WSREQUESTCLIENT_H
#define WSREQUESTCLIENT_H

#include <string>
#include <functional>
#include "HuobiSwap/Enums.h"
#include "HuobiSwap/Error.h"

#include "HuobiSwap/Candlestick.h"

namespace HuobiSwap {

    /***
     * The ws request client interface, it is used for requesting any market data update and
     * account change, it is synchronous,  you must implement the ReqListener interface.
     */
    struct WsRequestClient {
        /**
         * Request candlestick/kline event. If the candlestick/kline is received, onReceive in callback will be called.
         * \param symbols    The symbols, like "BTC-USD". Use comma to separate multi symbols, like
         * "BTC-USD,EOS-USD".
         * \param interval The candlestick/kline interval, 1min, 5min, 15min, 30min, 60min,4hour,1day,1week, 1mon.
         * \param callback The implementation is required, onReceive will be called if receive server's
         * response.
         * \param errorHandler The error handler will be called if request failed or error happen
         * between client and HuobiSwap server.
         */
        virtual void requestCandlestickEvent(
                const char* symbols,
                CandlestickInterval interval,
                const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
                const std::function<void(Error&)>& errorHandler = std::function<void(Error&)>()) = 0;
        /**
         * Request candlestick/kline event. If the candlestick/kline is received, onReceive in callback will be called.
         * \param autoClose ,true or false
         * \param symbols    The symbols, like "BTC-USD". Use comma to separate multi symbols, like
         * "BTC-USD,EOS-USD".
         * \param interval The candlestick/kline interval, 1min, 5min, 15min, 30min, 60min,4hour,1day,1week, 1mon.
         * \param callback The implementation is required, onReceive will be called if receive server's
         * response.
         * \param errorHandler The error handler will be called if request failed or error happen
         * between client and HuobiSwap server.
         */
        virtual void requestCandlestickEvent(
                bool autoClose,
                const char* symbols,
                CandlestickInterval interval,
                const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
                const std::function<void(Error&)>& errorHandler = std::function<void(Error&)>()) = 0;
        /**
         * Request candlestick/kline event. If the candlestick/kline is received, onReceive in callback will be called.
         *
         * \param symbols    The symbols, like "BTC-USD". Use comma to separate multi symbols, like
         * "BTC-USD,EOS-USD".
         * \param interval The candlestick/kline interval, 1min, 5min, 15min, 30min, 60min,4hour,1day,1week, 1mon.
         * \param callback   The implementation is required, onReceive will be called if receive server's response.
         * \param startTime  The request kline/candlestick start time.
         * \param endTime    The request kline/candlestick start time.
         * \param errorHandler The error handler will be called if request failed or error happen
         * between client and HuobiSwap server.
         */
        virtual void requestCandlestickEvent(
                const char* symbols,
                CandlestickInterval interval,
                long startTime,
                long endTime,
                const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
                const std::function<void(Error&)>& errorHandler = std::function<void(Error&)>()) = 0;
        /**
         * Request candlestick/kline event. If the candlestick/kline is received, onReceive in callback will be called.
         *
         * \param autoClose ,true or false
         * \param symbols    The symbols, like "BTC-USD". Use comma to separate multi symbols, like
         * "BTC-USD,EOS-USD".
         * \param interval The candlestick/kline interval, 1min, 5min, 15min, 30min, 60min,4hour,1day,1week, 1mon.
         * \param callback   The implementation is required, onReceive will be called if receive server's response.
         * \param startTime  The request kline/candlestick start time.
         * \param endTime    The request kline/candlestick start time.
         * \param errorHandler The error handler will be called if request failed or error happen
         * between client and HuobiSwap server.
         */
        virtual void requestCandlestickEvent(
                bool autoClose,
                const char* symbols,
                CandlestickInterval interval,
                long startTime,
                long endTime,
                const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
                const std::function<void(Error&)>& errorHandler = std::function<void(Error&)>()) = 0;
    };
    WsRequestClient* createWsRequestClient();
    WsRequestClient* createWsRequestClient(const char* apiKey, const char* secretKey);

}



#endif /* WSREQUESTCLIENT_H */

