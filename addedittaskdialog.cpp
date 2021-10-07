#include "addedittaskdialog.h"
#include "ui_addedittaskdialog.h"

addEditTaskDialog::addEditTaskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEditTaskDialog)
{
    ui->setupUi(this);
    ui->colorLabel->setAutoFillBackground(true);
    QPalette palette = ui->label->palette();
    chosenColor = palette.color(QPalette::Window);
}

addEditTaskDialog::addEditTaskDialog(QString name, QColor color, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEditTaskDialog), chosenColor(color), chosenName(name)
{
    ui->setupUi(this);
    ui->colorLabel->setAutoFillBackground(true);
    ui->lineEdit->setText(chosenName);
    QPalette palette = ui->label->palette();
    palette.setColor(QPalette::Window, chosenColor);
    ui->colorLabel->setPalette(palette);
}

addEditTaskDialog::~addEditTaskDialog()
{
    delete ui;
}

void addEditTaskDialog::on_colorButton_clicked()
{
    QPalette palette = ui->label->palette();
    chosenColor = QColorDialog::getColor(chosenColor, this, "Выберите цвет");
    if(chosenColor.isValid())
    {
        palette.setColor(QPalette::Window, chosenColor);
        ui->colorLabel->setPalette(palette);
        qDebug() << "Choosed valid color " << chosenColor.name();
    }else
    {
        qDebug() << "Choosed invalid color";
    }
}


void addEditTaskDialog::on_saveButton_clicked()
{
    if(ui->lineEdit->text() == "")
    {
        QMessageBox::information(this, "Ошибка", "Не введено название!");
        return;
    }
    chosenName = ui->lineEdit->text();
    accept();
}


void addEditTaskDialog::on_cancelButton_clicked()
{
    reject();
}

const QString addEditTaskDialog::getChosenName()
{
    return chosenName;
}

const QColor addEditTaskDialog::getChosenColor()
{
    return chosenColor;
}

