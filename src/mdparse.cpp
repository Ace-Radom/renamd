#include"renamd/mdparse.h"
#include"renamd/linestyles.h"
#include"renamd/nodestyles.h"

void rena::mdparser::test(){
    styles::line::normal normal1;
    auto node = new styles::node::bold();
    node -> bind( new styles::node::italic( "Hello" ) );
    normal1.add( node );
    normal1.add( new styles::node::code( "This is the way" ) );
    normal1.render( std::cout );
    return;   
}
