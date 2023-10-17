#include <iostream>
#include <limits>
#include <sstream>

template <typename T>
class Array {
    private:
        T* data_;
        int size_;

    public:
        Array(int size) : size_(size), data_(new T[size]) {}

        ~Array() { delete[] data_; }

        void fillArray() {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string input;
            std::getline(std::cin, input);
            std::istringstream stream(input);
            for (int i = 0; i < size_; i++) {
                stream >> data_[i];
            }
        }

        void bubbleSort() {
            for (int i = 0; i < size_ - 1; i++) {
                for (int j = 0; j < size_ - i - 1; j++) {
                    if (data_[j] > data_[j + 1]) {
                        T temporary = data_[j];
                        data_[j] = data_[j + 1];
                        data_[j + 1] = temporary;
                    }
                }
            }
        }

        T getMin() {
            T min = data_[0];
            for (int i = 1; i < size_; i++) {
                if (data_[i] < min) {
                    min = data_[i];
                }
            }
            return min;
        }

        T getMax() {
            T max = data_[0];
            for (int i = 1; i < size_; i++) {
                if (data_[i] > max) {
                    max = data_[i];
                }
            }
            return max;
        }

        void printArray() {
            for (int i = 0; i < size_; i++) {
                std::cout << data_[i] << " ";
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
