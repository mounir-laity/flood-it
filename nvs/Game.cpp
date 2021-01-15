#include "Game.h"

Game::Game(unsigned lines, unsigned columns, unsigned colors) : board(lines, columns, colors){
}

void Game::launch() {
    board.initialize();
}

Board& Game::getBoard() {
    return board;
}

void Game::changeColor(Color oldColor, Color newColor, Square &square) {
    unsigned line = square.getLine();
    unsigned column = square.getColumn();
    vector<vector<Square>> &array = board.getSquares();
    if(square.getColor() == oldColor) {
        square.setColor(newColor);
        if(line > 0) {
            changeColor(oldColor, newColor, array[line-1][column]);
        } if(line < array.size()-1) {
            changeColor(oldColor, newColor, array[line+1][column]);
        } if (column > 0) {
            changeColor(oldColor, newColor, array[line][column-1]);
        } if (column < array[0].size()-1) {
            changeColor(oldColor, newColor, array[line][column+1]);
        }
    }
}

void Game::modifyBoard(Color oldColor, Color newColor, Square &square) {
    changeColor(oldColor, newColor, square);
    notifyObservers();
}

bool Game::isOver() {
    unsigned lines = board.getLines();
    unsigned columns = board.getColumns();
    Color originColor = board.getSquares()[0][0].getColor();
    for(unsigned i = 0; i < board.getLines()-1; i++) {
        for(unsigned j = 0; j < board.getColumns()-1; j++) {
            if(originColor != board.getSquares()[i+1][j].getColor()) {
                return false;
            } if(originColor != board.getSquares()[i][j+1].getColor()) {
                return false;
            }
        }

    }if(originColor != board.getSquares()[lines-1][columns-1].getColor()) {
        return false;
    }
    return true;
}
