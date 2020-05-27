#ifndef RESTAPIIMPL_H
#define RESTAPIIMPL_H

#include <string>
#include <vector>

#include "RestApi.h"
#include "Utils/ApiSignature.h"
#include "Utils/UrlParamsBuilder.h"
#include "Utils/JsonDocument.h"
#include "HuobiSwap/Account.h"
#include "HuobiSwap/ContractInfo.h"
#include "HuobiSwap/Log.h"
#include "HuobiSwap/RequestOptions.h"
#include "GetHost.h"

namespace HuobiSwap {

    class RestApiImpl {
    private:

        std::string TradingUrl = "https://api.hbdm.vn";
        std::string MarketQueryUrl = "https://api.hbdm.vn";

        std::string subscriptionMarketUrl = "wss://api.hbdm.vn/swap-ws";
        std::string subscriptionTradingUrl = "wss://api.Hbdm.vn/swap-notification";
        std::string accessKey;
        std::string secretKey;
        std::string host = "api.hbdm.vn";


    public:

        RestApiImpl() {
            accessKey = "";
            secretKey = "";

        }

        RestApiImpl(RequestOptions& op) {
            accessKey = "";
            secretKey = "";
            host = GetHost(op.url);
            if (host.find("api") != -1) {
                this->MarketQueryUrl = "https://";
                this->MarketQueryUrl += host;
                this->TradingUrl = "https://";
                this->TradingUrl += host;
            } else {
                this->MarketQueryUrl = "https://";
                this->MarketQueryUrl = this->MarketQueryUrl + host + "/api";
                this->TradingUrl = "https://";
                this->TradingUrl = this->TradingUrl + host + "/api";
            }

        }

        RestApiImpl(const char* accessKey,
                const char* secretKey) {
            this->accessKey = accessKey;
            this->secretKey = secretKey;
        }

        RestApiImpl(const char* accessKey,
                const char* secretKey,
                RequestOptions& op) {
            this->accessKey = accessKey;
            this->secretKey = secretKey;
            host = GetHost(op.url);
            if (host.find("api") != -1) {
                this->MarketQueryUrl = "https://";
                this->MarketQueryUrl += host;
                this->TradingUrl = "https://";
                this->TradingUrl += host;
            } else {
                this->MarketQueryUrl = "https://";
                this->MarketQueryUrl = this->MarketQueryUrl + host + "/swap-api";
                this->TradingUrl = "https://";
                this->TradingUrl = this->TradingUrl + host + "/swap-api";
            }

        }
        template <typename T>
        RestApi<T>* createRequestByPostWithSignature(const char* adress, UrlParamsBuilder&builder);
        template <typename T>
        RestApi<T>* createRequestByGet(const char* adress, UrlParamsBuilder&builder);

        RestApi<std::vector<Account>>*getAccountInfo();
        RestApi<std::vector<Account>>*getAccountInfo(std::string contractCode);
        RestApi<std::vector<ContractInfo>>*getContractInfo();
        RestApi<std::vector<ContractInfo>>*getContractInfo(std::string contractCode);

    };
}
#endif /* RESTAPIIMPL_H */
