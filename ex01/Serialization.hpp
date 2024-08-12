#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP
#include <string>
#include <iostream>

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdint.h>

struct Data

{
    int number;
    std::string word;
};

class Serialization
{
private:
    Serialization();
    Serialization(const Serialization &other);
    Serialization &operator=(const Serialization &other);

public:
    ~Serialization();
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif