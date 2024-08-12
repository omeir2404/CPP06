#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

/*std::string getType(const std::string& str) {
    // Try to convert to char
    if (str.length() == 1 && isprint(str[0])) {
        return "char";
    }

    // Try to convert to int
    std::istringstream iss(str);
    int i;
    if (!(iss >> i).fail() && iss.eof()) {
        return "int";
    }

    // Try to convert to float
    iss.clear();
    iss.str(str);
    float f;
    if (!(iss >> f).fail() && iss.eof()) {
        return "float";
    }

    // Try to convert to double
    iss.clear();
    iss.str(str);
    double d;
    if (!(iss >> d).fail() && iss.eof()) {
        return "double";
    }

    // If all conversions failed, return "unknown"
    return "unknown";
}*/
void ScalarConverter::convert(std::string input)
{
    // std::getType(input);
    try
    {
        int i;
        char c;
        std::istringstream iss(input);
        iss >> i;
        if (iss.fail())
        {
            if (input.length() == 1 && isprint(input[0]))
            {
                c = input[0];
                std::cout << "char: '" << c << "'" << std::endl;
            }
            else
                throw std::invalid_argument("invalid argument");
        }
        else if (i >= 32 && i <= 126)
        {
            c = static_cast<char>(i); // compile time cast int to char via asci: 48 = 0 ...
            std::cout << "char: '" << c << "'" << std::endl;
        }
        else
        {
            std::cout << "char: Non displayable" << std::endl;
        }
    }
    catch (std::invalid_argument &)
    {
        std::cout << "char: impossible" << std::endl;
    }

    try
    {
        int i;
        std::istringstream iss(input);
        iss >> i;
        if (iss.fail())
        {
            if (input.length() == 1 && isprint(input[0]))
            {
                i = static_cast<int>(input[0]);
                std::cout << "int: " << i << std::endl;
            }
            else
                throw std::invalid_argument("invalid argument");
        }
        else
            std::cout << "int: " << i << std::endl;
    }
    catch (std::invalid_argument &)
    {
        std::cout << "int: impossible" << std::endl;
    }
    catch (std::out_of_range &)
    {
        std::cout << "int: out of range" << std::endl;
    }

    try
    {
        float f;
        if (input == "nan" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff" || input == "nanf" || input == "inf" || input == "inff")
        {
            f = std::numeric_limits<float>::quiet_NaN();
            if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
            {
                f = std::numeric_limits<float>::infinity();
            }
            else if (input == "-inf" || input == "-inff")
            {
                f = -std::numeric_limits<float>::infinity();
            }
        }
        else
        {
            std::istringstream iss(input);
            iss >> f;
            if (iss.fail())
            {
                if (input.length() == 1 && isprint(input[0]))
                    f = static_cast<float>(input[0]);
                else
                throw std::invalid_argument("invalid argument");
            }
        }
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    }
    catch (std::invalid_argument &)
    {
        std::cout << "float: invalid argument" << std::endl;
    }
    catch (std::out_of_range &)
    {
        std::cout << "float: out of range" << std::endl;
    }

    try
    {
        double d;
        if (input == "nan" || input == "+inf" || input == "-inf" || input == "+inff" || input == "-inff" || input == "nanf" || input == "inf" || input == "inff")
        {
            d = std::numeric_limits<double>::quiet_NaN();
            if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
                d = std::numeric_limits<double>::infinity();
            else if (input == "-inf" || input == "-inff")
                d = -std::numeric_limits<double>::infinity();
        }
        else
        {
            std::istringstream iss(input);
            iss >> d;
            if (iss.fail())
            {
                if (input.length() == 1 && isprint(input[0]))
                    d = static_cast<double>(input[0]);
                else
                    throw std::invalid_argument("invalid argument");
            }
        }
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
    }
    catch (std::invalid_argument &)
    {
        std::cout << "double: invalid argument" << std::endl;
    }
    catch (std::out_of_range &)
    {
        std::cout << "double: out of range" << std::endl;
    }
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other)
    {
    }
    return *this;
}