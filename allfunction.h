#ifndef ALLFUNCTION_H
#define ALLFUNCTION_H

#include <QMainWindow>
#include "json.h"

namespace Ui {
class AllFunction;
}

class AllFunction : public QMainWindow
{
    Q_OBJECT

public:
    explicit AllFunction(QWidget *parent = nullptr);
    ~AllFunction();

private:
    Ui::AllFunction *ui;

signals:
    void sendMes(const QString&);
private slots:
    void on_toolButton_abs_clicked();

    QJsonObject makeJSON(const QString&);
    void on_toolButton_acos_clicked();
    void on_toolButton_asin_clicked();
    void on_toolButton_atan_clicked();
    void on_toolButton_atan2_clicked();
    void on_toolButton_ceil_clicked();
    void on_toolButton_cos_clicked();
    void on_toolButton_cosh_clicked();
    void on_toolButton_e_clicked();
    void on_toolButton_exp_clicked();
    void on_toolButton_floor_clicked();
    void on_toolButton_ln_clicked();
    void on_toolButton_lg_clicked();
    void on_toolButton_pi_clicked();
    void on_toolButton_sin_clicked();
    void on_toolButton_sinh_clicked();
    void on_toolButton_tan_clicked();
    void on_toolButton_tanh_clicked();
};

#endif // ALLFUNCTION_H
