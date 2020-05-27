/*******************************************************************************
* File name： Order.h
* Description: HuobiSwap api Order header files.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/

#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "HuobiSwap/Enums.h"
#include "HuobiSwap/Decimal.h"
#include "HuobiSwap/Trade.h"

namespace HuobiSwap {

    /**
     * The detail order information.
     */
    struct Order {
        /**
         * symbol here is the contract_code.
         */
        std::string symbol;

        /**
         * The quantity in this order.
         */
        Decimal volume;

        /**
         * The limit price of order.
         */
        Decimal price;


        /**
         * The Order price type.
         */
        OrderPriceType order_price_type;

        /**
         * The direction 
         */
        OrderSide direction;

        /**
         * The offset 
         */
        TradeOffset offset;

        /**
         * order status
         */
        OrderStatus status;

        /**
         * order id
         */
        long order_id;

        /**
         * client_order_id
         */
        long client_order_id;

        /**
         * order source.
         */
        OrderSource source;   

        /**
         * order type.
         */
        OrderType order_type; 

        /**
         * The UNIX formatted timestamp in UTC when the order was created.
         */
        long created_at = 0;

        /**
         * accumulated trade volume
         */
        Decimal trade_volume = 0;

        /**
         *  accumulated turnover 
         */
        Decimal trade_turnover = 0;

        /**
         * accumulated fee
         */
        Decimal fee = 0;

        /**
         * trade average order price
         */
        Decimal trade_avg_price = 0;

        /**
         * margin frozen
         */
        Decimal margin_frozen = 0;

        /**
         * profit
         */
        Decimal profit = 0;

        /**
         * liquidation type
         */
        LiquidationType liquidation_type;

        /**
         * match results
         */
        std::vector<Trade> trades;

    };

}


#endif /* ORDER_H */
