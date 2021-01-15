#include "PlayWindow.h"
namespace Ui {
class PlayWindow;
}

PlayWindow::PlayWindow(QWidget *parent, unsigned lines, unsigned columns, unsigned colors) :
    QDialog(parent), game(Game(lines, columns,colors)), handler(FileHandler(lines,columns,colors)),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);
    this->turns = 0;
    this->setSizeGripEnabled( false );
    this->setWindowIcon(QIcon(":/Images/Menu.png"));

    string title = "Flood-It : "+to_string(lines)+" x "+to_string(columns)+" x "+to_string(colors);
    QString qstring = QString::fromStdString(title);
    this->setWindowTitle(QString(qstring));

    game.registerObserver(&*this);
    game.launch();

    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    this->ui->turnsText->setStyleSheet("QLabel {  color : white; }");
    this->ui->numberOfTurns->setStyleSheet("QLabel { color : white; }");
    this->ui->recordText->setStyleSheet("QLabel {  color : white; }");
    this->ui->recordTurns->setStyleSheet("QLabel {  color : white; }");
}
PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::displayBoard() {
    unsigned lines = game.getBoard().getLines();
    unsigned columns = game.getBoard().getColumns();
    int record = handler.readRecord();
    this->setFixedSize(columns*SQUARESIZE+WIDTH, lines*SQUARESIZE+HEIGHT);
    this->ui->recordTurns->setText(QString::number(handler.readRecord()));
    for(unsigned i = 0; i < lines; i++) {
        for(unsigned j = 0; j < columns; j++) {
            ClickableLabel *label = new ClickableLabel(this);
            Square square = game.getBoard().getSquares()[i][j];
            switch (square.getColor()) {
            case RED:
                label->setPixmap(REDSQUARE);
                break;
            case BLUE:
                label->setPixmap(BLUESQUARE);
                break;
            case YELLOW:
                label->setPixmap(YELLOWSQUARE);
                break;
            case ORANGE:
                label->setPixmap(ORANGESQUARE);
                break;
            case CYAN:
                label->setPixmap(CYANSQUARE);
                break;
            case PURPLE:
                label->setPixmap(PURPLESQUARE);
                break;
            case GREEN:
                label->setPixmap(GREENSQUARE);
                break;
            default:
                label->setPixmap(PINKSQUARE);
                break;
            }
            ui->gridLayout->addWidget(label, i, j, nullptr);
            label->setAttributes(square, &game);
        }
    }
    ui->gridLayout->setContentsMargins(0,0,0,0);

    if(game.isOver()) {
        if(turns < record) {
            handler.writeRecord(turns);
            record = turns;
        }
        this->close();
        EndWindow endView = EndWindow(nullptr, false, turns, record);
        endView.setModal(true);
        endView.exec();
    }
    ui->numberOfTurns->setText(QString::number(turns));
    turns++;
}

void PlayWindow::update(const Subject *subject) {
    clearWidgets();
    displayBoard();
}

void PlayWindow::clearWidgets() {
    for (int i = 0; i < ui->gridLayout->count(); i++)
    {
        ui->gridLayout->itemAt(i)->widget()->deleteLater();
    }
}

void PlayWindow::on_Abandon_clicked()
{
    this->close();
    EndWindow endView = EndWindow(nullptr, true);
    endView.setModal(true);
    endView.exec();
}
