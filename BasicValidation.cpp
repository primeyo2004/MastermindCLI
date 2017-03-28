//
//  BasicValidation.cpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 28/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#include "BasicValidation.hpp"
#include "MastermindFactory.hpp"


using namespace Mastermind::Core;



bool BasicCodePegValidator::IsValid(Mastermind::Core::CodePeg_Colors cp_c){
    
    short index = CoreConverter::to_index(cp_c);
    
    return (index < this->m_maxColors && index != -1);
}


bool DuplicateCodePegValidator::IsValid(Mastermind::Core::CodePeg_Colors cp_c){
    
    bool bRet = true;
    
    if (m_oldValPtr.get()){
        bRet = m_oldValPtr->IsValid(cp_c);
    }
    
    if (bRet){
        auto itr = m_uniqColors.find(cp_c);
        bRet = (itr == m_uniqColors.end());
    }
    
    if (bRet){
        m_uniqColors.insert(cp_c);
    }
    
    return bRet;
    
}

