#include "StudentCalculator.h"

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
}

void StudentCalculator::updateCalculateButton() {
    int sum = _flagName + _flagCity + _flagAddress + _flagCaffe + _flagCinema + _flagInstitute + _flagCostsFile +
              _flagInstituteFile + _flagOtherCostsFile + _flagTransportFile;

    if (sum == 10) {
        _calculateButton->setEnabled(true);
        _calculateButton->setText("Calculate");
    }
    else {
        _calculateButton->setEnabled(false);
        QString line = QString::number(sum);
        _calculateButton->setText(line + "/10");
    }
}


void StudentCalculator::errorDataLoadShow(const std::vector<string>& errors) {
    string errorLine = "";

    for (int i = 0; i < errors.size(); ++i) {
        errorLine += errors[i];
        errorLine += '\n';
    }

    QMessageBox* errorInput = new QMessageBox(QMessageBox::Warning, "Warning", QString::fromStdString(errorLine),
                                              QMessageBox::Ok, this);
    errorInput->show();
}

void StudentCalculator::studentMoneyShow(int sum) {
    QString line = "The " + QString::fromStdString(_name) + " spend " + QString::number(sum) + " rubles";

    QMessageBox* studentMoney = new QMessageBox(QMessageBox::Information, "Warning", line,
                                                QMessageBox::Ok, this);
    studentMoney->show();
}