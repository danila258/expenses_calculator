#include "StudentCalculator.h"


int main(int argc, char *argv[]) {

    bool EnableHighDpiScaling = false;

    {
        QApplication startApp(argc, argv);
        if (startApp.screens().at(0)->geometry().width() > 1200 && startApp.screens().at(0)->geometry().height() > 2500) {
            EnableHighDpiScaling = true;
        }
    }

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling, EnableHighDpiScaling);
    QApplication Application(argc, argv);

    StudentCalculator calculator;
    calculator.show();

    return Application.exec();
}