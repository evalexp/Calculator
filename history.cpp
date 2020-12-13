#include "history.h"
#include "ui_history.h"
#include "json.h"
#include "QClipboard"

History::History(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::History)
{
    ui->setupUi(this);
}

History::~History()
{
    delete ui;
}

void History::mesRecv(const QString& mes){
    QJsonObject json = JSON::StringToJson(mes);
    if(json.value("action").toString() == "Add-Item"){
        ui->listWidget->insertItem(0, json.value("expr").toString() + "\n\t=" + json.value("result").toString());
    }
}

void History::on_toolButton_del_clicked()
{
    foreach(QModelIndex index, ui->listWidget->selectionModel()->selectedIndexes()){
        ui->listWidget->takeItem(index.row());
    }
}

void History::on_toolButton_expr_clicked()
{
    foreach(QModelIndex index, ui->listWidget->selectionModel()->selectedIndexes()){
        QApplication::clipboard()->setText(ui->listWidget->item(index.row())->text().split('\n')[0]);
    }
}

void History::on_toolButton_result_clicked()
{
    foreach(QModelIndex index, ui->listWidget->selectionModel()->selectedIndexes()){
        QApplication::clipboard()->setText(ui->listWidget->item((index.row()))->text().split('=')[1]);
    }
}
