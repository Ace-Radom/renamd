#include"renamd/mdbasicobj.h"
#include"utf8cwidth.h"
#ifdef _WIN32
#include<windows.h>
#endif

namespace styles = rena::styles;

styles::basic_node::~basic_node(){
    if ( this -> n != nullptr )
    {
        delete this -> n;
    }
    return;
}

size_t styles::basic_node::output_width() const {
    return unicode::display_width( this -> ews ? this -> d + " " : this -> d );
}

styles::style_flag styles::basic_node::style() const noexcept {
    if ( this -> n != nullptr )
    {
        return this -> s & this -> n -> style();
    }
    else
    {
        return this -> s;
    }
}

void styles::basic_node::bind( styles::basic_node* __next_level ){
    if ( n == nullptr )
    {
        this -> n = __next_level;
    }
    else
    {
        this -> n -> bind( __next_level );
    }
    return;
}

styles::basic_line::~basic_line(){
    for ( auto& it : this -> nodes )
    {
        delete it;
    }
    this -> nodes.clear();
    return;
}

size_t styles::basic_line::output_width() const {
    size_t width = 0;
    for ( const auto& it : this -> nodes )
    {
        width += it -> output_width();
    }
    return width;
}

styles::style_flag styles::basic_line::style() const noexcept {
    return this -> s;
}

void styles::basic_line::add( styles::basic_node* __node ){
    this -> nodes.push_back( __node );
    return;
}

styles::putils::coord styles::putils::gotoxy( int x , int y ){
    return { x , y };
}

#ifdef _WIN32

void styles::putils::SetCursorPosition( styles::putils::coord __coord ){
    HANDLE hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo( hStdOut , &csbi );
    COORD newpos;
    newpos.X = ( __coord.x == -1 ) ? csbi.dwCursorPosition.X : __coord.x - 1;
    newpos.Y = ( __coord.y == -1 ) ? csbi.dwCursorPosition.Y : __coord.y - 1;
    SetConsoleCursorPosition( hStdOut , newpos );
    return;
}

#endif

styles::putils::repeat_str styles::putils::repeat_string( const std::string& __str , int times ){
    return { __str , times };
}
