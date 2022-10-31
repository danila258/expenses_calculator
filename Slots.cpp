#include "StudentCalculator.h"

void StudentCalculator::startCalculate() {
    try {
        _expenses = StudentExpenses(_student, _database[0], _database[1], _database[2], _database[3]);
    }
    catch (QVector<QString>& error) {
        errorDataLoadShow(error);
        return;
    }

    StudentExpenses& exp = _expenses;

    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int workdays[] = {16, 19, 22, 21, 18, 21, 21, 23, 22, 21, 21, 22};

    int workdaysCost = workdays[_month] * (exp._instituteFoodCost + 2 * exp._transportCost);
    int weekdaysCost = (daysInMonth[_month] - workdays[_month]) * (exp._cinemaCost + exp._cafeCost);

    if (_calculateAgeFlag) {
        studentMoneyShow(weekdaysCost + workdaysCost + exp._avgFoodCost + exp._otherCost);
    }
    else {
        studentMoneyShow(weekdaysCost + workdaysCost + 15000 + exp._otherCost);
    }
}

void StudentCalculator::regulateAgeSpinBox(int mode) {
    _ageSpinBox->setEnabled(mode);
    _calculateAgeFlag = mode;
}

void StudentCalculator::ageEdited(int age) {
    _student._age = age;
}

void StudentCalculator::monthEdited(int month) {
    _month = month;
}

void StudentCalculator::nameEdited(const QString& name) {
    _student._name = name;
    calculateButtonFlag(0, !_student._name.isEmpty());
}

void StudentCalculator::cityEdited(const QString& city) {
    _student._city = city;
    calculateButtonFlag(1, !_student._city.isEmpty());
}

void StudentCalculator::addressEdited(const QString& address) {
    _student._address = address;
    calculateButtonFlag(2, !_student._address.isEmpty());
}

void StudentCalculator::instituteEdited(const QString& institute) {
    _student._institute = institute;
    calculateButtonFlag(3, !_student._institute.isEmpty());
}

void StudentCalculator::cinemaEdited(const QString& cinema) {
    _student._cinema = cinema;
    calculateButtonFlag(4, !_student._cinema.isEmpty());
}

void StudentCalculator::caffeEdited(const QString& caffe) {
    _student._cafe = caffe;
    calculateButtonFlag(5, !_student._cafe.isEmpty());
}

void StudentCalculator::costsFileDialog() {
    QString costsFilePath = QFileDialog::getOpenFileName(this, "Costs File", "", "*.csv");

    if ( costsFilePath.isEmpty() ) {
        return;
    }

    bool flag = true;
    try {
        _database.storeFile(costsFilePath, costsFile);
    }
    catch (string& line) {
        flag = false;
    }

    if ( _expenses.costsFileCheck(_database[costsFile]) && flag ) {
        switchButtonMode(6, true, _buttonEditCostsFile);
    }
    else {
        switchButtonMode(6, false, _buttonEditCostsFile);
        _database.clearData(costsFile);
    }
}

void StudentCalculator::instituteFileDialog() {
    QString instituteFilePath = QFileDialog::getOpenFileName(this, "Institute File", "", "*.csv");

    if ( instituteFilePath.isEmpty() ) {
        return;
    }

    bool flag = true;
    try {
        _database.storeFile(instituteFilePath, instituteFile);
    }
    catch (string& line) {
        flag = false;
    }

    if ( _expenses.instituteFileCheck(_database[instituteFile]) && flag ) {
        switchButtonMode(7, true, _buttonEditInstituteFile);
    }
    else {
        switchButtonMode(7, false, _buttonEditInstituteFile);
        _database.clearData(instituteFile);
    }
}

void StudentCalculator::transportFileDialog() {
    QString transportFilePath = QFileDialog::getOpenFileName(this, "Transport File", "", "*.csv");

    if ( transportFilePath.isEmpty() ) {
        return;
    }

    bool flag = true;
    try {
        _database.storeFile(transportFilePath, transportFile);
    }
    catch (string& line) {
        flag = false;
    }

    if ( _expenses.transportFileCheck(_database[transportFile]) && flag ) {
        switchButtonMode(8, true, _buttonEditTransportFile);
    }
    else {
        switchButtonMode(8, false, _buttonEditTransportFile);
        _database.clearData(transportFile);
    }
}

void StudentCalculator::otherCostsFileDialog() {
    QString otherCostsFilePath = QFileDialog::getOpenFileName(this, "Weekends File", "", "*.csv");

    if ( otherCostsFilePath.isEmpty() ) {
        return;
    }

    bool flag = true;
    try {
        _database.storeFile(otherCostsFilePath, otherCostsFile);
    }
    catch (string& line) {
        flag = false;
    }

    if ( _expenses.cafeCinemaFileCheck(_database[otherCostsFile]) && flag ) {
        switchButtonMode(9, true, _buttonEditOtherCostsFile);
    }
    else {
        switchButtonMode(9, false, _buttonEditOtherCostsFile);
        _database.clearData(otherCostsFile);
    }
}

void StudentCalculator::editCostsFile() {
    if ( !fileEditWidgetShow(_database[costsFile]) ) {
        return;
    }

    _database.restoreFile(costsFile);
}

void StudentCalculator::editInstituteFile() {
    if ( !fileEditWidgetShow(_database[instituteFile]) ) {
        return;
    }

    _database.restoreFile(instituteFile);
}

void StudentCalculator::editTransportFile() {
    if ( !fileEditWidgetShow(_database[transportFile]) ) {
        return;
    }

    _database.restoreFile(transportFile);
}

void StudentCalculator::editCaffeCinemaFile() {
    if ( !fileEditWidgetShow(_database[otherCostsFile]) ) {
        return;
    }

    _database.restoreFile(otherCostsFile);
}