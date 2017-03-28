//
//  BasicFactory.cpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#include "BasicFactory.hpp"
#include "CmdLineUI.hpp"
#include "BasicParams.hpp"
#include "BasicValidation.hpp"
#include "CodePegRandomGen.hpp"
#include <memory>

using namespace Mastermind::Factory;
using namespace Mastermind::UI;
using namespace Mastermind::Params;
using namespace Mastermind::Val;
using namespace Mastermind::Logic;
using namespace Mastermind::Gen;

BasicFactory::BasicFactory(){
    
}

BasicFactory::~BasicFactory(){
    
}


SimpleUIPtr BasicFactory::getUserInterface(){
    
    if (!m_uiInstPtr.get()){
        
        m_uiInstPtr = std::make_shared<CmdLineUI>();
    }
    
    return m_uiInstPtr;
}

GameParamsPtr BasicFactory::getParams(){
    
    if (!m_gameInstPtr.get()){
        m_gameInstPtr = std::make_shared<BasicParams>();
    }
    
    return m_gameInstPtr;
}

FeedbackResultValidatorPtr BasicFactory::getResultValidator(){
    
    if (!m_resultValidatorPtr.get()){
        m_resultValidatorPtr = std::make_shared<FeedbackResultValidator>();
    }
    
    return m_resultValidatorPtr;
}

CodePegValidatorPtr  BasicFactory::createCodePegValidator(){
    GameParamsPtr paramsPtr = getParams();
    
    CodePegValidatorPtr valPtr = std::make_shared<BasicCodePegValidator>(BasicCodePegValidator(paramsPtr->ColorCount()));
    
    // if duplicate is not allowed then
    // decorate it with duplicate validator
    if (!paramsPtr->AllowDuplicates()){
        valPtr = std::make_shared<DuplicateCodePegValidator>(DuplicateCodePegValidator(valPtr));
    }
    
    return valPtr;
}

FeedbackLogicPtr   BasicFactory::createFeedbackLogic(){
    // return the ptr initialized with random
    return FeedbackLogicPtr(std::make_shared<FeedbackLogic>());
}

CodePegGeneratorPtr  BasicFactory::createSecreteCodeGenerator(){
    
    return CodePegGeneratorPtr(
        std::make_shared<CodePegRandomGen>(
        getParams()->ColorCount(),
        getParams()->ColumnCount(),
        createCodePegValidator()));
}

