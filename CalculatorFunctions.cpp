#include "StudentCalculator.h"

StudentCalculator::~StudentCalculator() {
    delete _ageSpinBox;

    delete _buttonEditCostsFile;
    delete _buttonEditInstituteFile;
    delete _buttonEditTransportFile;
    delete _buttonEditOtherCostsFile;

    delete _calculateButton;
}

void StudentCalculator::updateCalculateButton() {
    int count = 0;

    for (int i = 0; i < countCheckedFields; ++i) {
        count += _completeFieldsArr[i];
    }

    if ( count == 10 ) {
        _calculateButton->setEnabled(true);
        _calculateButton->setText("Calculate");
    }
    else {
        _calculateButton->setEnabled(false);
        _calculateButton->setText(QString::number(count) + "/10");
    }
}

void StudentCalculator::errorDataLoadShow(const QVector<QString>& dataLoudErrors) {
    QString lineForWarning;

    for (int i = 0; i < dataLoudErrors.size(); ++i) {
        lineForWarning += "<font color=\"red\">" + dataLoudErrors[i] + "</font><br>";
    }

    QMessageBox* errorInput = new QMessageBox(QMessageBox::Warning, "Warning", lineForWarning,
                                              QMessageBox::Ok, this);
    errorInput->show();
}

void StudentCalculator::errorDataLoadShow() {
    QVector<QString> errorsVector = {"File structure error."};
    errorDataLoadShow(errorsVector);
}

void StudentCalculator::studentMoneyShow(int sum) {
    QString line = "Student " + _student._name + " spend " + QString::number(sum) + " rubles";

    QMessageBox* studentMoney = new QMessageBox(QMessageBox::Information, " ", line,
                                                QMessageBox::Ok, this);
    studentMoney->show();
}

bool StudentCalculator::fileEditWidgetShow(QVector<QStringList>& _file) {
    hide();
    FileEditWidget* fileEditWidget = new FileEditWidget(_file, this);
    bool dialogCode = fileEditWidget->exec();
    show();

    this->move(fileEditWidget->pos());

    return dialogCode;
}

void StudentCalculator::switchButtonMode(int index, bool flag, QPushButton* button) {
    button->setEnabled(flag);
    calculateButtonFlag(index, flag);

    if (!flag) {
        errorDataLoadShow();
    }
}

void StudentCalculator::calculateButtonFlag(int index, bool flag) {
    _completeFieldsArr[index] = flag;
    updateCalculateButton();
}