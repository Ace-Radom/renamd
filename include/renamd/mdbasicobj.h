#ifndef _RENAMD_MDBASICOBJ_H_
#define _RENAMD_MDBASICOBJ_H_

#pragma once

#include<cstdint>
#include<iostream>
#include<string>
#include<vector>

namespace rena::styles {

    typedef uint16_t style_flag;

    static const style_flag s_f_bold      = 0b1000000000000000;
    static const style_flag s_f_italic    = 0b0100000000000000;
    static const style_flag s_f_code      = 0b0010000000000000;
    static const style_flag s_l_title1    = 0b0001000000000000;
    static const style_flag s_l_title2    = 0b0000100000000000;
    static const style_flag s_l_title3    = 0b0000010000000000;
    static const style_flag s_l_title4    = 0b0000001000000000;
    static const style_flag s_l_title5    = 0b0000000100000000;
    static const style_flag s_l_title6    = 0b0000000010000000;
    static const style_flag s_l_quote     = 0b0000000001000000;
    static const style_flag s_l_ul        = 0b0000000000100000;
    static const style_flag s_l_ol        = 0b0000000000010000;
    static const style_flag s_l_table     = 0b0000000000001000;
    static const style_flag s_l_codeblock = 0b0000000000000100;
    static const style_flag s_a_normal    = 0b0000000000000000;

    class basic_mdobj {

        public:
            basic_mdobj(){};
            virtual ~basic_mdobj(){};

            virtual size_t output_width() const = 0;
            virtual void render( std::ostream& __os ) const = 0;

    }; // class basic_mdobj

    class basic_node : public basic_mdobj {

        public:
            basic_node( const style_flag __s , const std::string& __d , const bool __ews )
                : s( __s ) , d ( __d ) , ews( __ews ){};
            basic_node( const style_flag __s , const std::string& __d )
                : s( __s ) , d( __d ) , ews( true ){};
            basic_node( const style_flag __s , const bool __ews )
                : s( __s ) , ews( __ews ){};
            basic_node( const style_flag __s )
                : s( __s ) , ews( true ){};
            virtual ~basic_node();

            virtual size_t output_width() const override;

            style_flag style() const noexcept;
            void bind( basic_node* __next_level );

        protected:
            std::string d;  // data
            basic_node* n;  // next level
            bool ews;  // end with space

        private:
            style_flag s;  // style

    }; // class basic_node

    class basic_line : public basic_mdobj {

        public:
            basic_line( const style_flag __s )
                : s( __s ){};
            virtual ~basic_line();

            virtual size_t output_width() const override;

            style_flag style() const noexcept;
            virtual void add( basic_node* __node );

        protected:
            std::vector<basic_node*> nodes;

        private:
            style_flag s;  // style

    }; // class basic_line

    namespace putils {

        typedef struct coord {
            int x;
            int y;
        } coord;

        coord gotoxy( int x , int y );

#ifdef _WIN32
        void SetCursorPosition( coord __coord );
#endif

        template <class _Elem , class _Traits>
        std::basic_ostream<_Elem,_Traits>& operator<<( std::basic_ostream<_Elem,_Traits>& __os , coord __coord ){
#ifdef _WIN32
            SetCursorPosition( __coord );
#else
            if ( __coord.y == -1 )
            {
                __os << "\033[" <<  __coord.x << "G";
            }
            // currently no support to vertical absolute
            else
            {
                __os << "\033[" << __coord.y << ";" << __coord.x << "H";
            }
#endif
            return __os;
        }

        typedef struct repeat_str {
            std::string str;
            int repeat_times;
        } repeat_str;

        repeat_str repeat_string( const std::string& __str , int times );

        template <class _Elem , class _Traits>
        std::basic_ostream<_Elem,_Traits>& operator<<( std::basic_ostream<_Elem,_Traits>& __os , const repeat_str& __rs ){
            for ( int i = 0 ; i < __rs.repeat_times ; i++ )
            {
                __os << __rs.str;
            }
            return __os;
        }

    }; // namespace putils

}; // namespace rena::styles

#endif // _RENAMD_MDBASICOBJ_H_
