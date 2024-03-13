#include"renamd/mdparse.h"
#include"renamd/linestyles.h"
#include"renamd/nodestyles.h"

void rena::mdparser::test(){
    styles::line::normal normal1;
    normal1.add( new styles::node::normal( "Hello" ) );
    normal1.add( new styles::node::normal( "World" ) );
    normal1.render( std::cout );
    return;   
}
