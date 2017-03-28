//
//  main.cpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 24/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#include <iostream>
#include "Application.hpp"
#include "MastermindFactory.hpp"
#include "BasicFactory.hpp"



int main(int argc, const char * argv[]) {
    
    // register basic factory
    // my plan is to override the factory with one that has more features
    Mastermind::Factory::Factory::RegisterInstance(std::make_shared<BasicFactory>());
    
    try{
       
        Application _app;
        
        _app.Start();
        
        while(_app.Play());
        
        _app.End();
        
    }catch(std::exception& e){
        
        std::cerr << "Exception: " << e.what() << std::endl;
        
    }
    
}

