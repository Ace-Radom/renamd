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

        protected:
            static putils::coord _get_console_size() noexcept;

    }; // class basic_title

    class title1 final : public basic_title {

        public:
            title1()
                : basic_title( s_l_title1 ){};
            ~title1(){};

            void render( std::ostream& __os ) const override;

    }; // class title1

    class title2 final : public basic_title {

        public:
            title2()
                : basic_title( s_l_title2 ){};
            ~title2(){};

            void render( std::ostream& __os ) const override;

    }; // class title2

    class title3 final : public basic_title {

        public:
            title3()
                : basic_title( s_l_title3 ){};
            ~title3(){};

            void render( std::ostream& __os ) const override;

    }; // class title3

    class title4 final : public basic_title {

        public:
            title4()
                : basic_title( s_l_title4 ){};
            ~title4(){};

            void render( std::ostream& __os ) const override {};

    }; // class title4

    class title5 final : public basic_title {

        public:
            title5()
                : basic_title( s_l_title5 ){};
            ~title5(){};

            void render( std::ostream& __os ) const override {};

    }; // class title5

    class title6 final : public basic_title {

        public:
            title6()
                : basic_title( s_l_title6 ){};
            ~title6(){};

            void render( std::ostream& __os ) const override {};

    }; // class title6

    basic_title* create_title( int __level );

}; // namespace rena

#endif // _RENAMD_LINESTYLES_H_
