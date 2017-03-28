//
//  CodePegRandomGen.cpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

#include "CodePegRandomGen.hpp"

using namespace Mastermind::Gen;
using namespace Mastermind::Val;
using namespace Mastermind::Core;

std::vector<CodePeg> CodePegRandomGen::Generate(){
    
    std::vector<CodePeg> vResult;

    /* initialize random seed: */
    srand (static_cast<unsigned int>(::time(NULL)));
    
    short itemIndex = 0;
    while (itemIndex < m_columnCount){

        bool bValid = true;
        CodePeg_Colors  cp_c;

        do{
            short secretIndex   = rand() % m_colorCount;
            cp_c = CoreConverter::from_index<CodePeg_Colors>(secretIndex);

            if (m_cpValPtr.get()){
               bValid = m_cpValPtr->IsValid(cp_c);
            }

        }while(!bValid);

        vResult.push_back(CodePeg{cp_c,CoreConverter::from_index<CodePegEntry_Placement>(itemIndex)});

        itemIndex++;
    }
    
    return vResult;
}

