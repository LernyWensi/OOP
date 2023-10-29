#include <cmath>
#include <iostream>

struct Roots {
        double firstRoot;
        double secondRoot;
};

class MyClass {
    private:
        int a, b, c;

    protected:
        double x, y, z;

    public:
        MyClass(int a, int b, int c, double x, double y, double z)
            : a(a), b(b), c(c), x(x), y(y), z(z) {}

        friend Roots calculateRoots(const MyClass& object);
        friend double calculateSum(const MyClass& object);
};

Roots calculateRoots(const MyClass& object) {
    Roots roots;

    double discriminant = object.b * object.b - 4 * object.a * object.c;

    if (discriminant < 0) {
        roots.firstRoot = 0;
        roots.secondRoot = 0;
    } else if (discriminant == 0) {
        roots.firstRoot = -object.b / (2 * object.a);
        roots.secondRoot = roots.firstRoot;
    } else {
        roots.firstRoot =
            (-object.b + std::sqrt(discriminant)) / (2 * object.a);
        roots.secondRoot =
            (-object.b - std::sqrt(discriminant)) / (2 * object.a);
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
