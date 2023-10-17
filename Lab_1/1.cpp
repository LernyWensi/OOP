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
        double det, detX, detY, x_, y_;

        void calc() {
            det = a1 * b2 - a2 * b1;
            detX = c1 * b2 - c2 * b1;
            detY = a1 * c2 - a2 * c1;
            x_ = detX / det;
            y_ = detY / det;
        }

        void display() {
            std::cout << "Solution:"
                      << "\n";
            std::cout << "x = " << x_ << "\n";
            std::cout << "y = " << y_ << "\n";
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
