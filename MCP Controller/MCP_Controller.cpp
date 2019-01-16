//
//  MCP_Controller.cpp
//  MCP Controller
//
//  Created by Michael Beaumont on 2019-01-15.
//  Copyright © 2019 mbeaumont. All rights reserved.
//

#include <iostream>
#include "MCP_Controller.hpp"
#include "MCP_ControllerPriv.hpp"

void MCP_Controller::HelloWorld(const char * s)
{
    MCP_ControllerPriv *theObj = new MCP_ControllerPriv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void MCP_ControllerPriv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

