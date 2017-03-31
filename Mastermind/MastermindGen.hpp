//
//  MastermindGen.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 28/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef MastermindGen_hpp
#define MastermindGen_hpp

#include "MastermindCore.hpp"
#include <vector>
#include <memory>

namespace Mastermind{
namespace Gen{
        
using namespace Mastermind::Core;

class CodePegGenerator{
public:
    virtual ~CodePegGenerator(){}
    virtual std::vector<CodePeg> Generate() = 0;
};

typedef std::shared_ptr<CodePegGenerator> CodePegGeneratorPtr;
    
}
}


#endif /* MastermindGen_hpp */
