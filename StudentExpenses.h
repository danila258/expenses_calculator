#ifndef STUDENTEXPENSES_H
#define STUDENTEXPENSES_H

#include "Student.h"
#include <QFile>
#include <QStringList>
#include <QVector>
#include <QString>

//#include <algorithm>

typedef QVector<QStringList> fileData;

struct StudentExpenses {
public:
    StudentExpenses(Student& student, fileData& costs, fileData& institute,
                    fileData& transport, fileData& cafeCinema);

    void findCosts(Student& student, fileData& data);
    void findInstitute(Student &student, fileData& data);
    void findTransport(Student &student, fileData& data);
    void findCafeCinema(Student &student, fileData& data);

    int _avgFoodCost{};
    int _otherCost{};
    int _transportCost{};
    int _instituteFoodCost{};
    int _cafeCost{};
    int _cinemaCost{};

    QVector<QString> errors;
};


#endif //STUDENTEXPENSES_H
