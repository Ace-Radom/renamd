#ifndef _RENAMD_LINESTYLES_H_
#define _RENAMD_LINESTYLES_H_

#pragma once

#include"mdbasicobj.h"

namespace rena::styles::line {

    class normal final : public basic_line {

        public:
            normal()
                : basic_line( s_a_normal ){};
            ~normal(){};

            void render( std::ostream& __os ) const override;

    }; // class normal

    class basic_title : public basic_line {

        public:
            basic_title( const style_flag __s )
                : basic_line( __s ){};
            virtual ~basic_title(){};

    }; // class basic_title

    class title1 final : public basic_title {

        public:
            title1()
                : basic_title( s_l_title1 ){};
            ~title1(){};

            void render( std::ostream& __os ) const override {};

    }; // class title1

    basic_title* choose_title( int __level );

}; // namespace rena

#endif // _RENAMD_LINESTYLES_H_
