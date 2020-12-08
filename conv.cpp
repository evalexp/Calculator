#include "conv.h"
#include "ui_conv.h"
#include "QMessageBox"
#include "numeralconverter.h"

extern QString result;

Conv::Conv(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Conv)
{
    ui->setupUi(this);
    ui->textEdit->setAlignment(Qt::AlignRight);
    ui->radioButton_dec->setChecked(true);
    this->origin = NumeralConverter::NumSystem::DEC;
}

Conv::~Conv()
{
    delete ui;
}

/**
 * @brief Conv::setBack
 * Illegal number, set the radio button back
 */
void Conv::setBack(){
    if(this->origin == NumeralConverter::NumSystem::BIN){
        ui->radioButton_bin->setChecked(true);
    }else if(this->origin == NumeralConverter::NumSystem::OCT){
        ui->radioButton_oct->setChecked(true);
    }else if(this->origin == NumeralConverter::NumSystem::DEC){
        ui->radioButton_dec->setChecked(true);
    }else if(this->origin == NumeralConverter::NumSystem::HEX){
        ui->radioButton_hex->setChecked(true);
    }
}

/**
 * @brief Conv::setText
 * @param text textEdit's content
 * simplify the setText and setAlignment
 */
void Conv::setText(const QString &text = "Illegal Number， please check it."){
    ui->textEdit->setText(text);
    ui->textEdit->setAlignment(Qt::AlignRight);
}

/**
 * @brief Conv::Warning
 * @param mes the error message
 */
void Conv::Warning(const QString &mes){
    QMessageBox::critical(NULL, "ERROR", mes);
}

void Conv::on_toolButton_clicked()
{
    for(auto i = 0; i < result.length(); i++){
        if(!((result[i] >= '0' && result[i] <= '9'))){
            QMessageBox::critical(NULL, "ERROR", "Looks like an expression in the calculator, paste failed!");
            return ;
        }
    }
    this->setText(result);
}

void Conv::on_radioButton_dec_clicked()
{
    if(ui->textEdit->toPlainText() == ""){
        return ;
    }
    NumeralConverter* converter = new NumeralConverter(origin, ui->textEdit->toPlainText().toStdString());
    if(converter->valueGood()){
        this->setText(QString::fromStdString(converter->ConvertValue(NumeralConverter::NumSystem::DEC)));
        this->origin = NumeralConverter::NumSystem::DEC;
    }else{
        this->setBack();
        this->Warning();
    }
    delete converter;
}

void Conv::on_radioButton_oct_clicked()
{
    if(ui->textEdit->toPlainText() == ""){
        return ;
    }
    NumeralConverter* converter = new NumeralConverter(origin, ui->textEdit->toPlainText().toStdString());
    if(converter->valueGood()){
        this->setText(QString::fromStdString(converter->ConvertValue(NumeralConverter::NumSystem::OCT)));
        this->origin = NumeralConverter::NumSystem::OCT;
    }else{
        this->setBack();
        this->Warning();
    }
    delete converter;
}

void Conv::on_radioButton_hex_clicked()
{
    if(ui->textEdit->toPlainText() == ""){
        return ;
    }
    NumeralConverter* converter = new NumeralConverter(origin, ui->textEdit->toPlainText().toStdString());
    if(converter->valueGood()){
        this->setText(QString::fromStdString(converter->ConvertValue(NumeralConverter::NumSystem::HEX)));
        this->origin = NumeralConverter::NumSystem::HEX;
    }else{
        this->setBack();
        this->Warning();
    }
    delete converter;
}

void Conv::on_radioButton_bin_clicked()
{
    if(ui->textEdit->toPlainText() == ""){
        return ;
    }
    NumeralConverter* converter = new NumeralConverter(origin, ui->textEdit->toPlainText().toStdString());
    if(converter->valueGood()){
        this->setText(QString::fromStdString(converter->ConvertValue(NumeralConverter::NumSystem::BIN)));
        this->origin = NumeralConverter::NumSystem::BIN;
    }else{
        this->setBack();
        this->Warning();
    }
    delete converter;
}
