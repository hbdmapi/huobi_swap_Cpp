#include <string>
#include <vector>
#include <libwebsockets.h>

#include "WebSocketApiImpl.h"
#include "WebSocketRequest.h"
#include "WebSocketConnection.h"
#include "Utils/Channels.h"
#include "Utils/ChannelParser.h"
#include "TimeService.h"
#include "InputChecker.h"

namespace HuobiSwap {

    WebSocketRequest* WebSocketApiImpl::subscribeCandlestickEvent(
            const std::list<std::string>& symbols,
            CandlestickInterval interval,
            const std::function<void(const CandlestickEvent&) >& callback,
            const std::function<void(Error&)>& errorHandler) {

        InputChecker::checker()
                ->shouldNotNull(interval.getValue(), "interval")
                ->checkCallback(callback);
        auto req = new WebSocketRequestImpl<CandlestickEvent>();
        req->connectionHandler = [symbols, interval](WebSocketConnection * connection) {
            for (std::string symbol : symbols) {
                connection->send(Channels::klineChannel(symbol, interval));
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        };
        req->JsonParser = [interval](const JsonWrapper & json) {
            ChannelParser parser = ChannelParser(json.getString("ch"));
            CandlestickEvent event;
            event.symbol = parser.getSymbol();
            event.interval = interval;
            event.timestamp = json.getLong("ts");
            JsonWrapper tick = json.getJsonObjectOrArray("tick");
            Candlestick data;
            data.timestamp = tick.getLong("id");
            data.id = tick.getLong("id");
            data.amount = tick.getDecimal("amount");
            data.close = tick.getDecimal("close");
            data.high = tick.getDecimal("high");
            data.low = tick.getDecimal("low");
            data.open = tick.getDecimal("open");
            data.volume = tick.getDecimal("vol");
            data.count = tick.getLong("count");
            event.data = data;
            return event;
        };
        req->isNeedSignature = false;
        req->Callback = callback;
        req->errorHandler = errorHandler;
        return req;
    }

    WebSocketRequest* WebSocketApiImpl::subscribeOrderUpdateEvent(
            const std::list<std::string>& symbols,
            const std::function<void(const OrderUpdateEvent&) >& callback,
            const std::function<void(Error&)>& errorHandler) {
        InputChecker::checker()->checkCallback(callback);

        auto req = new WebSocketRequestImpl<OrderUpdateEvent>();

        req->connectionHandler = [symbols](WebSocketConnection * connection) {
            for (std::string symbol : symbols) {
                connection->send(Channels::orderChannel(symbol));
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        };

        req->JsonParser = [this](const JsonWrapper & json) {
            Log::WriteLog("[OrderUpdate...]");
            ChannelParser parser = ChannelParser(json.getString("topic"));
            OrderUpdateEvent orderUpdateEvent;
            orderUpdateEvent.symbol = parser.getSymbol();
            orderUpdateEvent.timestamp = json.getLong("ts");
            Order order;
            order.symbol = parser.getSymbol();           
            order.volume  = json.getDecimal("volume");
            order.price = json.getDecimal("price");
            //fix me: SegementFault if below code is removed.
            order.direction = OrderSide::buy;
            order.direction = OrderSide::lookup(json.getString("direction"));
            order.offset = TradeOffset::lookup(json.getString("offset"));
            order.status = OrderStatus::lookup(json.getString("status"));
            order.order_price_type = OrderPriceType::lookup(json.getString("order_price_type"));
            order.order_id = json.getLong("order_id");
            order.client_order_id = json.getLongOrDefault("client_order_id", 0);
            order.source = OrderSource::lookup(json.getString("order_source"));
            order.order_type = OrderType::lookup(json.getString("order_type"));
            order.created_at = json.getLong("created_at");
            order.trade_volume = json.getDecimal("trade_volume");
            order.margin_frozen = json.getDecimal("margin_frozen");
            order.profit = json.getDecimal("profit");
            order.fee = json.getDecimalOrDefault("fee", 0);
            order.trade_turnover = json.getDecimalOrDefault("trade_turnover", 0);
            order.trade_avg_price = json.getDecimal("trade_avg_price");
            order.liquidation_type = LiquidationType::lookup(json.getString("liquidation_type"));
            
            JsonWrapper trades = json.getJsonObjectOrArray("trade");
            size_t size = trades.size();
            for (int i = 0; i < size; i++) {
                JsonWrapper item = trades.getJsonObjectAt(i);
                Trade trade;
                trade.id = item.getString("id");
                trade.trade_volume = item.getDecimal("trade_volume");
                trade.trade_price = item.getDecimal("trade_price");
                trade.trade_fee = item.getDecimal("trade_fee");
                trade.trade_turnover = item.getDecimal("trade_turnover");
                trade.created_at = item.getLong("created_at");
                trade.role = DealRole::lookup(item.getString("role"));
                order.trades.push_back(trade);
            }
            orderUpdateEvent.data = order;
            //Log::WriteLog("clientorderid: %s \n", orderUpdateEvent.data.order_id);

            orderUpdateEvent.client_order_id = json.getLongOrDefault("client_order_id", 0);
            orderUpdateEvent.unfilled_volume = json.getDecimal("volume") - json.getDecimal("trade_volume");

            return orderUpdateEvent;
        };
        req->isNeedSignature = true;
        req->Callback = callback;
        req->errorHandler = errorHandler;
        return req;
    }



    WebSocketRequest* WebSocketApiImpl::requestCandlestickEvent(
            bool autoClose,
            const std::list<std::string>& symbols,
            CandlestickInterval interval,
            long startTime,
            long endTime,
            const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
            const std::function<void(Error&)>& errorHandler) {

        InputChecker::checker()
                ->shouldNotNull(interval.getValue(), "interval")
                ->checkCallback(callback);
        auto req = new WebSocketRequestImpl<std::vector < CandlestickEvent >> ();
        req->autoClose = autoClose;
        req->time = symbols.size();
        req->connectionHandler = [symbols, interval, startTime, endTime](WebSocketConnection * connection) {
            for (std::string symbol : symbols) {
                connection->send(Channels::klineChannel(Channels::OP_REQ, symbol, interval, startTime, endTime));
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        };
        req->JsonParser = [interval](const JsonWrapper & json) {
            std::vector<CandlestickEvent> cans;
            JsonWrapper data = json.getJsonObjectOrArray("data");
            for (int i = 0; i < data.size(); i++) {
                JsonWrapper item = data.getJsonObjectAt(i);
                CandlestickEvent candlestickEvent;
                ChannelParser parser = ChannelParser(json.getString("rep"));
                candlestickEvent.symbol = parser.getSymbol();
                candlestickEvent.interval = interval;
                Candlestick can;
                can.timestamp = item.getLong("id");
                can.id = item.getLong("id");
                can.amount = item.getDecimal("amount");
                can.close = item.getDecimal("close");
                can.high = item.getDecimal("high");
                can.low = item.getDecimal("low");
                can.open = item.getDecimal("open");
                can.volume = item.getDecimal("vol");
                can.count = item.getLong("count");
                candlestickEvent.data = can;
                candlestickEvent.timestamp = can.timestamp;
                cans.push_back(candlestickEvent);
            }
            return cans;
        };
        req->isNeedSignature = false;
        req->Callback = callback;
        req->errorHandler = errorHandler;
        return req;
    }

}

