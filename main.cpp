#include "StudentCalculator.h"
#include <iostream>


int main(int argc, char *argv[]) {

    bool enableHighDpiScaling = false;

    {
        QApplication startApp(argc, argv);
        if (startApp.screens().at(0)->geometry().width() > 1200 && startApp.screens().at(0)->geometry().height() > 2000) {
            enableHighDpiScaling = true;
        }
    }

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling, enableHighDpiScaling);
    QApplication Application(argc, argv);

    StudentCalculator calculator;
    calculator.show();

    return Application.exec();
}