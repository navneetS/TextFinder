#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>

namespace Ui {
class TextFinder;
}

class TextFinder : public QWidget
{
    Q_OBJECT

public:
    explicit TextFinder(QWidget *parent = 0);
    ~TextFinder();

private slots:

    void on_browseButton_clicked();

    void on_findButton_released();

    void on_findButton_pressed();

private:
    Ui::TextFinder *ui;
};

#endif // TEXTFINDER_H
