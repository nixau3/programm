#include <iostream>
#include <string>

struct Toy {
    std::string name;
    double price;
    std::string storeName;
    Toy* next;
};

Toy* createToy(std::string name, double price, std::string storeName) {
    Toy* newToy = new Toy;
    newToy->name = name;
    newToy->price = price;
    newToy->storeName = storeName;
    newToy->next = nullptr;
    return newToy;
}

void appendToy(Toy*& head, std::string name, double price, std::string storeName) {
    Toy* newToy = createToy(name, price, storeName);
    if (head == nullptr) {
        head = newToy;
    } else {
        Toy* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newToy;
    }
}

Toy* findToy(Toy* head, std::string name) {
    Toy* current = head;
    while (current != nullptr) {
        if (current->name == name) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void printToyInfo(Toy* toy) {
    if (toy != nullptr) {
        std::cout << "Название игрушки: " << toy->name << std::endl;
        std::cout << "Стоимость: " << toy->price << std::endl;
        std::cout << "Магазин: " << toy->storeName << std::endl;
    } else {
        std::cout << "Игрушка не найдена." << std::endl;
    }
}

int main() {
    Toy* head = nullptr;

    appendToy(head, "Кукла", 1200.50, "Детский мир");
    appendToy(head, "Машинка", 850.00, "Мир игрушек");
    appendToy(head, "Конструктор", 1500.75, "Той-Лэнд");

    std::string searchName;
    std::cout << "Введите название игрушки для поиска: ";
    std::cin >> searchName;

    Toy* foundToy = findToy(head, searchName);
    printToyInfo(foundToy);

    while (head != nullptr) {
        Toy* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
