#include <iostream>
#include <string>

template <class T>
class Class {
        T* data;
        int size;
        int n;

    public:
        Class(int);
        ~Class() { delete[] data; };

        T& operator[](int i) { return data[i]; }
};

template <class T>
Class<T>::Class(int n) {
    data = new T[n];
    size = n;
}

int main() {
    int arraySize;

    std::cout << "Enter size for array: ";
    std::cin >> arraySize;

    Class<std::string> strings(arraySize);

    for (int i = 0; i < arraySize; i++) {
        std::cout << "Enter string " << i + 1 << ": ";
        std::cin >> strings[i];
    }

    std::cout << "Entered strings: ";
    for (int i = 0; i < arraySize; i++) {
        std::cout << strings[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
