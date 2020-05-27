# Huobi Swap C++ DEMO

A lightweight c++ library, you can import to your C++ project and use this project.

The DEMO now only contains the implementation of these interfaces: query contract info(swap-api/v1/swap_contract_info),query account info(swap-api/v1/swap_account_info), websocket subscription of the candlestick data(market.$contract_code.kline.$period), websocket subscription of the order event(orders.$contract_code).

This Demo has implemented the auto-reconnection mechanism of the websocket.

## Quick Start

### Start Docker

```shell
cd huobi_swap_Cpp

docker build -t huobiswapdev -f ./docker/ubuntu/Dockerfile .

docker run -itd --name huobiswapdev --network host -v $PWD:/home/huobiswap/work huobiswapdev

docker exec -it huobiswapdev /bin/bash
```
### Build Library

```shell

rm -rf build
mkdir build
cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_COMPILER_TYPE=CLANG
make
sudo make install
cd ..
```

### Run example

```shell
cd examples
cd RequestContractInfo
rm -rf build
mkdir build
cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCMAKE_COMPILER_TYPE=CLANG
make
./RequestContractInfo

```

### Happy Coding!


## Docs

### Install

If you don't want to use docker,you can refer to docs<a href="docs/install.md"> here </a> for different platforms such as ubuntu, centos, mac,etc.

### How to use this library

In your c++ project, you can follow below steps:

* include HuobiSwap/Client.h (All classes are under namespace HuobiSwap)
* Create the client instance.
* Call the interfaces provided by client.
* If you want to release the memory of client, delete it directly.

#### Restful example:

Querying the account info:

```c++
#include "HuobiSwap/Client.h"
#include <iostream>

using namespace HuobiSwap;
using namespace std;
int main(int argc, char** argv) {

    try {
            RequestClient* request = createRequestClient("api_key", "secret_key");
            std::vector<Account> accounts = request->getAccountInfo("BTC-USD");
            std::cout << accounts[0].symbol << std::endl;
            std::cout << accounts[0].contract_code << std::endl;
            std::cout << accounts[0].risk_rate << std::endl;
            std::cout << accounts[0].margin_balance << std::endl;
            std::cout << accounts[0].margin_postion << std::endl;
            std::cout << accounts[0].margin_frozen << std::endl;
            std::cout << accounts[0].margin_available << std::endl;
            std::cout << accounts[0].profit_real << std::endl;
            std::cout << accounts[0].risk_rate << std::endl;
            std::cout << accounts[0].liquidation_price << std::endl;
            std::cout << accounts[0].withdraw_available << std::endl;
            std::cout << accounts[0].lever_rate << std::endl;
            std::cout << accounts[0].adjust_factor << std::endl;
            std::cout << accounts[0].margin_static << std::endl;
    } catch (Error e) {
            std::cout << e.errorCode << std::endl;
    	    std::cout << e.errorMsg << std::endl;
    }
}

```

Querying the contract info:

```c++

#include "HuobiSwap/Client.h"
#include <iostream>

using namespace HuobiSwap;
using namespace std;
int main(int argc, char** argv) {

    RequestClient* request = createRequestClient();
    std::vector<ContractInfo> contractInfos = request->getContractInfo();
    std::cout << contractInfos[0].symbol << std::endl;
    std::cout << contractInfos[0].contract_code << std::endl;
    std::cout << contractInfos[0].contract_size << std::endl;
    std::cout << contractInfos[0].price_tick << std::endl;
    std::cout << contractInfos[0].settlement_date << std::endl;
    std::cout << contractInfos[0].create_date << std::endl;
    std::cout << contractInfos[0].contract_status << std::endl;
}

```

#### Websocket subscription of candlestick data

```c++
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

```

#### websocket subscription of order event

```c++
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
```

Please NOTE:

All timestamp which is got from SDK is the Unix timestamp based on UTC.

### Clients

There are 2 clients, one is for request method, ```RequestClient``` , another is for subscription method ```SubscriptionClient```. 

* **RequestClient**: It is a synchronous request, it will invoke the Hbdm API via synchronous method, all invoking will be blocked until receiving the response from server.

