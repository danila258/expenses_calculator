#ifndef STUDENTCALCULATOR_H
#define STUDENTCALCULATOR_H

#include <QtWidgets>
#include <QApplication>
#include <string>

#include "Database.h"
#include "Student.h"
#include "StudentExpenses.h"
#include "FileEditWidget.h"

using std::string;

#define ageByDefault 18

#define countFiles 4
#define countCheckedFields 10

enum files { costsFile, instituteFile, transportFile, otherCostsFile };


class StudentCalculator : public QWidget {
    Q_OBJECT

public:
    explicit StudentCalculator(QWidget* parent = nullptr);
    ~StudentCalculator() override;

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
    Student _student;
    Database _database;
    StudentExpenses _expenses;

    QWidget* fileChoiceWidget();
    QWidget* studentInputWidget();
    QTabWidget* tabWidget();
    QPushButton* calculateButton();

    void updateCalculateButton();
    void calculateButtonFlag(int index, bool flag);
    void switchButtonMode(int index, bool flag);

    void errorDataLoadShow(const QVector<QString>& dataLoudErrors);
    void errorDataLoadShow();
    void studentMoneyShow(int sum);
    bool fileEditWidgetShow (QVector<QStringList>& _file);

    QSpinBox* _ageSpinBox;

    QPushButton* _buttonEditCostsFile;
    QPushButton* _buttonEditInstituteFile;
    QPushButton* _buttonEditTransportFile;
    QPushButton* _buttonEditOtherCostsFile;

    QPushButton* _calculateButton;

    int _month;

    std::vector<bool> _completeFieldsArr;

    bool _calculateAgeFlag = true;
};


#endif //STUDENTCALCULATOR_H