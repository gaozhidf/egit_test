#include <boost/regex.hpp>
#include <string>
#include <iostream>

int main(int argc,char* argv[])
{
        boost::regex r("(\\+|-)?123");
        std::string str("+123");
        if(boost::regex_match(str,r))
        {
                std::cout<<"r"<<std::endl;
        }
        return 0;
}
