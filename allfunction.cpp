#include "allfunction.h"
#include "ui_allfunction.h"

AllFunction::AllFunction(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AllFunction)
{
    ui->setupUi(this);
}

AllFunction::~AllFunction()
{
    delete ui;
}

QJsonObject AllFunction::makeJSON(const QString& func){
    QJsonObject json;
    json.insert("action", "Expr-Append-Function");
    json.insert("function", func);
    return json;
}

void AllFunction::on_toolButton_abs_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("abs(")));
}

void AllFunction::on_toolButton_acos_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("acos(")));
}

void AllFunction::on_toolButton_asin_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("asin(")));
}

void AllFunction::on_toolButton_atan_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("atan(")));
}

void AllFunction::on_toolButton_atan2_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("atan2(")));
}

void AllFunction::on_toolButton_ceil_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("ceil(")));
}

void AllFunction::on_toolButton_cos_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("cos(")));
}

void AllFunction::on_toolButton_cosh_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("cosh(")));
}

void AllFunction::on_toolButton_e_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("e(0)")));
}

void AllFunction::on_toolButton_exp_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("exp(")));
}

void AllFunction::on_toolButton_floor_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("floor(")));
}

void AllFunction::on_toolButton_ln_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("ln(")));
}

void AllFunction::on_toolButton_lg_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("lg(")));
}

void AllFunction::on_toolButton_pi_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("pi(0)")));
}

void AllFunction::on_toolButton_sin_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("sin(")));
}

void AllFunction::on_toolButton_sinh_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("sinh(")));
}

void AllFunction::on_toolButton_tan_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("tan(")));
}

void AllFunction::on_toolButton_tanh_clicked()
{
    this->sendMes(JSON::JsonToString(this->makeJSON("tanh(")));
}
