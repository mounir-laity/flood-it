#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <windows.h>
#include "Game.h"

/*!
 * \brief The ClickableLabel class represents the tiles that can be clicked on
 */
class ClickableLabel : public QLabel {
    Q_OBJECT

public:

    /*!
     * \brief ClickableLabel constructor for the clickable label
     * \param parent the parent widget
     * \param game the game affected by the label
     */
    ClickableLabel(QWidget* parent = Q_NULLPTR, Game *game = nullptr);
    /*!
     * \brief ~ClickableLabel destructor for the clickable label
     */
    ~ClickableLabel() override;

    /*!
     * \brief setAttributes sets the attributes of the clickable label to the given parameters
     * \param square the new square of ClickableLabel
     * \param game the new game for ClickableLabel
     */
    void setAttributes(Square square, Game* game);

private:
    Square square;
    Game *game;

signals:
    /*!
     * \brief clicked emitted signal when clicked
     */
    void clicked();

protected:
    /*!
     * \brief mousePressEvent event handler when a mouse button is pressed
     * \param event the event to handle
     */
    void mousePressEvent(QMouseEvent* event) override;

};

#endif // CLICKABLELABEL_H
