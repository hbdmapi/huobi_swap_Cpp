#include "SyncClientImpl.h"
#include "RestApiInvoke.h"

namespace HuobiSwap {

    SyncClientImpl::SyncClientImpl(const char* accesssKey, const char* secretKey) {
        this->accesssKey = accesssKey;
        this->secretKey = secretKey;
        impl = new RestApiImpl(accesssKey, secretKey);

    }

    SyncClientImpl::SyncClientImpl(const char* accesssKey, const char* secretKey, RequestOptions& op) {
        this->accesssKey = accesssKey;
        this->secretKey = secretKey;
        impl = new RestApiImpl(accesssKey, secretKey, op);

    }

    SyncClientImpl::SyncClientImpl() {
        this->accesssKey = "";
        this->secretKey = "";
        impl = new RestApiImpl();
    }

    SyncClientImpl::SyncClientImpl(RequestOptions& op) {
        this->accesssKey = "";
        this->secretKey = "";
        impl = new RestApiImpl(op);
    }

    std::vector<Account> SyncClientImpl::getAccountInfo() {
        std::vector<Account> accounts = RestApiInvoke::callSync(impl->getAccountInfo());
        return accounts;
    }


    std::vector<Account> SyncClientImpl::getAccountInfo(std::string contractCode) {
        std::vector<Account> accounts = RestApiInvoke::callSync(impl->getAccountInfo(contractCode));
        return accounts;
    }

    std::vector<ContractInfo> SyncClientImpl::getContractInfo() {
        std::vector<ContractInfo> contracts = RestApiInvoke::callSync(impl->getContractInfo());
        return contracts;
    }

    std::vector<ContractInfo> SyncClientImpl::getContractInfo(std::string contractCode) {
        std::vector<ContractInfo> contracts = RestApiInvoke::callSync(impl->getContractInfo(contractCode));
        return contracts;
    }
}