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

    QCheckBox* ageCheckBox = new QCheckBox("Use age");
    ageCheckBox->setChecked(true);

    _ageSpinBox = new QSpinBox();
    _ageSpinBox->setRange(7, 200);
    _ageSpinBox->setSuffix(" years old");

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

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(ageLabel, 0, 0);
    layout->addWidget(_ageSpinBox, 0, 1);
    layout->addWidget(monthLabel, 1, 0);
    layout->addWidget(monthsList, 1, 1);
    layout->addWidget(nameLabel, 2, 0);
    layout->addWidget(lineEditName, 2, 1);
    layout->addWidget(cityLabel, 3, 0);
    layout->addWidget(lineEditCity, 3, 1);
    layout->addWidget(addressLabel, 4, 0);
    layout->addWidget(lineEditAddress, 4, 1);
    layout->addWidget(instituteLabel, 5, 0);
    layout->addWidget(lineEditInstitute, 5, 1);
    layout->addWidget(cinemaLabel, 6, 0);
    layout->addWidget(lineEditCinema, 6, 1);
    layout->addWidget(caffeLabel, 7, 0);
    layout->addWidget(lineEditCaffe, 7, 1);
    layout->addWidget(ageCheckBox, 8, 0);

    studentInputWidget->setLayout(layout);
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

    _buttonEditeCostsFile = new QPushButton("Edit");
    _buttonEditeInstituteFile = new QPushButton("Edit");
    _buttonEditeTransportFile = new QPushButton("Edit");
    _buttonEditeOtherCostsFile = new QPushButton("Edit");

    _buttonEditeCostsFile->setEnabled(false);
    _buttonEditeInstituteFile->setEnabled(false);
    _buttonEditeTransportFile->setEnabled(false);
    _buttonEditeOtherCostsFile->setEnabled(false);

    costsLabel->setBuddy(_buttonBrowseCostsFile);
    instituteLabel->setBuddy(_buttonBrowseInstituteFile);
    transportLabel->setBuddy(_buttonBrowseTransportFile);
    weekendsLabel->setBuddy(_buttonBrowseCaffeCinemaFile);

    connect(_buttonBrowseCostsFile, SIGNAL(clicked()), SLOT(costsFileDialog()));
    connect(_buttonBrowseInstituteFile, SIGNAL(clicked()), SLOT(instituteFileDialog()));
    connect(_buttonBrowseTransportFile, SIGNAL(clicked()), SLOT(transportFileDialog()));
    connect(_buttonBrowseCaffeCinemaFile, SIGNAL(clicked()), SLOT(otherCostsFileDialog()));

    connect(_buttonEditeCostsFile, SIGNAL(clicked()), SLOT(EditeCostsFile()));
    connect(_buttonEditeInstituteFile, SIGNAL(clicked()), SLOT(EditeInstituteFile()));
    connect(_buttonEditeTransportFile, SIGNAL(clicked()), SLOT(EditeTransportFile()));
    connect(_buttonEditeOtherCostsFile, SIGNAL(clicked()), SLOT(EditeCaffeCinemaFile()));

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(costsLabel, 0, 0);
    layout->addWidget(_buttonBrowseCostsFile, 0, 1);
    layout->addWidget(_buttonEditeCostsFile, 0, 2);
    layout->addWidget(instituteLabel, 1, 0);
    layout->addWidget(_buttonBrowseInstituteFile, 1, 1);
    layout->addWidget(_buttonEditeInstituteFile, 1, 2);
    layout->addWidget(transportLabel, 2, 0);
    layout->addWidget(_buttonBrowseTransportFile, 2, 1);
    layout->addWidget(_buttonEditeTransportFile, 2, 2);
    layout->addWidget(weekendsLabel, 3, 0);
    layout->addWidget(_buttonBrowseCaffeCinemaFile, 3, 1);
    layout->addWidget(_buttonEditeOtherCostsFile, 3, 2);

    fileChoiceWidget->setLayout(layout);
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

void StudentCalculator::fileTable(const QStringList &labels) {

    _table = new QTableWidget(_bufVector->size(), _bufVector->size(), this);
    _table->setHorizontalHeaderLabels(labels);
    _table->setShowGrid(true);

    for (int i = 1; i < _bufVector->size(); ++i) {
        for (int k = 0; k < labels.size(); ++k) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString((*_bufVector)[i][k]));
            _table->setItem(i, k, item);
        }
    }
}