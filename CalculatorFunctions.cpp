#include "StudentCalculator.h"

QWidget* StudentCalculator::fileEditWidget(std::vector<std::vector<std::string>> file, const QStringList &labels,
                                           std::function<void()>& sendFile) {

    fileTable(file, labels);
    *(_sendFile) = new sendFile; //TODO как сделать указатель на функцию из твоей публичной?


    //осталось 3 кнопки


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
    QString line = "The " + QString::fromStdString(_name) + " spend " + QString::number(sum) + " rubles";

    QMessageBox* studentMoney = new QMessageBox(QMessageBox::Information, "Warning", line,
                                                QMessageBox::Ok, this);
    studentMoney->show();
}