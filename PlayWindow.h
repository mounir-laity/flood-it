#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <fstream>
#include "ClickableLabel.h"
#include "ui_PlayWindow.h"
#include "Observer.h"
#include "EndWindow.h"
#include "Filehandler.h"

namespace Ui {
class PlayWindow;
}

/**
 * @brief The PlayWindow class represents the window that displays the game while it's playing
 */
class PlayWindow : public QDialog, public Observer
{
    Q_OBJECT

public:

    /**
     * @brief PlayWindow constructor for the window displayed while playing the game
     * @param parent the parent widget
     * @param lines the number of lines wanted by the user
     * @param columns the number of columns wanted by the user
     * @param colors the number of colors wanted by the user
     */
    explicit PlayWindow(QWidget *parent = nullptr, unsigned lines = 3, unsigned columns = 3, unsigned colors = 3);

    /**
     * @brief ~PlayWindow destructor of PlayWindow
     */
    ~PlayWindow() override;



    /**
     * @brief update updates the view when notified by the subject
     * @param subject the subject that notifies
     */
    virtual void update(const Subject * subject) override;

    /**
     * @brief displayBoard displays the board with the colored squares
     */
    void displayBoard();

private slots:

    /**
     * @brief on_Abandon_clicked handler when the button abandon is clicked
     */
    void on_Abandon_clicked();

private:
    Game game;
    FileHandler handler;
    unsigned turns;
    Ui::PlayWindow *ui;
    const QPixmap REDSQUARE = QPixmap(":/Images/Red.png");
    const QPixmap BLUESQUARE = QPixmap(":/Images/Blue.png");
    const QPixmap YELLOWSQUARE = QPixmap(":/Images/Yellow.png");
    const QPixmap ORANGESQUARE = QPixmap(":/Images/Orange.png");
    const QPixmap GREENSQUARE = QPixmap(":/Images/Green.png");
    const QPixmap PINKSQUARE = QPixmap(":/Images/Pink.png");
    const QPixmap CYANSQUARE = QPixmap(":/Images/Cyan.png");
    const QPixmap PURPLESQUARE = QPixmap(":/Images/Purple.png");
    const int SQUARESIZE = 32;
    const int WIDTH = 250;
    const int HEIGHT = 30;

    /**
     * @brief checkRecords gets the record for this particular board size of linesxcolumns
     * @param lines the number of lines of the board
     * @param columns the number of colors of the board
     */
    unsigned checkRecords(unsigned lines, unsigned columns);

    /**
     * @brief writeRecords writes the new record in the record file
     * @param lines the number of lines of the board having a new record
     * @param columnsthe number of columns of the board having a new record
     * @param turns the number of turns that will become the new record
     */
    void writeRecords(unsigned lines, unsigned columns, unsigned turns);

    /**
     * @brief clearWidgets deletes all the widgets from the gridLayout to avoid keeping them in memory
     */
    void clearWidgets();

};

#endif // PLAYWINDOW_H
