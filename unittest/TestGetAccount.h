/*******************************************************************************
* File name： TestGetAccount.h
* Description: gtest HuobiSwap header file.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-03
* History: 
*
*******************************************************************************/

#ifndef TESTGETACCOUNT_H
#define TESTGETACCOUNT_H


#include <gtest/gtest.h>
#include <../src/RestApiImpl.h>
#include "../include/HuobiSwap/Error.h"
#include "../include/HuobiSwap/Decimal.h"
#include "../src/Utils/JsonDocument.h"
#include "../src/TimeService.h"


using namespace HuobiSwap;

TEST(TestGetAccount, Request) {
    RestApiImpl* impl = new RestApiImpl("12345", "67890");
    auto request = impl->getAccountInfo();
    ASSERT_TRUE(request->getUrl().find("swap-api/v1/swap_account_info") != -1);
    ASSERT_EQ("POST", request->method);
    ASSERT_TRUE(request->getUrl().find("Signature"));
}

TEST(TestGetAccount, Result) {
    std::string data = "{\"status\":\"ok\",\"data\":[{\"symbol\":\"BTC\",\"margin_balance\":2.364671102E-9,\"margin_position\":0,\"margin_frozen\":0,\"margin_available\":2.364671102E-9,\"profit_real\":0E-18,\"profit_unreal\":0,\"risk_rate\":null,\"withdraw_available\":2.364671102E-9,\"liquidation_price\":null,\"lever_rate\":125,\"adjust_factor\":0.650000000000000000,\"margin_static\":2.364671102E-9,\"contract_code\":\"BTC-USD\"}],\"ts\":1588165704668}";

    RestApiImpl* impl = new RestApiImpl("12345", "67890");
    auto request = impl->getAccountInfo();
    JsonWrapper json = JsonDocument().parseFromString(data);
    auto result = request->jsonParser(json);
    ASSERT_EQ("BTC", result[0].symbol);
    ASSERT_EQ(Decimal(0), result[0].risk_rate);
    ASSERT_EQ("BTC-USD", result[0].contract_code);
}

#endif /* TESTGETACCOUNT_H */

