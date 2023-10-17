#include <iostream>

class DynamicIntArray {
private:
    int* data;
    int size;

public:
    DynamicIntArray(int size) {
        this->size = size;
        data = new int[size];
    }

    ~DynamicIntArray() {
        delete[] data;
    }

    // Конструктор копирования
    DynamicIntArray(const DynamicIntArray& other) {
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    void printArray() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    void setValueAtIndex(int index, int value) {
        if (index >= 0 && index < size) {
            if (value >= -100 && value <= 100) {
                data[index] = value;
            } else {
                std::cout << "Значение должно быть в промежутке от -100 до 100" << std::endl;
            }
        } else {
            std::cout << "Недопустимый индекс" << std::endl;
        }
    }

    int getValueAtIndex(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        } else {
            std::cout << "Недопустимый индекс" << std::endl;
            return 0;
        }
    }

    void addToEnd(int value) {
        if (value >= -100 && value <= 100) {
            int* newData = new int[size + 1];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            newData[size] = value;
            size++;
            delete[] data;
            data = newData;
        } else {
            std::cout << "Значение должно быть в промежутке от -100 до 100" << std::endl;
        }
    }

    void add(DynamicIntArray& other) {
        int maxSize = std::max(size, other.size);
        int* newData = new int[maxSize];
        for (int i = 0; i < maxSize; i++) {
            newData[i] = data[i] + other.getValueAtIndex(i);
        }
        delete[] data;
        data = newData;
    }
};

int main() {
    DynamicIntArray arr1(5);
    arr1.setValueAtIndex(0, 10);
    arr1.setValueAtIndex(1, 20);
    arr1.setValueAtIndex(2, 30);
    arr1.printArray(); // Выводит: 10 20 30 0 0

    DynamicIntArray arr2 = arr1;
    arr2.printArray(); // Выводит: 10 20 30 0 0 (копия arr1)

    arr1.addToEnd(40);
    arr1.printArray(); // Выводит: 10 20 30 0 0 40

    DynamicIntArray arr3(3);
    arr3.setValueAtIndex(0, 1);
    arr3.setValueAtIndex(1, 2);
    arr3.setValueAtIndex(2, 3);

    arr1.add(arr3);
    arr1.printArray(); // Выводит: 11 22 33 0 0 40 (сложение всех элементов)

    return 0;
}