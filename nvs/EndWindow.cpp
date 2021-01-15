#include "EndWindow.h"

EndWindow::EndWindow(QWidget *parent, bool abandonned, unsigned turns, int record) :
    QDialog(parent),
    ui(new Ui::EndWindow)
{
    ui->setupUi(this);
    this->setSizeGripEnabled( false );
    this->setWindowIcon(QIcon(":/Images/Menu.png"));

    QPixmap back(":/Images/End.png");
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, back);
    this->setPalette(palette);
    this->abandonned = abandonned;
    this->ui->endLabel->setStyleSheet("QLabel {  color : white; }");
    this->ui->turnsLabel->setStyleSheet("QLabel {  color : white; }");
    this->ui->turnsNumber->setStyleSheet("QLabel {  color : white; }");
    this->ui->recordLabel->setStyleSheet("QLabel {  color : white; }");
    this->ui->recordTurns->setStyleSheet("QLabel {  color : white; }");

    if(!abandonned) {
        this->ui->endLabel->setText("Félicitations, vous avez gagné !");
        this->ui->turnsNumber->setText(QString::number(turns));
        this->ui->recordTurns->setText(QString::number(record));
        if(turns <= record) {
            this->ui->endLabel->setText("Bravo, vous avez fait un nouveau record !");
        }
    }
}

EndWindow::~EndWindow()
{
    delete ui;
}
