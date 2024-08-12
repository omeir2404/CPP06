#ifndef BASS_HPP
#define BASS_HPP
#include <string>
#include <iostream>

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdint.h>

class Base
{
private:
public:
    virtual ~Base();
};

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};


Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif