/*******************************************************************************
* File name： Error.h
* Description: HuobiSwap api client header files.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/

#ifndef ERROR_H
#define ERROR_H

#include <string>

namespace HuobiSwap {

    class Error {
    public:
        std::string errorCode;
        std::string errorMsg;
    public:
        static std::string RUNTIME_ERROR;
        static std::string INPUT_ERROR;
        static std::string KEY_MISSING;
        static std::string SYS_ERROR;
        static std::string SUBSCRIPTION_ERROR;
        static std::string ENV_ERROR;
        static std::string EXEC_ERROR;

        Error(std::string code, std::string msg) {
            errorCode = code;
            errorMsg = msg;
        }

        Error() {

        }
    };
}


#endif /* ERROR_H */

