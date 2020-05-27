#ifndef SYNCCLIENTIMPL_H
#define SYNCCLIENTIMPL_H

#include "RestApiImpl.h"
#include "HuobiSwap/RequestClient.h"
#include "Utils/ApiSignature.h"
#include "HuobiSwap/RequestOptions.h"

namespace HuobiSwap {

    class SyncClientImpl : public RequestClient {
    private:
        const char* accesssKey;
        const char* secretKey;
        RestApiImpl *impl;

    public:
        SyncClientImpl(const char* accesssKey, const char* secretKey);
        SyncClientImpl(const char* accesssKey, const char* secretKey, RequestOptions& op);
        SyncClientImpl();
        SyncClientImpl(RequestOptions& op);
        std::vector<Account> getAccountInfo();
        std::vector<Account> getAccountInfo(std::string contractCode);
        std::vector<ContractInfo> getContractInfo();
        std::vector<ContractInfo> getContractInfo(std::string contractCode);
    };

}



#endif /* SYNCCLIENTIMPL_H */