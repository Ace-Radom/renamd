#include"renamd/linestyles.h"

namespace line = rena::styles::line;

void line::normal::render( std::ostream& __os ) const {
    bool is_bol = true;  // is begin of line
    for ( const auto& it : this -> nodes )
    {
        if ( !is_bol )
        {
            __os << " ";
        }
        it -> render( __os );
        is_bol = false;
    }
    return;
}
