#include "ClickableLabel.h"
using namespace std;

ClickableLabel::ClickableLabel(QWidget* parent, Game *game)
    : QLabel(parent), square(Square(0,0,RED)), game(game) {

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::setAttributes(Square newSquare, Game *setGame)
{
    square = newSquare;
    game = setGame;
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    Square &origin = game->getBoard().getSquares()[0][0];
    if(!square.hasSameColor(origin)) {
        game->modifyBoard(origin.getColor(), square.getColor(), origin);
        emit clicked();
    }
}




