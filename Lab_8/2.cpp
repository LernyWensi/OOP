#include <iostream>

class Base {
    private:
        int basePrivateData;

    public:
        int basePublicData;

        Base(int basePrivateData) : basePrivateData(basePrivateData) {}

        virtual void input() {
            std::cout << "Enter value for Base class: ";
            std::cin >> basePublicData;
        }

        virtual void display() {
            std::cout << "Value of basePublicData: " << basePublicData << "\n"
                      << "Value of basePrivateData: " << basePrivateData
                      << "\n";
        }
};

class FirstDerived : public Base {
    private:
        int firstPrivateData;

    public:
        int firstPublicData;

        FirstDerived(int basePrivateData, int firstPrivateData)
            : firstPrivateData(firstPrivateData), Base(basePrivateData) {}

        void input() override {
            Base::input();
            std::cout << "Enter value for FirstDerived class: ";
            std::cin >> firstPublicData;
        }

        void display() override {
            Base::display();
            std::cout << "Value of firstPublicData: " << firstPublicData << "\n"
                      << "Value of firstPrivateData: " << firstPrivateData
                      << "\n";
        }
};

class SecondDerived : public Base {
    private:
        int secondPrivateData;

    public:
        int secondPublicData;

        SecondDerived(int basePrivateData, int secondPrivateData)
            : secondPrivateData(secondPrivateData), Base(basePrivateData) {}

        void input() override {
            Base::input();
            std::cout << "Enter value for SecondDerived class: ";
            std::cin >> secondPublicData;
        }

        void display() override {
            Base::display();
            std::cout << "Value of secondPublicData: " << secondPublicData
                      << "\n"
                      << "Value of secondPrivateData: " << secondPrivateData
                      << "\n";
        }
};

int main() {
    Base *base = new Base(1);
    FirstDerived *first = new FirstDerived(2, 20);
    SecondDerived *second = new SecondDerived(3, 30);

    base->input();
    base->display();

    std::cout << "\n";

    first->input();
    first->display();

    std::cout << "\n";

    second->input();
    second->display();

    delete base;
    delete first;
    delete second;

    return 0;
}
