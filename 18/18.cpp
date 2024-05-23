#include <iostream>
#include <vector>
#include <algorithm>

class MyObject {
public:
    explicit MyObject(int val) : value(val) {}
    int value;
};

int main() {
    int num_objects;
    std::cout << "Введите размерность векторов: ";
    std::cin >> num_objects;

    std::vector<MyObject> initial_vector(num_objects);
    std::generate(initial_vector.begin(), initial_vector.end(), []() { return MyObject(rand() % 100); });

    std::cout << "Исходный вектор:" << std::endl;
    for (const auto& obj : initial_vector) {
        std::cout << obj.value << " ";
    }
    std::cout << std::endl;

    std::vector<MyObject> new_vector;
    std::copy_if(initial_vector.begin(), initial_vector.end(), std::back_inserter(new_vector), [](const MyObject& obj) {
        return obj.value > 50;
    });

    std::cout << "Новый вектор:" << std::endl;
    for (const auto& obj : new_vector) {
        std::cout << obj.value << " ";
    }
    std::cout << std::endl;

    if (new_vector.empty()) {
        std::cout << "Новый вектор пуст" << std::endl;
    } else {
        std::sort(new_vector.begin(), new_vector.end(), [](const MyObject& a, const MyObject& b) {
            return a.value < b.value;
        });
        std::cout << "Сортированный новый вектор:" << std::endl;
        for (const auto& obj : new_vector) {
            std::cout << obj.value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
