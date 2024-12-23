#include <iostream>

void calculateSumAndAverage(const int* arr, int size, int& sum, double& average) {
    sum = 0; // Инициализация суммы
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    average = static_cast<double>(sum) / size; // Вычисление среднего арифметического
}

void printArray(const int* arr, int size, const std::string& arrayName) {
    std::cout << "Элементы массива " << arrayName << ": ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int size = 5; // Размер массивов

    int A[size]; // Массив A
    int B[size]; // Массив B

    // Ввод массивов
    std::cout << "Введите " << size << " элементов для массива A:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> A[i];
    }

    std::cout << "Введите " << size << " элементов для массива B:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> B[i];
    }

    // Вычисление суммы и среднего арифметического
    int sumA = 0, sumB = 0;
    double averageA = 0.0, averageB = 0.0;

    calculateSumAndAverage(A, size, sumA, averageA);
    calculateSumAndAverage(B, size, sumB, averageB);

    // Вывод массивов и их средних значений
    printArray(A, size, "A");
    std::cout << "Среднее арифметическое A: " << averageA << std::endl;

    printArray(B, size, "B");
    std::cout << "Среднее арифметическое B: " << averageB << std::endl;

    return 0;
}