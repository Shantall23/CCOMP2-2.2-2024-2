#include "piece.h"
#include <iostream>

// Declaraciones estáticas
std::array<int, 16> Piece::posiciones;
std::array<int, 16> Piece::bposiciones;

// Inicializa las propiedades de una pieza
void Piece::setPiece(char type, bool player, int pos, bool moved){
    setType(type);
    setPlayer(player);
    setPosition(pos);
    setMoved(moved);
}

// Mueve una pieza a una nueva posición
void Piece::move(){
    if(m_position <= -1 || 64 <= m_position){
        m_position = -1;
        m_sprite.setColor(sf::Color(0x00000000)); // Hacer transparente
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f));
        m_moved = true;
    } else {
        m_sprite.setPosition(sf::Vector2f((m_position % 8) * 64.f + 32.f, (m_position / 8) * 64.f + 32.f));
        m_moved = true;
    }
    return;
}

// Establece la textura de la pieza
void Piece::setTexture(){
    m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x/2 , m_sprite.getTexture()->getSize().y/2)); // Define el centro de la textura
    m_sprite.setScale(sf::Vector2f(0.150f, 0.150f)); // Escala la textura
}

// Dibuja la pieza en el objetivo dado
void Piece::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    target.draw(m_sprite);
}

// Calcula los posibles movimientos de la pieza (vacío por defecto)
void Piece::calcPiecePossibleMoves(){
    // Implementación vacía
}

// Establece las posiciones de las piezas blancas
void Piece::setPosiciones(const std::array<int, 16>& new_posiciones) {
    posiciones = new_posiciones;
}

// Establece las posiciones de las piezas negras
void Piece::setPosicionesB(const std::array<int, 16>& new_posiciones) {
    bposiciones = new_posiciones;
}

// Verifica y elimina los movimientos no válidos
int Piece::eraseMovesA(int pos){
    for (int j = 0; j < 16; j++) {
        if ((getPlayer() && posiciones[j] == pos) || (!getPlayer() && bposiciones[j] == pos)) {
            return 1; // Se encontró una pieza del mismo equipo
        } else if ((getPlayer() && bposiciones[j] == pos) || (!getPlayer() && posiciones[j] == pos)) {
            return 2; // Se encontró una pieza del equipo contrario
        }
    }
    return 3; // Ninguna pieza en el camino
}
