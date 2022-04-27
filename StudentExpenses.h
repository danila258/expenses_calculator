#ifndef STUDENTEXPENSES_H
#define STUDENTEXPENSES_H

#include "Student.h"
#include <QFile>
#include <QStringList>
#include <QVector>
#include <QString>

typedef QVector<QStringList> fileData;

struct StudentExpenses {
public:
    StudentExpenses() = default;
    StudentExpenses(Student& student, fileData& costs, fileData& institute,
                    fileData& transport, fileData& cafeCinema);

    bool costsFileCheck(fileData& data);
    bool instituteFileCheck(fileData& data);
    bool transportFileCheck(fileData& data);
    bool cafeCinemaFileCheck(fileData& data);

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

private:
    bool checkColumnsNum(fileData& data, int i) const;
};


#endif //STUDENTEXPENSES_H
