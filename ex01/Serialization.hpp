#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>

 struct Data
 
 {
    int member;
 };
 

class Serialization
{
    private:
        Serialization();
    
        
    public:
        ~Serialization();
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
};

#endif