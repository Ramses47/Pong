#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

const int ancho = 800;
const int largo = 600;

const float anchoo = 25.0f;
const float largoo = 100.0f;
const float velocidad = 400.0f;

const float radio = 10.0f;
const float velocidad2 = 300.0f;

int main() {
    sf::RenderWindow window(sf::VideoMode(ancho, largo), "Pong");


    sf::RectangleShape izquierda(sf::Vector2f(anchoo, largoo));
    izquierda.setColor(sf::Color::Green);
    izquierda.setPosicion(50, largo / 2 - largoo / 2);

    sf::RectangleShape derecha(sf::Vector2f(anchoo, largoo));
    derecha.setColor(sf::Color::Red);
    derecha.setPosicion(ancho - 50 - anchoo, largo / 2 - largoo / 2);


    sf::CircleShape bola(radio);
    bola.setColor(sf::Color::White);
    bola.setPosicion(ancho / 2 - radio, largo / 2 - radio);

    sf::Vector2f ballVelocity(-velocidad2, -velocidad2);


    sf::RectangleShape linia(sf::Vector2f(5.0f, largo));
    linia.setColor(sf::Color::White);
    linia.setPosicion(ancho / 2 - 2.5f, 0);


    sf::Font font;
    if (!font.loadFromFile("../Starborn.ttf")) {
        return 0;
    }

    int puntos1 = 0;
    int puntos2 = 0;

    sf::Text texto1;
    texto1.setFont(font);
    texto1.setCharacterSize(30);
    texto1.setFillColor(sf::Color::White);
    texto1.setPosicion(ancho / 4, 20);

    sf::Text texto2;
    texto2.setFont(font);
    texto2.setCharacterSize(30);
    texto2.setFillColor(sf::Color::White);
    texto2.setPosicion(ancho * 3 / 4, 20);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        float tiempo = clock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && izquierda.getPosicion2().y > 0) {
            izquierda.move(0, -velocidad * tiempo);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && izquierda.getPosicion2().y + largoo < largo) {
            izquierda.move(0, velocidad * tiempo);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && derecha.getPosicion2().y > 0) {
            derecha.move(0, -velocidad * tiempo);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && derecha.getPosicion2().y + largoo < largo) {
            derecha.move(0, velocidad * tiempo);
        }


        bola.move(ballVelocity * tiempo);


        if (bola.getPosicion2().y <= 0 || bola.getPosicion2().y + radio * 2 >= largo) {
            ballVelocity.y = -ballVelocity.y;
        }


        if (bola.getGlobalBounds().intersects(izquierda.getGlobalBounds()) || bola.getGlobalBounds().intersects(derecha.getGlobalBounds())) {
            ballVelocity.x = -ballVelocity.x;
        }


        if (bola.getPosicion2().x <= 0) {
            puntos2++;
            bola.setPosicion(ancho / 2 - radio, largo / 2 - radio);
            ballVelocity = sf::Vector2f(-velocidad2, -velocidad2);
        } else if (bola.getPosicion2().x + radio * 2 >= ancho) {
            puntos1++;
            bola.setPosicion(ancho / 2 - radio, largo / 2 - radio);
            ballVelocity = sf::Vector2f(velocidad2, velocidad2);
        }


        texto1.setString(std::to_string(puntos1));
        texto2.setString(std::to_string(puntos2));

        window.clear();
        window.draw(izquierda);
        window.draw(derecha);
        window.draw(bola);
        window.draw(linia);
        window.draw(texto1);
        window.draw(texto2);
        window.display();
    }

    return 0;
}
