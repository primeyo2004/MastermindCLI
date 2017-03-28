//
//  MastermindIO.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 26/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef MastermindIO_hpp
#define MastermindIO_hpp

#include <ostream>
#include "MastermindCore.hpp"

    
namespace Mastermind{
namespace IO{
    
    using namespace Mastermind::Core;
    
    
    
    inline   std::ostream& operator << (std::ostream& os, const KeyPeg_Colors& kp_c)
    {
    
        static const std::map<KeyPeg_Colors,std::string> s_kpcolors2str = {
            std::make_pair(KeyPeg_Colors::NONE,     "__"),
            std::make_pair(KeyPeg_Colors::WHITE,    "WT"),
            std::make_pair(KeyPeg_Colors::BLACK,    "BK"),
        };
        
        auto itr = s_kpcolors2str.find(kp_c);
        if (itr != s_kpcolors2str.end()){
            os << itr->second;
        }
        
        return os;
    }
    
    inline   std::ostream& operator << (std::ostream& os, const Mastermind::Core::CodePeg_Colors& cp_c)
    {
        
        static const std::map<CodePeg_Colors,std::string> s_cpcolors2str = {
            std::make_pair(CodePeg_Colors::INVALID,   "<INVALID>"),
            std::make_pair(CodePeg_Colors::NONE,   "__"),
            std::make_pair(CodePeg_Colors::RED,    "RD"),
            std::make_pair(CodePeg_Colors::GREEN,  "GN"),
            std::make_pair(CodePeg_Colors::BLUE,   "BL"),
            std::make_pair(CodePeg_Colors::YELLOW, "YE"),
            std::make_pair(CodePeg_Colors::BROWN,  "BR"),
            std::make_pair(CodePeg_Colors::ORANGE, "OR"),
            std::make_pair(CodePeg_Colors::BLACK,  "BK"),
            std::make_pair(CodePeg_Colors::WHITE,  "WT"),
        };
       
        auto itr = s_cpcolors2str.find(cp_c);
        if (itr != s_cpcolors2str.end()){
            os << itr->second;
        }
       
        
        return os;
    }

    inline std::istream& operator >>(std::istream &is,Mastermind::Core::CodePeg_Colors& cp_c)
    {
       
        
        static const std::map<std::string, CodePeg_Colors> s_str2cpcolors = {
            std::make_pair("__", CodePeg_Colors::NONE),
            std::make_pair("RD", CodePeg_Colors::RED),
            std::make_pair("GN", CodePeg_Colors::GREEN),
            std::make_pair("BL", CodePeg_Colors::BLUE),
            std::make_pair("YE", CodePeg_Colors::YELLOW),
            std::make_pair("BR", CodePeg_Colors::BROWN),
            std::make_pair("OR", CodePeg_Colors::ORANGE),
            std::make_pair("BK", CodePeg_Colors::BLACK),
            std::make_pair("WT", CodePeg_Colors::WHITE),
        };
        
        std::string inputStr;
        char _input_char;
        
        while (is >> _input_char){
            
            if (::isalnum(_input_char)){
                inputStr.append(1,_input_char);
            }
            else{
                is.putback(_input_char);
                break;
            }
        }
        
        std::cout << inputStr << std::endl;
        
        auto itr = s_str2cpcolors.find(inputStr);
        if (itr != s_str2cpcolors.end()){
            cp_c = itr->second;
        }
        else{
            cp_c = CodePeg_Colors::INVALID;
        }

        
        return is;
    }
    
    
    class CodePegEntryIO{
    public:
        CodePegEntryIO(){
            
        }
        
        std::vector<CodePeg>  Read(){
            return std::vector<CodePeg>();
        }
        
        void Display(std::vector<CodePeg> input,std::vector<KeyPeg> feedback){
            
        }
    };

}
}
        
#endif /* MastermindIO_hpp */
