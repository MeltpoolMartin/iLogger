//
//  main.cpp
//  iLogger
//
//  Created by Martin on 15.02.20.
//  Copyright © 2020 Martin. All rights reserved.
//
#include <iostream>
#include <memory>
#include "Logger.hpp"


int main()
{
    std::string loggerName = "Main";
    std::string logLevel = "trace";
    std::string pattern = "[%H:%M:%S %z] [thread %t] %v";
    std::shared_ptr<iLogger> pLog(new Logger(loggerName, logLevel, pattern));
//    pLog->createLogger();
    if(pLog == nullptr)
        return -1;
    pLog->createLogger();
    pLog->trace("First message");
    std::cout << "Press enter to exit" << std::endl;
    getchar();
}

