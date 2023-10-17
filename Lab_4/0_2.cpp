#include <algorithm>
#include <iostream>

template <typename T>
T findMinimum(T a, T b, T c) {
    std::cout << "Current arguments: " << a << " " << b << " " << c << "\n";
    return std::min({a, b, c});
}

int main() {
    double doubleMinimum = findMinimum(3.14, 2.71, 1.618);
    std::cout << "Minumum for (double): " << doubleMinimum << "\n\n";

    int intMinumum = findMinimum(10, 5, 8);
    std::cout << "Minumum for (int): " << intMinumum << "\n\n";

    char charMinimum = findMinimum('c', 'b', 'a');
    std::cout << "Minumum for (char): " << charMinimum << "\n";

    return 0;
}
