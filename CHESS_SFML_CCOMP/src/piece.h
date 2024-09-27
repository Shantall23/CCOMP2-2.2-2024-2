#ifndef _PIECE_H
#define _PIECE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>
#include <string>
#include <vector>
using namespace std;

class Piece : public sf::Drawable {
public:
    // Prueba para borrar movimientos
    friend class ChessGame;


    // Constructor de la clase Piece
    Piece(char type = 'P', bool player = true, int pos = -1, bool moved = false)
    : m_type{type}, m_player{player}, m_position{-1}, m_moved{true} {}

    // Métodos SET y GET
    void setPiece(char type, bool player, int pos, bool moved = false);

    void setType(char ch) { m_type = ch; setTexture(); }
    char getType() { return m_type; }

    void setPlayer(bool bl) { m_player = bl; setTexture(); }
    bool getPlayer() { return m_player; }

    void setPosition(int pos) {
        m_position = pos; 
        move();
    }
    int getPosition() { return m_position; }

    void setMoved(bool moved) { m_moved = moved; }
    bool getMoved() { return m_moved; }

    // Métodos para calcular posibles movimientos
    std::vector<int>& getPossibleMoves() { return possibleMoves; }
    virtual void calcPiecePossibleMoves();
    int eraseMovesA(int);

    //! Prueba de borrar movimientos
    static std::array<int, 16> posiciones;
    static std::array<int, 16> bposiciones;
    static void setPosiciones(const std::array<int, 16>& new_posiciones);
    static void setPosicionesB(const std::array<int, 16>& new_posiciones);

protected:
    sf::Sprite m_sprite;
    std::vector<int> possibleMoves;

    char m_type; // 'K' = King, 'Q' = Queen, 'R' = Rook, 'B' = Bishop, 'N' = Knight, 'P' = Pawn
    bool m_player; // true == White, false == Black
    int m_position; // 0-63 tablero, -1 muerto
    bool m_moved;

    virtual void setTexture();
    void move();
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // _PIECE_H
