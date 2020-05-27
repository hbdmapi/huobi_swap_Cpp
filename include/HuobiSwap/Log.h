/*******************************************************************************
* File name： Log.h
* Description: Log header file.
* Author: QiaoXiaofeng(andyjoe318@gmail.com)
* Version: 0.0.1
* Date： 2020-05-26
* History: 
*
*******************************************************************************/

#ifndef LOG_H
#define LOG_H

#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include "Enums.h"

namespace HuobiSwap {


    class Log {
       
    public:
        static int log;
        static std::string log_file_locate;
        static FILE* log_fp;
    public:
        static void WriteLog(const char *msg,...);
        static void setlogMode(int mode);
        static void setLogfilelocate(std::string &pDebug_log_file);

    };

}


#endif /* Log_H */

