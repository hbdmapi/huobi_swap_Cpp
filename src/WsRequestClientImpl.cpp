#include "WsRequestClientImpl.h"
namespace HuobiSwap {

    void WsRequestClientImpl::requestCandlestickEvent(
            const char* symbols,
            CandlestickInterval interval,
            const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
            const std::function<void(Error&)>& errorHandler) {
        requestCandlestickEvent(true, symbols, interval, 0, 0, callback, errorHandler);
    }

    void WsRequestClientImpl::requestCandlestickEvent(
            bool autoClose,
            const char* symbols,
            CandlestickInterval interval,
            const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
            const std::function<void(Error&)>& errorHandler) {
        requestCandlestickEvent(autoClose, symbols, interval, 0, 0, callback, errorHandler);
    }

    void WsRequestClientImpl::requestCandlestickEvent(
            const char* symbols,
            CandlestickInterval interval,
            long startTime,
            long endTime,
            const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
            const std::function<void(Error&)>& errorHandler) {
        requestCandlestickEvent(true, symbols, interval, startTime, endTime, callback, errorHandler);
    }

    void WsRequestClientImpl::requestCandlestickEvent(
            bool autoClose,
            const char* symbols,
            CandlestickInterval interval,
            long startTime,
            long endTime,
            const std::function<void(const std::vector<CandlestickEvent>&) >& callback,
            const std::function<void(Error&)>& errorHandler) {
        WebSocketRequest* req = impl->requestCandlestickEvent(autoClose, symbols, interval, startTime, endTime, callback, errorHandler);       
        
    }

}