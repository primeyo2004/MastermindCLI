//
//  CmdLineUI.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef CmdLineUI_hpp
#define CmdLineUI_hpp

#include "MastermindUI.hpp"

    
class CmdLineUI : public Mastermind::UI::SimpleUI{
    
public:
    CmdLineUI(){}
    virtual ~CmdLineUI(){}
    virtual void DisplayLine(std::string display) override;
    virtual std::string GetInput(std::string strPrompt, Mastermind::UI::ValidateInputFunc_t fn) override;
    virtual std::string GetInput(std::string strPrompt,std::string strErrorPrompt,Mastermind::UI::ValidateInputFunc_t fn) override;

};
    


#endif /* CmdLineUI_hpp */