* **SubscriptionClient**: It is the subscription, it is used for subscribing any market data update and account change.  It is asynchronous, so you must implement  ```callback()``` function. The server will push any update for the client. if client receive the update, the ```callback()``` function will be called. 

  

### Create client

You can assign the API key and Secret key when you create the client. See below:

```c++
RequestClient* request = createRequestClient(
  "xxxxxxxx-xxxxxxxx-xxxxxxxx-xxxxx",
  "xxxxxxxx-xxxxxxxx-xxxxxxxx-xxxxx");
```

```c++
SubscriptionClient* subscription = createSubscriptionClient(
  "xxxxxxxx-xxxxxxxx-xxxxxxxx-xxxxx",
  "xxxxxxxx-xxxxxxxx-xxxxxxxx-xxxxx");
```

The API key and Secret key are used for authentication.

Some APIs related with account, trading etc require the authentication. We can name them after private interface.

The APIs only return the market data  don't need the authentication. We can name them after public interface.

If you want to invoke both public interface and private interface. You must apply API Key and Secret Key from Huobi Swap and put them into the client you created.

If the authentication cannot pass, the invoking of private interface will fail.

If you want to invoke public interface only. You can create the client as follow:

```c++
RequestClient* request = createRequestClient();
```

```c++
SubscriptionClient* subscription = createSubscriptionClient();
```



### Custom host

1. Set your custom host to ```RequestClient``` or ```SubscriptionClient```.
2. Set the url or uri string to client when creating the client instance.

See below example

```c++
//Set custom host for request
RequestOptions reqOp;
reqOp.url = "https://www.xxx.yyy/";
RequestClient* request = createRequestClient(
  "xxxxxxxx-xxxxxxxx-xxxxxxxx-xxxxx",
  "xxxxxxxx-xxxxxxxx-xxxxxxxx-xxxxx",
  reqOp);

// Set custom host for subscription
SubscriptionOptions subOp;
subOp.url = "wss://www.xxx.yyy";
SubscriptionClient* subscription = createSubscriptionClient(
  "xxxxxxxx-xxxxxxxx-xxxxxxxx-xxxxx",
  "xxxxxxxx-xxxxxxxx-xxxxxxxx-xxxxx",
  subOp);
```

If you do not set yout custom host, below default host will be used:

For request: <https://api.hbdm.vn>

For subscription: <wss://api.hbdm.vn>


### Error handling

#### For request

In error case, such as you set the invalid api key. The ```Error``` will be thrown. See below example:

```c++
#include "HuobiSwap/Client.h"
#include <iostream>

using namespace HuobiSwap;
using namespace std;
int main(int argc, char** argv) {

    try {
            RequestClient* request = createRequestClient("api_key", "secret_key");
            std::vector<Account> accounts = request->getAccountInfo("BTC-USD");
            std::cout << accounts[0].symbol << std::endl;
     catch (Error e) {
            std::cout << e.errorCode << std::endl;
    	    std::cout << e.errorMsg << std::endl;
    }
}

```

#### For Subscription

If you want to check the error, you should implement your ```errorHandler```. See below example:

```c++
SubscriptionClient*client = createSubscriptionClient();
client->subscribeCandlestickEvent(
  "BTC-USD",
  CandlestickInterval::min15,
  [](CandlestickEvent candlestickEvent){
    std::cout <<"Timestamp: "<< candlestickEvent.data.timestamp << std::endl;
    std::cout <<"High: "<< candlestickEvent.data.high << std::endl;},
  [](Error exception){
    std::cout << exception.errorCode << std::endl;
    std::cout << exception.errorMsg << std::endl;
  });
client->startService();
```

Any error made during subscription will be output to a log file, If you do not define your ```errorHandler```, the error will be output to log only.

#### Log

The library is using the common logging module, you can set the log mode ``` setlogMode() ```,0 is no log,1 is print in console, 2 is print in the specified file, you can set the file ``` setLogfilelocate()```, bigger than 2 is same as 0. The default is 2.Using ``` WriteLog()``` if you want record log somewhere. You can follow below steps before create the client:

```c++
 Log::setlogMode(2);
 Log::setLogfilelocate("your log locate");
```

### Reference

Huobi Spot

