#include "StudentCalculator.h"


StudentCalculator::~StudentCalculator() {
    delete _ageSpinBox;
    delete _calculateButton;

    delete _buttonEditCostsFile;
    delete _buttonEditInstituteFile;
    delete _buttonEditTransportFile;
    delete _buttonEditOtherCostsFile;
}

void StudentCalculator::fileEditWidget(const QStringList &labels) {
    fileTable(labels);

    QPushButton* buttonDeleteRow = new QPushButton("Delete Row");
    QPushButton* buttonAddRow = new QPushButton("Add row");
    QPushButton* buttonCancelFile = new QPushButton("Cancel");
    QPushButton* buttonSaveFile = new QPushButton("Save");

    connect(buttonDeleteRow, SIGNAL(clicked()), SLOT(deleteRow()));
    connect(buttonAddRow, SIGNAL(clicked()), SLOT(addRow()));
    connect(buttonCancelFile, SIGNAL(clicked()), SLOT(cancelEditFile()));
    connect(buttonSaveFile, SIGNAL(clicked()), SLOT(saveNewFile()));

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(buttonDeleteRow, 0, 0);
    layout->addWidget(buttonAddRow, 0, 1);
    layout->addWidget(buttonCancelFile, 1, 0);
    layout->addWidget(buttonSaveFile, 1, 1);

    _fileEditWidget->setLayout(layout);
    _fileEditWidget->show();
}

void StudentCalculator::updateCalculateButton() {
    int count = 0;

    for (int i = 0; i < countCheckedFields; ++i) {
        count += _completeFieldsArr[i];
    }

    if (count == 10) {
        _calculateButton->setEnabled(true);
        _calculateButton->setText("Calculate");
    }
    else {
        _calculateButton->setEnabled(false);
        QString line = QString::number(count);
        _calculateButton->setText(line + "/10");
    }
}


void StudentCalculator::errorDataLoadShow(const std::vector<string>& dataLoudErrors) {
    string lineForWarning;

    for (int i = 0; i < dataLoudErrors.size(); ++i) {
        lineForWarning += dataLoudErrors[i];
        lineForWarning += '\n';
    }

    QMessageBox* errorInput = new QMessageBox(QMessageBox::Warning, "Warning", QString::fromStdString(lineForWarning),
                                              QMessageBox::Ok, this);
    errorInput->show();
}

void StudentCalculator::studentMoneyShow(int sum) {
    QString line = "The " + QString::fromStdString(_name) + " spend " + QString::number(sum) + " rubles";

    QMessageBox* studentMoney = new QMessageBox(QMessageBox::Information, " ", line,
                                                QMessageBox::Ok, this);
    studentMoney->show();
}