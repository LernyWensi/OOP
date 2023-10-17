#include <cmath>
#include <iostream>

struct Roots {
        double firstRoot;
        double secondRoot;
};

class MyClass {
    private:
        int a_, b_, c_;

    protected:
        double x, y, z;

    public:
        MyClass(int a, int b, int c, double x, double y, double z)
            : a_(a), b_(b), c_(c), x(x), y(y), z(z) {}

        friend Roots calculateRoots(const MyClass& object);
        friend double calculateSum(const MyClass& object);
};

Roots calculateRoots(const MyClass& object) {
    Roots roots;

    double discriminant = object.b_ * object.b_ - 4 * object.a_ * object.c_;

    if (discriminant < 0) {
        roots.firstRoot = 0;
        roots.secondRoot = 0;
    } else if (discriminant == 0) {
        roots.firstRoot = -object.b_ / (2 * object.a_);
        roots.secondRoot = roots.firstRoot;
    } else {
        roots.firstRoot =
            (-object.b_ + std::sqrt(discriminant)) / (2 * object.a_);
        roots.secondRoot =
            (-object.b_ - std::sqrt(discriminant)) / (2 * object.a_);
    }

    return roots;
}

double calculateSum(const MyClass& object) {
    return std::abs(object.x) + std::abs(object.y) + std::abs(object.z);
}

int main() {
    MyClass object(1, 3, -4, -5.0, 6.75, 7.5);

    Roots roots = calculateRoots(object);
    double sum = calculateSum(object);

    std::cout << "Root 1: " << roots.firstRoot << "\n";
    std::cout << "Root 2: " << roots.secondRoot << "\n\n";
    std::cout << "Sum of absolute values of x, y, z: " << sum << "\n";

    return 0;
}
