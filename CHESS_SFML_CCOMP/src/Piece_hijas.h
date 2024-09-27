// piece_hijas.h

#ifndef _PIECE_HIJAS_H
#define _PIECE_HIJAS_H

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include "piece.h"
#include "board.h"
#include "chessGame.h"

using namespace std;

// Clase para la pieza Rey
class PKing : public Piece {
public:
    PKing(bool player, int pos) : Piece('K', player, pos) {
        setPiece('K', player, pos, false);
    }

    // Sobrescribe setTexture
    void setTexture() override;
    void calcPiecePossibleMoves();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  
    }
};

// Clase para la pieza Reina
class PQueen : public Piece {
public:
    PQueen(bool player, int pos) : Piece('Q', player, pos) {
        setPiece('Q', player, pos, false);
    }

    // Sobrescribe setTexture
    void setTexture()override;
    void calcPiecePossibleMoves();
    int eraseMoves(int);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  
    }
};

// Clase para la pieza Torre
class PRook : public Piece {
public:
    PRook(bool player, int pos) : Piece('R', player, pos) {
        setPiece('R', player, pos, false);
    }

    // Sobrescribe setTexture
    void setTexture()override;
    void calcPiecePossibleMoves();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  
    }
};

// Clase para la pieza Alfil
class PBishop : public Piece {
public:
    PBishop(bool player, int pos) : Piece('B', player, pos) {
        setPiece('B', player, pos, false);
    }

    // Sobrescribe setTexture
    void setTexture()override;
    int eraseMoves(int);
    void calcPiecePossibleMoves();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  
    }
};

// Clase para la pieza Caballo
class PKnight : public Piece {
public:
    PKnight(bool player, int pos) : Piece('N', player, pos) {
        setPiece('N', player, pos, false);
    }

    // Sobrescribe setTexture
    void setTexture()override;
    void calcPiecePossibleMoves();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        target.draw(m_sprite);  
    }
};

// Clase para la pieza Peón
class PPawn : public Piece {
private:
    bool firstMove;

public:
    PPawn(bool player, int pos) : Piece('P', player, pos) {
        setPiece('P', player, pos, false);
    }

    // Verifica si es el primer movimiento
    bool hasFirstMove() const { return firstMove; }
    void setFirstMove(bool value) { firstMove = value; }

    // Sobrescribe setTexture
    void setTexture()override;
    void calcPiecePossibleMoves();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(m_sprite);
    }
};

#endif // _PIECE_HIJAS_H
