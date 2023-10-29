#include <iostream>

class Base {
    private:
        int basePrivateData;

    public:
        int basePublicData;

        Base(int basePrivateData) : basePrivateData(basePrivateData) {}

        void input() {
            std::cout << "Enter value for Base class: ";
            std::cin >> basePublicData;
        }

        void display() {
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

        void input() {
            Base::input();
            std::cout << "Enter value for FirstDerived class: ";
            std::cin >> firstPublicData;
        }

        void display() {
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

        void input() {
            Base::input();
            std::cout << "Enter value for SecondDerived class: ";
            std::cin >> secondPublicData;
        }

        void display() {
            Base::display();
            std::cout << "Value of secondPublicData: " << secondPublicData
                      << "\n"
                      << "Value of secondPrivateData: " << secondPrivateData
                      << "\n";
        }
};

int main() {
    Base base(1);
    FirstDerived first(2, 20);
    SecondDerived second(3, 30);

    base.input();
    base.display();

    std::cout << "\n";

    first.input();
    first.display();

    std::cout << "\n";

    second.input();
    second.display();

    return 0;
}
