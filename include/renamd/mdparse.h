#ifndef _RENAMD_MDPARSE_H_
#define _RENAMD_MDPARSE_H_

#pragma once

#include<cstdint>
#include<iostream>
#include<string>

namespace rena {

    class mdparser {

        public:
            mdparser(){};
            mdparser( std::string __raw )
                : raw( __raw ){}
            ~mdparser(){};

        protected:
            

            

        private:
            std::string raw;

    }; // class mdparser

}; // namespace rena

#endif
