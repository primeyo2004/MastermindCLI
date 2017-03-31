//
//  MastermindCore.hpp
//  Mastermind
//
//  Created by Jeune Prime Origines on 26/3/17.
//  Copyright © 2017 Jeune Prime Origines. All rights reserved.
//

#ifndef MastermindCore_hpp
#define MastermindCore_hpp

#include <string>
#include <memory>

namespace Mastermind{
namespace Core{

// used by code maker to feedback/score the codebreaker's input
enum class KeyPeg_Colors{
    NONE,               // indicates color and position didn't match
    WHITE,               // indicates only the color has matched
    BLACK               // indicates both color and position matched
};

enum class CodePeg_Colors{
    INVALID = -1,
    RED,                // Arbitrary colors
    GREEN,
    BLUE,
    YELLOW,
    BROWN,
    ORANGE,
    BLACK,
    WHITE
};
    


// placement indicator for both the codemaker's secret entry and codebreaker guess entry
enum class CodePegEntry_Placement{
    COLUMN_1,
    COLUMN_2,
    COLUMN_3,
    COLUMN_4,
    COLUMN_5,
    COLUMN_6,
    COLUMN_7,
    COLUMN_8
};


class CodePeg {
public:
    
    CodePeg(CodePeg_Colors a_color,CodePegEntry_Placement a_placement) :
    m_color(a_color),
    m_placement(a_placement){}
    
    CodePeg_Colors getColor() const{
        return m_color;
    }
    
    CodePegEntry_Placement getPlacement() const{
        return m_placement;
    }
    
    
private:
    CodePeg_Colors         m_color;
    CodePegEntry_Placement m_placement;
};

class KeyPeg  {
public:
    KeyPeg(KeyPeg_Colors a_color) : m_color(a_color) {}
    KeyPeg_Colors getColor() const{
        return m_color;
    }
    
    
private:
    KeyPeg_Colors m_color;
};
    
    
class CoreConverter{
public:
    
    template <typename T>
    static std::string to_str(T param);
    
    template <typename T>
    static std::string to_long_str(T param);
    
    template <typename T>
    static T from_str(std::string str);
    
    template <typename T>
    static short to_index(T param);
    
    template <typename T>
    static T from_index(short index);
};
    
    
}

}
    






#endif /* MastermindCore_hpp */
