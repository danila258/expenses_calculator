#include "StudentCalculator.h"

void StudentCalculator::startCalculate() {
    Student student(_student._age, _student._city, _student._address, _student._institute, _student._cafe, _student._cinema);

    _expenses = StudentExpenses(student, _database[0], _database[1], _database[2], _database[3]);
    StudentExpenses& exp = _expenses;

    if ( !exp.errors.empty() ) {
        errorDataLoadShow(exp.errors);
    }

    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int workdays[] = {16, 19, 22, 21, 18, 21, 21, 23, 22, 21, 21, 22};

    int workdaysCost = workdays[_month] * (exp._instituteFoodCost + 2 * exp._transportCost);
    int weekdaysCost = (daysInMonth[_month] - workdays[_month]) * (exp._cinemaCost + exp._cafeCost);

    if ( !exp.errors.empty() ) {
        return;
    }

    if (_calculateAgeFlag) {
        studentMoneyShow(weekdaysCost + workdaysCost + exp._avgFoodCost + exp._otherCost);
    }
    else {
        studentMoneyShow(weekdaysCost + workdaysCost + 15000 + exp._otherCost);
    }

    exp.errors.clear();
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
    _student._name = name.toStdString();
    calculateButtonFlag(0, !_student._name.empty());
}

void StudentCalculator::cityEdited(const QString& city) {
    _student._city = city.toStdString();
    calculateButtonFlag(1, !_student._city.empty());
}

void StudentCalculator::addressEdited(const QString& address) {
    _student._address = address.toStdString();
    calculateButtonFlag(2, !_student._address.empty());
}

void StudentCalculator::instituteEdited(const QString& institute) {
    _student._institute = institute.toStdString();
    calculateButtonFlag(3, !_student._institute.empty());
}

void StudentCalculator::cinemaEdited(const QString& cinema) {
    _student._cinema = cinema.toStdString();
    calculateButtonFlag(4, !_student._cinema.empty());
}

void StudentCalculator::caffeEdited(const QString& caffe) {
    _student._cafe = caffe.toStdString();
    calculateButtonFlag(5, !_student._cafe.empty());
}

void StudentCalculator::costsFileDialog() {
    QString costsFilePath = QFileDialog::getOpenFileName(this, "Costs File", "", "*.csv");

    if ( costsFilePath.isEmpty() ) {
        return;
    }

    _database.storeFile(costsFilePath, costsFile);

    if ( _expenses.costsFileCheck(_database[costsFile]) ) {
        switchButtonMode(6, true, _buttonEditCostsFile);
    }
    else {
        switchButtonMode(6, false, _buttonEditCostsFile);
    }
}

void StudentCalculator::instituteFileDialog() {
    QString instituteFilePath = QFileDialog::getOpenFileName(this, "Institute File", "", "*.csv");

    if ( instituteFilePath.isEmpty() ) {
        return;
    }

    _database.storeFile(instituteFilePath, instituteFile);

    if ( _expenses.instituteFileCheck(_database[instituteFile]) ) {
        switchButtonMode(7, true, _buttonEditInstituteFile);
    }
    else {
        switchButtonMode(7, false, _buttonEditInstituteFile);
    }
}

void StudentCalculator::transportFileDialog() {
    QString transportFilePath = QFileDialog::getOpenFileName(this, "Transport File", "", "*.csv");

    if ( transportFilePath.isEmpty() ) {
        return;
    }

    _database.storeFile(transportFilePath, transportFile);

    if ( _expenses.transportFileCheck(_database[transportFile]) ) {
        switchButtonMode(8, true, _buttonEditTransportFile);
    }
    else {
        switchButtonMode(8, false, _buttonEditTransportFile);
    }
}

void StudentCalculator::otherCostsFileDialog() {
    QString otherCostsFilePath = QFileDialog::getOpenFileName(this, "Weekends File", "", "*.csv");

    if ( otherCostsFilePath.isEmpty() ) {
        return;
    }

    _database.storeFile(otherCostsFilePath, otherCostsFile);

    if ( _expenses.cafeCinemaFileCheck(_database[otherCostsFile]) ) {
        switchButtonMode(9, true, _buttonEditOtherCostsFile);
    }
    else {
        switchButtonMode(9, false, _buttonEditOtherCostsFile);
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