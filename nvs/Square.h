#ifndef SQUARE_H
#define SQUARE_H

#include "Color.h"

/*!
 * \brief The Square class represents the square composing the board of the game
 */
class Square {
private:
    unsigned line;
    unsigned column;
    Color color;

public:

    /*!
     * \brief Square constructor for the square
     * \param line the line of the square
     * \param column the column of the square
     * \param color the color of the square
     */
    Square(unsigned line, unsigned column, Color color);

    /*!
     * \brief getColor getter for the color of the square
     */
    Color getColor();

    /*!
     * \brief setColor setter for the color of the square
     * \param color the new color for the square
     */
    void setColor(Color color);

    /*!
     * \brief hasSameColor checks if two squares have the same color
     * \param square the second square to check the color to
     * \return true if both squares have the same color
     */
    bool hasSameColor(Square square);

    /*!
     * \brief getLine getter of the line of the square
     */
    unsigned getLine();

    /*!
     * \brief getColumn getter of the column of the square
     */
    unsigned getColumn();

};

#endif
