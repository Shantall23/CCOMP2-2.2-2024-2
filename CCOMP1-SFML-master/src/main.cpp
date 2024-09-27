#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(1720, 1080), "Juego SFML");

    sf::CircleShape player(30);
    player.setFillColor(sf::Color::Blue);
    int x = 400;
    int *x1 = &x;
    int y = 300;
    int *y1 = &y;

    sf::CircleShape enemy(30);
    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(600, 400);

    float playerSpeed = 500.0f;
    float enemySpeed = 300.0f;
    bool zKey = false;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        player.setPosition(*x1, *y1);

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z) {
                zKey = true;
                player.setRadius(60);
                playerSpeed /= 2.0f; // Reducir la velocidad a la mitad cuando se presiona Z
                enemySpeed = 50.0f;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Z) {
                zKey = false;
                player.setRadius(30);
                playerSpeed *= 2.0f; // Restaurar la velocidad original cuando se suelta Z
                enemySpeed = 300.0f;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            y -= playerSpeed * deltaTime.asSeconds();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            x -= playerSpeed * deltaTime.asSeconds();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            y += playerSpeed * deltaTime.asSeconds();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            x += playerSpeed * deltaTime.asSeconds();
        }
        

        if (x < 0) x = 0;
        if (x > 1690) x = 1690;
        if (y < 0) y = 0;
        if (y > 1050) y = 1050;

        sf::Vector2f playerPos = player.getPosition();
        sf::Vector2f enemyPos = enemy.getPosition();
        sf::Vector2f direction = playerPos - enemyPos;
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (distance > 0) {
            direction /= distance;
            enemy.move(direction * enemySpeed * deltaTime.asSeconds());
        }

        window.clear();
        window.draw(player);
        window.draw(enemy);
        window.display();
    }

    return 0;
}