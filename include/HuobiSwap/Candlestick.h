/*******************************************************************************
* File name： Candlestick.h
* Description: HuobiSwap api candlestick header files.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/

#ifndef CANDLESTICK_H
#define CANDLESTICK_H

#include "HuobiSwap/Decimal.h"

namespace HuobiSwap {
   /**
    * The candlestick/kline data.
    */
    struct Candlestick {
        /**
         * The UNIX formatted timestamp in UTC.
         */
        long timestamp = 0;

        /**
         * Trade Volume(Coin), trade volume(coin)=sum(order quantity of a single order * face value of the coin/order price).
         */
        Decimal amount;
        
        /**
         * The number of completed trades.
         */
        long count = 0;
        
        /**
         * The opening price.
         */
        Decimal open;
        
        /**
         * The closing price.
         */
        Decimal close;
        
        /**
         * The low price.
         */
        Decimal low;
        
        /**
         * The high price.
         */
        Decimal high;
        
        /**
         * The trading volume.
         */
        Decimal volume;
        
        /**
         * id.
         */
        long id = 0;
    };
}

#endif /* CANDLESTICK_H */

