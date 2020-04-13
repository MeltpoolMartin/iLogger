//
//  iLogger-h.h
//  iLogger
//
//  Created by Martin on 15.02.20.
//  Copyright © 2020 Martin. All rights reserved.
//

#ifndef iLogger_h_h
#define iLogger_h_h

#include <list>
#include <string>

class iLogger {
protected:
    std::string                         m_sLoggerName;
    struct                              LogEntry
    {
    std::string logLevel;
    std::string logMsg;
    };

    std::list<LogEntry>                 m_logBuffer;
    
public:
                                        iLogger();
                                        iLogger(const std::string& loggerName) {m_sLoggerName = loggerName;};
    
    virtual void                        createLogger() = 0;
    virtual void                        createLoggers() = 0;
    
    virtual void                        flushLogBuffer() = 0;
    
    virtual void                        trace(const std::string& msg) = 0;
    virtual void                        debug(const std::string& msg) = 0;
    virtual void                        info(const std::string& msg) = 0;
    virtual void                        warning(const std::string& msg) = 0;
    virtual void                        error(const std::string& msg) = 0;
    virtual void                        critical(const std::string& msg) = 0;
    
    
};

#endif /* iLogger_h_h */
