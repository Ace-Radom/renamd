#include"renamd/mdbasicobj.h"

namespace styles = rena::styles;

styles::style_flag styles::basic_node::style(){
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

styles::style_flag styles::basic_line::style(){
    return this -> s;
}

void styles::basic_line::add( styles::basic_node* __node ){
    this -> nodes.push_back( __node );
    return;
}
