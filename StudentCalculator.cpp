#include "StudentCalculator.h"
#include "iostream"

StudentCalculator::StudentCalculator(QWidget *parent) : QWidget(parent){
    QVBoxLayout* calculatorLayout = new QVBoxLayout();

    calculatorLayout->addWidget(tabWidget());
    calculatorLayout->addWidget(calculateButton());

    resize(350, 0);

    setWindowTitle("Calculator");
    setLayout(calculatorLayout);
}

QWidget* StudentCalculator::studentInputWidget() {
    QWidget* studentInfoWidget = new QWidget();

    QLabel* ageLabel = new QLabel("&Age:");
    QLabel* monthLabel = new QLabel("&Month:");
    QLabel* cityLabel = new QLabel("&City:");
    QLabel* addressLabel = new QLabel("&Address:");
    QLabel* instituteLabel = new QLabel("&Institute:");
    QLabel* cinemaLabel = new QLabel("&Cinema:");
    QLabel* caffeLabel = new QLabel("&Caffe:");

    QLineEdit* lineEditAge = new QLineEdit;
    QLineEdit* lineEditMonth = new QLineEdit;
    QLineEdit* lineEditCity = new QLineEdit;
    QLineEdit* lineEditAddress = new QLineEdit;
    QLineEdit* lineEditInstitute = new QLineEdit;
    QLineEdit* lineEditCinema = new QLineEdit;
    QLineEdit* lineEditCaffe = new QLineEdit;

    ageLabel->setBuddy(lineEditAge);
    monthLabel->setBuddy(lineEditMonth);
    cityLabel->setBuddy(lineEditCity);
    addressLabel->setBuddy(lineEditAddress);
    instituteLabel->setBuddy(lineEditInstitute);
    cinemaLabel->setBuddy(lineEditCinema);
    caffeLabel->setBuddy(lineEditCaffe);

    connect(lineEditAge, SIGNAL(textChanged(const QString&)), SLOT(ageEdited(const QString&)));
    connect(lineEditMonth, SIGNAL(textChanged(const QString&)), SLOT(monthEdited(const QString&)));
    connect(lineEditCity, SIGNAL(textChanged(const QString&)), SLOT(cityEdited(const QString&)));
    connect(lineEditAddress, SIGNAL(textChanged(const QString&)), SLOT(addressEdited(const QString&)));
    connect(lineEditInstitute, SIGNAL(textChanged(const QString&)), SLOT(instituteEdited(const QString&)));
    connect(lineEditCinema, SIGNAL(textChanged(const QString&)), SLOT(cinemaEdited(const QString&)));
    connect(lineEditCaffe, SIGNAL(textChanged(const QString&)), SLOT(caffeEdited(const QString&)));

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(ageLabel, 0, 0);
    layout->addWidget(lineEditAge, 0, 1);
    layout->addWidget(monthLabel, 1, 0);
    layout->addWidget(lineEditMonth, 1, 1);
    layout->addWidget(cityLabel, 2, 0);
    layout->addWidget(lineEditCity, 2, 1);
    layout->addWidget(addressLabel, 3, 0);
    layout->addWidget(lineEditAddress, 3, 1);
    layout->addWidget(instituteLabel, 4, 0);
    layout->addWidget(lineEditInstitute, 4, 1);
    layout->addWidget(cinemaLabel, 5, 0);
    layout->addWidget(lineEditCinema, 5, 1);
    layout->addWidget(caffeLabel, 6, 0);
    layout->addWidget(lineEditCaffe, 6, 1);

    studentInfoWidget->setLayout(layout);

    return studentInfoWidget;
}

QWidget* StudentCalculator::fileChoiceWidget() {
    QWidget* fileChoiceWidget = new QWidget();

    QLabel* costsLabel = new QLabel("&Costs file:");
    QLabel* instituteLabel = new QLabel("&Institute file:");
    QLabel* transportLabel = new QLabel("&Transport file:");
    QLabel* weekendsLabel = new QLabel("&Weekends file:");

    QPushButton* buttonBrowseCostsFile = new QPushButton("Browse");
    QPushButton* buttonBrowseInstituteFile = new QPushButton("Browse");
    QPushButton* buttonBrowseTransportFile = new QPushButton("Browse");
    QPushButton* buttonBrowseCaffeCinemaFile = new QPushButton("Browse");

    QPushButton* buttonEditeCostsFile = new QPushButton("Edite");
    QPushButton* buttonEditeInstituteFile = new QPushButton("Edite");
    QPushButton* buttonEditeTransportFile = new QPushButton("Edite");
    QPushButton* buttonEditeCaffeCinemaFile = new QPushButton("Edite");

    costsLabel->setBuddy(buttonBrowseCostsFile);
    instituteLabel->setBuddy(buttonBrowseInstituteFile);
    transportLabel->setBuddy(buttonBrowseTransportFile);
    weekendsLabel->setBuddy(buttonBrowseCaffeCinemaFile);

    connect(buttonBrowseCostsFile, SIGNAL(clicked()), SLOT(costsFileDialog()));
    connect(buttonBrowseInstituteFile, SIGNAL(clicked()), SLOT(instituteFileDialog()));
    connect(buttonBrowseTransportFile, SIGNAL(clicked()), SLOT(transportFileDialog()));
    connect(buttonBrowseCaffeCinemaFile, SIGNAL(clicked()), SLOT(otherCostsFileDialog()));

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(costsLabel, 0, 0);
    layout->addWidget(buttonBrowseCostsFile, 0, 1);
    layout->addWidget(buttonEditeCostsFile, 0, 2);
    layout->addWidget(instituteLabel, 1, 0);
    layout->addWidget(buttonBrowseInstituteFile, 1, 1);
    layout->addWidget(buttonEditeInstituteFile, 1, 2);
    layout->addWidget(transportLabel, 2, 0);
    layout->addWidget(buttonBrowseTransportFile, 2, 1);
    layout->addWidget(buttonEditeTransportFile, 2, 2);
    layout->addWidget(weekendsLabel, 3, 0);
    layout->addWidget(buttonBrowseCaffeCinemaFile, 3, 1);
    layout->addWidget(buttonEditeCaffeCinemaFile, 3, 2);

    fileChoiceWidget->setLayout(layout);

    return fileChoiceWidget;
}

