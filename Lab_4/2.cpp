#include <iostream>

class Base {
    protected:
        int baseInt;
        char baseChar;

    public:
        Base(int baseInt, char baseChar)
            : baseInt(baseInt), baseChar(baseChar) {}

        virtual void display() {
            std::cout << "Base class: " << baseInt << ", " << baseChar << "\n";
        }
};

class Derived : public Base {
    private:
        double derivedDouble_;
        char derivedChar_;

    public:
        Derived(int baseInt, char baseChar, double derivedDouble,
                char derivedChar)
            : Base(baseInt, baseChar),
              derivedDouble_(derivedDouble),
              derivedChar_(derivedChar) {}

        void display() override {
            std::cout << "Derived class: " << Base::baseInt << ", "
                      << Base::baseChar << ", " << derivedDouble_ << ", "
                      << derivedChar_ << "\n";
        }
};

int main() {
    Base baseObject(10, 'Y');
    Derived derivedObject(20, 'K', 30, 'L');

    Base* basePointer = &baseObject;
    Derived* derivedPointer = &derivedObject;

    basePointer->display();
    derivedPointer->display();

    return 0;
}
