#include "StudentCalculator.h"

StudentCalculator::StudentCalculator(QWidget *parent) : QWidget(parent), _completeFieldsArr(countCheckedFields, 0) {
    QVBoxLayout* calculatorLayout = new QVBoxLayout();

    calculatorLayout->addWidget(tabWidget());
    calculatorLayout->addWidget(calculateButton());

    setWindowTitle("Calculator");
    setLayout(calculatorLayout);
}

QWidget* StudentCalculator::studentInputWidget() {
    QWidget* studentInputWidget = new QWidget();

    QLabel* ageLabel = new QLabel("&Age:");
    QLabel* monthLabel = new QLabel("&Month:");
    QLabel* nameLabel = new QLabel("&Name:");
    QLabel* cityLabel = new QLabel("&City:");
    QLabel* addressLabel = new QLabel("&Address:");
    QLabel* instituteLabel = new QLabel("&Institute:");
    QLabel* cinemaLabel = new QLabel("&Cinema:");
    QLabel* caffeLabel = new QLabel("&Caffe:");

    QStringList strMonths = {"January", "February", "March", "April", "May", "June", "July", "August", "September",
                             "October", "November", "December"};

    QComboBox* monthsList = new QComboBox();
    monthsList->addItems(strMonths);
    _month = 0;

    QCheckBox* ageCheckBox = new QCheckBox("Use age");
    ageCheckBox->setChecked(true);

    _ageSpinBox = new QSpinBox();
    _ageSpinBox->setRange(7, 200);
    _ageSpinBox->setSuffix(" years old");
    _ageSpinBox->setValue(ageByDefault);
    _age = ageByDefault;

    QLineEdit* lineEditName = new QLineEdit;
    QLineEdit* lineEditCity = new QLineEdit;
    QLineEdit* lineEditAddress = new QLineEdit;
    QLineEdit* lineEditInstitute = new QLineEdit;
    QLineEdit* lineEditCinema = new QLineEdit;
    QLineEdit* lineEditCaffe = new QLineEdit;

    ageLabel->setBuddy(ageCheckBox);
    monthLabel->setBuddy(monthsList);
    nameLabel->setBuddy(lineEditName);
    cityLabel->setBuddy(lineEditCity);
    addressLabel->setBuddy(lineEditAddress);
    instituteLabel->setBuddy(lineEditInstitute);
    cinemaLabel->setBuddy(lineEditCinema);
    caffeLabel->setBuddy(lineEditCaffe);

    connect(_ageSpinBox, SIGNAL(valueChanged(int)), SLOT(ageEdited(int)));
    connect(monthsList, SIGNAL(activated(int)), SLOT(monthEdited(int)));
    connect(lineEditName, SIGNAL(textChanged(const QString&)), SLOT(nameEdited(const QString&)));
    connect(lineEditCity, SIGNAL(textChanged(const QString&)), SLOT(cityEdited(const QString&)));
    connect(lineEditAddress, SIGNAL(textChanged(const QString&)), SLOT(addressEdited(const QString&)));
    connect(lineEditInstitute, SIGNAL(textChanged(const QString&)), SLOT(instituteEdited(const QString&)));
    connect(lineEditCinema, SIGNAL(textChanged(const QString&)), SLOT(cinemaEdited(const QString&)));
    connect(lineEditCaffe, SIGNAL(textChanged(const QString&)), SLOT(caffeEdited(const QString&)));
    connect(ageCheckBox, SIGNAL(stateChanged(int)), SLOT(regulateAgeSpinBox(int)));

    QGridLayout* studentInputWidgetLayout = new QGridLayout();

    studentInputWidgetLayout->addWidget(ageLabel, 0, 0);
    studentInputWidgetLayout->addWidget(_ageSpinBox, 0, 1);
    studentInputWidgetLayout->addWidget(monthLabel, 1, 0);
    studentInputWidgetLayout->addWidget(monthsList, 1, 1);
    studentInputWidgetLayout->addWidget(nameLabel, 2, 0);
    studentInputWidgetLayout->addWidget(lineEditName, 2, 1);
    studentInputWidgetLayout->addWidget(cityLabel, 3, 0);
    studentInputWidgetLayout->addWidget(lineEditCity, 3, 1);
    studentInputWidgetLayout->addWidget(addressLabel, 4, 0);
    studentInputWidgetLayout->addWidget(lineEditAddress, 4, 1);
    studentInputWidgetLayout->addWidget(instituteLabel, 5, 0);
    studentInputWidgetLayout->addWidget(lineEditInstitute, 5, 1);
    studentInputWidgetLayout->addWidget(cinemaLabel, 6, 0);
    studentInputWidgetLayout->addWidget(lineEditCinema, 6, 1);
    studentInputWidgetLayout->addWidget(caffeLabel, 7, 0);
    studentInputWidgetLayout->addWidget(lineEditCaffe, 7, 1);
    studentInputWidgetLayout->addWidget(ageCheckBox, 8, 0);

    studentInputWidget->setLayout(studentInputWidgetLayout);
    return studentInputWidget;
}

