#include"renamd/nodestyles.h"
#include"renamd/rich.h"

namespace node = rena::styles::node;

void node::normal::render( std::ostream& __os ) const {
    __os << this -> d;
    if ( this -> ews )
    {
        __os << " ";
    }
    return;
}

void node::bold::render( std::ostream& __os ) const {
    __os << rich::FStyle::BOLD;
    if ( this -> n != nullptr )
    {
        this -> n -> render( __os );
    }
    else
    {
        __os << this -> d;
        if ( this -> ews )
        {
            __os << " ";
        } // space should only be added in the lowest level
    }
    __os << rich::style_reset;
    return;
}

void node::italic::render( std::ostream& __os ) const {
    __os << rich::FStyle::ITALIC;
    if ( this -> n != nullptr )
    {
        this -> n -> render( __os );
    }
    else
    {
        __os << this -> d;
        if ( this -> ews )
        {
            __os << " ";
        } // space should only be added in the lowest level
    }
    __os << rich::style_reset;
    return;
}

void node::code::render( std::ostream& __os ) const {
    __os << rich::BColor::GRAY << rich::FColor::YELLOW << this -> d << rich::style_reset;
    // code node should be on the lowest level
    if ( this -> ews )
    {
        __os << " ";
    }
    return;
}
