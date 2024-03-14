#include"renamd/mdparse.h"
#include"renamd/linestyles.h"
#include"renamd/mdregex.h"
#include"renamd/nodestyles.h"

bool rena::mdparser::read( std::string __raw ){
    this -> raw = __raw;
    return this -> _parse();
}

const std::string& rena::mdparser::err() const noexcept {
    return this -> errmsg;
}

void rena::mdparser::test(){
    // styles::line::normal normal1;
    // auto node = new styles::node::bold();
    // node -> bind( new styles::node::italic( "Hello" ) );
    // normal1.add( node );
    // normal1.add( new styles::node::code( "This is the way" ) );
    // normal1.render( std::cout );

    styles::line::title1 title;

    std::cout << title._calc_output_width();

    // this -> raw = "# Title 1\n## Title 2\n ### Title 3\n#### Title4 \n##### R\n###### Title 6\n####### TITLE 7\n#TITLE8";
    // this -> _parse();

    return;   
}

bool rena::mdparser::_parse(){
    std::istringstream iss( this -> raw );
    std::string this_line;
    while ( std::getline( iss , this_line ) )
    {
        std::cout << this_line << " ";
        if ( std::regex_match( this_line , mdregex::reg_title ) )
        {
            int level;
            for ( level = 0 ; level < 6 ; level++ )
            {
                if ( this_line[level] != '#' )
                {
                    break;
                }
            }
        }
    }
    return true;
}
