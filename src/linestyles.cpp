#include"renamd/linestyles.h"
#include"renamd/rich.h"
#include<cassert>
#include<cmath>
#include<limits>
#ifdef _WIN32
#include<windows.h>
#else
#include<sys/types.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<termios.h>
#endif

namespace styles = rena::styles;
namespace line = rena::styles::line;

void line::normal::render( std::ostream& __os ) const {
    for ( const auto& it : this -> nodes )
    {
        it -> render( __os );
    }
    return;
}

styles::putils::coord line::basic_title::_get_console_size() noexcept {

#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if ( GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ) , &csbi ) )
    {
        return { 
            csbi.srWindow.Right - csbi.srWindow.Left + 1 ,
            csbi.srWindow.Bottom - csbi.srWindow.Top + 1
        };
    }
    else
    {
        return { -1 , -1 };
    }
#else
    struct winsize size;
    ioctl( STDIN_FILENO ,TIOCGWINSZ , &size );
    return { size.ws_col , size.ws_row };
#endif

};

void line::title1::render( std::ostream& __os ) const {
    putils::coord csize = this -> _get_console_size();
    size_t title_width = this -> output_width();
    int empty_spaces_left = std::round( ( csize.x - title_width ) / 2.0 );
    
    __os << rich::FStyle::BOLD << "╔" << putils::repeat_string( "═" , csize.x - 2 ) << "╗\n"
         << "║" << putils::gotoxy( empty_spaces_left , -1 );
    for ( const auto& it : this -> nodes )
    {
        it -> render( __os );
        __os << rich::FStyle::BOLD;
        // style reset
    }
    __os << putils::gotoxy( csize.x , -1 ) << "║\n"
         << "╚" << putils::repeat_string( "═" , csize.x - 2 ) << "╝" << rich::style_reset << "\n\n";
    return;
};

void line::title2::render( std::ostream& __os ) const {
    putils::coord csize = this -> _get_console_size();
    size_t title_width = this -> output_width();
    int empty_spaces_left = std::round( ( csize.x - title_width ) / 2.0 );

    __os << rich::FStyle::BOLD << "┏" << putils::repeat_string( "━" , csize.x - 2 ) << "┓\n"
         << "┃" << putils::gotoxy( empty_spaces_left , -1 );
    for ( const auto& it : this -> nodes )
    {
        it -> render( __os );
        __os << rich::FStyle::BOLD;
        // style reset
    }
    __os << putils::gotoxy( csize.x , -1 ) << "┃\n"
         << "┗" << putils::repeat_string( "━" , csize.x - 2 ) << "┛" << rich::style_reset << "\n\n";
    return;
}

void line::title3::render( std::ostream& __os ) const {
    putils::coord csize = this -> _get_console_size();
    size_t title_width = this -> output_width();
    int empty_spaces_left = std::round( ( csize.x - title_width ) / 2.0 );

    __os << rich::FStyle::BOLD << putils::gotoxy( empty_spaces_left , -1 );
    for ( const auto& it : this -> nodes )
    {
        it -> render( __os );
        __os << rich::FStyle::BOLD;
        // style reset
    }
    __os << "\n" << putils::repeat_string( "━" , csize.x ) << rich::style_reset << "\n\n";
    return;
}

line::basic_title* line::create_title( int __level ){
    switch ( __level )
    {
        case 1: return new title1(); break;
        case 2: return new title2(); break;
        case 3: return new title3(); break;
        case 4: return new title4(); break;
        case 5: return new title5(); break;
        case 6: return new title6(); break;
    }

    return nullptr;
}
