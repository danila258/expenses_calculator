#include "StudentCalculator.h"


int main(int argc, char *argv[]) {
    QApplication Application(argc, argv);

    StudentCalculator calculator;
    calculator.show();

    return Application.exec();
}