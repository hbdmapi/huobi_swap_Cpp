/*******************************************************************************
* File name： CandlestickRequest.h
* Description: HuobiSwap api CandlestickEvent header files.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/

#ifndef CANDLESTICKREQUEST_H
#define CANDLESTICKREQUEST_H

#include <string>
#include "HuobiSwap/Enums.h"

namespace HuobiSwap {

    /**
     * The request for getting candlestick/kline data.
     */
    struct CandlestickRequest {

        /**
         * The request for getting candlestick/kline data.
         *
         * \param symbol: The symbol, like "btcusdt". To query hb10, put "hb10" at here. (mandatory)
         * \param interval: The candlestick/kline interval, MIN1, MIN5, DAY1 etc. (mandatory)
         */

        CandlestickRequest(const std::string& symbol, const CandlestickInterval& interval) : symbol(symbol), interval(interval) {
        }

        /**
         * The request for getting candlestick/kline data.
         *
         * \param symbol: The symbol, like "btcusdt". To query hb10, put "hb10" at here. (mandatory)
         * \param interval: The candlestick/kline interval, MIN1, MIN5, DAY1 etc. (mandatory)
         * \param startTime: The start time of of requested candlestick/kline data. (optional)
         * \param endTime: The end time of of requested candlestick/kline data. (optional)
         * \param size: The maximum number of candlestick/kline requested. Range [1 - 2000]. (optional)
         */

        CandlestickRequest(
                const std::string& symbol,
                const CandlestickInterval& interval,
                long startTime,
                long endTime,
                int size) : symbol(symbol), interval(interval), startTime(startTime), endTime(endTime), size(size) {
        }


        std::string symbol;
        CandlestickInterval interval;
        long startTime = 0;
        int endTime = 0;
        int size = 150;
    };

}
#endif /* CANDLESTICKREQUEST_H */

