//
//  MastermindFactory.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef MastermindFactory_hpp
#define MastermindFactory_hpp

#include "MastermindUI.hpp"
#include "MastermindParams.hpp"
#include "MastermindVal.hpp"
#include "MastermindLogic.hpp"
#include "MastermindGen.hpp"
#include <memory>

namespace Mastermind {
namespace Factory{
    
class Factory;
    
typedef  std::shared_ptr<Factory> FactoryPtr;
    
    
class Factory{
public:
    ~Factory() {}
    
    static void     RegisterInstance(FactoryPtr facPtr);
    static Factory& getIntance();
    
    virtual UI::SimpleUIPtr                   getUserInterface()       = 0;
    virtual Params::GameParamsPtr             getParams()              = 0;
    virtual Val::FeedbackResultValidatorPtr   getResultValidator()     = 0;
    
    virtual Val::CodePegValidatorPtr          createCodePegValidator() = 0;
    virtual Logic::FeedbackLogicPtr           createFeedbackLogic()    = 0;
    virtual Gen::CodePegGeneratorPtr          createSecreteCodeGenerator() = 0;
    
    
    
};
        
}
}

#endif /* MastermindFactory_hpp */
