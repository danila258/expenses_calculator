#ifndef STUDENTCALCULATOR_H
#define STUDENTCALCULATOR_H

#include <QtWidgets>
#include "StudentsDatabase.h"
#include "Student.h"

#include <string>
using std::string;

class StudentCalculator : public QWidget {
    Q_OBJECT

public:
    StudentCalculator(QWidget* parent = nullptr);

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

    void EditeCostsFile();
    void EditeInstituteFile();
    void EditeTransportFile();
    void EditeCaffeCinemaFile();

    void deleteRow();
    void addRow();
    void cancelEditFile();
    void saveNewFile();

    void startCalculate();
    
private:
    Database _database;

    QWidget* fileChoiceWidget();
    QWidget* studentInputWidget();
    QTabWidget* tabWidget();
    QPushButton* calculateButton();

    void fileTable(const QStringList &labels);
    void fileEditWidget(const QStringList &labels);

    void errorDataLoadShow(const std::vector<string>& dataLoudErrors);
    void studentMoneyShow(int sum);

    void updateCalculateButton();

    QSpinBox* _ageSpinBox;
    QPushButton* _calculateButton;

    QWidget* _fileEditWidget;
    QTableWidget* _table;

    QPushButton* _buttonEditeCostsFile;
    QPushButton* _buttonEditeInstituteFile;
    QPushButton* _buttonEditeTransportFile;
    QPushButton* _buttonEditeOtherCostsFile;

    std::vector<std::vector<std::string>>* _bufVector;

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

    bool _flagCostsFile = false;
    bool _flagInstituteFile = false;
    bool _flagTransportFile = false;
    bool _flagOtherCostsFile = false;
    bool _flagName = false;
    bool _flagCity = false;
    bool _flagAddress = false;
    bool _flagInstitute = false;
    bool _flagCinema = false;
    bool _flagCaffe = false;

    bool _calculateAgeFlag = true;  //TODO как обработать без возраста?
};


#endif //STUDENTCALCULATOR_H