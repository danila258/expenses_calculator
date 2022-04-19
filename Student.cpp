#include "Student.h"

Student::Student(size_t age, const string& city, const string& address, const string& institute,
                 const string& cinema, const string& caffe, const Database& data) :
                 _city(city), _address(address), _cinema(cinema), _institute(institute), _age(age), _data(data) {}

size_t Student::getWeekendCost() const {
    return static_cast<size_t>(_data.getCinemaCost() + _data.getCoffeeCost());
}

size_t Student::getWorkdayCost() const {
    return static_cast<size_t>(2 * _data.getTransportCost() + _data.getInstituteDinnerCost());
}

size_t Student::getCosts(size_t month) const {
    const size_t daysCount = Database::getDaysCount(month);
    const size_t workDays = Database::getWorkdays(month);
    const size_t weekends = daysCount - workDays;

    return workDays * getWorkdayCost() + weekends * getWeekendCost() + _data.getOtherMonthlyCosts()
        + _data.getHomeFoodCost();
}