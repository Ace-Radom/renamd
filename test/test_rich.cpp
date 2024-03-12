#include"renamd/rich.h"

int main(){
    rena::rich::init();
    std::cout << rena::rich::FColor::RED << "Hello World" << rena::rich::style_reset << std::endl;
    std::cout << "Reset" << std::endl;
    std::cout << rena::rich::FColor::BLACK << "\\"
              << rena::rich::FColor::RED << "/"
              << rena::rich::FColor::GREEN << "\\"
              << rena::rich::FColor::YELLOW << "/"
              << rena::rich::FColor::BLUE << "\\"
              << rena::rich::FColor::MAGENTA << "/"
              << rena::rich::FColor::CYAN << "\\"
              << rena::rich::FColor::WHITE << "/"
              << rena::rich::FColor::GRAY << "\\"
              << rena::rich::FColor::BRIGHTRED << "/"
              << rena::rich::FColor::BRIGHTGREEN << "\\"
              << rena::rich::FColor::BRIGHTYELLOW << "/"
              << rena::rich::FColor::BRIGHTBLUE << "\\"
              << rena::rich::FColor::BRIGHTMAGENTA << "/"
              << rena::rich::FColor::BRIGHTCYAN << "\\"
              << rena::rich::FColor::BRIGHTWHITE << "/"
              << rena::rich::style_reset << std::endl;
    std::cout << rena::rich::BColor::BLACK << " "
              << rena::rich::BColor::RED << " "
              << rena::rich::BColor::GREEN << " "
              << rena::rich::BColor::YELLOW << " "
              << rena::rich::BColor::BLUE << " "
              << rena::rich::BColor::MAGENTA << " "
              << rena::rich::BColor::CYAN << " "
              << rena::rich::BColor::WHITE << " "
              << rena::rich::BColor::GRAY << " "
              << rena::rich::BColor::BRIGHTRED << " "
              << rena::rich::BColor::BRIGHTGREEN << " "
              << rena::rich::BColor::BRIGHTYELLOW << " "
              << rena::rich::BColor::BRIGHTBLUE << " "
              << rena::rich::BColor::BRIGHTMAGENTA << " "
              << rena::rich::BColor::BRIGHTCYAN << " "
              << rena::rich::BColor::BRIGHTWHITE << " "
              << rena::rich::style_reset << std::endl;
    return 0;
}