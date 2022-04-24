#include "StudentCalculator.h"

void StudentCalculator::startCalculate() {
    Student student(_age, _city, _address, _institute, _cafe, _cinema);

    std::vector<string>& errors = _database.findStudentInfo(student);
  
    if ( !errors.empty() ) {
        errorDataLoadShow(errors);
    }
    errors.clear();

    const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    const int workdays[] = {16, 19, 22, 21, 18, 21, 21, 23, 22, 21, 21, 22};

    int workdaysCost = workdays[_month] * (student._instituteFoodCost + 2 * student._transportCost);
    int weekdaysCost = (daysInMonth[_month] - workdays[_month]) * (student._cinemaCost + student._cafeCost);
    int cost = weekdaysCost + workdaysCost + student._avgFoodCost + student._otherCost;

    studentMoneyShow(cost);
}

void StudentCalculator::regulateAgeSpinBox(int mode) {
    _ageSpinBox->setEnabled(mode);
    _calculateAgeFlag = (mode) != 0;
}

void StudentCalculator::ageEdited(int age) {
    _age = age;
}

void StudentCalculator::monthEdited(int month) {
    _month = month;
}

void StudentCalculator::nameEdited(const QString& name) {
    _name = name.toStdString();
    _completeFieldsArr[0] = !(_name.empty());
    updateCalculateButton();
}

void StudentCalculator::cityEdited(const QString& city) {
    _city = city.toStdString();
    _completeFieldsArr[1] = !(_city.empty());
    updateCalculateButton();
}

void StudentCalculator::addressEdited(const QString& address) {
    _address = address.toStdString();
    _completeFieldsArr[2] = !(_address.empty());
    updateCalculateButton();
}

void StudentCalculator::instituteEdited(const QString& institute) {
    _institute = institute.toStdString();
    _completeFieldsArr[3] = !(_institute.empty());
    updateCalculateButton();
}

void StudentCalculator::cinemaEdited(const QString& cinema) {
    _cinema = cinema.toStdString();
    _completeFieldsArr[4] = !(_cinema.empty());
    updateCalculateButton();
}

void StudentCalculator::caffeEdited(const QString& caffe) {
    _cafe = caffe.toStdString();
    _completeFieldsArr[5] = !(_cafe.empty());
    updateCalculateButton();
}

void StudentCalculator::costsFileDialog() {
    string costsFilePath = QFileDialog::getOpenFileName(this, "Costs File", "", "*.csv").toStdString();
    bool flag;

    if ( flag = costsFilePath.empty() ) {
        return;
    }

    _database.setCosts(costsFilePath);
    _buttonEditCostsFile->setEnabled(!flag);

    _completeFieldsArr[6] = true;
    updateCalculateButton();
}

void StudentCalculator::instituteFileDialog() {
    string instituteFilePath = QFileDialog::getOpenFileName(this, "Institute File", "", "*.csv").toStdString();
    bool flag;

    if ( flag = instituteFilePath.empty() ) {
        return;
    }

    _database.setInstitute(instituteFilePath);
    _buttonEditInstituteFile->setEnabled(!flag);

    _completeFieldsArr[7] = flag;
    updateCalculateButton();
}

void StudentCalculator::transportFileDialog() {
    string transportFilePath = QFileDialog::getOpenFileName(this, "Transport File", "", "*.csv").toStdString();
    bool flag;

    if ( flag = transportFilePath.empty() ) {
        return;
    }

    _database.setTransport(transportFilePath);
    _buttonEditTransportFile->setEnabled(!flag);

    _completeFieldsArr[8] = flag;
    updateCalculateButton();
}

void StudentCalculator::otherCostsFileDialog() {
    string otherCostsFilePath = QFileDialog::getOpenFileName(this, "Weekends File", "", "*.csv").toStdString();
    bool flag;

    if ( flag = otherCostsFilePath.empty() ) {
        return;
    }

    _database.setCafeCinema(otherCostsFilePath);
    _buttonEditOtherCostsFile->setEnabled(!flag);

    _completeFieldsArr[9] = flag;
    updateCalculateButton();
}

void StudentCalculator::editCostsFile() {
    QStringList headerLabels = {"City", "Age", "Average food cost per month", "Other costs"};

    if ( fileEditWidgetShow(headerLabels, _database._costsData) ) {
        _database.resetCosts();
    }
}

void StudentCalculator::editInstituteFile() {
    QStringList headerLabels = {"City", "Institute", "Dinner cost"};

    if ( fileEditWidgetShow(headerLabels, _database._instituteData) ) {
        _database.resetInstitute();
    }
}

void StudentCalculator::editTransportFile() {
    QStringList headerLabels = {"City", "District", "Institute", "Transport cost"};

    if ( fileEditWidgetShow(headerLabels, _database._transportData) ) {
        _database.resetTransport();
    }
}

void StudentCalculator::editCaffeCinemaFile() {
    QStringList headerLabels = {"City", "Address", "Caffe", "Average caffe cost", "Cinema", "Cinema cost"};

    if ( fileEditWidgetShow(headerLabels, _database._cafeCinemaData) ) {

    }
}