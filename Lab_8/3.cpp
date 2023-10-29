#include <SFML/Graphics.hpp>
#include <iostream>

class Shape {
    public:
        virtual void Draw(sf::RenderWindow& window) = 0;
        virtual void Erase(sf::RenderWindow& window) = 0;
};

class RectangleShape : public Shape {
    private:
        int x1, y1, x2, y2;

    public:
        RectangleShape(int x1, int y1, int x2, int y2) {
            this->x1 = x1;
            this->y1 = y1;
            this->x2 = x2;
            this->y2 = y2;
        }

        void Draw(sf::RenderWindow& window) override {
            sf::RectangleShape rectangle(sf::Vector2f(x2 - x1, y2 - y1));
            rectangle.setPosition(x1, y1);
            rectangle.setFillColor(sf::Color::Transparent);
            rectangle.setOutlineThickness(2);
            rectangle.setOutlineColor(sf::Color::Red);
            window.draw(rectangle);
        }

        void Erase(sf::RenderWindow& window) override {
            sf::RectangleShape rectangle(sf::Vector2f(x2 - x1, y2 - y1));
            rectangle.setPosition(x1, y1);
            rectangle.setFillColor(sf::Color::White);
            window.draw(rectangle);
        }
};

class CircleShape : public Shape {
    private:
        int x, y, radius;
        sf::Color color;

    public:
        CircleShape(int x, int y, int radius, sf::Color color) {
            this->x = x;
            this->y = y;
            this->radius = radius;
            this->color = color;
        }

        void Draw(sf::RenderWindow& window) override {
            sf::CircleShape circle(radius);
            circle.setPosition(x - radius, y - radius);
            circle.setFillColor(sf::Color::Transparent);
            circle.setOutlineThickness(2);
            circle.setOutlineColor(color);
            window.draw(circle);
        }

        void Erase(sf::RenderWindow& window) override {
            sf::CircleShape circle(radius);
            circle.setPosition(x - radius, y - radius);
            circle.setFillColor(sf::Color::White);
            window.draw(circle);
        }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes");

    std::vector<Shape*> shapes;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                int mouseX = event.mouseButton.x;
                int mouseY = event.mouseButton.y;

                if (event.mouseButton.button == sf::Mouse::Left) {
                    Shape* circle =
                        new CircleShape(mouseX, mouseY, 30, sf::Color::Blue);
                    shapes.push_back(circle);
                } else if (event.mouseButton.button == sf::Mouse::Right) {
                    Shape* rectangle = new RectangleShape(
                        mouseX, mouseY, mouseX + 100, mouseY + 50);
                    shapes.push_back(rectangle);
                }
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    for (Shape* shape : shapes) {
                        shape->Erase(window);
                    }
                    shapes.clear();
                }
            }
        }

        window.clear();

        for (Shape* shape : shapes) {
            shape->Draw(window);
        }

        window.display();
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}