#ifndef BOARD_H
#define BOARD_H

#include <math.h>
#include <time.h>
#include <vector>
#include "Square.h"


using namespace std;

/*!
 * \brief The Board class represents the board of colored squares
 */
class Board
{

public:

    /*!
     * \brief Board constructor of the board class
     * \param line the number of lines of the board
     * \param column the number of columns of the board
     * \param colors colors the number of colors of the board
     */
    Board(unsigned line, unsigned column, unsigned colors);

    /*!
     * \brief initialize creates a board linesxcolumns size with squares of random colors
     */
    void initialize();

    /*!
     * \brief getLines getter for the number of lines of the board
     */
    unsigned getLines();

    /*!
     * \brief getColumns getter for the number of columns of the board
     */
    unsigned getColumns();

    /*!
     * \brief getSquares getter for the array containing the squares
     */
    vector<vector<Square>>& getSquares();

private:
    unsigned lines;
    unsigned columns;
    unsigned colors;
    vector<vector<Square>> squares;

    /*!
     * \brief chooseColor selects a random color from the enum colors
     * \return the randomly selected color
     */
    Color chooseColor();


};
#endif // BOARD_H
