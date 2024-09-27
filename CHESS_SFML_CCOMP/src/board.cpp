/*
    This code file contains member functions of board.h
*/

#include "board.h"

Board::Board(sf::Color l_col, sf::Color d_col){
    load(l_col,d_col);
}

void Board::load(sf::Color l_col, sf::Color d_col) {
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            sf::RectangleShape& escaque = matriz_tabla[j + (i * 8)];//referencia square que apunta a un elemto de tipo rectangle shape de matriz_tabla
            //usamos referencia para manipular directamente el objeto original y asi evitar la sobrecarga de copiar objetos
            escaque.setPosition(sf::Vector2f(j * 64.f, i * 64.f)); //j colum , i fil
            escaque.setSize(sf::Vector2f(64.f, 64.f));
            escaque.setFillColor(((i + j) % 2 == 0) ? l_col : d_col);
        }
    }
}

// Draw class on SFML Window
void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    for(int i=0;i<64;i++){
        target.draw(matriz_tabla[i]);
    }
}