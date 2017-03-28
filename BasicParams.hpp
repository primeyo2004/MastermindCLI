//
//  BasicParams.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef BasicParams_hpp
#define BasicParams_hpp

#include "MastermindParams.hpp"

    
class BasicParams : public Mastermind::Params::GameParams{
    
public:
    BasicParams(){}
    virtual ~BasicParams(){}
    
    virtual size_t MaxAttempts()    const  override;
    virtual bool   AllowDuplicates() const  override;
    virtual size_t ColumnCount()     const  override;
    virtual size_t ColorCount()      const  override;
};



#endif /* BasicParams_hpp */
