#include "textfinder.h"
#include "ui_textfinder.h"
#include "QFileDialog"
#include"QtCore"
#include"QtGui"
#include"QFile"
#include"QTextStream"

TextFinder::TextFinder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TextFinder)
{
    ui->setupUi(this);
}

TextFinder::~TextFinder()
{
    delete ui;
}


void TextFinder::on_browseButton_clicked()
{
    QFileDialog fileDialog(this);
    QString fileName=fileDialog.getOpenFileName(this,tr("Open"),"","");
    QFile inputFile(fileName);
    inputFile.open(QIODevice::ReadOnly);

    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();

    ui->textEdit->setPlainText(line);

}

void TextFinder::on_findButton_released()
{
    ui->textEdit->setTextBackgroundColor(QColor(0,0,123,144));
}

void TextFinder::on_findButton_pressed()
{
    QString searchString = ui->lineEdit->text();
    ui->textEdit->find(searchString, QTextDocument::FindWholeWords);
}


