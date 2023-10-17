#include <iostream>

class MyFriendDemo {
    private:
        int x1_, y1_, x2_, y2_;
        char s1_;

    public:
        float z, r;
        MyFriendDemo(int x1, int y1, int x2, int y2, char s1, float z, float r)
            : x1_(x1), y1_(y1), x2_(x2), y2_(y2), s1_(s1), z(z), r(r) {}

        void output() {
            std::cout << "x1 = " << x1_ << ", y1 = " << y1_ << ", x2 = " << x2_
                      << ", y2 = " << y2_ << ", s1 = " << s1_ << ", z = " << z
                      << ", r = " << r << "\n";
        }

        friend int sum(MyFriendDemo obj);
        friend int sub(MyFriendDemo obj);
};

int sum(MyFriendDemo object) {
    return object.x1_ + object.y1_ + object.x2_ + object.y2_ +
           static_cast<int>(object.s1_);
}

int sub(MyFriendDemo object) {
    return (object.x1_ + object.x2_) - (object.y1_ + object.y2_);
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
