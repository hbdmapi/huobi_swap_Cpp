#include "RestApiImpl.h"
#include <vector>
#include <stdlib.h>
#include <list>

#include "HuobiSwap/Error.h"
#include "HuobiSwap/Account.h"
#include "HuobiSwap/ContractInfo.h"
#include "Utils/UrlParamsBuilder.h"
#include "TimeService.h"
#include "InputChecker.h"
#include "Utils/JsonWriter.h"

namespace HuobiSwap {

    RestApi<std::vector<Account>>*RestApiImpl::getAccountInfo() {
        UrlParamsBuilder builder;
        auto res = createRequestByPostWithSignature<std::vector < Account >> ("/swap-api/v1/swap_account_info", builder);
        res->jsonParser = [this](const JsonWrapper & json) {
            std::vector<Account> accounts;
            JsonWrapper data = json.getJsonObjectOrArray("data");
            size_t size = data.size();
            for (int i = 0; i < size; i++) {
                JsonWrapper item = data.getJsonObjectAt(i);
                Account account;
                account.symbol = item.getString("symbol");
                account.contract_code = item.getString("contract_code");
                account.margin_balance = item.getDecimal("margin_balance");
                account.margin_static = item.getDecimal("margin_static");
                account.margin_postion = item.getDecimal("margin_position");
                account.margin_available = item.getDecimal("margin_available");
                account.profit_real = item.getDecimal("profit_real");
                account.profit_unreal = item.getDecimal("profit_unreal");
                account.risk_rate = item.getDecimalOrDefault("risk_rate", 0);
                account.liquidation_price = item.getDecimalOrDefault("liquidation_price", 0);
                account.withdraw_available = item.getDecimal("withdraw_available");
                account.lever_rate = item.getDecimal("lever_rate");
                account.adjust_factor = item.getDecimal("adjust_factor");
                accounts.push_back(account);
            }
            return accounts;
        };
        return res;
    }

    RestApi<std::vector<Account>>*RestApiImpl::getAccountInfo(std::string contractCode) {
        InputChecker::checker();

        UrlParamsBuilder builder;
        builder.putPost("contract_code", contractCode);
        
        auto res = createRequestByPostWithSignature<std::vector < Account >> ("/swap-api/v1/swap_account_info", builder);
        res->jsonParser = [this](const JsonWrapper & json) {
            std::vector<Account> accounts;
            JsonWrapper data = json.getJsonObjectOrArray("data");
            size_t size = data.size();
            for (int i = 0; i < size; i++) {
                JsonWrapper item = data.getJsonObjectAt(i);
                Account account;
                account.symbol = item.getString("symbol");
                account.contract_code = item.getString("contract_code");
                account.margin_balance = item.getDecimal("margin_balance");
                account.margin_static = item.getDecimal("margin_static");
                account.margin_postion = item.getDecimal("margin_position");
                account.margin_available = item.getDecimal("margin_available");
                account.profit_real = item.getDecimal("profit_real");
                account.profit_unreal = item.getDecimal("profit_unreal");
                account.risk_rate = item.getDecimalOrDefault("risk_rate", 0);
                account.liquidation_price = item.getDecimalOrDefault("liquidation_price", 0);
                account.withdraw_available = item.getDecimal("withdraw_available");
                account.lever_rate = item.getDecimal("lever_rate");
                account.adjust_factor = item.getDecimal("adjust_factor");
                accounts.push_back(account);
            }
            return accounts;
        };
        return res;
    }

    RestApi<std::vector<ContractInfo>>*RestApiImpl::getContractInfo() {
        UrlParamsBuilder builder;
        auto res = createRequestByGet<std::vector < ContractInfo >> ("/swap-api/v1/swap_contract_info", builder);
        res->jsonParser = [this](const JsonWrapper & json){
            std::vector<ContractInfo> contractInfos;
            JsonWrapper data = json.getJsonObjectOrArray("data");
            size_t size = data.size();
            for (int i = 0; i < size; i++) {
                JsonWrapper item = data.getJsonObjectAt(i);
                ContractInfo contractInfo;
                contractInfo.symbol = item.getString("symbol");
                contractInfo.contract_code = item.getString("contract_code");
                contractInfo.contract_size = item.getDecimal("contract_size");
                contractInfo.price_tick = item.getDecimal("price_tick");
                contractInfo.settlement_date = item.getString("settlement_date");
                contractInfo.create_date = item.getString("create_date");
                contractInfo.contract_status = item.getInt("contract_status");
                contractInfos.push_back(contractInfo);
            }
            return contractInfos;
        };
        return res;
    }

    RestApi<std::vector<ContractInfo>>*RestApiImpl::getContractInfo(std::string contractCode) {
        InputChecker::checker();

        UrlParamsBuilder builder;
        builder.putUrl("contract_code", contractCode);

        auto res = createRequestByGet<std::vector < ContractInfo >> ("/swap-api/v1/swap_contract_info", builder);
        res->jsonParser = [this](const JsonWrapper & json){
            std::vector<ContractInfo> contractInfos;
            JsonWrapper data = json.getJsonObjectOrArray("data");
            size_t size = data.size();
            for (int i = 0; i < size; i++) {
                JsonWrapper item = data.getJsonObjectAt(i);
                ContractInfo contractInfo;
                contractInfo.symbol = item.getString("symbol");
                contractInfo.contract_code = item.getString("contract_code");
                contractInfo.contract_size = item.getDecimal("contract_size");
                contractInfo.price_tick = item.getDecimal("price_tick");
                contractInfo.settlement_date = item.getString("settlement_date");
                contractInfo.create_date = item.getString("create_date");
                contractInfo.contract_status = item.getInt("contract_status");
                contractInfos.push_back(contractInfo);
            }
            return contractInfos;
        };
        return res;
    }


    template <typename T>
    RestApi<T>* RestApiImpl::createRequestByPostWithSignature(const char* adress, UrlParamsBuilder& builder) {
        RestApi<T>* res = new RestApi<T>;
        res->method = "POST";
        std::string temp = adress;
        temp += "?";

        std::string tail = ApiSignature::buildSignaturePath(host, accessKey, secretKey,
                adress, res->method, builder.getAdress().c_str());
        if (builder.getAdress().empty()) {
            builder.setAdress(temp + builder.getAdress() + tail);
        } else {
            builder.setAdress(temp + builder.getAdress() + "&" + tail);
        }

        res->setUrl(TradingUrl + builder.getAdress());
        res->setPostBody(builder.getPostBody());
        return res;
    }

    template <typename T>
    RestApi<T>* RestApiImpl::createRequestByGet(const char* adress, UrlParamsBuilder& builder) {
        RestApi<T>* res = new RestApi<T>;
        res->method = "GET";
        std::string url;
        if (builder.getAdress() == "") {
            url = adress;
        } else {
            builder.getAdress();
            std::string sadress = adress;
            url = sadress + "?" + builder.getAdress();
        }
        builder.setAdress(url);

        res->setUrl(MarketQueryUrl + builder.getAdress());
        res->setPostBody(builder.getPostBody());
        return res;
    }

}
