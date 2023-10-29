#include <iostream>
#include <sstream>

class FirstClass {
    public:
        double a1, b1, c1, a2, b2, c2;

        void input() {
            std::cout << "Enter a1, b1, c1, a2, b2, c2 respectively: ";
            std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        }
};

class SecondClass : public FirstClass {
    public:
        double det, detX, detY, x, y;

        void calc() {
            det = a1 * b2 - a2 * b1;
            detX = c1 * b2 - c2 * b1;
            detY = a1 * c2 - a2 * c1;
            x = detX / det;
            y = detY / det;
        }

        void display() {
            std::cout << "Solution:"
                      << "\n";
            std::cout << "x = " << x << "\n";
            std::cout << "y = " << y << "\n";
            std::cout << "det = " << det << "\n";
            std::cout << "detX = " << detX << "\n";
            std::cout << "detY = " << detY << "\n";
        }
};

int main() {
    SecondClass calculator;
    calculator.input();
    calculator.calc();
    calculator.display();

    return 0;
}
