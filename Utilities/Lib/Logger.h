/*******************************************************
 * Copyright (C) 2022 Bastien A. Auxer <auxerbastien@gmail.com>
 *
 * This file is part of utilities project.
 *
 * utilities project can not be copied and/or distributed without the express
 * permission of Bastien A. Auxer
 *******************************************************/

#define LOGGER_ENABLED 1 // Move to Cmake Flag

#if LOGGER_ENABLED

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>

#define log_v(pMsg)\
{\
       log.log(pMsg, Logger::LogLevel::Verbose);\
}

#define log_d(pMsg)\
{\
       log.log(pMsg, Logger::LogLevel::Debug);\
}

#define log_w(pMsg)\
{\
       log.log(pMsg, Logger::LogLevel::Warn);\
}

#define log_e(pMsg)\
{\
       log.log(pMsg, Logger::LogLevel::Error);\
}

namespace UTILS
{

    /// <summary>
    /// Simple class that will help 
    /// </summary>
    class Logger
    {

    public:

        enum class LogLevel
        {
            Verbose,
            Debug,
            Warn,
            Error
        };


        void log(std::string pMsg, LogLevel pLevel)
        {
            if (pLevel >= minThresh)
            {
                std::cout << pMsg << std::endl;
            }
        }

    private:
        LogLevel minThresh = LogLevel::Debug;

    };

    static Logger log;

}

#endif //LOGGER_H

#else // !LOGGER_ENABLED

/// These are blank so if the Logger is not in use, we can still compile.
/// Any logger stalemates just are compiled out

#define log_v(pMsg)
#define log_d(pMsg)
#define log_w(pMsg)
#define log_e(pMsg)

#endif // !LOGGER_ENABLED

