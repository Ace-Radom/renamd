#include"renamd/nodestyles.h"

namespace node = rena::styles::node;

void node::normal::render( std::ostream& __os ) const {
    __os << this -> d;
    return;
}
