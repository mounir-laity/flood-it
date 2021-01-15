#include "StartWindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    QPixmap back(":/Images/Menu.png");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, back);
    this->setPalette(palette);

    this->statusBar()->setSizeGripEnabled( false );
    this->setWindowIcon(QIcon(":/Images/Menu.png"));

    this->ui->horizontalLayout->setSpacing(10);
    this->ui->linesLabel->setStyleSheet("QLabel { color : white; }");
    this->ui->columnsLabel->setStyleSheet("QLabel { color : white; }");
    this->ui->colorsLabel->setStyleSheet("QLabel { color : white; }");



    this->fillComboBox(this->ui->linesComboBox, 6, 20);
    this->fillComboBox(this->ui->columnsComboBox, 6, 20);
    this->fillComboBox(this->ui->colorsComboBox, 3, 8);
}

void StartWindow::fillComboBox(QComboBox *combo, int min, int max) {
    for(int i = min; i <= max; i++) {
        combo->addItem(QString::fromStdString(to_string(i)));
    }
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_playButton_clicked()
{
    unsigned lines = ui->linesComboBox->currentText().toInt();
    unsigned columns = ui->columnsComboBox->currentText().toInt();
    unsigned colors = ui->colorsComboBox->currentText().toInt();
    this->close();
    PlayWindow gameView = PlayWindow(nullptr, lines, columns, colors);
    gameView.displayBoard();
    gameView.setModal(true);
    gameView.exec();
}
