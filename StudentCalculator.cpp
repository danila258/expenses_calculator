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

    QLineEdit* lineEditCostsFile = new QLineEdit;
    QLineEdit* lineEditInstituteFile = new QLineEdit;
    QLineEdit* lineEditTransportFile = new QLineEdit;
    QLineEdit* lineEditCaffeCinemaFile = new QLineEdit;

    costsLabel->setBuddy(lineEditCostsFile);
    instituteLabel->setBuddy(lineEditInstituteFile);
    transportLabel->setBuddy(lineEditTransportFile);
    weekendsLabel->setBuddy(lineEditCaffeCinemaFile);

    connect(lineEditCostsFile, SIGNAL(textChanged(const QString&)), SLOT(costsFileEdited(const QString&)));
    connect(lineEditInstituteFile, SIGNAL(textChanged(const QString&)), SLOT(instituteFileEdited(const QString&)));
    connect(lineEditTransportFile, SIGNAL(textChanged(const QString&)), SLOT(transportFileEdited(const QString&)));
    connect(lineEditCaffeCinemaFile, SIGNAL(textChanged(const QString&)), SLOT(caffeCinemaFileEdited(const QString&)));

    lineEditCostsFile->setText("../Resources/Costs.csv");
    lineEditInstituteFile->setText("../Resources/Institute.csv");
    lineEditTransportFile->setText("../Resources/Transport2.csv");
    lineEditCaffeCinemaFile->setText("../Resources/Caffe-and-cinema.csv");

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(costsLabel);
    layout->addWidget(lineEditCostsFile);
    layout->addWidget(instituteLabel);
    layout->addWidget(lineEditInstituteFile);
    layout->addWidget(transportLabel);
    layout->addWidget(lineEditTransportFile);
    layout->addWidget(weekendsLabel);
    layout->addWidget(lineEditCaffeCinemaFile);

    layout->addStretch(1);
    fileChoiceWidget->setLayout(layout);
    _messagePosition = fileChoiceWidget;

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
    Database database = Database(_costsFile, _instituteFile, _transportFile, _caffeCinemaFile);

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

void StudentCalculator::costsFileEdited(const QString &costsFile) {
    _costsFile = costsFile.toStdString();
}

void StudentCalculator::instituteFileEdited(const QString &instituteFile) {
    _instituteFile = instituteFile.toStdString();
}

void StudentCalculator::transportFileEdited(const QString &transportFile) {
    _transportFile = transportFile.toStdString();
}

void StudentCalculator::caffeCinemaFileEdited(const QString &caffeCinemaFile) {
    _caffeCinemaFile = caffeCinemaFile.toStdString();
}