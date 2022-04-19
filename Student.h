#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Database.h"

using std::string;

class Student {
public:
    Student(size_t age, const string& city, const string& address, const string& institute,
            const string& cinema, const string& caffe, const Database& data);

    size_t getWeekendCost() const;
    size_t getWorkdayCost() const;
    size_t getCosts(size_t month) const;

private:
    size_t _age;
    string _city;
    string _address;
    string _institute;
    string _cinema;
    string _caffe;

    Database _data;
};

#endif //STUDENT_H
