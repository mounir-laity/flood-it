#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Subject.h"

/*!
 * \brief The Game class represents the game that is being played. It implements the interface subject.
 */
class Game : public Subject {

private:
    Board board;

    /*!
     * \brief changeColor recursive function that changes the color
     *  of all the squares of the same 'patch' that the top left square
     * \param oldColor the color of the patch of squares before changing
     * \param newColor the wanted new color for that patch
     * \param square the square that needs to change color
     */
    void changeColor(Color oldColor, Color newColor, Square &square);

public:

    /*!
     * \brief Game Constructor of the game
     * \param lines the number of lines chosen for that game
     * \param columns the number of columns chosen for that game
     * \param colors the number of colors chosen for that game
     */
    Game(unsigned lines, unsigned columns, unsigned colors);

    /*!
     * \brief launch creates the board for the game to be ready to be played.
     */
    void launch();

    /*!
     * \brief getBoard getter for the board of the game
     */
    Board& getBoard();

    /*!
     * \brief modifyBoard modifies the board depending on the new color wanted for the patch and notifies its observer
     * \param oldColor the color of the patch before the color changing
     * \param newColor the new color of the patch after changing the colors
     * \param square the square that needs to change color
     */
    void modifyBoard(Color oldColor, Color newColor, Square &square);

    /*!
     * \brief isOver checks if the game is over. It is over when all the squares have the same color.
     * \return true if all the squares have the same color
     */
    bool isOver();

};
#endif // GAME_H
