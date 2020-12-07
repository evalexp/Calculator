#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QProcess"
#include "QMessageBox"
#include "exprtk.hpp"
#include <string>


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

}

MainWindow::~MainWindow()
{
    delete ui;
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
 * parse the expression and shou it
 */
void MainWindow::on_toolButton_equal_clicked()
{
    std::string exp = ui->textEdit->toPlainText().toStdString();
    exprtk::parser<double> parser;
    exprtk::expression<double> expression;
    parser.compile(exp, expression);
    const double result = expression.value();
    QMessageBox::information(NULL, "Tips", QString("%1").arg(result));
    QString command = ui->textEdit->toPlainText().replace("sqrt", "[math]::sqrt");
    return ;
    QProcess *p = new QProcess();
    QStringList ql;
    ql << "-Command" << "{" + command + "}";
    p->start("powershell", QStringList() << "powershell -Command {" + command + "}");
    p->waitForStarted();
    p->waitForReadyRead();
    QString s = p->readAllStandardOutput();
    p->close();
    if(s == ""){
        QMessageBox::information(NULL, "Error", "Please check your math expression, something went wrong just now.");
        return ;
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

/**
 * @brief MainWindow::on_toolButton_inv_clicked
 * find the last number x, and replace it to 1/x
 */
void MainWindow::on_toolButton_inv_clicked()
{
    QString exp = ui->textEdit->toPlainText();
    if(     exp[exp.length() -1 ] == ')' ||
            exp[exp.length() -1 ] == '(' ||
            exp[exp.length() -1 ] == '+' ||
            exp[exp.length() -1 ] == '-' ||
            exp[exp.length() -1 ] == '*' ||
            exp[exp.length() -1 ] == '/' ||
            exp[exp.length() -1 ] == '%'){
        return ;
    }
    int index = this->Find_LastNumber(exp);
    if(exp.mid(index) == "1"){
        return ;
    }
    QString s_num = "1/" + exp.mid(index);
    ui->textEdit->setText(exp.mid(0, index) + s_num);
    ui->textEdit->setAlignment(Qt::AlignRight);
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

/**
 * @brief MainWindow::on_toolButton_sqrt_clicked
 * find the last number x, and replace it to sqrt(x)
 */
void MainWindow::on_toolButton_sqrt_clicked()
{
    this->TextEdit_Add("sqrt(");
}

void MainWindow::on_toolButton_clear_clicked()
{
    ui->textEdit->clear();
}

void MainWindow::on_toolButton_del_clicked()
{
    QString text = ui->textEdit->toPlainText();
    QString s;
    if(text.length() <= 1){
        s = "";
    }
    else if(text[text.length() - 1] == '(' && text[text.length() - 2] == 't'){
        s = text.mid(0, text.length() - 5);
    }else{
        s = text.mid(0, text.length() - 1);
    }

    ui->textEdit->setText(s);
    ui->textEdit->setAlignment(Qt::AlignRight);
}

void MainWindow::on_toolButton_left_clicked()
{
    this->TextEdit_Add("(");
}

void MainWindow::on_toolButton_right_clicked()
{
    this->TextEdit_Add(")");
}
