#include <iostream>
#include <string>

class Teacher {
    private:
        std::string fullName;
        std::string subject;
        int age;

    public:
        Teacher(const std::string& fio, const std::string& subject, int age)
            : fullName(fio), subject(subject), age(age) {}

        void display() {
            std::cout << "Full Name: " << fullName << "\n";
            std::cout << "Subject: " << subject << "\n";
            std::cout << "Age: " << age << " years"
                      << "\n";
        }
};

int main() {
    Teacher teacher("John Doe", "Mathematics", 35);
    teacher.display();

    return 0;
}
