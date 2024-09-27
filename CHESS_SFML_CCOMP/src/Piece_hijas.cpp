#include "piece_hijas.h"
#include "pieceTextures.h"
#include "chessGame.h"


// Rey: Calcula los posibles movimientos y establece la textura
void PKing::setTexture() {
    m_sprite.setTexture(m_player ? PieceTextures::whiteKing : PieceTextures::blackKing);
    Piece::setTexture();
}

void PKing::calcPiecePossibleMoves(){
    int piecePos{getPosition()};
    getPossibleMoves().clear();

    if((piecePos / 8) != 0){
        getPossibleMoves().push_back(piecePos - 8);
        if((piecePos % 8) != 0)
            getPossibleMoves().push_back(piecePos - 9);
        if((piecePos % 8) != 7)
            getPossibleMoves().push_back(piecePos - 7);
    }
    if((piecePos / 8) != 7){
        getPossibleMoves().push_back(piecePos + 8);
        if((piecePos % 8) != 0)
            getPossibleMoves().push_back(piecePos + 7);
        if((piecePos % 8) != 7)
            getPossibleMoves().push_back(piecePos + 9);
    }
    if((piecePos % 8) != 0)
        getPossibleMoves().push_back(piecePos - 1);
    if((piecePos % 8) != 7)
        getPossibleMoves().push_back(piecePos + 1);
}


// Reina: Calcula los posibles movimientos y establece la textura
void PQueen::setTexture() {
    m_sprite.setTexture(m_player ? PieceTextures::whiteQueen : PieceTextures::blackQueen);
    Piece::setTexture();
}

void PQueen::calcPiecePossibleMoves(){
    int piecePos{getPosition()};
    getPossibleMoves().clear();
    
    // Calcula para caminos de arriba
    for (int i = 1; (piecePos / 8 - i) >= 0; ++i) {
        int newPos = piecePos - 8 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }
    
    // Calcula para caminos diagonales hacia arriba a la izquierda
    for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
        int newPos = piecePos - 9 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }
    // Calcula para caminos diagonales hacia arriba a la derecha
    for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
        int newPos = piecePos - 7 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }

    // Calcula para caminos de abajo
    for (int i = 1; (piecePos / 8 + i) <= 7; ++i) {
        int newPos = piecePos + 8 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }
    // Calcula para caminos diagonales hacia abajo a la izquierda
    for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
        int newPos = piecePos + 7 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }
    // Calcula para caminos diagonales hacia abajo a la derecha
    for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
        int newPos = piecePos + 9 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }

    // Calcula para los costados
    for (int dir = -1; dir <= 1; dir += 2) {
        for (int i = 1; (piecePos % 8 + dir * i) >= 0 && (piecePos % 8 + dir * i) <= 7; ++i) {
            int newPos = piecePos + dir * i;
            int eraseResult = eraseMovesA(newPos);
            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);
                if (eraseResult == 2) {
                    break;
                }
            } else if (eraseResult == 1) {
                break;
            }
        }
    }
}


// Torre: Calcula los posibles movimientos y establece la textura
void PRook::setTexture() {
    m_sprite.setTexture(m_player ? PieceTextures::whiteRook : PieceTextures::blackRook);
    Piece::setTexture();
}

void PRook::calcPiecePossibleMoves(){
    int piecePos{getPosition()};
    getPossibleMoves().clear();
    
    // Calcula para caminos de arriba
    for (int i = 1;(piecePos / 8 - i) >= 0; ++i) {
        int newPos = piecePos - 8 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }
    // Calcula para caminos de abajo
    for (int i = 1; (piecePos / 8 + i) <= 7; ++i) {
        int newPos = piecePos + 8 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }
    // Calcula para los costados
    for (int dir = -1; dir <= 1; dir += 2) {
        for (int i = 1; (piecePos % 8 + dir * i) >= 0 && (piecePos % 8 + dir * i) <= 7; ++i) {
            int newPos = piecePos + dir * i;
            int eraseResult = eraseMovesA(newPos);
            if (eraseResult == 3 || eraseResult == 2) {
                getPossibleMoves().push_back(newPos);
                if (eraseResult == 2) {
                    break;
                }
            } else if (eraseResult == 1) {
                break;
            }
        }
    }
}


