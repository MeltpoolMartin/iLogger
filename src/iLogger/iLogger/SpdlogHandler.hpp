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

class SpdlogHandler : public iLogger
{
protected:
    std::string                         m_sPatternConsole;
    std::string                         m_sPatternFile;
    std::string                         m_sLogLevelConsole;
    std::string                         m_sLogLevelFile;
    std::string                         m_sFileName;
    std::string                         m_sFilePath;
    std::shared_ptr<iLogger>            m_pLog;
    
public:
    
                                        SpdlogHandler(const std::string &logName, const std::string &logFileName, const std::string &logFilePath, const std::string &logLevelConsole, const std::string &logLevelFile, const std::string &patternConsole, const std::string &patternFile);
                                        ~SpdlogHandler();
    
    iLogger::LogEntry                   createLogger() override;      
    
//    iLogger::LogEntry                   setLogLevel(std::string level));
//    iLogger::LogEntry                   setPattern(std::string pattern);
    
    std::shared_ptr<spdlog::logger>     getLogger(const std::string& loggerName);
    spdlog::level::level_enum           stringToLogLevel(const std::string& logLevel);
    
    void                                trace(const std::string& msg) override;
    void                                debug(const std::string& msg) override;
    void                                info(const std::string& msg) override;
    void                                warning(const std::string& msg) override;
    void                                error(const std::string& msg) override;
    void                                critical(const std::string& msg) override;
};

#endif /* Logger_hpp */

