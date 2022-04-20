#include "StudentCalculator.h"

StudentCalculator::StudentCalculator(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* calculatorLayout = new QVBoxLayout();

    calculatorLayout->addWidget(tabWidget());
    calculatorLayout->addWidget(calculateButton());

    resize(350, 0);

    setWindowTitle("Calculator");
    setLayout(calculatorLayout);
}

QWidget* StudentCalculator::studentInputWidget() {
    QWidget* studentInputWidget = new QWidget();

    QLabel* ageLabel = new QLabel("&Age:");
    QLabel* monthLabel = new QLabel("&Month:");
    QLabel* cityLabel = new QLabel("&City:");
    QLabel* addressLabel = new QLabel("&Address:");
    QLabel* instituteLabel = new QLabel("&Institute:");
    QLabel* cinemaLabel = new QLabel("&Cinema:");
    QLabel* caffeLabel = new QLabel("&Caffe:");

    QStringList strMonths = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                             "October", "November", "December"};

    QComboBox* monthsList = new QComboBox();
    monthsList->addItems(strMonths);

    QCheckBox* ageCheckBox = new QCheckBox("Use age");
    ageCheckBox->setChecked(true);

    _ageSpinBox = new QSpinBox();
    _ageSpinBox->setRange(7, 200);
    _ageSpinBox->setSuffix(" years old");

    QLineEdit* lineEditCity = new QLineEdit;
    QLineEdit* lineEditAddress = new QLineEdit;
    QLineEdit* lineEditInstitute = new QLineEdit;
    QLineEdit* lineEditCinema = new QLineEdit;
    QLineEdit* lineEditCaffe = new QLineEdit;

    ageLabel->setBuddy(ageCheckBox);
    monthLabel->setBuddy(monthsList);
    cityLabel->setBuddy(lineEditCity);
    addressLabel->setBuddy(lineEditAddress);
    instituteLabel->setBuddy(lineEditInstitute);
    cinemaLabel->setBuddy(lineEditCinema);
    caffeLabel->setBuddy(lineEditCaffe);

    connect(_ageSpinBox, SIGNAL(valueChanged(int)), SLOT(ageEdited(int)));

    connect(monthsList, SIGNAL(activated(int)), SLOT(monthEdited(int)));

    connect(lineEditCity, SIGNAL(textChanged(const QString&)), SLOT(cityEdited(const QString&)));
    connect(lineEditAddress, SIGNAL(textChanged(const QString&)), SLOT(addressEdited(const QString&)));
    connect(lineEditInstitute, SIGNAL(textChanged(const QString&)), SLOT(instituteEdited(const QString&)));
    connect(lineEditCinema, SIGNAL(textChanged(const QString&)), SLOT(cinemaEdited(const QString&)));
    connect(lineEditCaffe, SIGNAL(textChanged(const QString&)), SLOT(caffeEdited(const QString&)));

    connect(ageCheckBox, SIGNAL(stateChanged(int)), SLOT(regulateAgeSpinBox(int)));

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(ageLabel, 0, 0);
    layout->addWidget(_ageSpinBox, 0, 1);

    layout->addWidget(monthLabel, 1, 0);
    layout->addWidget(monthsList, 1, 1);
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

    layout->addWidget(ageCheckBox, 7, 0);

    studentInputWidget->setLayout(layout);
    return studentInputWidget;
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
    _calculateButton = new QPushButton();
    connect(_calculateButton, SIGNAL(clicked(bool)), SLOT(startCalculate()));
    updateCalculateButton();

    return _calculateButton;
}
