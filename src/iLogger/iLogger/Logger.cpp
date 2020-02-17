//
//  Logger.cpp
//  iLogger
//
//  Created by Martin on 16.02.20.
//  Copyright © 2020 Martin. All rights reserved.
//

#include "Logger.hpp"

Logger::Logger(const std::string& loggerName, const std::string& logLevel, const std::string& pattern )
:
iLogger(loggerName),
m_sLogLevel(logLevel),
m_sPattern(pattern)
{
}

Logger::~Logger() {
    spdlog::shutdown();
}


iLogger::LogEntry Logger::createConsoleLogger()
{
    try
    {
        auto consoleSink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
        auto consoleLogger = std::make_shared<spdlog::logger>(m_sLoggerName, consoleSink);
        
        consoleLogger->set_level(spdlog::level::info); //TODO: replace with member variable of string
        spdlog::register_logger(consoleLogger);
        spdlog::set_default_logger(consoleLogger);
    }
    catch(const spdlog::spdlog_ex& error)
    {
        return { "error", std::string("Log initialization failed") + error.what() };
    }
    setPattern();
    setLogLevel();
    return { "debug", "Log initialization was successful" };
}

iLogger::LogEntry Logger::setPattern() {
    try
    {
        spdlog::set_pattern(m_sPattern);
    }
    catch(const spdlog::spdlog_ex& error)
    {
        return { "error", std::string("Setting pattern failed") + error.what() };
    }
    return { "debug", "Setting pattern was successful" };
}


iLogger::LogEntry Logger::setLogLevel() {
     try
    {
        spdlog::set_level(stringToLogLevel(m_sLogLevel));
    }
    catch(const spdlog::spdlog_ex& error)
    {
        return { "error", std::string("Setting pattern failed") + error.what() };
    }
    return { "debug", "Setting pattern was successful" };;
}

spdlog::level::level_enum Logger::stringToLogLevel(const std::string& logLevel) {
    //std::for_each(logLevel.begin(), logLevel.end(), [](char& c){c = ::tolower(c);});
    if(logLevel == "trace")
    {
        return spdlog::level::trace;
    }
    if(logLevel == "debug")
     {
         return spdlog::level::debug;
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

void Logger::trace(const std::string &msg) {
    spdlog::trace(msg);
}

void Logger::debug(const std::string &msg) {
    spdlog::debug(msg);
}

void Logger::warning(const std::string &msg) {
    spdlog::warn(msg);
}

void Logger::error(const std::string &msg) {
    spdlog::error(msg);
}

void Logger::critical(const std::string &msg) {
    spdlog::critical(msg);
}

void Logger::createLogger() {
    createConsoleLogger();
}



