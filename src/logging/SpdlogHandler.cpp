//
//  SpdlogHandler.cpp
//  iLogger
//
//  Created by Martin on 16.02.20.
//  Copyright © 2020 Martin. All rights reserved.
//

#include "SpdlogHandler.hpp"
#include <chrono>

SpdlogHandler::SpdlogHandler(const std::string &logName, const std::string &logFileName, const std::string &logFileBasePath, const std::string &logLevelConsole, const std::string &logLevelFile, const std::string &patternConsole, const std::string &patternFile, unsigned int maxLogFiles, unsigned long maxFileSize)
:
iLogger(logName),
m_sLoggerNameList(),
m_sLogLevelConsole(logLevelConsole),
m_sLogLevelFile(logLevelFile),
m_sPatternConsole(patternConsole),
m_sPatternFile(patternFile),
m_sFileName(logFileName),
m_sFileBasePath(logFileBasePath),
m_iMaxLogFiles(maxLogFiles),
m_iMaxFileSize(maxFileSize)
{
    m_sFilePath = m_sFileBasePath + "/" + m_sFileName;
    m_logBuffer.clear(); //clearing buffer
}

SpdlogHandler::~SpdlogHandler()
{
    spdlog::shutdown();
}


void SpdlogHandler::createLogger() {
    try
    {
        m_pSinkList.push_back(createConsoleSink());
        //m_pSinkList.push_back(createRotatingFileSink());
        m_pSinkList.push_back((createDailyFileSink()));
        auto multiLogger = std::make_shared<spdlog::logger>(m_sLoggerName, m_pSinkList.begin(), m_pSinkList.end());
        
        multiLogger->set_level(stringToLogLevel(m_sLogLevelConsole));
        spdlog::register_logger(multiLogger);
        spdlog::set_default_logger(multiLogger);
        //spdlog::flush_every(std::chrono::seconds(1));
        //Flush policy depending on log level to print relevant messages immediately
    }
    catch(const spdlog::spdlog_ex& error)
    {
        m_logBuffer.push_back({ "error", std::string(__FUNCTION__) + std::string(" >> Initialization of " + m_sLoggerName + " failed; Error: ") + error.what() });
        return;
    }
    m_logBuffer.push_back({ "debug", std::string(__FUNCTION__) + " >> Initialization of " + m_sLoggerName + " was successful" });
}

void SpdlogHandler::createLoggers()
{
    try
    {
        m_pSinkList.push_back(createConsoleSink());
        m_pSinkList.push_back((createDailyFileSink()));
        for(auto& loggerName : m_sLoggerNameList)
        {
            auto multiLogger = std::make_shared<spdlog::logger>(loggerName, m_pSinkList.begin(), m_pSinkList.end());
            multiLogger->set_level(stringToLogLevel(m_sLogLevelConsole));
            spdlog::register_logger(multiLogger);
            spdlog::set_default_logger(multiLogger);
            m_logBuffer.push_back({ "debug", std::string(__FUNCTION__) + " >> Initialization of " + loggerName + " was successful" });
        }

        //spdlog::flush_every(std::chrono::seconds(1));
        //Flush policy depending on log level to print relevant messages immediately
    }
    catch(const spdlog::spdlog_ex& error)
    {
        m_logBuffer.push_back({ "error", std::string(__FUNCTION__) + std::string(" >> Initialization of " + m_sLoggerName + " failed; Error: ") + error.what() });
        return;
    }
}

spdlog::sink_ptr SpdlogHandler::createConsoleSink() {
    auto consoleSink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
    consoleSink->set_level(stringToLogLevel(m_sLogLevelConsole));
    consoleSink->set_pattern(m_sPatternConsole);
    return consoleSink;
}

spdlog::sink_ptr SpdlogHandler::createRotatingFileSink() {
    auto RotatingSink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(m_sFilePath, m_iMaxFileSize, m_iMaxLogFiles, false);
    RotatingSink->set_level(stringToLogLevel(m_sLogLevelFile));
    RotatingSink->set_pattern(m_sPatternFile);
    return RotatingSink;
}

spdlog::sink_ptr SpdlogHandler::createDailyFileSink() {
    auto dailyFileSink = std::make_shared<spdlog::sinks::daily_file_sink_mt>(m_sFilePath, 0, 0, false, m_iMaxLogFiles);
    dailyFileSink->set_level(stringToLogLevel(m_sLogLevelFile));
    dailyFileSink->set_pattern(m_sPatternFile);
    return dailyFileSink;
}

spdlog::level::level_enum SpdlogHandler::stringToLogLevel(const std::string& logLevel) {
    //std::for_each(logLevel.begin(), logLevel.end(), [](char& c){c = ::tolower(c);});
    if(logLevel == "trace")
    {
        return spdlog::level::trace;
    }
    if(logLevel == "debug")
     {
         return spdlog::level::debug;
     }
    if(logLevel == "info")
    {
        return spdlog::level::info;
    }
    if(logLevel == "warn")
     {
         return spdlog::level::warn;
     }
    if(logLevel == "error")
     {
         return spdlog::level::err;
     }
    if(logLevel == "critical")
     {
         return spdlog::level::critical;
     }
    else
        return spdlog::level::trace; //if nothing was found return all
}

std::shared_ptr<spdlog::logger> SpdlogHandler::getLogger(const std::string& loggerName)
{
    return spdlog::get(loggerName);
}

void SpdlogHandler::trace(const std::string &msg) {
    spdlog::trace(msg);
}

void SpdlogHandler::trace(const std::string &loggerName, const std::string &msg) {
    getLogger(loggerName)->trace(msg);
}

void SpdlogHandler::debug(const std::string &msg) {
    spdlog::debug(msg);
}

void SpdlogHandler::debug(const std::string &loggerName, const std::string &msg) {
    getLogger(loggerName)->debug(msg);
}

void SpdlogHandler::info(const std::string &msg) {
    spdlog::debug(msg);
}

void SpdlogHandler::info(const std::string &loggerName, const std::string &msg) {
    getLogger(loggerName)->info(msg);
}

void SpdlogHandler::warning(const std::string &msg) {
    spdlog::warn(msg);
}

void SpdlogHandler::warning(const std::string &loggerName, const std::string &msg) {
    getLogger(loggerName)->warn(msg);
}

void SpdlogHandler::error(const std::string &msg) {
    spdlog::error(msg);
}

void SpdlogHandler::error(const std::string &loggerName, const std::string &msg) {
    getLogger(loggerName)->error(msg);
}

void SpdlogHandler::critical(const std::string &msg) {
    spdlog::critical(msg);
}

void SpdlogHandler::critical(const std::string &loggerName, const std::string &msg) {
    getLogger(loggerName)->critical(msg);
}

void SpdlogHandler::flushLogBuffer() {
//    for(auto& logMsg : m_logBuffer)
//    {
//
//    }
}
