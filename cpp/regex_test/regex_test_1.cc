#include <string>   
#include <iostream>   
    
#include "boost/regex.hpp"   
    
int main(int argc, char ** argv)   
{   
    if (argc != 4)   
    {      
        std::cerr << "Usage: " << argv[0] << " option regex text\n"   
            << "option: 0 --whole match\n"   
            << "        1 --sub match\n"   
            << "        2 --replace match\n";   
        return 1;   
    }      
    
    boost::regex oRegex(argv[2]);   
    boost::smatch oResults;   
    std::string strStr(argv[3]);   
    std::string strRes;   
    
    switch (atoi(argv[1]))   
    {      
        case 0:   
            if(boost::regex_match(strStr, oResults, oRegex))   
            {      
                std::cout << strStr << " matches " << oRegex << "\n";   
            }      
            else   
            {      
                std::cout << strStr << " doesn't match " << oRegex << "\n";   
            }      
            break;   
        case 1:   
            if(boost::regex_search(strStr, oResults, oRegex))   
            {   
                std::cout << strStr << " matches " << oRegex << "\n";   
            }   
            else   
            {   
                std::cout << strStr << " doesn't match " << oRegex << "\n";   
            }   
            break;   
        case 2:   
            strRes = boost::regex_replace(strStr, oRegex, " ");   
            std::cout << "strRes=" << strRes << "\n";   
            break;   
        default:   
            std::cerr << "Invalid option: " << argv[1] << "\n";   
            break;   
    }   
}   
