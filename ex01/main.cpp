#include "Serialization.hpp"

int main()
{
    Data data;
    data.number = 42;
    data.word ="hello world";

    uintptr_t serializedData = Serialization::serialize(&data);

    Data* deserializedData = Serialization::deserialize(serializedData);

    std::cout << "number: " << deserializedData->number << " word: "<< deserializedData->word << std::endl;
    if (deserializedData == &data) {
        std::cout << "Deserialization successful!" << std::endl;
    } else {
        std::cout << "Deserialization failed!" << std::endl;
    }


    return 0;
}
