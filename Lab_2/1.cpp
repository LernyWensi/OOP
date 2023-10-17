#include <SFML/Graphics.hpp>

class MyPicture {
    public:
        int x1, y1, x2, y2, r1, r2;
        sf::RenderWindow window;

    public:
        MyPicture(int x1, int y1, int x2, int y2, int r1, int r2)
            : x1(x1), y1(y1), x2(x2), y2(y2), r1(r1), r2(r2){};

        void initGraphics() {
            window.create(sf::VideoMode(x1, y1), "MyPicture");
            window.setFramerateLimit(1);
        }

        sf::Color getRandomColor() {
            return sf::Color(rand() % 256, rand() % 256, rand() % 256, 255);
        }

        void drawNestedEllipses(int k) {
            while (window.isOpen()) {
                sf::Event event;
                while (window.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) window.close();
                }

                window.clear();

                for (int i = 1; i <= k; i++) {
                    sf::CircleShape ellipse(r1 * static_cast<float>(i) / k);
                    ellipse.setScale(1, r2 / r1);

                    ellipse.setFillColor(sf::Color::Transparent);
                    ellipse.setOutlineColor(getRandomColor());
                    ellipse.setOutlineThickness(2.0f);

                    ellipse.setPosition(x2 - ellipse.getRadius(),
                                        y2 - (static_cast<float>(r2) / k) * i);

                    window.draw(ellipse);
                }

                window.display();
            }
        }
};

int main() {
    MyPicture firstPicture(700, 700, 350, 350, 150, 300);
    MyPicture secondPicture(700, 700, 350, 350, 150, 300);

    firstPicture.initGraphics();
    firstPicture.drawNestedEllipses(10);

    secondPicture.initGraphics();
    secondPicture.drawNestedEllipses(5);

    return 0;
}
