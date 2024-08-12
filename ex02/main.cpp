#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate() {
    srand(time(NULL));
    int random = rand() % 3;

    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception & e) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (std::exception & e) {
            try {
                dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            } catch (std::exception & e) {
                // Handle the case where p is not of type A, B, or C
            }
        }
    }
}

int main() {
    Base* obj = generate();
    identify(obj);
    identify(*obj);

    delete obj;
    return 0;
}