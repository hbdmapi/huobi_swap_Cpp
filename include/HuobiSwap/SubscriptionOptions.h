/*******************************************************************************
* File name： SubscriptionOptions.h
* Description: HuobiSwap api SubscriptionOptions header files.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/
#ifndef SUBSCRIPTIONOPTIONS_H
#define SUBSCRIPTIONOPTIONS_H

#include <string>

namespace HuobiSwap {

    struct SubscriptionOptions {
        /**
         * flag of reconnect
         */
        bool isAutoReconnect = true;
        /**
         * receiving timeout limit,in milliseconds
         */
        int receiveLimitMs = 60000;

        /**
         * connection failed delay time, in seconds
         */
       int connectionDelayOnFailure = 15;
       /*
        *support set url by user
        */
       std::string url;

    };

}

#endif /* SUBSCRIPTIONOPTIONS_H */

