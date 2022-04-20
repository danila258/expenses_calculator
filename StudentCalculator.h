#ifndef STUDENTCALCULATOR_H
#define STUDENTCALCULATOR_H

#include <QtWidgets>
#include "Database.h"
#include "Student.h"

#include <vector>
#include <string>
using std::string;

class StudentCalculator : public QWidget {
    Q_OBJECT

public:
    StudentCalculator(QWidget* parent = nullptr);

private slots:

    void ageEdited(int age);
    void monthEdited(int month);
    void regulateAgeSpinBox(int mode);

    void cityEdited(const QString& city);
    void addressEdited(const QString& address);
    void instituteEdited(const QString& institute);
    void cinemaEdited(const QString& cinema);
    void caffeEdited(const QString& caffe);

    void costsFileDialog();
    void instituteFileDialog();
    void transportFileDialog();
    void otherCostsFileDialog();

    void startCalculate();
    
private:
    QWidget* fileChoiceWidget();
    QWidget* studentInputWidget();
    QWidget* tabWidget();
    QWidget* calculateButton();

    void errorFileShow();
    void errorInputShow();
    void studentMoneyShow(int sum);

    void updateCalculateButton();

    QSpinBox* _ageSpinBox;
    QPushButton* _calculateButton;

    int _age;
    int _month;

    string _city;
    string _address;
    string _institute;
    string _cinema;
    string _caffe;

    string _costsFile;
    string _instituteFile;
    string _transportFile;
    string _otherCostsFile;

    bool _flagCostsFile = false;
    bool _flagInstituteFile = false;
    bool _flagTransportFile = false;
    bool _flagOtherCostsFile = false;
    bool _flagCity = false;
    bool _flagAddress = false;
    bool _flagInstitute = false;
    bool _flagCinema = false;
    bool _flagCaffe = false;

    bool _calculateAgeFlag;
};


#endif //STUDENTCALCULATOR_H