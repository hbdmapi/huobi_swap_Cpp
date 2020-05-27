#include <iostream>
#include "HuobiSwap/Client.h"


using namespace HuobiSwap;
using namespace std;

int main(int argc, char** argv) {
    SubscriptionClient* client = createSubscriptionClient();
    client->subscribeCandlestickEvent("BTC-USD", CandlestickInterval::min15, [](CandlestickEvent candlestickEvent) {

        cout << "Timestamp: " << candlestickEvent.data.timestamp << endl;
        cout << "High: " << candlestickEvent.data.high << endl;
        cout << "Low: " << candlestickEvent.data.low << endl;
        cout << "Open: " << candlestickEvent.data.open << endl;
        cout << "Close: " << candlestickEvent.data.close << endl;
        cout << "Volume: " << candlestickEvent.data.volume << endl;
    });

    client->startService();

}
