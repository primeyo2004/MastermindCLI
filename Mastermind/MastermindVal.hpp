//
//  MastermindVal.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 28/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef MastermindVal_hpp
#define MastermindVal_hpp

#include "MastermindCore.hpp"
#include <memory>
#include <vector>


namespace Mastermind{
namespace Val{
    
using namespace Mastermind::Core;
    

class CodePegValidator {
public:
    virtual ~CodePegValidator(){}
    
    virtual bool IsValid(CodePeg_Colors cp_c) = 0;

private:
};
    
class FeedbackResultValidator {
public:
    virtual ~FeedbackResultValidator(){}
    
    virtual bool IsCompleted(std::vector<KeyPeg> feedbackResult){
        for(const auto& item:feedbackResult){
            if (item.getColor() != KeyPeg_Colors::BLACK){
                return false;
            }
        }
        return true;
    }
    
private:
};

    
    
typedef std::shared_ptr<CodePegValidator>         CodePegValidatorPtr;
typedef std::shared_ptr<FeedbackResultValidator>  FeedbackResultValidatorPtr;
    
}
}

#endif /* MastermindVal_hpp */
