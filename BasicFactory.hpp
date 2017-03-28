//
//  BasicFactory.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 27/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef BasicFactory_hpp
#define BasicFactory_hpp

#include "MastermindFactory.hpp"


class BasicFactory : public Mastermind::Factory::Factory{
public:
     BasicFactory();
    ~BasicFactory();
    
    
    virtual Mastermind::UI::SimpleUIPtr                 getUserInterface() override;
    virtual Mastermind::Params::GameParamsPtr           getParams()  override;
    virtual Mastermind::Val::FeedbackResultValidatorPtr getResultValidator()  override;
    
    virtual Mastermind::Val::CodePegValidatorPtr    createCodePegValidator()  override;
    virtual Mastermind::Logic::FeedbackLogicPtr     createFeedbackLogic()  override;
    virtual Mastermind::Gen::CodePegGeneratorPtr    createSecreteCodeGenerator() override;

    
private:
    Mastermind::UI::SimpleUIPtr                 m_uiInstPtr;
    Mastermind::Params::GameParamsPtr           m_gameInstPtr;
    Mastermind::Val::FeedbackResultValidatorPtr m_resultValidatorPtr;
    
};
        


#endif /* BasicFactory_hpp */
