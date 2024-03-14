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
            bold()
                : basic_node( s_f_bold ){};        
            bold( const std::string& __d )
                : basic_node( s_f_bold , __d ){};
            ~bold(){};

            void render( std::ostream& __os ) const override;

    }; // class bold

    class italic : public basic_node {

        public:
            italic()
                : basic_node( s_f_italic ){};
            italic( const std::string& __d )
                : basic_node( s_f_italic , __d ){};
            ~italic(){};

            void render( std::ostream& __os ) const override;

    }; // class italic

    class code : public basic_node {

        public:
            code()
                : basic_node( s_f_code ){};
            code( const std::string& __d )
                : basic_node( s_f_code , __d ){};
            ~code(){};

            void render( std::ostream& __os ) const override;

    }; // class code

}; // namespace rena::styles::node

#endif // _RENAMD_NODESTYLES_H_
