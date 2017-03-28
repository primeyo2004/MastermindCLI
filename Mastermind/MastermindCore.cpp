//
//  MastermindCore.cpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 28/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#include "MastermindCore.hpp"
#include <map>


namespace Mastermind{
namespace Core{

        
template<>
std::string CoreConverter::to_str<KeyPeg_Colors>(KeyPeg_Colors kp_c){
    
    std::string strRet;
    
    static const std::map<KeyPeg_Colors,std::string> s_kpcolors2str = {
        std::make_pair(KeyPeg_Colors::NONE,     "__"),
        std::make_pair(KeyPeg_Colors::WHITE,    "WT"),
        std::make_pair(KeyPeg_Colors::BLACK,    "BK"),
    };
    
    auto itr = s_kpcolors2str.find(kp_c);
    if (itr != s_kpcolors2str.end()){
        strRet = itr->second;
    }
    
    return strRet;

}

template<>
std::string CoreConverter::to_str<CodePeg_Colors>(CodePeg_Colors cp_c){
    std::string strRet;
    
    static const std::map<CodePeg_Colors,std::string> s_cpcolors2str = {
        std::make_pair(CodePeg_Colors::INVALID,   "<INVALID>"),
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
        strRet = itr->second;
    }
    
    return strRet;

}
    
