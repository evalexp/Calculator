#include "history.h"
#include "ui_history.h"
#include "json.h"

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
        ui->listWidget->insertItem(0, json.value("expr").toString() + "\n=" + json.value("result").toString());
    }
}
