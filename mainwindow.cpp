#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include "QMessageBox"
#include "calculator.h"
#include "tinyexpr.h"
#include "conv.h"
#include "json.h"
#include "QDebug"

QString result;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /**
      * Set AlignRight
      */
    ui->textEdit->clear();
    ui->textEdit->setAlignment(Qt::AlignRight);
    /**
      * Initial extensions
      */
    this->conv = new Conv();
    this->his = new History();
    connect(this, SIGNAL(sendSignal(const QString&)), his, SLOT(mesRecv(const QString&)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete conv;
    delete his;
}

/**
 * @brief MainWindow::TextEdit_Add
 * @param text
 * to set the Textedit content and reset Align
 */
void MainWindow::TextEdit_Add(const QString &text){
    ui->textEdit->setText(ui->textEdit->toPlainText() + text);
    ui->textEdit->setAlignment(Qt::AlignRight);
}

/**
 * @brief MainWindow::Find_LastNumber
 * @param exp
 * @return the last number index
 */
int MainWindow::Find_LastNumber(const QString &exp){
    for (auto i = exp.length() - 1; i >= 0; i--) {
        if(exp[i] == '-' || exp[i] == '+' || exp[i] == '*' || exp[i] == '/' || exp[i] == '%'){
            return i+1;
        }else if(exp[i] == '('){
            return i- 4;
        }
    }
    return 0;
}

/**
 * @brief MainWindow::on_toolButton_equal_clicked
 * parse the expression and show the result
 */
void MainWindow::on_toolButton_equal_clicked()
{
    double result = Calculator::eval(ui->textEdit->toPlainText());
    QString s = QString("%1").arg(result);
    QJsonObject json;
    json.insert("action", "Add-Item");
    json.insert("expr", ui->textEdit->toPlainText());
    json.insert("result", s);
//    QMessageBox::information(NULL, "Tips", s);
    if(s == "nan"){
        QMessageBox::critical(NULL, "ERROR", "Illegal Expression! Please check your expression!");
        return ;
    }
    ui->textEdit->setText(s);
    ui->textEdit->setAlignment(Qt::AlignRight);
    sendSignal(JSON::JsonToString(json));
}

void MainWindow::on_toolButton_del_clicked()
{
    qDebug() << "Del";
    QStringList function_list;
    QString text = ui->textEdit->toPlainText();
    QString s;
    if(text.length() <= 1){
        s = "";
    }
    /**
      * Check if the last one is a function
      */
    else if(text[text.length() - 1] == '('){
        int i = text.length() - 2;
        for(; i >= 0; i--){
            if(!(text[i] >= 'a' && text[i] <= 'z')){
                break;
            }
        }
        s = text.mid(0, i + 1);
    }else{
        s = text.mid(0, text.length() - 1);
    }

    ui->textEdit->setText(s);
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::on_toolButton_0_clicked()
{
    this->TextEdit_Add("0");
}

void MainWindow::on_toolButton_dot_clicked()
{
    this->TextEdit_Add(".");
}

void MainWindow::on_toolButton_div_clicked()
{
    this->TextEdit_Add("/");
}

void MainWindow::on_toolButton_1_clicked()
{
    this->TextEdit_Add("1");
}

void MainWindow::on_toolButton_2_clicked()
{
    this->TextEdit_Add("2");
}

void MainWindow::on_toolButton_3_clicked()
{
    this->TextEdit_Add("3");
}

void MainWindow::on_toolButton_4_clicked()
{
    this->TextEdit_Add("4");
}

void MainWindow::on_toolButton_5_clicked()
{
    this->TextEdit_Add("5");
}

void MainWindow::on_toolButton_6_clicked()
{
    this->TextEdit_Add("6");
}

void MainWindow::on_toolButton_7_clicked()
{
    this->TextEdit_Add("7");
}

void MainWindow::on_toolButton_8_clicked()
{
    this->TextEdit_Add("8");
}

void MainWindow::on_toolButton_9_clicked()
{
    this->TextEdit_Add("9");
}

void MainWindow::on_toolButton_mul_clicked()
{
    this->TextEdit_Add("*");
}

void MainWindow::on_toolButton_mod_clicked()
{
    this->TextEdit_Add("%");
}

void MainWindow::on_toolButton_add_clicked()
{
    this->TextEdit_Add("+");
}

void MainWindow::on_toolButton_dec_clicked()
{
    this->TextEdit_Add("-");
}

void MainWindow::on_toolButton_sqrt_clicked()
{
    this->TextEdit_Add("sqrt(");
}

void MainWindow::on_toolButton_clear_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_toolButton_left_clicked()
{
    this->TextEdit_Add("(");
}

void MainWindow::on_toolButton_right_clicked()
{
    this->TextEdit_Add(")");
}

void MainWindow::on_toolButton_pow_clicked()
{
    this->TextEdit_Add("pow(");
}

void MainWindow::on_toolButton_comma_clicked()
{
    this->TextEdit_Add(",");
}

void MainWindow::on_history_triggered()
{
    this->his->show();
}

void MainWindow::on_action_conv_triggered()
{
    this->conv->show();
}

void MainWindow::on_textEdit_textChanged()
{
    result = ui->textEdit->toPlainText();
}
