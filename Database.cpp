#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Database.h"

using std::stoi;

Database::Database(const string& costsFile, const string& instituteFile, const string& transportFile,
                   const string& caffeCinemaFile) :
                   _costsFile(costsFile), _instituteFile(instituteFile), _transportFile(transportFile),
                   _caffeCinemaFile(caffeCinemaFile) {}

bool Database::initDatabase() {

    std::ifstream file1, file2, file3, file4;
    bool flag = true;

    file1.open(_costsFile);
    file2.open(_instituteFile);
    file3.open(_transportFile);
    file4.open(_caffeCinemaFile);

    if ( !(file1.is_open()) ) {
        flag = false;
    }

    if (!file2.is_open()) {
        flag = false;
    }

    if (!file3.is_open()) {
        flag = false;
    }

    if (!file4.is_open()) {
        flag = false;
    }

    return flag;
}

bool Database::userInputCheck(size_t age, const string& city, const string& address, const string& institute,
                    const string& caffe, const string& cinema) {

    return costsLoad(city, age) * instituteLoad(city, institute) * transportLoad(city, address, institute) *
        pastimeLoad(city, address, caffe, cinema);
}

bool Database::costsLoad(const string& city, size_t age) {
    std::ifstream file;
    file.open(_costsFile);

    string line, cityFile, ageFile, foodCost, otherCost;

    getline(file, line);
    getline(file, line);

    while (!file.eof()) {
        std::stringstream streamLine(line);

        getline(streamLine, cityFile, ',');
        getline(streamLine, ageFile, ',');
        getline(streamLine, foodCost, ',');
        getline(streamLine, otherCost, ',');

        if (cityFile == city && stoi(ageFile) == age) {
            _homeFoodCost = stoi(foodCost);
            _otherCost = stoi(otherCost);

            return true;
        }

        getline(file, line);
    }

    return false;
}

bool Database::instituteLoad(const string& city, const string& institute) {
    std::ifstream file;
    file.open(_instituteFile);

    string line, cityFile, instituteFile, instituteDinnerCost;

    getline(file, line);
    getline(file, line);

    while (!file.eof()) {
        std::stringstream streamLine(line);

        getline(streamLine, cityFile, ',');
        getline(streamLine, instituteFile, ',');
        getline(streamLine, instituteDinnerCost, ',');

        if (cityFile == city && instituteFile == institute) {
            _instituteDinnerCost = stoi(instituteDinnerCost);

            return true;
        }

        getline(file, line);
    }

    return false;
}

bool Database::transportLoad(const string& city, const string& address, const string& institute) {
    std::ifstream file;
    file.open(_transportFile);

    string line, cityFile, addressFile, instituteFile, transportCost;

    getline(file, line);
    getline(file, line);

    while (!file.eof()) {
        std::stringstream lineStream(line);

        getline(lineStream, cityFile, ',');
        getline(lineStream, addressFile, ',');
        getline(lineStream, instituteFile, ',');
        getline(lineStream, transportCost, ',');

        if (cityFile == city && addressFile == address && instituteFile == institute) {
            _transportCost = stoi(transportCost);

            return true;
        }

        getline(file, line);
    }

    return false;
}

bool Database::pastimeLoad(const string& city, const string& address, const string& caffe, const string& cinema) {
    std::ifstream file;
    file.open(_caffeCinemaFile);

    string line, cityFile, addressFile, caffeFile, caffeCost, cinemaFile, cinemaCost;

    getline(file, line);
    getline(file, line);

    while (!file.eof()) {
        std::stringstream streamLine(line);

        getline(streamLine, cityFile, ',');
        getline(streamLine, addressFile, ',');
        getline(streamLine, caffeFile, ',');
        getline(streamLine, caffeCost, ',');
        getline(streamLine, cinemaFile, ',');
        getline(streamLine, cinemaCost, ',');

        if (cityFile == city && addressFile == address && caffeFile == caffe && cinemaFile == cinema) {
            _caffeCost = stoi(caffeCost);
            _cinemaCost = stoi(cinemaCost);

            return true;
        }

        getline(file, line);
    }

    return false;
}

size_t Database::getWorkdays(size_t month) {
    size_t workdays[12] = {16, 19, 22, 21, 18, 21, 21, 23, 22, 21, 21, 22};
    return workdays[month - 1];
}

size_t Database::getDaysCount(size_t month) {
    size_t countDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return countDays[month - 1];
}

size_t Database::getOtherMonthlyCosts() const {
    return _otherCost;
}

size_t Database::getHomeFoodCost() const {
    return _homeFoodCost;
}

size_t Database::getTransportCost() const {
    return _transportCost;
}

size_t Database::getInstituteDinnerCost() const {
    return _instituteDinnerCost;
}

size_t Database::getCinemaCost() const {
    return _cinemaCost;
}

size_t Database::getCoffeeCost() const {
    return _caffeCost;
}