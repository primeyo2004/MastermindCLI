//
//  Game.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 26/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include "MastermindLogic.hpp"

class Game{
public:
    Game();
    virtual ~Game();
    
    bool Init();
    
    bool Run();
    
    void Deinit();
    
private:
    Mastermind::Logic::FeedbackLogicPtr     m_feedbackLogicPtr;
    std::vector<Mastermind::Core::CodePeg>  m_secretCode;
    std::vector<Mastermind::Core::KeyPeg>   m_lastFeedbackResult;
    
    
};

    

#endif /* Game_hpp */
