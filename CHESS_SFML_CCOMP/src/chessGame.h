#ifndef CHESSGAME_H
#define CHESSGAME_H

#include <SFML/Graphics.hpp>
#include "board.h"
#include "piece.h"
#include "Piece_hijas.h"
#include <array>
#include <vector>
#include <string>

// Clase que representa el juego de ajedrez
class ChessGame : public sf::Drawable {
public:
    // Constructor que inicializa el tablero con los colores dados
    ChessGame(sf::Color bordL_col, sf::Color bordD_col);

    // Reinicia el juego a su estado inicial
    void restart();

    // Selecciona una pieza en una posición dada
    bool selectPiece(int pos);

    // Mueve la pieza seleccionada a una nueva posición
    void moveSelected(int pos);

    // Devuelve si hay una pieza seleccionada
    bool getSelected() const { return selected; }

    // Calcula los movimientos posibles para todas las piezas
    void calcPossibleMoves();

    // Obtiene las posiciones de las piezas blancas
    std::array<int, 16> getPosicionesWhitePieces();

    // Obtiene las posiciones de las piezas negras
    std::array<int, 16> getPosicionesBlackPieces();

private:
    // Dibuja el estado actual del juego
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    // Crea las posibles casillas de movimiento para la pieza seleccionada
    void createMovesSquares();

    // Crea el cuadro de selección alrededor de la pieza seleccionada
    void createSelectSquare();

    // Actualiza la información del turno, situación, y último movimiento
    void updateInfo();

    Board board; // El tablero de ajedrez
    Piece* selectedPiece; // Puntero a la pieza seleccionada
    bool selected; // Indica si hay una pieza seleccionada
    bool playerTurn; // Indica de quién es el turno
    bool playerTurnCheck; // Indica si el rey del jugador está en jaque
    bool mate; // Indica si hay jaque mate
    int turn; // Contador de turnos

    // Arreglos de piezas blancas y negras
    Piece* whitePieces[16];
    Piece* blackPieces[16];

    // Recursos gráficos
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::RectangleShape infoRestart;
    sf::Text textRestart;
    sf::Text textTurn;
    sf::Text textSituation;
    sf::Text textLastMove;
    sf::RectangleShape selectionBorder;
    std::vector<sf::RectangleShape> possibleMovesSquares;
    std::string lastMove; // Último movimiento realizado
};

#endif // CHESSGAME_H
