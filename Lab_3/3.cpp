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

        friend int Sum(MyFriendDemo obj);
        friend int Sub(MyFriendDemo obj);
};

int Sum(MyFriendDemo obj) {
    return obj.x1_ + obj.y1_ + obj.x2_ + obj.y2_ + static_cast<int>(obj.s1_);
}

int Sub(MyFriendDemo obj) { return (obj.x1_ + obj.x2_) - (obj.y1_ + obj.y2_); }

int main() {
    MyFriendDemo obj1(1, 2, 3, 4, 'F', 5.5, 6.6);
    MyFriendDemo obj2(7, 8, 9, 10, 'B', 11.11, 12.12);

    obj1.output();
    obj2.output();

    std::cout << "Sum: " << Sum(obj1) << std::endl;
    std::cout << "Sub: " << Sub(obj2) << std::endl;

    return 0;
}
