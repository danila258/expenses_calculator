#include "StudentCalculator.h"

void StudentCalculator::startCalculate() {
    Student student(_age, _city, _address, _institute, _cafe, _cinema);
    errorDataLoadShow(_database.findStudentInfo(student));

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
    _flagName = !(_name.empty());
    updateCalculateButton();
}

void StudentCalculator::cityEdited(const QString& city) {
    _city = city.toStdString();
    _flagCity = !(_city.empty());
    updateCalculateButton();
}

void StudentCalculator::addressEdited(const QString& address) {
    _address = address.toStdString();
    _flagAddress = !(_address.empty());
    updateCalculateButton();
}

void StudentCalculator::instituteEdited(const QString& institute) {
    _institute = institute.toStdString();
    _flagInstitute = !(_institute.empty());
    updateCalculateButton();
}

void StudentCalculator::cinemaEdited(const QString& cinema) {
    _cinema = cinema.toStdString();
    _flagCinema = !(_cinema.empty());
    updateCalculateButton();
}

void StudentCalculator::caffeEdited(const QString& caffe) {
    _cafe = caffe.toStdString();
    _flagCaffe = !(_cafe.empty());
    updateCalculateButton();
}

void StudentCalculator::costsFileDialog() {
    _costsFile = QFileDialog::getOpenFileName(this, "Costs File", "", "*.csv").toStdString();
    _flagCostsFile = !(_costsFile.empty());

    _database.setCosts(_costsFile);

    updateCalculateButton();
}

void StudentCalculator::instituteFileDialog() {
    _instituteFile = QFileDialog::getOpenFileName(this, "Institute File", "", "*.csv").toStdString();
    _flagInstituteFile = !(_instituteFile.empty());

    _database.setInstitute(_instituteFile);

    updateCalculateButton();
}

void StudentCalculator::transportFileDialog() {
    _transportFile = QFileDialog::getOpenFileName(this, "Transport File", "", "*.csv").toStdString();
    _flagTransportFile = !(_transportFile.empty());

    _database.setTransport(_transportFile);

    updateCalculateButton();
}

void StudentCalculator::otherCostsFileDialog() {
    _otherCostsFile = QFileDialog::getOpenFileName(this, "Other Costs File", "", "*.csv").toStdString();
    _flagOtherCostsFile = !(_otherCostsFile.empty());

    _database.setCafeCinema(_otherCostsFile);

    updateCalculateButton();
}

void StudentCalculator::EditeCostsFile() {
    QStringList list = {"City", "Age", "Average food cost per month", "Other costs"};
    _bufVector = &_database._costsData;
    fileEditWidget(list);
}

void StudentCalculator::EditeInstituteFile() {
    QStringList list = {"City", "Institute", "Dinner cost"};
    _bufVector = &_database._instituteData;
    fileEditWidget(list);
}

void StudentCalculator::EditeTransportFile() {
    QStringList list = {"City", "District", "Institute", "Transport cost"};
    _bufVector = &_database._transportData;
    fileEditWidget(list);
}

void StudentCalculator::EditeCaffeCinemaFile() {
    QStringList list = {"City", "Address", "Caffe", "Average caffe cost", "Cinema", "Cinema cost"};
    _bufVector = &_database._cafeCinemaData;
    fileEditWidget(list);
}

void StudentCalculator::deleteRow() {
    _table->removeRow(_table->rowCount() - 1);
}

void StudentCalculator::addRow() {
    _table->insertRow(_table->rowCount());
}

void StudentCalculator::cancelEditFile() {
    QWidget::close();
}

void StudentCalculator::saveNewFile() {
    std::vector<std::vector<std::string>> file;
    string item;

    for (int i = 1; i < _table->rowCount(); ++i) {
        for (int k = 0; k < _table->columnCount(); ++k) {
            item = _table->itemAt(i, k)->text().toStdString();
            file[i][k] = item;
        }
    }

    *_bufVector = std::move(file);
    cancelEditFile();
}
