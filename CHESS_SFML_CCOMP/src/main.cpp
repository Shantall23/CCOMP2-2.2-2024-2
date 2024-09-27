
// Función principal que ejecuta el juego

#include <iostream>
#include <SFML/Graphics.hpp>
#include "chessGame.h"
using namespace std;

int main(){
    ChessGame chess(sf::Color(235,236,208), sf::Color(128, 128, 128));

    sf::RenderWindow window(sf::VideoMode(512, 512), "AJEDREZ", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    if((0 <= event.mouseButton.x) && (event.mouseButton.x <= 512) && (0 <= event.mouseButton.y) && (event.mouseButton.y <= 512)){
                        unsigned int buttonPos{(event.mouseButton.x / 64) + ((event.mouseButton.y / 64) * 8)}; // obtiene la posición del cuadro seleccionado
                        
                        if(!chess.getSelected())
                            chess.selectPiece(buttonPos);
                        else
                            chess.moveSelected(buttonPos);
                    } else if((517 <= event.mouseButton.x) && (event.mouseButton.x <= 763) && (5 <= event.mouseButton.y) && (event.mouseButton.y <= 45)){
                        // chess.restart();
                    }
                }
            }
        }

        window.draw(chess);
        window.display();
    }
}
