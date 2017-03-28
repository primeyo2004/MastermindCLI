//
//  MastermindLogic.cpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 28/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#include "MastermindLogic.hpp"

namespace Mastermind {
namespace Logic{
    

CodePegColorGroup::CodePegColorGroup()
  : m_groupColor(CodePeg_Colors::INVALID){
      
}

CodePegColorGroup::CodePegColorGroup(CodePeg_Colors groupColor)
   : m_groupColor(groupColor){
}

void CodePegColorGroup::Add(CodePeg codePeg){
    
    if (m_groupColor != codePeg.getColor()){
        throw std::invalid_argument("Invalid color");
    }
    
    m_groupMembers.push_back(codePeg);
}

size_t CodePegColorGroup::Count() const {
    return m_groupMembers.size();
}

void CodePegColorGroup::Evaluate(CodePeg codePeg){
    
    auto matchRet = MatchTypes::MATCHED_NONE;
    
    if (m_groupColor == codePeg.getColor()){
        
        std::vector<CodePeg>::iterator itr;
        itr = std::find_if(m_groupMembers.begin(),m_groupMembers.end(),[&](const CodePeg makerCodePeg){
            
            if (makerCodePeg.getPlacement() == codePeg.getPlacement()){
                return true;
            }
            
            return false;
        });
        
        if (itr != m_groupMembers.end()){
            matchRet = MatchTypes::MATCHED_ALL;
        }
        else{
            matchRet = MatchTypes::MATCHED_COLOR_ONLY;
        }
        
        // scores per match type
        m_matchType2GuessMatchCount[matchRet]++;
        
        
    }
    
}

void  CodePegColorGroup::ResetGuessMatchCounts() {
    m_matchType2GuessMatchCount.clear();
}

std::vector<KeyPeg>  CodePegColorGroup::GetResults() const{
    
    std::vector<KeyPeg>  aResults;
    
    // get the total match count first
    int totalMatchGuessCount = 0;
    
    for(const auto& item : m_matchType2GuessMatchCount){
        totalMatchGuessCount += item.second;
    }
    
    
    int excessMatchCount = static_cast<int>(totalMatchGuessCount - m_groupMembers.size());
    
    
    // if matchcount < m_groupMembers.size(), generate blank KeyPeg for all
    if ( 0  <= excessMatchCount){
        
        // MatchTypes::MATCHED_ALL      - generate colored KeyPeg if totalMatchGuessCount >= m_groupMembers.size()
        auto itrMatchAll = m_matchType2GuessMatchCount.find(MatchTypes::MATCHED_ALL);
        
        for (auto i = 0;
             itrMatchAll != m_matchType2GuessMatchCount.end() &&
             i < itrMatchAll->second;
             i++){
            
            aResults.push_back(KeyPeg{KeyPeg_Colors::BLACK});
            totalMatchGuessCount--;
        }
        
        // MatchTypes::MATCHED_COLOR_ONLY   - generate colored KeyPeg if totalMatchGuessCount >= m_groupMembers.size()
        auto itrMatchColor = m_matchType2GuessMatchCount.find(MatchTypes::MATCHED_COLOR_ONLY);
        for (auto i = 0;
             itrMatchColor != m_matchType2GuessMatchCount.end() &&
             totalMatchGuessCount > excessMatchCount &&
             i < m_matchType2GuessMatchCount.at(MatchTypes::MATCHED_COLOR_ONLY)
             ;i++){
            
            aResults.push_back(KeyPeg{KeyPeg_Colors::WHITE});
            totalMatchGuessCount--;
        }
        
    }
    
    // otherwise - generate blank KeyPeg
    while (totalMatchGuessCount > 0){
        aResults.push_back(KeyPeg{KeyPeg_Colors::NONE});
        totalMatchGuessCount--;
    }
    
    return aResults;
}

void CodePegColorGroup::Dump() const{
#ifdef _DEBUG
    std::cout << "======= Start CodePegColorGroup::Dump() =========" << std::endl;
    std::cout << "m_groupColor = " << (int)m_groupColor << std::endl;
    std::cout << "m_groupMembers = {" << std::endl;
    for(auto& i : m_groupMembers){
        std::cout << " {" << (int) i.getColor() << ", " <<  (int) i.getPlacement() << "}" << std::endl;
    }
    std::cout << "}" << std::endl;
    
    std::cout << "m_matchType2GuessMatchCount = {" << std::endl;
    for(auto& i : m_matchType2GuessMatchCount){
        std::cout << " {" << (int) i.first << "," <<  (int) i.second << "}" << std::endl;
    }
    std::cout << "}" << std::endl;
    std::cout << "======= End CodePegColorGroup::Dump() =========" << std::endl;
#endif
}
    
    
FeedbackLogic::FeedbackLogic(){
}
    
void FeedbackLogic::BuildPattern(std::vector<CodePeg> secretCode){
    
    m_codePegColor2Group.clear();
    
    for(auto& item : secretCode){
        
        auto itr = m_codePegColor2Group.find(item.getColor());
        
        if (itr == m_codePegColor2Group.end()){
            
            m_codePegColor2Group.insert(std::make_pair(item.getColor(),CodePegColorGroup(item.getColor())));
            
        }
        
        m_codePegColor2Group[item.getColor()].Add(item);
        
    }
}
    
void  FeedbackLogic::TestPattern(std::vector<CodePeg> guessCode){
    
    m_ungroupedKeyPegs.clear();
    
    for (auto&& item : m_codePegColor2Group){
        item.second.ResetGuessMatchCounts();
    }
    
    for(auto& item : guessCode){
        
        auto itr = m_codePegColor2Group.find(item.getColor());
        
        
        if (itr != m_codePegColor2Group.end()){
            itr->second.Evaluate(item);
        }
        else{
            m_ungroupedKeyPegs.push_back(KeyPeg{KeyPeg_Colors::NONE});
        }
    }
}
    
    
std::vector<KeyPeg> FeedbackLogic::GetResults() const{
    
    std::vector<KeyPeg> aResults;
    // generate feedback for each group
    for (const auto& item : m_codePegColor2Group){
        std::vector<KeyPeg> _aResults = item.second.GetResults();
        aResults.insert(aResults.end(), _aResults.begin(),_aResults.end());
    }
    
    for (const auto& item: m_ungroupedKeyPegs){
        aResults.push_back(item);
    }
    
    std::sort(aResults.begin(),aResults.end(),[](const KeyPeg& k1,const KeyPeg& k2){
        return k1.getColor() > k2.getColor();
    });
    
    return aResults;
}
    
void FeedbackLogic::Dump() const{
#ifdef _DEBUG
    // generate feedback for each group
    for (const auto& item : m_codePegColor2Group){
        item.second.Dump();
    }
#endif
}


}
}
