#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cout << "you need to insert one number\nexample: ./converter <number> \n";
        return -1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
