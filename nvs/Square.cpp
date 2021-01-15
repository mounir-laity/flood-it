#include "Square.h"

Square::Square(unsigned line, unsigned column, Color color) {
    this->line = line;
    this->column = column;
    this->color = color;


}
Color Square::getColor() {
    return color;
}

void Square::setColor(Color color) {
    this->color = color;
}

bool Square::hasSameColor(Square square) {
    return this->color == square.color;
}

unsigned Square::getLine() {
    return line;
}

unsigned Square::getColumn() {
    return column;
}
