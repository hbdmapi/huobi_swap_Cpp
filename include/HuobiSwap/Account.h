/*******************************************************************************
* File name： Account.h
* Description: HuobiSwap api account header files.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <vector>
#include "HuobiSwap/Enums.h"
#include "HuobiSwap/Decimal.h"

namespace HuobiSwap {

    /**
     * The account information for swap account.
     */
    struct Account {
        /**
         * The symbol.
         */
        std::string symbol;

        /*
         *  The contract code.
         */
        std::string contract_code;

        /*
         * The margin balance
         */
        Decimal margin_balance;

        /*
         * The static margin.
         */
        Decimal margin_static;

        /*
         * The position margin.
         */
        Decimal margin_postion;

        /*
         * The frozen margin.
         */
        Decimal margin_frozen;

        /*
         * The Available margin.
         */
        Decimal margin_available;

        /*
         * Realized profit.
         */
        Decimal profit_real;

        /*
         * Unrealized profit.
         */
        Decimal profit_unreal;

        /*
         * The risk rate.
         */
        Decimal risk_rate;

        /*
         * Estimated liquidation price.
         */
        Decimal liquidation_price;

        /*
         * Available withdrawl.
         */
        Decimal withdraw_available;

        /*
         * Leverage rate
         */
        Decimal lever_rate;

        /*
         * Adjustment Factor
         */
        Decimal adjust_factor;

    };
}

#endif /* ACCOUNT_H */



