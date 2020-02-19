//
//  main.cpp
//  iLogger
//
//  Created by Martin on 15.02.20.
//  Copyright © 2020 Martin. All rights reserved.
//
#include <iostream>
#include <memory>
#include "LogHandler.hpp"
#include <chrono>

int main()
{
       
    std::shared_ptr<iLogger> s_log;
    
    LogHandler logHandler;
    s_log = logHandler.init();
    for(int i=0; i < 1000; i++)
    {
        s_log->trace("Log message number " + std::to_string(i));
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
