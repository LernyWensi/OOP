#include <cmath>
#include <iostream>

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

class ThirdClass : public FirstClass, public SecondClass {
    public:
        float mean, geometricMean;

        ThirdClass(float z1, float z2) : z1(z1), z2(z2) {}

        void calculateMean() { mean = (a + b + c + x + y + z1 + z2) / 7; }

        void calculateGeometricMean() {
            geometricMean = pow((a * b * c * x * y * z1 * z2),
                                (static_cast<float>(1) / 7));
        }

    private:
        float z1, z2;
};

int main(int argc, char const* argv[]) {
    ThirdClass third(2, 6);
    third.firstInput();
    third.secondInput();
    third.calculateMean();
    third.calculateGeometricMean();

    std::cout << "M: " << third.mean << " G: " << third.geometricMean << "\n";

    return 0;
}
