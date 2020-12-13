#ifndef HISTORY_H
#define HISTORY_H

#include <QMainWindow>

namespace Ui {
class History;
}

class History : public QMainWindow
{
    Q_OBJECT

public:
    explicit History(QWidget *parent = nullptr);
    ~History();


public slots:
    void mesRecv(const QString&);

private slots:
    void on_toolButton_del_clicked();

    void on_toolButton_expr_clicked();

    void on_toolButton_result_clicked();

private:
    Ui::History *ui;
};

#endif // HISTORY_H
