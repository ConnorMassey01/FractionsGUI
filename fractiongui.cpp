#include "fractiongui.h"
#include "ui_fractiongui.h"

#include "fraction.h"

#include <QString>
#include <QKeyEvent>
#include <QButtonGroup>
#include <QIntValidator>

FractionGUI::FractionGUI(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FractionGUI)
{
    ui->setupUi(this);

    //clear the answer if any of the inputs are changed using signals
    connect(ui->fraction1_num, &QLineEdit::textChanged, this, [this](){
         clearAnswer();
    });
    connect(ui->fraction1_denom, &QLineEdit::textChanged, this, [this](){
         clearAnswer();
    });
    connect(ui->fraction2_num, &QLineEdit::textChanged, this, [this](){
         clearAnswer();
    });
    connect(ui->fraction2_denom, &QLineEdit::textChanged, this, [this](){
         clearAnswer();
    });

    //allow only numbers from the input boxes
    ui->fraction1_num->setValidator(new QIntValidator(-9999, 9999, this));
    ui->fraction1_denom->setValidator(new QIntValidator(-9999, 9999, this));
    ui->fraction2_num->setValidator(new QIntValidator(-9999, 9999, this));
    ui->fraction2_denom->setValidator(new QIntValidator(-9999, 9999, this));


    //set correct tab order to progress through input boxes
    QWidget::setTabOrder(ui->fraction1_num, ui->fraction1_denom);
    QWidget::setTabOrder(ui->fraction1_denom, ui->fraction2_num);
    QWidget::setTabOrder(ui->fraction2_num, ui->fraction2_denom);
}

FractionGUI::~FractionGUI()
{
    delete ui;
}

void FractionGUI::on_EqualsButton_clicked(){    
    int numerator1, numerator2, denominator1, denominator2;
    Fraction fraction1, fraction2, answer;
    //clear any previous errors and results displayed
    ui->errorDisplay->setText(QString::fromStdString(""));
    clearAnswer();
    //check if any errors are present
    if(ui->fraction1_num->text().isEmpty() || ui->fraction1_denom->text().isEmpty()
       || ui->fraction2_num->text().isEmpty() || ui->fraction2_denom->text().isEmpty()){
        ui->errorDisplay->setText(QString::fromStdString(("Not all fractions have been entered yet")));
    }
    //if no errors present, calculate and display the answer
    else{
        numerator1 = ui->fraction1_num->text().toInt();
        denominator1 = ui->fraction1_denom->text().toInt();
        try{
            fraction1 = Fraction(numerator1, denominator1);
        } catch (FractionException &e) {
            ui->errorDisplay->setText(QString::fromStdString("Fraction 1 " + e.what()));
            return;
        }
        numerator2 = ui->fraction2_num->text().toInt();
        denominator2 = ui->fraction2_denom->text().toInt();

        try{
            fraction2 = Fraction(numerator2, denominator2);
        } catch (FractionException &e) {
            ui->errorDisplay->setText(QString::fromStdString("Fraction 2 " + e.what()));
            return;
        }
        //do calculation depending on which button is selected
        try{
            if(ui->addButton->isChecked()){
                answer = fraction1 + fraction2;
            }
            else if(ui->subtractButton->isChecked()){
                answer = fraction1 - fraction2;
            }
            else if(ui->multiplyButton->isChecked()){
                answer = fraction1 * fraction2;
            }
            else if(ui->devideButton->isChecked()){
                answer = fraction1 / fraction2;
            }
            else{
                ui->errorDisplay->setText(QString::fromStdString("Must select an operation"));
                return;
            }
        } catch (FractionException &e){
            ui->errorDisplay->setText(QString::fromStdString("Can't devide by zero"));
            return;
        }

        ui->answer_num->setText(QString::number(answer.numerator()));
        if(answer.denominator() != 1 && answer.numerator() != 0){
            ui->answer_denom->setText(QString::number(answer.denominator()));
        }
    }
}

void FractionGUI::on_addButton_clicked(){
    clearAnswer();
}
void FractionGUI::on_subtractButton_clicked(){
    clearAnswer();
}
void FractionGUI::on_multiplyButton_clicked(){
    clearAnswer();
}
void FractionGUI::on_devideButton_clicked(){
    clearAnswer();
}


void FractionGUI::clearAnswer(){
    ui->answer_num->setText(QString::fromStdString(""));
    ui->answer_denom->setText(QString::fromStdString(""));
}

void FractionGUI::keyPressEvent(QKeyEvent *event){

    if(event->type() == QKeyEvent::KeyPress){
        if(event->key() == Qt::Key_C){
            ui->errorDisplay->setText(QString::fromStdString("close"));
        }
        //let pressing enter be the same as pressing the equals button
        if(event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter){
            on_EqualsButton_clicked();
        }
    }
}


