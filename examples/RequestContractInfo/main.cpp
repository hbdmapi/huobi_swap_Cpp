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