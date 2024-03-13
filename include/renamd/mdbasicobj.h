#ifndef _RENAMD_MDBASICOBJ_H_
#define _RENAMD_MDBASICOBJ_H_

#pragma once

#include<cstdint>
#include<iostream>
#include<string>
#include<vector>

namespace rena::styles {

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
    static const uint16_t s_l_quote     = 0b0000000000100000;
    static const uint16_t s_l_ul        = 0b0000000000010000;
    static const uint16_t s_l_ol        = 0b0000000000001000;
    static const uint16_t s_l_table     = 0b0000000000000100;
    static const uint16_t s_l_codeblock = 0b0000000000000010;
    static const uint16_t s_a_normal    = 0b0000000000000000;

    class basic_node {

        public:
            basic_node( const uint16_t __s , const std::string& __d )
                : s( __s ) , d( __d ){};
            virtual ~basic_node(){};

            uint16_t style();
            virtual void render( std::ostream& __os ) const = 0;

        protected:
            std::string d; // data

        private:
            uint16_t s;    // style

    }; // class basic_node

    class basic_line {

        public:
            basic_line( const uint16_t __s )
                : s( __s ){};
            virtual ~basic_line();

            uint16_t style();
            virtual void render( std::ostream& __os ) const = 0;
            virtual void add( basic_node* __node );

        protected:
            std::vector<basic_node*> nodes;

        private:
            uint16_t s;    // style

    }; // class basic_line

}; // namespace rena::styles

#endif // _RENAMD_MDBASICOBJ_H_
