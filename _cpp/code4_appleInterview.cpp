#include <iostream>
#include <string>

void pointersExcs();
void whileExcs();

int main() {
    // pointersExcs();
    whileExcs();

    return 0;
}

void whileExcs() {
    int count = 1;
    while (count <= 5) {
        std::cout << "Hello There!" << std::endl;
        count++;
    }
}

void 

void pointersExcs() {
    std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
    std::cout << freePizzas << std::endl;
    std::cout << *freePizzas << std::endl;
    std::cout << &freePizzas << std::endl;
    std::cout << *(&freePizzas) << std::endl;

    int age = 27;
    int *pAge = &age;
    std::cout << age << std::endl;
    std::cout << &age << std::endl;
    std::cout << pAge << std::endl;
    std::cout << *pAge << std::endl;
    std::cout << &(*pAge) << std::endl;
}