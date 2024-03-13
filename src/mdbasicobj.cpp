#include"renamd/mdbasicobj.h"

namespace styles = rena::styles;

uint16_t styles::basic_node::style(){
    return this -> s;
}

styles::basic_line::~basic_line(){
    for ( auto& it : this -> nodes )
    {
        delete it;
    }
    this -> nodes.clear();
    return;
}

uint16_t styles::basic_line::style(){
    return this -> s;
}

void styles::basic_line::add( styles::basic_node* __node ){
    this -> nodes.push_back( __node );
    return;
}
