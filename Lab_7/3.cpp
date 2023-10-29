#include <SFML/Graphics.hpp>

class BaseClass {
    public:
        BaseClass() {}
        virtual ~BaseClass() {}
        virtual void figure() = 0;
};

class FirstClass : public BaseClass {
    private:
        int x1, y1, x2, y2;

    public:
        FirstClass(int x1, int y1, int x2, int y2)
            : x1(x1), y1(y1), x2(x2), y2(y2) {}

        ~FirstClass() {}

        void figure() override {
            sf::RenderWindow window(sf::VideoMode(800, 600), "Rectangle");
            sf::RectangleShape rectangle(sf::Vector2f(x2 - x1, y2 - y1));

            rectangle.setPosition(x1, y1);
            rectangle.setFillColor(sf::Color::Blue);

            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }

                window.clear();
                window.draw(rectangle);
                window.display();
            }
        }
};

class SecondClass : public BaseClass {
    private:
        float x, y, r;

    public:
        SecondClass(float x, float y, float r) : x(x), y(y), r(r) {}

        ~SecondClass() {}

        void figure() override {
            sf::RenderWindow window(sf::VideoMode(800, 600), "Circle");
            sf::CircleShape circle(r);

            circle.setPosition(x, y);
            circle.setFillColor(sf::Color::Red);

            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                }

                window.clear();
                window.draw(circle);
                window.display();
            }
        }
};

int main() {
    const int size = 2;
    BaseClass* objects[size];

    objects[0] = new FirstClass(100, 100, 300, 200);
    objects[1] = new SecondClass(400, 300, 100);

    for (int i = 0; i < size; i++) {
        objects[i]->figure();
    }

    for (int i = 0; i < size; i++) {
        delete objects[i];
    }

    return 0;
}
