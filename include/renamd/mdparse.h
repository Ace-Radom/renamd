#ifndef _RENAMD_MDPARSE_H_
#define _RENAMD_MDPARSE_H_

#pragma once

#include<cstdint>
#include<iostream>
#include<string>
#include<vector>

#include"mdbasicobj.h"

namespace rena {

    class mdparser {

        public:
            mdparser(){};
            mdparser( std::string __raw )
                : raw( __raw ){}
            ~mdparser(){};

            void test();

        protected:
            

            

        private:
            std::vector<styles::basic_line> lines;
            std::string raw;

    }; // class mdparser

}; // namespace rena

#endif
