#include <iostream>

class MyFriendDemo {
    private:
        int x1, y1, x2, y2;
        char s1;

    public:
        float z, r;
        MyFriendDemo(int x1, int y1, int x2, int y2, char s1, float z, float r)
            : x1(x1), y1(y1), x2(x2), y2(y2), s1(s1), z(z), r(r) {}

        void output() {
            std::cout << "x1 = " << x1 << ", y1 = " << y1 << ", x2 = " << x2
                      << ", y2 = " << y2 << ", s1 = " << s1 << ", z = " << z
                      << ", r = " << r << "\n";
        }

        friend int sum(MyFriendDemo obj);
        friend int sub(MyFriendDemo obj);
};

int sum(MyFriendDemo object) {
    return object.x1 + object.y1 + object.x2 + object.y2 +
           static_cast<int>(object.s1);
}

int sub(MyFriendDemo object) {
    return (object.x1 + object.x2) - (object.y1 + object.y2);
}

int main() {
    MyFriendDemo firstObject(1, 2, 3, 4, 'F', 5.5, 6.6);
    MyFriendDemo secondObject(7, 8, 9, 10, 'B', 11.11, 12.12);

    firstObject.output();
    secondObject.output();

    std::cout << "Sum: " << sum(firstObject) << std::endl;
    std::cout << "Sub: " << sub(secondObject) << std::endl;

    return 0;
}
