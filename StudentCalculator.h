#ifndef STUDENTCALCULATOR_H
#define STUDENTCALCULATOR_H

#include <QtWidgets>
#include "Database.h"
#include "Student.h"

#include <string>
using std::string;

class StudentCalculator : public QWidget {
    Q_OBJECT

public:
    StudentCalculator(QWidget* parent = nullptr);

private slots:
    void calculateButtonClicked();

    void ageEdited(const QString& age);
    void monthEdited(const QString& month);
    void cityEdited(const QString& city);
    void addressEdited(const QString& address);
    void instituteEdited(const QString& institute);
    void cinemaEdited(const QString& cinema);
    void caffeEdited(const QString& caffe);

    void costsFileDialog();
    void instituteFileDialog();
    void transportFileDialog();
    void otherCostsFileDialog();
    
private:
    QWidget* fileChoiceWidget();
    QWidget* studentInputWidget();
    QWidget* tabWidget();
    QWidget* calculateButton();

    void errorAgeMonthShow();
    void errorFileShow();
    void errorInputShow();
    void studentMoneyShow(size_t count);

    void startCalculate();
    bool inputInspection();

    string _age;
    string _month;
    string _city;
    string _address;
    string _institute;
    string _cinema;
    string _caffe;

    size_t _ageI;
    size_t _monthI;

    string _costsFile;
    string _instituteFile;
    string _transportFile;
    string _otherCostsFile;
};


#endif //STUDENTCALCULATOR_H