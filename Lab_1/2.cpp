#include <iostream>

class FirstClass {
    public:
        double a1, b1, c1, a2, b2, c2;

        void input() {
            std::cout << "Enter a1, b1, c1, a2, b2, c2 respectively: ";
            std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        }

        class SecondClass {
            public:
                double det, detX, detY, x, y;

                void calc(FirstClass& solver) {
                    det = solver.a1 * solver.b2 - solver.a2 * solver.b1;
                    detX = solver.c1 * solver.b2 - solver.c2 * solver.b1;
                    detY = solver.a1 * solver.c2 - solver.a2 * solver.c1;
                    x = detX / det;
                    y = detY / det;
                }

                void display() {
                    std::cout << "Solution:"
                              << "\n";
                    std::cout << "  x = " << x << "\n";
                    std::cout << "  y = " << y << "\n";
                    std::cout << "  det = " << det << "\n";
                    std::cout << "  detX = " << detX << "\n";
                    std::cout << "  detY = " << detY << "\n";
                }
        };
};

int main() {
    FirstClass solver;
    solver.input();

    FirstClass::SecondClass calculator;
    calculator.calc(solver);
    calculator.display();

    return 0;
}
