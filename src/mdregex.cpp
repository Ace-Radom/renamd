#include"renamd/mdregex.h"

namespace mdregex = rena::mdregex;

const std::regex mdregex::reg_title( R"(^#{1,6} .*)" );
