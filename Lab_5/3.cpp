#include <iostream>

class AbstractClass {
    public:
        virtual void print() = 0;
        virtual ~AbstractClass() {}
};

class FirstClass : public AbstractClass {
    private:
        int a, b, c, d;

    public:
        FirstClass(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}

        void print() override {
            std::cout << "FirstClass fields: a = " << a << ", b = " << b
                      << ", c = " << c << ", d = " << d << std::endl;
        }

        ~FirstClass() {}
};

class SecondClass : public AbstractClass {
    private:
        double x, y;

    public:
        SecondClass(double x, double y) : x(x), y(y) {}

        void print() override {
            std::cout << "SecondClass fields: x = " << x << ", y = " << y
                      << std::endl;
        }

        ~SecondClass() {}
};

class ThirdClass : public AbstractClass {
    private:
        double a1, b1;

    public:
        ThirdClass(double a1, double b1) : a1(a1), b1(b1) {}

        void print() override {
            std::cout << "ThirdClass fields: a1 = " << a1 << ", b1 = " << b1
                      << std::endl;
        }

        ~ThirdClass() {}
};

int main() {
    FirstClass firstObject(10, 52, 34, 1);
    SecondClass secondObject(3.9, 4.3);
    ThirdClass thirdObject(1.14, 9.11);

    AbstractClass* firstPointer = &firstObject;
    AbstractClass* secondPointer = &secondObject;
    AbstractClass* thirdPointer = &thirdObject;

    firstPointer->print();
    secondPointer->print();
    thirdPointer->print();

    return 0;
}
