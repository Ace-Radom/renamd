#include"renamd/mdbasicobj.h"

namespace styles = rena::styles;

styles::basic_node::~basic_node(){
    if ( this -> n != nullptr )
    {
        delete this -> n;
    }
    return;
}

styles::style_flag styles::basic_node::style(){
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

styles::style_flag styles::basic_line::style(){
    return this -> s;
}

void styles::basic_line::add( styles::basic_node* __node ){
    this -> nodes.push_back( __node );
    return;
}
