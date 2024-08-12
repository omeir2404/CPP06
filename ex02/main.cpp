#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate() {
    srand(time(nullptr));
    int random = rand() % 3;

    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != nullptr) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p) != nullptr) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p) != nullptr) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::bad_cast&) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (std::bad_cast&) {
            try {
                dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            } catch (std::bad_cast&) {
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