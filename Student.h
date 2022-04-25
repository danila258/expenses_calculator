#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

struct Student {
public:
    Student(int age, std::string& city, std::string& address, std::string& institute,
            std::string cafe, std::string cinema) :
            _age(age), _city(city), _address(address), _institute(institute), _cafe(cafe), _cinema(cinema) {
    }

    int _age;
    std::string _city;
    std::string _address;
    std::string _institute;
    std::string _cafe;
    std::string _cinema;
};

#endif //STUDENT_H
