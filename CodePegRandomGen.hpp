//
//  CodePegRandomGen.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef CodePegRandomGen_hpp
#define CodePegRandomGen_hpp

#include "MastermindGen.hpp"
#include "MastermindVal.hpp"
#include "MastermindCore.hpp"

    
class CodePegRandomGen : public Mastermind::Gen::CodePegGenerator {
    
public:
    CodePegRandomGen(short colorCount,short columnCount,Mastermind::Val::CodePegValidatorPtr valPtr):
    m_colorCount(colorCount),m_columnCount(columnCount),m_cpValPtr(valPtr){}
    virtual ~CodePegRandomGen(){}
    virtual std::vector<Mastermind::Core::CodePeg> Generate() override;
private:
    const short  m_colorCount;
    const short  m_columnCount;
    Mastermind::Val::CodePegValidatorPtr m_cpValPtr;


};
    


#endif /* CodePegRandomGen_hpp */
