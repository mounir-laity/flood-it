#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include "PlayWindow.h"
#include "ui_StartWindow.h"

namespace Ui {
class StartWindow;
}

/*!
 * \brief The StartWindow class represents the first window that opens when launching the program.
 * That window lets the user select the size and number of colors of the board
 */
class StartWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
     * \brief StartWindow constructor for StartWindow
     * \param parent the parent widget
     */
    explicit StartWindow(QWidget *parent = nullptr);

    /*!
     * \brief ~PlayWindow destructor of StartWindow
     */
    ~StartWindow();

private slots:

    /*!
     * \brief on_playButton_clicked handler for when the play button is clicked
     */
    void on_playButton_clicked();

private:

    /*!
     * \brief fillComboBox fills the comboboxes for lines, columns and colors from min value to max value
     * \param combo the combobox to fill
     * \param min the minimum value for that combobox
     * \param max the maximal value for the combobox
     */
    void fillComboBox(QComboBox *combo, int min, int max);
    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_H
