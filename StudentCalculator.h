#ifndef STUDENTCALCULATOR_H
#define STUDENTCALCULATOR_H

#include <QtWidgets>
#include <string>
using std::string;

#include "StudentsDatabase.h"
#include "Student.h"
#include "FileEditWidget.h"

#define countCheckedFields 10
#define ageByDefault 18


class StudentCalculator : public QWidget {
    Q_OBJECT

public:
    explicit StudentCalculator(QWidget* parent = nullptr);
    ~StudentCalculator();

private slots:

    void ageEdited(int age);
    void regulateAgeSpinBox(int mode);

    void monthEdited(int month);
    void nameEdited(const QString& name);
    void cityEdited(const QString& city);
    void addressEdited(const QString& address);
    void instituteEdited(const QString& institute);
    void cinemaEdited(const QString& cinema);
    void caffeEdited(const QString& caffe);

    void costsFileDialog();
    void instituteFileDialog();
    void transportFileDialog();
    void otherCostsFileDialog();

    void editCostsFile();
    void editInstituteFile();
    void editTransportFile();
    void editCaffeCinemaFile();

    void startCalculate();
    
private:
    Database _database;

    QWidget* fileChoiceWidget();
    QWidget* studentInputWidget();
    QTabWidget* tabWidget();
    QPushButton* calculateButton();

    void errorDataLoadShow(const std::vector<string>& dataLoudErrors);
    void studentMoneyShow(int sum);

    void updateCalculateButton();

    QSpinBox* _ageSpinBox;
    QPushButton* _calculateButton;

    QPushButton* _buttonEditCostsFile;
    QPushButton* _buttonEditInstituteFile;
    QPushButton* _buttonEditTransportFile;
    QPushButton* _buttonEditOtherCostsFile;

    int _age;
    int _month;

    string _name;
    string _city;
    string _address;
    string _institute;
    string _cinema;
    string _cafe;

    string _costsFile;
    string _instituteFile;
    string _transportFile;
    string _otherCostsFile;

    std::vector<bool> _completeFieldsArr;

    bool _calculateAgeFlag = true;  //TODO как обработать без возраста?
};


#endif //STUDENTCALCULATOR_H