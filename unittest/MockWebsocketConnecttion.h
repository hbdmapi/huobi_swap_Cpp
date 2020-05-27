#ifndef MOCKWEBSOCKETCONNECTTION_H
#define MOCKWEBSOCKETCONNECTTION_H
#include <gtest/gtest.h>
#include <../src/WebSocketApiImpl.h>
#include "../include/HuobiSwap/Error.h"
#include "../include/HuobiSwap/Decimal.h"
#include "../src/Utils/JsonDocument.h"
#include "../src/WebSocketConnection.h"
#include "../src/WebSocketRequest.h"

#include <list>
namespace HuobiSwap{
class MockWebsocketConnecttion: public WebSocketConnection
{
    public:
       
        MockWebsocketConnecttion(WebSocketRequest* request) : WebSocketConnection("", "", nullptr, nullptr,"") {
            
        }
        std::string pop() {
            std::string front=*(sendBufferList.begin());
            sendBufferList.pop_front();
            return front;
        }
        
      
};
}

#endif /* MOCKWEBSOCKETCONNECTTION_H */