// Alfil: Calcula los posibles movimientos y establece la textura
void PBishop::setTexture() {
    m_sprite.setTexture(m_player ? PieceTextures::whiteBishop : PieceTextures::blackBishop);
    Piece::setTexture();
}

void PBishop::calcPiecePossibleMoves(){
    int piecePos{getPosition()};
    getPossibleMoves().clear();
    
    // Calcula para caminos diagonales hacia arriba a la derecha
    for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
        int newPos = piecePos - 7 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }
    // Calcula para caminos diagonales hacia arriba a la izquierda
    for (int i = 1; (piecePos / 8 - i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
        int newPos = piecePos - 9 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }
    // Calcula para caminos diagonales hacia abajo a la izquierda
    for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 - i) >= 0; ++i) {
        int newPos = piecePos + 7 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }
    // Calcula para caminos diagonales hacia abajo a la derecha
    for (int i = 1; (piecePos / 8 + i) >= 0 && (piecePos % 8 + i) <= 7; ++i) {
        int newPos = piecePos + 9 * i;
        int eraseResult = eraseMovesA(newPos);
        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
            if (eraseResult == 2) {
                break;
            }
        } else if (eraseResult == 1) {
            break;
        }
    }
}

// Caballo: Calcula los posibles movimientos y establece la textura
void PKnight::setTexture() {
    m_sprite.setTexture(m_player ? PieceTextures::whiteKnight : PieceTextures::blackKnight);
    Piece::setTexture();
}

void PKnight::calcPiecePossibleMoves(){
    int piecePos{getPosition()};
    getPossibleMoves().clear();

    if((piecePos / 8) != 0 ){
        if((piecePos % 8) >= 2 ){
            getPossibleMoves().push_back(piecePos - 10);}
        if( (piecePos % 8) <= 5 ){
            getPossibleMoves().push_back(piecePos - 6);}
        if((piecePos / 8) != 1){
            if((piecePos % 8) >= 1 ){
                getPossibleMoves().push_back(piecePos - 17);}
            if((piecePos % 8) <= 6 ){
                getPossibleMoves().push_back(piecePos - 15);}
        }
    }
    if((piecePos / 8) != 7){
        if((piecePos % 8) >= 2 ){
            getPossibleMoves().push_back(piecePos + 6);}
        if( (piecePos % 8) <= 5 ){
            getPossibleMoves().push_back(piecePos + 10);}
        if((piecePos / 8) != 6){
            if((piecePos % 8) >= 1 ){
                getPossibleMoves().push_back(piecePos + 15);}
            if((piecePos % 8) <= 6 ){
                getPossibleMoves().push_back(piecePos + 17);}
        }
    }
}


// Peón: Calcula los posibles movimientos y establece la textura
void PPawn::setTexture() {
    m_sprite.setTexture(m_player ? PieceTextures::whitePawn : PieceTextures::blackPawn);
    Piece::setTexture();
}

void PPawn::calcPiecePossibleMoves() {
    int piecePos{getPosition()};
    getPossibleMoves().clear();

    int newPos = piecePos-8;
    int eraseResult = eraseMovesA(newPos);

    if (m_player) {
        if (firstMove) {
            for (int i = 0; i <= 2; ++i) {
                getPossibleMoves().push_back(piecePos - 8 * i);
            }
            setFirstMove(false);
        }

        if (eraseResult == 3 || eraseResult == 2) {
            getPossibleMoves().push_back(newPos);
        } 
        
    }
    else{
        getPossibleMoves().push_back(piecePos+8);
     }
}
