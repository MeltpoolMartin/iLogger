//
//  Logger.hpp
//  iLogger
//
//  Created by Martin on 16.02.20.
//  Copyright © 2020 Martin. All rights reserved.
//

#ifndef Logger_hpp
#define Logger_hpp

#pragma once
#include <algorithm>
#include <memory>

#include "iLogger.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

class Logger : public iLogger
{
private:
    std::string                         m_sPattern;
    std::string                         m_sLogLevel;
    
public:

                                        Logger(const std::string& loggerName, const std::string& logLevel, const std::string& pattern);
                                        ~Logger();
    
    void                                createLogger() override;
    iLogger::LogEntry                   createConsoleLogger();
    
    iLogger::LogEntry                   setLogLevel();
    iLogger::LogEntry                   setPattern();
    
    std::shared_ptr<spdlog::logger>     getLogger(const std::string& loggerName);
    spdlog::level::level_enum           stringToLogLevel(const std::string& logLevel);
    
    void                                trace(const std::string& msg) override;
    void                                debug(const std::string& msg) override;
    void                                warning(const std::string& msg) override;
    void                                error(const std::string& msg) override;
    void                                critical(const std::string& msg) override;
};

#endif /* Logger_hpp */

