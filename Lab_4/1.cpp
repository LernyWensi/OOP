#include <iostream>
#include <limits>
#include <sstream>

template <typename T>
class Array {
    private:
        T* data;
        int size;

    public:
        Array(int size) : size(size), data(new T[size]) {}

        ~Array() { delete[] data; }

        void fillArray() {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string input;
            std::getline(std::cin, input);
            std::istringstream stream(input);
            for (int i = 0; i < size; i++) {
                stream >> data[i];
            }
        }

        void bubbleSort() {
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (data[j] > data[j + 1]) {
                        T temporary = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temporary;
                    }
                }
            }
        }

        T getMin() {
            T min = data[0];
            for (int i = 1; i < size; i++) {
                if (data[i] < min) {
                    min = data[i];
                }
            }
            return min;
        }

        T getMax() {
            T max = data[0];
            for (int i = 1; i < size; i++) {
                if (data[i] > max) {
                    max = data[i];
                }
            }
            return max;
        }

        void printArray() {
            for (int i = 0; i < size; i++) {
                std::cout << data[i] << " ";
            }
            std::cout << "\n";
        }
};

int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    //     Array<int> intArray(size);
    //     std::cout << "Fill array with integers: ";

    Array<float> intArray(size);
    std::cout << "Fill array with floats: ";

    // Array<char> intArray(size);
    // std::cout << "Fill array with chars: ";

    intArray.fillArray();

    std::cout << "Initial array: ";
    intArray.printArray();

    intArray.bubbleSort();
    std::cout << "Sorted array: ";
    intArray.printArray();

    std::cout << "Minimum: " << intArray.getMin() << "\n";
    std::cout << "Maximum: " << intArray.getMax() << "\n";

    return 0;
}
