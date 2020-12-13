#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "conv.h"
#include "history.h"
#include "allfunction.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_toolButton_6_clicked();

    void on_toolButton_equal_clicked();

    void on_toolButton_0_clicked();

    void on_toolButton_dot_clicked();

    void on_toolButton_div_clicked();

    void on_toolButton_1_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_9_clicked();

    void on_toolButton_mul_clicked();

    void on_toolButton_mod_clicked();

    void on_toolButton_add_clicked();

    void on_toolButton_dec_clicked();

    void on_toolButton_sqrt_clicked();

    void on_toolButton_clear_clicked();

    void on_toolButton_del_clicked();

    void on_toolButton_left_clicked();

    void on_toolButton_right_clicked();

    void on_toolButton_pow_clicked();

    void on_toolButton_comma_clicked();

    void on_history_triggered();

    void on_action_conv_triggered();

    void on_textEdit_textChanged();

    void recvMes(const QString&);

    void on_showAll_triggered();

private:
    Ui::MainWindow *ui;
    void TextEdit_Add(const QString &text);
    int Find_LastNumber(const QString &exp);

    Conv* conv;
    History* his;
    AllFunction* af;

signals:
    void sendSignal(const QString&);
};
#endif // MAINWINDOW_H
