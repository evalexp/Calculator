#ifndef CONV_H
#define CONV_H

#include <QMainWindow>
#include "numeralconverter.h"

namespace Ui {
class Conv;
}

class Conv : public QMainWindow
{
    Q_OBJECT

public:
    explicit Conv(QWidget *parent = nullptr);
    ~Conv();

public slots:


private slots:
    void on_toolButton_clicked();

    void on_radioButton_dec_clicked();

    void on_radioButton_oct_clicked();

    void on_radioButton_hex_clicked();

    void on_radioButton_bin_clicked();

private:
    Ui::Conv *ui;

    NumeralConverter::NumSystem origin;

    void setBack();

    void setText(const QString& text);

    void Warning(const QString& mes = "Illegal Number， please check it.");
};

#endif // CONV_H
