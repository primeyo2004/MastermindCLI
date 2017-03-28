//
//  MastermindUI.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef MastermindUI_hpp
#define MastermindUI_hpp

#include <string>
#include <memory>
#include <functional>

namespace Mastermind{
namespace UI{
    
    typedef std::function<bool(const std::string&)> ValidateInputFunc_t;
    
    class SimpleUI{
        
    public:
        virtual ~SimpleUI(){};
        virtual void DisplayLine(std::string display) = 0;
        virtual std::string GetInput(std::string strPrompt, ValidateInputFunc_t fn) = 0;
        virtual std::string GetInput(std::string strPrompt,std::string strErrorPrompt, ValidateInputFunc_t fn) = 0;
    };
    
    
typedef std::shared_ptr<SimpleUI>  SimpleUIPtr;
    
}
    
}


#endif /* MastermindUI_hpp */
