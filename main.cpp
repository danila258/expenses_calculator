#include "StudentCalculator.h"


int main(int argc, char *argv[]) {

    bool enableHighDpiScaling = false;

    {
        QApplication testApp(argc, argv);

        if ( (testApp.screens().at(0)->geometry().width() > 1200) &&
             (testApp.screens().at(0)->geometry().height() > 2000) ) {

            enableHighDpiScaling = true;
        }
    }

    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling, enableHighDpiScaling);
    QApplication Application(argc, argv);

    StudentCalculator calculator;
    calculator.show();

    return QApplication::exec();
}