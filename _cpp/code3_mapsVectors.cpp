#include <iostream>
#include <map>
#include <vector>

void mapUse();
void vectorUse();

int main() {
    mapUse();
    vectorUse();
    return 0;
}

void mapUse() {
    std::map<std::string, int> nameAge {
        {"Joshua", 27},
        {"John", 28},
        {"Joel", 25}
    };
    std::cout << "Joel's age: " << nameAge["Joel"] << std::endl;
    std::cout << "John's age: " << nameAge.at("John") << std::endl;
}

void vectorUse() {
    std::vector<int> numbers{1,2,3,4,5};
    for (int num : numbers) {
        std::cout << num << " ";
    }
}