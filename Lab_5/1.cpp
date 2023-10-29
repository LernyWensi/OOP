#include <iostream>

class Base {
    protected:
        int baseInt;
        char baseChar;

    public:
        Base(int baseInt, char baseChar)
            : baseInt(baseInt), baseChar(baseChar) {}

        void display() {
            std::cout << "Base class: " << baseInt << ", " << baseChar << "\n";
        }
};

class Derived : public Base {
    private:
        double derivedDouble;
        char derivedChar;

    public:
        Derived(int baseInt, char baseChar, double derivedDouble,
                char derivedChar)
            : Base(baseInt, baseChar),
              derivedDouble(derivedDouble),
              derivedChar(derivedChar) {}

        void display() {
            std::cout << "Derived class: " << Base::baseInt << ", "
                      << Base::baseChar << ", " << derivedDouble << ", "
                      << derivedChar << "\n";
        }
};

int main() {
    Base baseObject(10, 'Y');
    Derived derivedObject(20, 'K', 30, 'L');

    baseObject.display();
    derivedObject.display();

    return 0;
}
