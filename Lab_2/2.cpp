#include <cmath>
#include <iostream>

class FirstClass {
    public:
        int a_, b_, c_;

        FirstClass() {}

        void firstInput() {
            std::cout << "Enter a, b, c respectively: ";
            std::cin >> a_ >> b_ >> c_;
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

        ThirdClass(float z1, float z2) : z1_(z1), z2_(z2) {}

        void calculateMean() { mean = (a_ + b_ + c_ + x + y + z1_ + z2_) / 7; }

        void calculateGeometricMean() {
            geometricMean = pow((a_ * b_ * c_ * x * y * z1_ * z2_),
                                (static_cast<float>(1) / 7));
        }

    private:
        float z1_, z2_;
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
