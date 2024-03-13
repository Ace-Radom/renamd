#ifndef _RENAMD_MDBASICOBJ_H_
#define _RENAMD_MDBASICOBJ_H_

#pragma once

#include<cstdint>
#include<iostream>
#include<string>

namespace rena {

    namespace styles {

        static const uint16_t s_f_bold      = 0b1000000000000000;
        static const uint16_t s_f_italic    = 0b0100000000000000;
        static const uint16_t s_f_underline = 0b0010000000000000;
        static const uint16_t s_f_code      = 0b0001000000000000;
        static const uint16_t s_l_title1    = 0b0000100000000000;
        static const uint16_t s_l_title2    = 0b0000010000000000;
        static const uint16_t s_l_title3    = 0b0000001000000000;
        static const uint16_t s_l_title4    = 0b0000000100000000;
        static const uint16_t s_l_title5    = 0b0000000010000000;
        static const uint16_t s_l_title6    = 0b0000000001000000;

        class basic_node {

            public:
                basic_node( const uint16_t __s , std::string __d )
                    : s( __s ) , d( __d ){};
                ~basic_node(){};

                uint16_t style();
                virtual void render( std::ostream& __os ) = 0;

            protected:
                std::string d; // data

            private:
                uint16_t s;    // style

        }; // class basic_node

        class basic_line {

            public:
                basic_line( const uint16_t __s )
                    : s( __s ){};
                ~basic_line(){};

                uint16_t style();
                virtual void render( std::ostream& __os ) = 0;

            private:
                uint16_t s; // style

        }; // class basic_line

    }; // namespace styles

}; // namespace rena

#endif // _RENAMD_MDBASICOBJ_H_
