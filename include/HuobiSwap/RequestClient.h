/*******************************************************************************
* File name： Client.h
* Description: HuobiSwap api client header files.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/

#ifndef REQUESTCLIENT_H
#define REQUESTCLIENT_H

#include <vector>
#include <list>
#include <string>
#include "HuobiSwap/Account.h"
#include "HuobiSwap/ContractInfo.h"
#include "RequestOptions.h"

namespace HuobiSwap {

    /**
     * Synchronous request interface, invoking HuobiSwap RestAPI via synchronous method.<br> All methods in
     * this interface will be blocked until the RestAPI response.
     * <p>
     * If the invoking failed or timeout, the Error will be thrown.
     */
    struct RequestClient {

        /**
         * Get the account info.
         *
         * \return The information of account.
         */
        virtual std::vector<Account> getAccountInfo() = 0;
        /**
         * Get the account of the specified  type
         *
         * \param contractCode The specified contract code
         * \return The information of the account that is specified type.
         */
        virtual std::vector<Account> getAccountInfo(std::string contractCode) = 0;
        /**
         * Get information of all contract.
         *
         * \return The information of all contract.
         */
        virtual std::vector<ContractInfo> getContractInfo() = 0;
        /**
         * Get information of the specified contract.
         *
         * \param contractCode The specified contract code
         * \return The information of the specified contract.
         */
        virtual std::vector<ContractInfo> getContractInfo(std::string contractCode) = 0;

    };

    RequestClient* createRequestClient();

    RequestClient* createRequestClient(const char* apiKey, const char* secretKey);

    RequestClient* createRequestClient(RequestOptions& op);

    RequestClient* createRequestClient(const char* apiKey, const char* secretKey, RequestOptions& op);

}
#endif /* REQUESTCLIENT_H */
