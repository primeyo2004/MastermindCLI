//
//  BasicValidation.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 28/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef BasicValidation_hpp
#define BasicValidation_hpp

#include "MastermindVal.hpp"
#include <set>


class BasicCodePegValidator : public Mastermind::Val::CodePegValidator {
    
public:
    BasicCodePegValidator(size_t maxColors) : m_maxColors (maxColors){}
    virtual ~BasicCodePegValidator(){}
    virtual bool IsValid(Mastermind::Core::CodePeg_Colors cp_c) override;
private:
    const size_t m_maxColors;
};

// decorator pattern, not inheritance
class DuplicateCodePegValidator : public Mastermind::Val::CodePegValidator {
    
public:
    DuplicateCodePegValidator(Mastermind::Val::CodePegValidatorPtr oldValPtr): m_oldValPtr(oldValPtr){}
    virtual ~DuplicateCodePegValidator(){}
    virtual bool IsValid(Mastermind::Core::CodePeg_Colors cp_c) override;
private:
    Mastermind::Val::CodePegValidatorPtr m_oldValPtr;
    std::set<Mastermind::Core::CodePeg_Colors>  m_uniqColors;
};

#endif /* BasicValidation_hpp */
