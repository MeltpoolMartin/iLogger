//
//  LogHandler.cpp
//  iLogger
//
//  Created by Martin on 17.02.20.
//  Copyright © 2020 Martin. All rights reserved.
//

#include "LogHandler.hpp"

LogHandler::LogHandler()
{
}

std::shared_ptr<iLogger> LogHandler::init() {
    std::string LoggerName = "iLogger";
    std::string PatternConsole = "[%H:%M:%S,%e] [%n] [thread %t] [%l] %v";
    std::string PatternFile = "[%H:%M:%S,%e] [%n] [thread %t] [%l] %v";
    std::string LogLevelConsole = "trace";
    std::string LogLevelFile = "trace";
    std::string FileName = "iLogger.txt";
    std::string FileBasePath = "/Users/Martin/dev/iLogger/TestLogs";
    unsigned int MaxLogFiles = 10;
    unsigned long MaxFileSize = 1024*1024; // 1 MiB

    std::shared_ptr<iLogger> m_pLog(new SpdlogHandler(LoggerName, FileName, FileBasePath, LogLevelConsole, LogLevelFile, PatternConsole, PatternFile, MaxLogFiles, MaxFileSize));
    m_pLog->createLogger(); //TODO: What happens if init fails
    return m_pLog;
}

void LogHandler::createAllLogger() { 
    //TODO: to be implemented
}


