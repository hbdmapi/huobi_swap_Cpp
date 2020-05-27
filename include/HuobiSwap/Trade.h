/*******************************************************************************
* File name： Trade.h
* Description: HuobiSwap api Trade header files.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/
#ifndef TRADE_H
#define TRADE_H

#include <string>
#include "HuobiSwap/Enums.h"
#include "HuobiSwap/Decimal.h"

namespace HuobiSwap {

    /**
     * The detail trade information.
     */
    struct Trade {

        /**
         * The global trade id.
         */
        std::string id;

        /**
         * The trade id.
         */
        Decimal trade_id;

        /**
         * The trade volume.
         */
        Decimal trade_volume;

        /**
         * The trade price.
         */
        Decimal trade_price;

        /**
         * The trade fee.
         */ 
        Decimal trade_fee;

        /**
         * The trade turnover.
         */ 
        Decimal trade_turnover;

        /**
         * The UNIX formatted timestamp in UTC when the order was created.
         */
        long created_at;

        /**
         * The role
         */
        DealRole role;

        /**
         * fee asset.
         */
        std::string fee_asset;

    };

}


#endif /* TRADE_H */
