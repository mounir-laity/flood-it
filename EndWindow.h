#ifndef ENDWINDOW_H
#define ENDWINDOW_H

#include <QDialog>
#include <QIcon>
#include "ui_EndWindow.h"


namespace Ui {
class EndWindow;
}
/*!
 *\brief EndWindow represents the window that appears when the game is over or
 *  when the user clicks on the abandon button
 */
class EndWindow : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief EndWindow constructor for the EndWindow
     * \param parent the parent widget
     * \param abandonned indicates if the game has been abandonned or not
     * \param turns the number of turns needed to finish the game
     */
    explicit EndWindow(QWidget *parent = nullptr, bool abandonned = false, unsigned turns = 0, int record = 9999);

    /*!
     *\brief ~EndWindow destructor for EndWindow
     */
    ~EndWindow();

private:
    bool abandonned;
    Ui::EndWindow *ui;
};

#endif // ENDWINDOW_H
