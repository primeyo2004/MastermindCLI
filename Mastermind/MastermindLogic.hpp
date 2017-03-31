//
//  MastermindLogic.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 28/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef MastermindLogic_hpp
#define MastermindLogic_hpp

#include "MastermindCore.hpp"
#include <map>
#include <vector>
#include <algorithm>

namespace Mastermind{
namespace Logic{
        
using namespace Mastermind::Core;
    
enum class MatchTypes{
    MATCHED_ALL,          // both the color and position has matched
    MATCHED_COLOR_ONLY,   // only the color has matched
    MATCHED_NONE          // none matched
};


class CodePegColorGroup {
    
public:
    
    CodePegColorGroup();
    CodePegColorGroup(CodePeg_Colors groupColor);
    
    void    Add(CodePeg codePeg);
    size_t  Count() const;
    void    Evaluate(CodePeg codePeg);
    void    ResetGuessMatchCounts();
    std::vector<KeyPeg>  GetResults() const;
    void    Dump() const;
    
private:
    CodePeg_Colors                        m_groupColor;
    std::vector<CodePeg>                  m_groupMembers;
    std::map<MatchTypes,size_t>           m_matchType2GuessMatchCount;
};
    
    
class FeedbackLogic {
public:
    FeedbackLogic();
    void  BuildPattern(std::vector<CodePeg> secreteCode);
    void  TestPattern(std::vector<CodePeg> guessCode);
    std::vector<KeyPeg> GetResults() const;
    void Dump() const;
private:
    std::map<CodePeg_Colors, CodePegColorGroup>   m_codePegColor2Group;
    std::vector<KeyPeg>                           m_ungroupedKeyPegs;
};

typedef std::shared_ptr<FeedbackLogic> FeedbackLogicPtr;
    
}
}


#endif /* MastermindLogic_hpp */
