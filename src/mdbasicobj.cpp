#include"renamd/mdbasicobj.h"
#include"utf8cwidth.h"

namespace styles = rena::styles;

styles::basic_node::~basic_node(){
    if ( this -> n != nullptr )
    {
        delete this -> n;
    }
    return;
}

size_t styles::basic_node::output_width() const {
    return unicode::display_width( ews ? this -> d + " " : this -> d );
}

styles::style_flag styles::basic_node::style() const noexcept {
    if ( this -> n != nullptr )
    {
        return this -> s & this -> n -> style();
    }
    else
    {
        return this -> s;
    }
}

void styles::basic_node::bind( styles::basic_node* __next_level ){
    if ( n == nullptr )
    {
        this -> n = __next_level;
    }
    else
    {
        this -> n -> bind( __next_level );
    }
    return;
}

styles::basic_line::~basic_line(){
    for ( auto& it : this -> nodes )
    {
        delete it;
    }
    this -> nodes.clear();
    return;
}

size_t styles::basic_line::output_width() const {
    size_t width;
    for ( const auto& it : this -> nodes )
    {
        width += it -> output_width();
    }
    return width;
}

styles::style_flag styles::basic_line::style() const noexcept {
    return this -> s;
}

void styles::basic_line::add( styles::basic_node* __node ){
    this -> nodes.push_back( __node );
    return;
}
