#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
class ScalarConverter
{
    private:
        ScalarConverter(/* args */);
    
        
    public:
        ~ScalarConverter();
        static void convert(std::string input);
};

#endif