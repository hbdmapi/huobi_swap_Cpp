/*******************************************************************************
* File name： TestSubscribeOrderUpdateEvent.h
* Description: gtest HuobiSwap header file.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-22
* History: 
*
*******************************************************************************/
#ifndef TESTSUBSCRIBEORDERUPDATEEVENT_H
#define TESTSUBSCRIBEORDERUPDATEEVENT_H
#include <gtest/gtest.h>
#include <../src/WebSocketApiImpl.h>
#include "../include/HuobiSwap/Error.h"
#include "../include/HuobiSwap/Decimal.h"
#include "../src/Utils/JsonDocument.h"
#include <list>
#include "MockWebsocketConnecttion.h"
using namespace HuobiSwap;

TEST(TestSubscribeOrderUpdateEvent, request) {

    SubscriptionOptions op;
    WebSocketApiImpl* impl = new WebSocketApiImpl();
    std::list<std::string> symbols;
    symbols.push_back("BTC-USD");
    auto request = impl->subscribeOrderUpdateEvent(symbols, [](const OrderUpdateEvent&) {
    }, nullptr);
    MockWebsocketConnecttion* websocketConnection = new MockWebsocketConnecttion(request);
    request->connectionHandler(websocketConnection);
    std::string subscription = websocketConnection->pop();
    ASSERT_TRUE(subscription.find("orders") != -1);
    ASSERT_TRUE(request->isNeedSignature);
}

TEST(TestSubscribeOrderUpdateEvent, Receive_Normal) {
    std::string data = "{\n"
            "  \"op\": \"notify\",\n"
            "  \"topic\": \"orders.btc-usd\",\n"
            "  \"ts\": 1589945631262,\n"
            "  \"symbol\": \"BTC\",\n"
            "  \"contract_code\": \"BTC-USD\",\n"
            "  \"volume\": 1,\n"
            "  \"price\": 110000.0,\n"
            "  \"order_price_type\": \"limit\",\n"
            "  \"direction\": \"sell\",\n"
            "  \"offset\": \"open\",\n"
            "  \"status\": 3,\n"
            "  \"lever_rate\": 20,\n"
            "  \"order_id\": 712629157472788480,\n"
            "  \"order_id_str\": \"712629157472788480\",\n"
            "  \"client_order_id\": null,\n"
            "  \"order_source\": \"api\",\n"
            "  \"order_type\": 1,\n"
            "  \"created_at\": 1589945631152,\n"
            "  \"trade_volume\": 1.0,\n"
            "  \"fee\": 0,\n"
            "  \"trade_avg_price\": 0.0,\n"
            "  \"trade_turnover\": 0,\n"
            "  \"margin_frozen\": 0.000045454545454545,\n"
            "  \"profit\": 0,\n"
            "  \"liquidation_type\": \"0\",\n"
            "  \"trade\": [\n"
            "        {\n"
            "           \"id\": \"2131234825-6124591349-1\",\n"
            "           \"trade_id\": 112,\n"
            "           \"trade_volume\": 1,\n"
            "           \"trade_price\": 123.455,\n"
            "           \"trade_fee\": 0.234,\n"
            "           \"trade_turnover\": 34.123,\n"
            "           \"created_at\": 1490759594752,\n"
            "           \"role\": \"maker\"\n"
            "       }\n" 
            "  ]\n"
            "}\n";
    SubscriptionOptions op;
    WebSocketApiImpl* impl = new WebSocketApiImpl("12345", "456");
    std::list<std::string> symbols;
    symbols.push_back("BTC-USD");
    auto request = (WebSocketRequestImpl<OrderUpdateEvent>*)impl->subscribeOrderUpdateEvent(symbols, [](const OrderUpdateEvent&) {
    }, nullptr);
    JsonDocument doc;
    JsonWrapper json = doc.parseFromString(data.c_str());
    auto event = request->JsonParser(json);
    ASSERT_EQ("btc-usd", event.symbol);
    ASSERT_EQ(Decimal("110000.0"), event.data.price);
    ASSERT_EQ("btc-usd", event.data.symbol);
    ASSERT_EQ(1589945631262, event.timestamp);
    ASSERT_EQ(1589945631152, event.data.created_at);
    ASSERT_EQ(712629157472788480, event.data.order_id);
    ASSERT_EQ(OrderPriceType::limit, event.data.order_price_type);
    ASSERT_EQ(OrderSource::api, event.data.source);
    ASSERT_EQ(Decimal("1.0"), event.data.trade_volume);
    ASSERT_EQ("2131234825-6124591349-1", event.data.trades[0].id);
    ASSERT_EQ(Decimal("1"), event.data.trades[0].trade_volume);
    ASSERT_EQ(Decimal("123.455"), event.data.trades[0].trade_price);
    ASSERT_EQ(Decimal("0.234"), event.data.trades[0].trade_fee);
    ASSERT_EQ(Decimal("34.123"), event.data.trades[0].trade_turnover);
    ASSERT_EQ(1490759594752, event.data.trades[0].created_at);
    ASSERT_EQ(DealRole::maker, event.data.trades[0].role);
}
#endif /* TESTSUBSCRIBEORDERUPDATEEVENT_H */

