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
    std::string PatternConsole = "*** [%H:%M:%S %z] [thread %t] %v ***";
    std::string PatternFile = "*** [%H:%M:%S %z] [thread %t] %v ***";
    std::string LogLevelConsole = "trace";
    std::string LogLevelFile = "trace";
    std::string FileName = "iLogger.txt";
    std::string FilePath = "/Benutzer/Martin/Dokumente";

    std::shared_ptr<iLogger> m_pLog(new SpdlogHandler(LoggerName, FileName, FilePath, LogLevelConsole, LogLevelFile, PatternConsole, PatternFile));
    m_pLog->createLogger(); //TODO: What happens if init fails
    return m_pLog;
}

