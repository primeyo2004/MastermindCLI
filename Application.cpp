
//
//  Application
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#include <string>
#include <sstream>
#include "MastermindFactory.hpp"
#include "MastermindCore.hpp"

#include "Application.hpp"
#include "Game.hpp"


using namespace Mastermind::Factory;
using namespace Mastermind::UI;
using namespace Mastermind::Params;
using namespace Mastermind::Core;



        
    
Application::Application(){
        
}
    
Application::~Application(){
        
}
            
void Application::Start(){
    
    std::ostringstream stroutstrm;
    SimpleUIPtr uiPtr          = Factory::getIntance().getUserInterface();
    GameParamsPtr gameParamPtr = Factory::getIntance().getParams();
    
    uiPtr->DisplayLine("*** Welcome to the original Mastermind game! ***");
    uiPtr->DisplayLine("");
   
    stroutstrm.str("");
    stroutstrm << "Param [Allow duplicates]: " << std::string(gameParamPtr->AllowDuplicates() ? "Yes":"No");
    uiPtr->DisplayLine(stroutstrm.str());
    
    stroutstrm.str("");
    stroutstrm << "Param [Max attempts    ]: " << gameParamPtr->MaxAttempts();
    uiPtr->DisplayLine(stroutstrm.str());
    
    stroutstrm.str("");
    stroutstrm << "Param [Column count    ]: " << gameParamPtr->ColumnCount();
    uiPtr->DisplayLine(stroutstrm.str());
    
    stroutstrm.str("");
    stroutstrm << "Param [Color count     ]: " << gameParamPtr->ColorCount();
    uiPtr->DisplayLine(stroutstrm.str());
    
    uiPtr->DisplayLine("");
    uiPtr->DisplayLine("Valid color input:");
    for(short colorIndex = 0; colorIndex < gameParamPtr->ColorCount(); colorIndex++){
        
        CodePeg_Colors cp = CoreConverter::from_index<CodePeg_Colors>(colorIndex);
        
        stroutstrm.str("");
        stroutstrm << "code: " << CoreConverter::to_str(cp) <<  "  -> color: " << CoreConverter::to_long_str(cp);
        uiPtr->DisplayLine(stroutstrm.str());
        
    }
    
    uiPtr->DisplayLine("");
    uiPtr->DisplayLine("Valid feedback codes:");
    
    stroutstrm.str("");
    stroutstrm << "feedback: " << CoreConverter::to_str(KeyPeg_Colors::BLACK)
    <<  "  -> description: " << CoreConverter::to_long_str(KeyPeg_Colors::BLACK);
    uiPtr->DisplayLine(stroutstrm.str());
    
    stroutstrm.str("");
    stroutstrm << "feedback: " << CoreConverter::to_str(KeyPeg_Colors::WHITE)
    <<  "  -> description: " << CoreConverter::to_long_str(KeyPeg_Colors::WHITE);
    uiPtr->DisplayLine(stroutstrm.str());
    
    stroutstrm.str("");
    stroutstrm << "feedback: " << CoreConverter::to_str(KeyPeg_Colors::NONE)
               <<  "  -> description: " << CoreConverter::to_long_str(KeyPeg_Colors::NONE);
    uiPtr->DisplayLine(stroutstrm.str());
    

    
    uiPtr->DisplayLine("");
    
    
}
    
bool Application::Play(){
    
    bool bRet = true;
    
    SimpleUIPtr uiPtr = Factory::getIntance().getUserInterface();
    
    // using a lambda to validate the input
    std::string strInput = uiPtr->GetInput("Start game? [Y/N] :", [](const std::string& str) {
        
        for(auto&& strValid : {"Y","N"}){
            if (0 == str.compare(strValid)){
                return true;
            }
        }
        
        return false;
    });
    
    
    // check if yes
    bRet = (0 == strInput.compare("Y"));
    
    
    if (bRet){
    
        Game _game;
        
        // if false, the  likely the game is aborted
        bRet = _game.Init();
        
        if (bRet)
        {
            bRet = _game.Run();
            
            _game.Deinit();
        }
        
    }
    
    if (!bRet){
        uiPtr->DisplayLine("Player requested to end the game.");
    }
    
    
  return bRet;
}

void Application::End(){
    
    SimpleUIPtr uiPtr = Factory::getIntance().getUserInterface();
    
    uiPtr->DisplayLine("--- Thank you for playing, bye! ---");
}
            



