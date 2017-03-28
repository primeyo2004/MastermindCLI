//
//  MastermindParams.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef MastermindParams_hpp
#define MastermindParams_hpp

#include <memory>


namespace Mastermind{
namespace Params{
    
    class GameParams{
        
    public:
        virtual ~GameParams(){};
        
        virtual size_t MaxAttempts()    const  = 0;
        virtual bool   AllowDuplicates() const  = 0;
        virtual size_t ColumnCount()     const  = 0;
        virtual size_t ColorCount()      const  = 0;
        
    };
    
    
typedef std::shared_ptr<GameParams>  GameParamsPtr;
    
}
    
}


#endif /* MastermindParams_hpp */
