#ifndef _RENAMD_MDPARSE_H_
#define _RENAMD_MDPARSE_H_

#pragma once

#include<cstdint>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>

#include"mdbasicobj.h"

namespace rena {

    class mdparser {

        public:
            mdparser(){};
            ~mdparser(){};
            
            bool read( std::string __raw );
            const std::string& err() const noexcept;
            void test();

        protected:
            bool _parse();
            void _update_errmsg() noexcept;

        private:
            std::vector<styles::basic_line> lines;
            std::string raw;
            std::string errmsg;
            int errnum;

    }; // class mdparser

}; // namespace rena

#endif
