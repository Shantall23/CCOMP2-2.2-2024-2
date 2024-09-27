#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(1720, 900), "Ejemplo de pruba del mapa");

    std::vector<std::vector<int>> limitMap;

    std::ifstream file("C:/CCOMP1-SFML-master/Assets/limit_map.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::vector<int> row;
            for (char c : line) {
                if (c == '0') {
                    row.push_back(0);
                } else if (c == '1') {
                    row.push_back(1);
                }
            }
            limitMap.push_back(row);
        }

        file.close();
    } else {
        std::cerr << "Error al abrir el archivo de límite." << std::endl;
        return 1;
    }

    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("C:/CCOMP1-SFML-master/Assets/map.png")) {
        std::cerr << "Error al cargar la imagen del mapa." << std::endl;
        return 1;
    }

    sf::Sprite mapSprite(mapTexture);
    mapSprite.setScale(static_cast<float>(window.getSize().x) / mapTexture.getSize().x, static_cast<float>(window.getSize().y) / mapTexture.getSize().y);

    const float scaleLimitX = static_cast<float>(window.getSize().x) / limitMap[0].size();
    const float scaleLimitY = static_cast<float>(window.getSize().y) / limitMap.size();

    sf::CircleShape point(10);
    point.setFillColor(sf::Color::Green);
    point.setPosition(50, 50);

    // Crear una vista
    sf::View playerView(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

    // Configurar la tasa de interpolación (ajusta según sea necesario)
    const float interpolationRate = 0.004f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Mover el punto de ejemplo
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            int nextX = static_cast<int>(point.getPosition().x + 10);
            int y = static_cast<int>(point.getPosition().y);
            if (nextX < window.getSize().x && limitMap[y / scaleLimitY][nextX / scaleLimitX] == 0) {
                point.move(1, 0);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            int nextX = static_cast<int>(point.getPosition().x - 10);
            int y = static_cast<int>(point.getPosition().y);
            if (nextX >= 0 && limitMap[y / scaleLimitY][nextX / scaleLimitX] == 0) {
                point.move(-1, 0);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            int x = static_cast<int>(point.getPosition().x);
            int nextY = static_cast<int>(point.getPosition().y + 10);
            if (nextY < window.getSize().y && limitMap[nextY / scaleLimitY][x / scaleLimitX] == 0) {
                point.move(0, 1);
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            int x = static_cast<int>(point.getPosition().x);
            int nextY = static_cast<int>(point.getPosition().y - 10);
            if (nextY >= 0 && limitMap[nextY / scaleLimitY][x / scaleLimitX] == 0) {
                point.move(0, -1);
            }
        }

        // Interpolación de la posición de la vista hacia la posición del jugador
        sf::Vector2f targetPosition = point.getPosition();
        sf::Vector2f currentPosition = playerView.getCenter();
        sf::Vector2f newPosition = currentPosition + (targetPosition - currentPosition) * interpolationRate;

        playerView.setSize(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

        playerView.setCenter(newPosition);

        // Aplicar la vista a la ventana
        window.setView(playerView);

        window.clear();
        window.draw(mapSprite);
        window.draw(point);
        window.display();
    }

    return 0;
}
