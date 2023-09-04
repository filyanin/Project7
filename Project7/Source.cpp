#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

// Для map и unordered_map сделаю пары ключ-значение <std::string, int>, set будет просто набором чисел

void print(int value) {
    std::cout << value << " ";
}
void printPair(std::pair<std::string, int> product) {
    std::cout << product.first << " - " << product.second << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "RUSSIAN");

    std::cout << "find для std::map" << std::endl;
    std::map<std::string, int> products;
    std::map<std::string, int>::iterator it;

    // Добавляем пары ключ-значение в map
    products["bread"] = 30;
    products["milk"] = 80;
    products["apple"] = 60;

    std::cout << "Содержимое map" << std::endl;
    std::for_each(begin(products), end(products), printPair);
    
    it = products.find("apple");

    //Ищем значение для ключа apple
    if (it != products.end()) {
        std::cout << "Значение для ключа " << "apple" << ": " << it->second << std::endl;
    }
    else {
        std::cout << "Ключ " << "apple" << " не найден." << std::endl;
    }


    std::cout << "\n\ncount_if для std::unordered_map" << std::endl;
    std::unordered_map<std::string, int> myMap;

    // Добавляем пары ключ-значение в unordered_map
    myMap["bread"] = 30;
    myMap["milk"] = 80;
    myMap["apple"] = 60;

    std::cout << "Содержимое unordered_map" << std::endl;
    std::for_each(begin(myMap), end(myMap), printPair);

    // Подсчитываем количество пар, в которых значение меньше 50
    char targetChar = 'д';
    int targetValue = 50;
    int count = std::count_if(myMap.begin(), myMap.end(), [targetValue](const std::pair<std::string, int>& pair) {
        return pair.second < targetValue;
        });

    std::cout << "Количество значений меньше '" << targetValue << "': " << count << std::endl;


    std::cout << "\n\nfor_each для std::set" << std::endl;
    std::set<int> mySet;

    // Добавляем элементы в set
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(3);

    // Применяем функцию к каждому элементу set
    std::for_each(mySet.begin(), mySet.end(), print);

    std::cout << std::endl;
    return 0;
}