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
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"

class SpdlogHandler : public iLogger
{
private:
    std::list<spdlog::sink_ptr>         m_pSinkList;
    std::string                         m_sFilePath;
    
protected:
    std::string                         m_sPatternConsole;
    std::string                         m_sPatternFile;
    std::string                         m_sLogLevelConsole;
    std::string                         m_sLogLevelFile;
    std::string                         m_sFileName;
    std::string                         m_sFileBasePath;
    std::list<std::string>              m_sLoggerNameList;
    unsigned int                        m_iMaxLogFiles;
    unsigned long                       m_iMaxFileSize; // in byte
    std::shared_ptr<iLogger>            m_pLog;
    
public:
    
                                        SpdlogHandler(const std::string &logName, const std::string &logFileName, const std::string &logFileBasePath, const std::string &logLevelConsole, const std::string &logLevelFile, const std::string &patternConsole, const std::string &patternFile, unsigned int maxLogFiles, unsigned long maxFileSize);
                                        ~SpdlogHandler();
    
    void                                createLogger() override;
    void                                createLoggers() override;
    spdlog::sink_ptr                    createConsoleSink();
    spdlog::sink_ptr                    createDailyFileSink();
    spdlog::sink_ptr                    createRotatingFileSink();
    
//    iLogger::LogEntry                   setLogLevel(std::string level));
//    iLogger::LogEntry                   setPattern(std::string pattern);
    
    std::shared_ptr<spdlog::logger>     getLogger(const std::string& loggerName);
    spdlog::level::level_enum           stringToLogLevel(const std::string& logLevel);
        
    void                                log(spdlog::level::level_enum logLevel, const std::string& loggerName, const std::string& msg);
    void                                trace(const std::string& msg) override;
    void                                trace(const std::string& loggerName, const std::string& msg);
    void                                debug(const std::string& msg) override;
    void                                debug(const std::string& loggerName, const std::string& msg);
    void                                info(const std::string& msg) override;
    void                                info(const std::string& loggerName, const std::string& msg);
    void                                warning(const std::string& msg) override;
    void                                warning(const std::string& loggerName, const std::string& msg);
    void                                error(const std::string& msg) override;
    void                                error(const std::string& loggerName, const std::string& msg);
    void                                critical(const std::string& msg) override;
    void                                critical(const std::string& loggerName, const std::string& msg);
    
    void                                flushLogBuffer() override;
};

#endif /* Logger_hpp */

