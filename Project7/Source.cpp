#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <set>

// ��� map � unordered_map ������ ���� ����-�������� <std::string, int>, set ����� ������ ������� �����

void print(int value) {
    std::cout << value << " ";
}
void printPair(std::pair<std::string, int> product) {
    std::cout << product.first << " - " << product.second << std::endl;
}

int main()
{
    std::setlocale(LC_ALL, "RUSSIAN");

    std::cout << "find ��� std::map" << std::endl;
    std::map<std::string, int> products;
    std::map<std::string, int>::iterator it;

    // ��������� ���� ����-�������� � map
    products["bread"] = 30;
    products["milk"] = 80;
    products["apple"] = 60;

    std::cout << "���������� map" << std::endl;
    std::for_each(begin(products), end(products), printPair);
    
    it = products.find("apple");

    //���� �������� ��� ����� apple
    if (it != products.end()) {
        std::cout << "�������� ��� ����� " << "apple" << ": " << it->second << std::endl;
    }
    else {
        std::cout << "���� " << "apple" << " �� ������." << std::endl;
    }


    std::cout << "\n\ncount_if ��� std::unordered_map" << std::endl;
    std::unordered_map<std::string, int> myMap;

    // ��������� ���� ����-�������� � unordered_map
    myMap["bread"] = 30;
    myMap["milk"] = 80;
    myMap["apple"] = 60;

    std::cout << "���������� unordered_map" << std::endl;
    std::for_each(begin(myMap), end(myMap), printPair);

    // ������������ ���������� ���, � ������� �������� ������ 50
    char targetChar = '�';
    int targetValue = 50;
    int count = std::count_if(myMap.begin(), myMap.end(), [targetValue](const std::pair<std::string, int>& pair) {
        return pair.second < targetValue;
        });

    std::cout << "���������� �������� ������ '" << targetValue << "': " << count << std::endl;


    std::cout << "\n\nfor_each ��� std::set" << std::endl;
    std::set<int> mySet;

    // ��������� �������� � set
    mySet.insert(5);
    mySet.insert(2);
    mySet.insert(8);
    mySet.insert(3);

    // ��������� ������� � ������� �������� set
    std::for_each(mySet.begin(), mySet.end(), print);

    std::cout << std::endl;
    return 0;
}