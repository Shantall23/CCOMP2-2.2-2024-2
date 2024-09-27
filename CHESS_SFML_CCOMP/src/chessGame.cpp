// piece.h
#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>

class Piece {
protected:
    int x, y;
    std::string color;

public:
    Piece(int x, int y, std::string color) : x(x), y(y), color(color) {}
    virtual ~Piece() {}

    virtual bool move(int newX, int newY) = 0;
    virtual std::vector<std::pair<int, int>> validMoves() = 0;

    std::string getColor() const { return color; }
    std::pair<int, int> getPosition() const { return {x, y}; }

    void setPosition(int newX, int newY) {
        x = newX;
        y = newY;
    }

    // Sobrecarga del operador de igualdad
    bool operator==(const Piece& other) const {
        return x == other.x && y == other.y && color == other.color;
    }

    // Sobrecarga del operador de desigualdad
    bool operator!=(const Piece& other) const {
        return !(*this == other);
    }
};

#endif // PIECE_H