QWidget* StudentCalculator::fileChoiceWidget() {
    QWidget* fileChoiceWidget = new QWidget();

    QLabel* costsLabel = new QLabel("&Costs file:");
    QLabel* instituteLabel = new QLabel("&Institute file:");
    QLabel* transportLabel = new QLabel("&Transport file:");
    QLabel* weekendsLabel = new QLabel("&Weekends file:");

    QPushButton* _buttonBrowseCostsFile = new QPushButton("Browse");
    QPushButton* _buttonBrowseInstituteFile = new QPushButton("Browse");
    QPushButton* _buttonBrowseTransportFile = new QPushButton("Browse");
    QPushButton* _buttonBrowseCaffeCinemaFile = new QPushButton("Browse");

    _buttonEditCostsFile = new QPushButton("Edit");
    _buttonEditInstituteFile = new QPushButton("Edit");
    _buttonEditTransportFile = new QPushButton("Edit");
    _buttonEditOtherCostsFile = new QPushButton("Edit");

    _buttonEditCostsFile->setEnabled(false);
    _buttonEditInstituteFile->setEnabled(false);
    _buttonEditTransportFile->setEnabled(false);
    _buttonEditOtherCostsFile->setEnabled(false);

    costsLabel->setBuddy(_buttonBrowseCostsFile);
    instituteLabel->setBuddy(_buttonBrowseInstituteFile);
    transportLabel->setBuddy(_buttonBrowseTransportFile);
    weekendsLabel->setBuddy(_buttonBrowseCaffeCinemaFile);

    connect(_buttonBrowseCostsFile, SIGNAL(clicked()), SLOT(costsFileDialog()));
    connect(_buttonBrowseInstituteFile, SIGNAL(clicked()), SLOT(instituteFileDialog()));
    connect(_buttonBrowseTransportFile, SIGNAL(clicked()), SLOT(transportFileDialog()));
    connect(_buttonBrowseCaffeCinemaFile, SIGNAL(clicked()), SLOT(otherCostsFileDialog()));

    connect(_buttonEditCostsFile, SIGNAL(clicked()), SLOT(editCostsFile()));
    connect(_buttonEditInstituteFile, SIGNAL(clicked()), SLOT(editInstituteFile()));
    connect(_buttonEditTransportFile, SIGNAL(clicked()), SLOT(editTransportFile()));
    connect(_buttonEditOtherCostsFile, SIGNAL(clicked()), SLOT(editCaffeCinemaFile()));

    QGridLayout* fileChoiceWidgetLayout = new QGridLayout();

    fileChoiceWidgetLayout->addWidget(costsLabel, 0, 0);
    fileChoiceWidgetLayout->addWidget(_buttonBrowseCostsFile, 0, 1);
    fileChoiceWidgetLayout->addWidget(_buttonEditCostsFile, 0, 2);
    fileChoiceWidgetLayout->addWidget(instituteLabel, 1, 0);
    fileChoiceWidgetLayout->addWidget(_buttonBrowseInstituteFile, 1, 1);
    fileChoiceWidgetLayout->addWidget(_buttonEditInstituteFile, 1, 2);
    fileChoiceWidgetLayout->addWidget(transportLabel, 2, 0);
    fileChoiceWidgetLayout->addWidget(_buttonBrowseTransportFile, 2, 1);
    fileChoiceWidgetLayout->addWidget(_buttonEditTransportFile, 2, 2);
    fileChoiceWidgetLayout->addWidget(weekendsLabel, 3, 0);
    fileChoiceWidgetLayout->addWidget(_buttonBrowseCaffeCinemaFile, 3, 1);
    fileChoiceWidgetLayout->addWidget(_buttonEditOtherCostsFile, 3, 2);

    fileChoiceWidget->setLayout(fileChoiceWidgetLayout);
    return fileChoiceWidget;
}

QTabWidget* StudentCalculator::tabWidget() {
    QTabWidget* calculatorTab = new QTabWidget();

    calculatorTab->addTab(studentInputWidget(), "&Input");
    calculatorTab->addTab(fileChoiceWidget(), "&Data");

    return calculatorTab;
}

QPushButton* StudentCalculator::calculateButton() {
    _calculateButton = new QPushButton();

    connect(_calculateButton, SIGNAL(clicked(bool)), SLOT(startCalculate()));
    updateCalculateButton();

    return _calculateButton;
}