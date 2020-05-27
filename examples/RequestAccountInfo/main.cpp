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
