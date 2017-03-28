//
//  MastermindFactory.cpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#include "MastermindFactory.hpp"

namespace Mastermind {
namespace Factory{

static FactoryPtr l_facPtr;
    
void Factory::RegisterInstance(FactoryPtr facPtr){
    l_facPtr = facPtr;
}
    
Factory& Factory::getIntance(){
    
    if (!l_facPtr.get()){
        throw std::logic_error("Factory is null");
    }
    
    return (*l_facPtr.get());
}

}
}
