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


int main()
{
       
    std::shared_ptr<iLogger> s_log;
    
    LogHandler logHandler;
    s_log = logHandler.init();
    s_log->trace("My first message");
    std::cout << "Press enter to exit" << std::endl;
    getchar();
}

