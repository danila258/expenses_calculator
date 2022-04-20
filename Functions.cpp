#include "StudentCalculator.h"

void StudentCalculator::updateCalculateButton() {
    int sum = _flagCity + _flagAddress + _flagCaffe + _flagCinema + _flagInstitute + _flagCostsFile +
              _flagInstituteFile + _flagOtherCostsFile + _flagTransportFile;

    if (sum == 9) {
        _calculateButton->setEnabled(true);
        _calculateButton->setText("Calculate");
    }
    else {
        _calculateButton->setEnabled(false);
        QString line = QString::number(sum);
        _calculateButton->setText(line + "/9");
    }
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

void StudentCalculator::studentMoneyShow(int sum) {
    QString line = "The student spend " + QString::number(sum) + " rubles";

    QMessageBox* studentMoney = new QMessageBox(QMessageBox::Information, "Warning", line,
                                                QMessageBox::Ok, this);
    studentMoney->show();
}