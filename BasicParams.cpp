//
//  CmdLineUI.cpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//
// can easily be overriden for a configuration based setting

#include <iostream>
#include "BasicParams.hpp"

using namespace Mastermind::Params;

size_t BasicParams::MaxAttempts()  const{
    return 10;
}

bool   BasicParams::AllowDuplicates() const{
    return true;
}

size_t BasicParams::ColumnCount()  const{
    return 4;
}

size_t BasicParams::ColorCount()  const{
    return 6;
}
