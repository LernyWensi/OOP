#include <iostream>

class AbstractClass {
    public:
        virtual void print() = 0;
        virtual ~AbstractClass() {}
};

class FirstClass : public AbstractClass {
    private:
        int a_, b_, c_, d_;

    public:
        FirstClass(int a, int b, int c, int d) : a_(a), b_(b), c_(c), d_(d) {}

        void print() override {
            std::cout << "FirstClass fields: a = " << a_ << ", b = " << b_
                      << ", c = " << c_ << ", d = " << d_ << std::endl;
        }

        ~FirstClass() {}
};

class SecondClass : public AbstractClass {
    private:
        double x_, y_;

    public:
        SecondClass(double x, double y) : x_(x), y_(y) {}

        void print() override {
            std::cout << "SecondClass fields: x = " << x_ << ", y = " << y_
                      << std::endl;
        }

        ~SecondClass() {}
};

class ThirdClass : public AbstractClass {
    private:
        double a1_, b1_;

    public:
        ThirdClass(double a1, double b1) : a1_(a1), b1_(b1) {}

        void print() override {
            std::cout << "ThirdClass fields: a1 = " << a1_ << ", b1 = " << b1_
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
