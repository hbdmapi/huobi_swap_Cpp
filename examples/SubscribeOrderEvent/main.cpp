#include <iostream>
#include "HuobiSwap/Client.h"


using namespace HuobiSwap;
using namespace std;

int main(int argc, char** argv) {
    SubscriptionClient* client = createSubscriptionClient("access_key", "secret_key");
    client->subscribeOrderUpdateEvent("BTC-USD", [](OrderUpdateEvent OrderUpdateEvent) {

        cout << "Symbol: " << OrderUpdateEvent.symbol << endl;
        cout << "Order Unfilled Volume: " << OrderUpdateEvent.unfilled_volume << endl;
        cout << "Order Volume: " << OrderUpdateEvent.data.trade_volume << endl;
        cout << "Order Status: " << OrderUpdateEvent.data.status.getValue() << endl;
        cout << "Order Direction: " << OrderUpdateEvent.data.direction.getValue() << endl;
        cout << "Order Offset: " << OrderUpdateEvent.data.offset.getValue() << endl;
        cout << "Order Client order id: "<< OrderUpdateEvent.data.client_order_id << endl;
        cout << "Order id:" << OrderUpdateEvent.data.order_id << endl;
        cout << "Order created at:" << OrderUpdateEvent.data.order_id << endl;
        std::vector<Trade> trades = OrderUpdateEvent.data.trades;
        for (Trade trade : OrderUpdateEvent.data.trades){
            cout << "id: " << trade.id << endl;
            cout << "trade price: " << trade.trade_price << endl;
            cout << "trade volume: " << trade.trade_volume << endl;
            cout << "trade created: " << trade.created_at << endl;
        }
    });

    client->startService();

}
