/*******************************************************************************
* File name： ContractInfo.h
* Description: HuobiSwap api client header file.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-03
* History: 
*
*******************************************************************************/

#ifndef CONTRACT_INFO_H
#define CONTRACT_INFO_H

#include <vector>
#include "HuobiSwap/Enums.h"
#include "HuobiSwap/Decimal.h"

namespace HuobiSwap {

    /**
     * The contract information.
     */
    struct ContractInfo {
        /**
         * The symbol.
         */
        std::string symbol;

        /*
         *  The contract code.
         */
        std::string contract_code;

        /*
         * The contract size.
         */
        Decimal contract_size;

        /*
         * The price tick.
         */
        Decimal price_tick;

        /*
         * The settlement date.
         */
        std::string settlement_date;

        /*
         * The Listing Date.
         */
        std::string create_date;

        /*
         * The Contract status.
         */
        int contract_status;

    };
}

#endif /* CONTRACT_INFO_H */