    template<>
    std::string CoreConverter::to_long_str<KeyPeg_Colors>(KeyPeg_Colors kp_c){
        
        std::string strRet;
        
        static const std::map<KeyPeg_Colors,std::string> s_kpcolors2str = {
            std::make_pair(KeyPeg_Colors::NONE,     "NONE  - Indicates both the color and the placement didn't match"),
            std::make_pair(KeyPeg_Colors::WHITE,    "White - Indicates only the color matched"),
            std::make_pair(KeyPeg_Colors::BLACK,    "Black - Indicates both the color and the placement matched"),
        };
        
        auto itr = s_kpcolors2str.find(kp_c);
        if (itr != s_kpcolors2str.end()){
            strRet = itr->second;
        }
        
        return strRet;
        
    }


template<>
std::string CoreConverter::to_long_str<CodePeg_Colors>(CodePeg_Colors cp_c){
        std::string strRet;
        
        static const std::map<CodePeg_Colors,std::string> s_cpcolors2str = {
            std::make_pair(CodePeg_Colors::INVALID,"<INVALID>"),
            std::make_pair(CodePeg_Colors::RED,    "RED"),
            std::make_pair(CodePeg_Colors::GREEN,  "GREEN"),
            std::make_pair(CodePeg_Colors::BLUE,   "BLUE"),
            std::make_pair(CodePeg_Colors::YELLOW, "YELLOW"),
            std::make_pair(CodePeg_Colors::BROWN,  "BROWN"),
            std::make_pair(CodePeg_Colors::ORANGE, "ORANGE"),
            std::make_pair(CodePeg_Colors::BLACK,  "BLACK"),
            std::make_pair(CodePeg_Colors::WHITE,  "WHITE"),
        };
        
        auto itr = s_cpcolors2str.find(cp_c);
        if (itr != s_cpcolors2str.end()){
            strRet = itr->second;
        }
        
        return strRet;
        
    }

    

template<>
CodePeg_Colors CoreConverter::from_str<CodePeg_Colors>(std::string str){
    
    CodePeg_Colors cp_c_ret;
    
    static const std::map<std::string, CodePeg_Colors> s_str2cpcolors = {
        std::make_pair("RD", CodePeg_Colors::RED),
        std::make_pair("GN", CodePeg_Colors::GREEN),
        std::make_pair("BL", CodePeg_Colors::BLUE),
        std::make_pair("YE", CodePeg_Colors::YELLOW),
        std::make_pair("BR", CodePeg_Colors::BROWN),
        std::make_pair("OR", CodePeg_Colors::ORANGE),
        std::make_pair("BK", CodePeg_Colors::BLACK),
        std::make_pair("WT", CodePeg_Colors::WHITE),
    };
    
    auto itr = s_str2cpcolors.find(str);
    if (itr != s_str2cpcolors.end()){
        cp_c_ret = itr->second;
    }
    else{
        cp_c_ret = CodePeg_Colors::INVALID;
    }

    return cp_c_ret;
 
}

template<>
CodePegEntry_Placement CoreConverter::from_index<CodePegEntry_Placement>(short index){
    
    CodePegEntry_Placement cpep;
    static const std::map<short,CodePegEntry_Placement> s_int2placement = {
        std::make_pair(0, CodePegEntry_Placement::COLUMN_1),
        std::make_pair(1, CodePegEntry_Placement::COLUMN_2),
        std::make_pair(2, CodePegEntry_Placement::COLUMN_3),
        std::make_pair(3, CodePegEntry_Placement::COLUMN_4),
        std::make_pair(4, CodePegEntry_Placement::COLUMN_5),
        std::make_pair(5, CodePegEntry_Placement::COLUMN_6),
        std::make_pair(6, CodePegEntry_Placement::COLUMN_7),
        std::make_pair(7, CodePegEntry_Placement::COLUMN_8)
    };
    
    auto itr = s_int2placement.find(index);
    if (itr != s_int2placement.end()){
        cpep = itr->second;
    }
    else{
        cpep = CodePegEntry_Placement::COLUMN_8;
    }
    
    return cpep;

}

template<>
short CoreConverter::to_index<CodePegEntry_Placement>(CodePegEntry_Placement cpp){
    
    short nRet = 0;
    
    static const std::map<CodePegEntry_Placement, short> s_placement2int = {
        std::make_pair(CodePegEntry_Placement::COLUMN_1, 0),
        std::make_pair(CodePegEntry_Placement::COLUMN_2, 1),
        std::make_pair(CodePegEntry_Placement::COLUMN_3, 2),
        std::make_pair(CodePegEntry_Placement::COLUMN_4, 3),
        std::make_pair(CodePegEntry_Placement::COLUMN_5, 4),
        std::make_pair(CodePegEntry_Placement::COLUMN_6, 5),
        std::make_pair(CodePegEntry_Placement::COLUMN_7, 6),
        std::make_pair(CodePegEntry_Placement::COLUMN_8, 7)
    };
    
    auto itr = s_placement2int.find(cpp);
    if (itr != s_placement2int.end()){
        nRet = itr->second;
    }
    else{
        nRet = 0;
    }

    return nRet;
}

template<>
CodePeg_Colors  CoreConverter::from_index<CodePeg_Colors>(short index){
    CodePeg_Colors cp_c_ret;
    
    static const std::map<short, CodePeg_Colors> s_short2cpcolors = {
        std::make_pair(0, CodePeg_Colors::RED),
        std::make_pair(1, CodePeg_Colors::GREEN),
        std::make_pair(2, CodePeg_Colors::BLUE),
        std::make_pair(3, CodePeg_Colors::YELLOW),
        std::make_pair(4, CodePeg_Colors::BROWN),
        std::make_pair(5, CodePeg_Colors::ORANGE),
        std::make_pair(6, CodePeg_Colors::BLACK),
        std::make_pair(7, CodePeg_Colors::WHITE),
    };
    
    auto itr = s_short2cpcolors.find(index);
    if (itr != s_short2cpcolors.end()){
        cp_c_ret = itr->second;
    }
    else{
        cp_c_ret = CodePeg_Colors::INVALID;
    }
    
    return cp_c_ret;
}
    
template<>
short  CoreConverter::to_index<CodePeg_Colors>(CodePeg_Colors cp_c){
        short nRet = 0;
    
        static const std::map<CodePeg_Colors,short> s_short2cpcolors = {
            std::make_pair(CodePeg_Colors::RED,    0),
            std::make_pair(CodePeg_Colors::GREEN,  1),
            std::make_pair(CodePeg_Colors::BLUE,   2),
            std::make_pair(CodePeg_Colors::YELLOW, 3),
            std::make_pair(CodePeg_Colors::BROWN,  4),
            std::make_pair(CodePeg_Colors::ORANGE, 5),
            std::make_pair(CodePeg_Colors::BLACK,  6),
            std::make_pair(CodePeg_Colors::WHITE,  7),
        };
        
        auto itr = s_short2cpcolors.find(cp_c);
        if (itr != s_short2cpcolors.end()){
            nRet = itr->second;
        }
        else{
            nRet = -1;
        }
        
    return nRet;
}


}
}
