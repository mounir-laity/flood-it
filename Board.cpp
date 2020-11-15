#include "Board.h"

using namespace std;

Board::Board(unsigned lines, unsigned columns, unsigned colors) {
    this->lines = lines;
    this->columns = columns;
    this->colors = colors;
    this->squares = vector<vector<Square>>(lines);
}

void Board::initialize() {
    srand ( time(NULL) );
    for(unsigned i =0; i < lines; i++) {
        vector<Square> temp;
        for(unsigned j = 0; j < columns; j++) {
            temp.push_back((Square(i,j, chooseColor())));
        }
        squares.at(i) = temp;
    }
}

/*
void Board::printBoard() {
    for(unsigned i = 0; i < line; i++) {
        for(unsigned j = 0; j < column; j++) {
            Color col = squares[i][j].getColor();
            if(col == RED) {
                cout << "R";
            } else if(col == BLUE) {
                cout << "B";
            } else if(col == CYAN) {
                cout << "C";
            } else if(col == PINK) {
                cout << "P";
            } else if(col == GREEN) {
                cout << "G";
            } else if(col == PURPLE) {
                cout << "U";
            }else if(col == YELLOW) {
                cout << "Y";
            } else {
                cout << "O";
            }
        }
        cout << "\n" << endl;
    }
}
*/
Color Board::chooseColor() {
    Color color = static_cast<Color>(rand()%(colors));
    return color;
}

unsigned Board::getLines() {
    return lines;
}

unsigned Board::getColumns() {
    return columns;
}

vector<vector<Square>>& Board::getSquares() {
    return squares;
}

