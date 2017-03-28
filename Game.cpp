//
//  Game.cpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 26/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#include "Game.hpp"
#include "MastermindFactory.hpp"
#include <sstream>

using namespace Mastermind::Factory;
using namespace Mastermind::UI;
using namespace Mastermind::Params;
using namespace Mastermind::Val;
using namespace Mastermind::Gen;

Game::Game(){
}

Game::~Game(){
}

bool Game::Init(){
    
    SimpleUIPtr uiPtr = Factory::getIntance().getUserInterface();
    
    uiPtr->DisplayLine("Generating secret code...");
    
    CodePegGeneratorPtr genPtr = Factory::getIntance().createSecreteCodeGenerator();
    
    // generate the code
    m_secretCode   = genPtr->Generate();
    m_feedbackLogicPtr  = Factory::getIntance().createFeedbackLogic();
    
    m_feedbackLogicPtr->BuildPattern(m_secretCode);
    
    
    uiPtr->DisplayLine("Done.");
    
    return true;
}

bool Game::Run(){
    
    GameParamsPtr gameParamsPtr = Factory::getIntance().getParams();
    SimpleUIPtr   uiPtr = Factory::getIntance().getUserInterface();
    
    for (auto i = 0; i < gameParamsPtr->MaxAttempts(); ++i){
        
        std::ostringstream stroutstrm;
        stroutstrm << "Attempt No. ( " << i+1 << " ) - Please enter  two-letter color code [??] or  blank to abort:";
        
        uiPtr->DisplayLine(stroutstrm.str());
        
        // create a validator for this attempt
        CodePegValidatorPtr  cpValPtr = Factory::getIntance().createCodePegValidator();
        
        std::vector<CodePeg> guessCode;
        CodePeg_Colors       cp_c;
        
        for (auto j = 0; j < gameParamsPtr->ColumnCount(); ++j){
            
            stroutstrm.str("");
            stroutstrm << "  Entry for Column No. ( " << j+1 << " ): ";
            
            
            
            std::string strInput = uiPtr->GetInput(stroutstrm.str(),"Opps!! Input is invalid ", [&](const std::string& str) {
                
                // empty is allowed
                if (str.size() == 0){
                    return true;
                }
                else{
                    cp_c = CoreConverter::from_str<CodePeg_Colors>(str);
                    return cpValPtr->IsValid(cp_c);
                }
                
                return true;
            });
            
            if (strInput.size() == 0){
                // game aborted by user
                return false;
            }
            
            guessCode.push_back(CodePeg{cp_c,CoreConverter::from_index<CodePegEntry_Placement>(j)});
            
        }
        
        uiPtr->DisplayLine("");
        
        m_feedbackLogicPtr->TestPattern(guessCode);
        
        m_lastFeedbackResult = m_feedbackLogicPtr->GetResults();
        
        stroutstrm.str("");
        stroutstrm << "Feedback ->  [";
        
        for (const auto& item : m_lastFeedbackResult){
            stroutstrm << CoreConverter::to_str(item.getColor()) << " ";
        }
        
        stroutstrm << "]";
        
        uiPtr->DisplayLine(stroutstrm.str());
        
        uiPtr->DisplayLine("");
        
        // check if game over
        if (Factory::getIntance().getResultValidator()->IsCompleted(m_lastFeedbackResult)){
            // break the loop
            break;
        }
        
    }
    
    
    
    return true;
}

void Game::Deinit(){
    
    SimpleUIPtr   uiPtr = Factory::getIntance().getUserInterface();
    GameParamsPtr gameParamsPtr = Factory::getIntance().getParams();
    
    if (Factory::getIntance().getResultValidator()->IsCompleted(m_lastFeedbackResult)){
        // break the loop
        uiPtr->DisplayLine(" *** Congratulation!!! you have broken the secret code *** ");
    }
    else{
        
        std::ostringstream stroutstrm;
        stroutstrm << "Secret code is: ";
        for (const auto& item : m_secretCode){
            stroutstrm << "( " << CoreConverter::to_index(item.getPlacement()) + 1 << " ): " << CoreConverter::to_str(item.getColor()) <<  " ";
        }
        
        uiPtr->DisplayLine(stroutstrm.str());

    }
}
