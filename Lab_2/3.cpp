#include <cmath>
#include <iostream>

class ThirdClass {
    public:
        float mean, geometricMean;

        ThirdClass(float z1, float z2) : z1(z1), z2(z2) {}

        class FirstClass {
            public:
                int a, b, c;

                FirstClass() {}

                void firstInput() {
                    std::cout << "Enter a, b, c respectively: ";
                    std::cin >> a >> b >> c;
                };
        };

        class SecondClass {
            public:
                int x, y;

                void secondInput() {
                    std::cout << "Enter x, y respectively: ";
                    std::cin >> x >> y;
                }
        };

        void calculateMean(FirstClass& firstClass, SecondClass& secondClass) {
            mean = (firstClass.a + firstClass.b + firstClass.c + secondClass.x +
                    secondClass.y + z1 + z2) /
                   7;
        }

        void calculateGeometricMean(FirstClass& firstClass,
                                    SecondClass& secondClass) {
            geometricMean = pow((firstClass.a * firstClass.b * firstClass.c *
                                 secondClass.x * secondClass.y * z1 * z2),
                                (static_cast<float>(1) / 7));
        }

    private:
        float z1, z2;
};

int main(int argc, char const* argv[]) {
    ThirdClass third(2, 6);
    ThirdClass::FirstClass first;
    ThirdClass::SecondClass second;

    first.firstInput();
    second.secondInput();

    third.calculateMean(first, second);
    third.calculateGeometricMean(first, second);

    std::cout << "M: " << third.mean << " G: " << third.geometricMean << "\n";

    return 0;
}
