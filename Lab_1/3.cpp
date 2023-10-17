#include <iostream>
#include <string>

class Teacher {
    private:
        std::string fullName_;
        std::string subject_;
        int age_;

    public:
        Teacher(const std::string& fio, const std::string& subject, int age)
            : fullName_(fio), subject_(subject), age_(age) {}

        void display() {
            std::cout << "Full Name: " << fullName_ << "\n";
            std::cout << "Subject: " << subject_ << "\n";
            std::cout << "Age: " << age_ << " years"
                      << "\n";
        }
};

int main() {
    Teacher teacher("John Doe", "Mathematics", 35);
    teacher.display();

    return 0;
}
