#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

struct Student {
public:
    Student() = default;
    Student(int age, QString& city, QString& address, QString& institute, QString cafe, QString cinema) :
            _age(age), _city(city), _address(address), _institute(institute), _cafe(cafe), _cinema(cinema) {
    }

    int _age;
    QString _name;
    QString _city;
    QString _address;
    QString _institute;
    QString _cafe;
    QString _cinema;
};

#endif //STUDENT_H
