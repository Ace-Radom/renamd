#ifndef _RENAMD_LINESTYLES_H_
#define _RENAMD_LINESTYLES_H_

#pragma once

#include"mdbasicobj.h"

namespace rena::styles::line {

    class normal : public basic_line {

        public:
            normal()
                : basic_line( s_a_normal ){};
            ~normal(){};

            void render( std::ostream& __os ) const override;

    }; // class normal

}; // namespace rena

#endif // _RENAMD_LINESTYLES_H_
