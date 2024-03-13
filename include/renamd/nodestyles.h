#ifndef _RENAMD_NODESTYLES_H_
#define _RENAMD_NODESTYLES_H_

#pragma once

#include"mdbasicobj.h"

namespace rena::styles::node {

    class normal : public basic_node {

        public:
            normal( const std::string& __d )
                : basic_node( s_a_normal , __d ){};
            ~normal(){};

            void render( std::ostream& __os ) const override;

    }; // class normal

    class bold : public basic_node {

        public:
            bold( const std::string& __d )
                : basic_node( s_f_bold , __d ){};
            ~bold(){};

            void render( std::ostream& __os ) const override;

    }; // class bold

}; // namespace rena::styles::node

#endif // _RENAMD_NODESTYLES_H_