QWidget* StudentCalculator::tabWidget() {
    QTabWidget* calculatorTab = new QTabWidget();

    calculatorTab->addTab(studentInputWidget(), "&Input");
    calculatorTab->addTab(fileChoiceWidget(), "&Data");

    return calculatorTab;
}

QWidget* StudentCalculator::calculateButton() {
    QPushButton* calculateButton = new QPushButton("Calculate");
    connect(calculateButton, SIGNAL(clicked(bool)), SLOT(calculateButtonClicked()));

    return calculateButton;
}

void StudentCalculator::errorAgeMonthShow() {
    QMessageBox* errorAgeMonth = new QMessageBox(QMessageBox::Warning, "Warning",
                                                 "Forbidden characters in the Age or Month field",
                                                 QMessageBox::Ok, this);
    errorAgeMonth->show();
}

void StudentCalculator::errorFileShow() {
    QMessageBox* errorFile = new QMessageBox(QMessageBox::Warning, "Warning", "No files in directory",
                                             QMessageBox::Ok, this);
    errorFile->show();
}

void StudentCalculator::errorInputShow() {
    QMessageBox* errorInput = new QMessageBox(QMessageBox::Warning, "Warning", "Incorrect student data",
                                              QMessageBox::Ok, this);
    errorInput->show();
}

void StudentCalculator::studentMoneyShow(size_t count) {
    QString line = "The student spend " + QString::number(count) + " rubles";

    QMessageBox* studentMoney = new QMessageBox(QMessageBox::Information, "Warning", line,
                                                QMessageBox::Ok, this);
    studentMoney->show();
}

void StudentCalculator::calculateButtonClicked() {
    if (inputInspection()) {
        startCalculate();
    }
    else {
        errorAgeMonthShow();
    }
}

void StudentCalculator::startCalculate() {
    Database database = Database(_costsFile, _instituteFile, _transportFile, _otherCostsFile);

    if ( !(database.initDatabase()) ) {
        errorFileShow();
    }
    else {
        if ( !(database.userInputCheck(_ageI, _city, _address, _institute, _caffe, _cinema)) ) {
            errorInputShow();
        }
        else {
            Student human = Student(_ageI, _city, _address, _institute, _cinema, _caffe, database);
            studentMoneyShow(human.getCosts(_monthI));
        }
    }
}

bool StudentCalculator::inputInspection() {
    bool flagAge = true;
    bool flagMonth = true;

    if (_age[0] == '\0') {
        flagAge = false;
    }

    if (_month[0] == '\0') {
        flagMonth = false;
    }

    for (size_t i = 0; _age[i] != '\0'; ++i) {
        if (_age[i] < '0' || _age[i] > '9') {
            flagAge = false;
            break;
        }
    }

    for (size_t i = 0; _month[i] != '\0'; ++i) {
        if (_month[i] < '0' || _month[i] > '9') {
            flagMonth = false;
            break;
        }
    }

    if (flagAge) {
        _ageI = std::stoi(_age);
    }

    if (flagMonth) {
        _monthI = std::stoi(_month);

        if (_monthI > 12 || _monthI == 0) {
            flagMonth = false;
        }
    }

    return flagAge && flagMonth;
}

void StudentCalculator::costsFileDialog() {
    _costsFile = QFileDialog::getOpenFileName(this, "Costs File", "", "*.csv").toStdString();
}

void StudentCalculator::instituteFileDialog() {
    _instituteFile = QFileDialog::getOpenFileName(this, "Institute File", "", "*.csv").toStdString();
}

void StudentCalculator::transportFileDialog() {
    _transportFile = QFileDialog::getOpenFileName(this, "Transport File", "", "*.csv").toStdString();
}

void StudentCalculator::otherCostsFileDialog() {
    _otherCostsFile = QFileDialog::getOpenFileName(this, "Other Costs File", "", "*.csv").toStdString();
}

void StudentCalculator::ageEdited(const QString& age) {
    _age = age.toStdString();
}

void StudentCalculator::monthEdited(const QString &month) {
    _month = month.toStdString();
}

void StudentCalculator::cityEdited(const QString &city) {
    _city = city.toStdString();
}

void StudentCalculator::addressEdited(const QString &address) {
    _address = address.toStdString();
}

void StudentCalculator::instituteEdited(const QString &institute) {
    _institute = institute.toStdString();
}

void StudentCalculator::cinemaEdited(const QString &cinema) {
    _cinema = cinema.toStdString();
}

void StudentCalculator::caffeEdited(const QString &caffe) {
    _caffe = caffe.toStdString();
}