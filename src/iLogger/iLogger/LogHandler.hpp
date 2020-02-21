//
//  LogHandler.hpp
//  iLogger
//
//  Created by Martin on 17.02.20.
//  Copyright © 2020 Martin. All rights reserved.
//

#ifndef LogHandler_hpp
#define LogHandler_hpp

#include "SpdlogHandler.hpp"

#endif /* LogHandler_hpp */

class LogHandler
{
    
public:
                                            LogHandler();
    std::shared_ptr<iLogger>                init();
    void                                    createAllLogger();
    
};
