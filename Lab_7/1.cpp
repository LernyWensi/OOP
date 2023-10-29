#include <iostream>

class FirstClass {
    protected:
        int x, y;

    private:
        float a, b, c;

    public:
        float s1, s2;

        FirstClass(int x, int y, float a, float b, float c)
            : x(x), y(y), a(a), b(b), c(c) {}

        void sum1() { s1 = x + y; }
        void sum2() { s2 = a + b + c; }

        friend void F1(FirstClass& obj);
        friend void F2(FirstClass& obj);
};

void F1(FirstClass& obj) { obj.s1 = obj.x + obj.y; }

void F2(FirstClass& obj) { obj.s2 = obj.a + obj.b + obj.c; }

int main() {
    FirstClass first(1, 5, 1.0, 2.5, 7.4);
    FirstClass second(3, 12, 3.2, 7.5, 2.4);

    F1(first);
    F1(second);

    F2(first);
    F2(second);

    std::cout << "First object {"
              << "\n";
    std::cout << "    s1: " << first.s1 << ",\n";
    std::cout << "    s2: " << first.s2 << "\n}\n";

    std::cout << "\nSecond object {"
              << "\n";
    std::cout << "    s1: " << second.s1 << ",\n";
    std::cout << "    s2: " << second.s2 << "\n}\n";

    return 0;
}