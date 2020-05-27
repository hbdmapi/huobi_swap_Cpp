#ifndef WEBSOCKETCONNETION_H
#define WEBSOCKETCONNETION_H

#include <memory>
#include <list>
#include <string>
#include <libwebsockets.h>
#include <mutex>

#include "HuobiSwap/Log.h"
#include "HuobiSwap/Enums.h"

#include "Utils/JsonWrapper.h"
#include "Utils/gzip.h"
#include "WebSocketRequest.h"
#include "WebSocketWatchDog.h"
#include "TimeService.h"

namespace HuobiSwap {

    typedef enum LINESTATUS {
        LINE_ACTIVE,
        LINE_IDEL,
        LINE_DELAY
    } LineStatus;

    typedef enum CONNECTIONSTATUS {
        CONNECTED,
        CLOSED,
    } ConnectionStatus;

    class WebSocketConnection {
    public:
        WebSocketConnection(const std::string& apiKey, const std::string& secretKey,
                WebSocketRequest* request, WebSocketWatchDog*dog, std::string host);

        void connect(lws_context* context);
        void disconnect();
        void reConnect();
        void reConnect(int delayInSecond);
        void close();
        void onOpen(lws* wsi);
        void onMessage( char* message,size_t len);
        void send(const std::string& message);
        bool flushSendBuffer(lws* ws);
        long getLastReceivedTime();

        ConnectionStatus getConnectState() {
            return connectStatus;
        }
        LineStatus getLineStatus() {
            return lineStatus;
        }

    private:
        std::string createSignature();
        void onReceive(JsonWrapper& json);
        void processPingOnTradingLine(JsonWrapper& json);
        void processPingOnMarketLine(JsonWrapper& json);
    private:
        std::string apiKey;
        std::string secretKey;
        std::mutex mutex;
        std::unique_ptr<WebSocketRequest> request;
        lws_context* context;
        lws* client;
        WebSocketWatchDog* dog;
        ConnectionStatus connectStatus = ConnectionStatus::CLOSED;
        LineStatus lineStatus = LineStatus::LINE_IDEL;
        long lastReceivedTime = 0;
        int delayInSecond = 0;
        std::string host;
        std::string subscriptionMarketUrl = "wss://api.hbdm.vn/swap-ws";
        std::string subscriptionTradingUrl = "wss://api.hbdm.vn/swap-notification";
        int connectionId;
        
        static int connectionCounter;
    protected:
        std::list<std::string> sendBufferList;
    };
}
#endif /* WEBSOCKETCONNETION_H */

