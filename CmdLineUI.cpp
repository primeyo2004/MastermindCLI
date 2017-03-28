//
//  CmdLineUI.cpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#include <iostream>
#include "CmdLineUI.hpp"

using namespace Mastermind::UI;



void CmdLineUI::DisplayLine(std::string display){
    std::cout << display << std::endl;
}

std::string CmdLineUI::GetInput(std::string strPrompt, ValidateInputFunc_t _fn){
    
    std::string strLine;
    
    do{
        
        strLine.clear();
        
        std::cout << strPrompt;
        

        std::getline(std::cin, strLine);
        
    }while (!_fn(strLine));
    
    return strLine;
}

std::string CmdLineUI::GetInput(std::string strPrompt,std::string strErrorPrompt, Mastermind::UI::ValidateInputFunc_t _fn){
    
    std::string strLine;
    
    bool bAskInput = false;
    
    while (!bAskInput){
        
        strLine.clear();
        
        std::cout << strPrompt;
        
        std::getline(std::cin, strLine);
        
        bAskInput = _fn(strLine);
        
        if (!bAskInput){
            std::cerr << strErrorPrompt << "(" << strLine << ")" << std::endl;
        }
        
    }
    
    
    
    
    return strLine;

}
