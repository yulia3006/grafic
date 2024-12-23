#include <iostream>
#include <set>
#include <locale.h>

void printEvenElementsFromUnion(const std::set<int>& setA, const std::set<int>& setB) {
    std::set<int> unionSet = setA;
    unionSet.insert(setB.begin(), setB.end()); // Объединяем множества

    std::cout << "Четные элементы из объединения множеств A и B: ";
    for (const int& element : unionSet) {
        if (element % 2 == 0) {
            std::cout << element << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int size = 5; // Размер множеств

    std::set<int> A; // Множество A
    std::set<int> B; // Множество B

    // Ввод элементов множества A
    std::cout << "Введите " << size << " уникальных элементов для множества A:" << std::endl;
    for (int i = 0; i < size; i++) {
        int element;
        std::cin >> element;
        A.insert(element); // Добавляем элемент в множество
    }

    // Ввод элементов множества B
    std::cout << "Введите " << size << " уникальных элементов для множества B:" << std::endl;
    for (int i = 0; i < size; i++) {
        int element;
        std::cin >> element;
        B.insert(element); // Добавляем элемент в множество
    }

    // Вывод четных элементов из объединения множеств
    printEvenElementsFromUnion(A, B);

    return 0;
}