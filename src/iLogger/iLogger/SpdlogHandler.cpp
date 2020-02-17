//
//  SpdlogHandler.cpp
//  iLogger
//
//  Created by Martin on 16.02.20.
//  Copyright © 2020 Martin. All rights reserved.
//

#include "SpdlogHandler.hpp"


SpdlogHandler::SpdlogHandler(const std::string &logName, const std::string &logFileName, const std::string &logFilePath, const std::string &logLevelConsole, const std::string &logLevelFile, const std::string &patternConsole, const std::string &patternFile)
:
iLogger(logName),
m_sLogLevelConsole(logLevelConsole),
m_sLogLevelFile(logLevelFile),
m_sPatternConsole(patternConsole),
m_sPatternFile(patternFile),
m_sFileName(logFileName),
m_sFilePath(logFilePath)
{
}

SpdlogHandler::~SpdlogHandler()
{
    spdlog::shutdown();
}


iLogger::LogEntry SpdlogHandler::createLogger() {
        try
    {
        auto consoleSink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
        auto consoleLogger = std::make_shared<spdlog::logger>(m_sLoggerName, consoleSink);
        
        consoleSink->set_level(stringToLogLevel(m_sLogLevelConsole));
        consoleSink->set_pattern(m_sPatternConsole);
        
        consoleLogger->set_level(stringToLogLevel(m_sLogLevelConsole));
        spdlog::register_logger(consoleLogger);
        spdlog::set_default_logger(consoleLogger);
    }
    catch(const spdlog::spdlog_ex& error)
    {
        return { "error", std::string("Log initialization failed") + error.what() };
    }
    return { "debug", "Log initialization was successful" };
}

//iLogger::LogEntry SpdlogHandler::setPattern(std::string pattern) {
//    try
//    {
//        spdlog::set_pattern(pattern);
//    }
//    catch(const spdlog::spdlog_ex& error)
//    {
//        return { "error", std::string("Setting pattern failed") + error.what() };
//    }
//    return { "debug", "Setting pattern was successful" };
//}
//
//
//iLogger::LogEntry SpdlogHandler::setLogLevel(std::string level) {
//     try
//    {
//        spdlog::set_level(stringToLogLevel(level));
//    }
//    catch(const spdlog::spdlog_ex& error)
//    {
//        return { "error", std::string("Setting pattern failed") + error.what() };
//    }
//    return { "debug", "Setting pattern was successful" };;
//}

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

void SpdlogHandler::trace(const std::string &msg) {
    spdlog::trace(msg);
}

void SpdlogHandler::debug(const std::string &msg) {
    spdlog::debug(msg);
}

void SpdlogHandler::info(const std::string &msg) {
    spdlog::debug(msg);
}

void SpdlogHandler::warning(const std::string &msg) {
    spdlog::warn(msg);
}

void SpdlogHandler::error(const std::string &msg) {
    spdlog::error(msg);
}

void SpdlogHandler::critical(const std::string &msg) {
    spdlog::critical(msg);
}
