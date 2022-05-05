#include "StudentExpenses.h"

StudentExpenses::   StudentExpenses(Student& student, fileData& costs, fileData& institute,
                                    fileData& transport, fileData& cafeCinema) {
    findCosts(student, costs);
    findInstitute(student, institute);
    findTransport(student, transport);
    findCafeCinema(student, cafeCinema);
    if (!errors.isEmpty()) {
        throw errors;
    }
}

bool StudentExpenses::checkColumnsNum(fileData& data, int n) const {
    for (int i = 0; i < data.size(); ++i) {
        if (data[i].size() != n) {
            return false;
        }
    }
    return true;
}

bool StudentExpenses::costsFileCheck(fileData& data) {
    if (data[0].join(",") == "City,Age,Average food cost per month,Other costs") {
        return checkColumnsNum(data, 4);
    }
    return "Invalid columns number.";
}

bool StudentExpenses::instituteFileCheck(fileData& data) {
    if (data[0].join(",") == "City,Institute,Dinner cost") {
        return checkColumnsNum(data, 3);
    }
    return "Invalid columns number.";
}

bool StudentExpenses::transportFileCheck(fileData& data) {
    if (data[0].join(",") == "City,District,Institute,Transport cost") {
        return checkColumnsNum(data, 4);
    }
    return "Invalid columns number.";
}

bool StudentExpenses::cafeCinemaFileCheck(fileData& data) {
    if (data[0].join(",") == "City,Address,Caffe,Average caffe cost,Cinema,Cinema cost") {
        return checkColumnsNum(data, 6);
    }
    throw "Invalid columns number.";
}

// TODO display data which I didn't find at all
void StudentExpenses::findCosts(Student& student, fileData& data) {
    bool find = false;
    bool city = false;
    bool age = false;

    for (int i = 0; i < data.size(); ++i) {
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), QString::number(student._age)) != data[i].end()) {
            find = true;
            _avgFoodCost = data[i][2].toInt();
            _otherCost = data[i][3].toInt();
        }
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()) {
            city = true;
        }
        if (std::find(data[i].begin(), data[i].end(), QString::number(student._age)) != data[i].end()) {
            age = true;
        }
    }
    QString buf;
    if (!find) {
        buf += "Costs file error.";
    }
    if (!city) {
        buf +=" City was not found.";
    }
    if (!age) {
        buf +=" Age was not found.";
    }
    if (!buf.isEmpty()) {
        errors.push_back(buf);
    }
    qDebug() << errors;
}

void StudentExpenses::findInstitute(Student &student, fileData& data) {
    bool find = false;
    bool city = false;
    bool institute = false;

    for (int i = 0; i < data.size(); ++i) {
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._institute) != data[i].end()) {
            find = true;
            _instituteFoodCost = data[i][2].toInt();
        }
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()) {
            city = true;
        }
        if (std::find(data[i].begin(), data[i].end(), student._institute) != data[i].end()) {
            institute = true;
        }
    }
    QString buf;
    if (!find) {
        buf += "Institute file error.";
    }
    if (!city) {
        buf +=" City was not found.";
    }
    if (!institute) {
        buf +=" Institute was not found.";
    }
    if (!buf.isEmpty()) {
        errors.push_back(buf);
    }
    qDebug() << errors;
}

void StudentExpenses::findTransport(Student& student, fileData& data) {
    bool find = false;
    bool city = false;
    bool address = false;
    bool institute = false;

    for (int i = 0; i < data.size(); ++i) {
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._address) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._institute) != data[i].end()) {
            find = true;
            _transportCost = data[i][3].toInt();
        }
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()) {
            city = true;
        }
        if (std::find(data[i].begin(), data[i].end(), student._address) != data[i].end()) {
            address = true;
        }
        if (std::find(data[i].begin(), data[i].end(), student._institute) != data[i].end()) {
            institute = true;
        }
    }
    QString buf;
    if (!find) {
        buf += "Transport file error.";
    }
    if (!city) {
        buf +=" City was not found.";
    }
    if (!address) {
        buf +=" Address was not found.";
    }
    if (!institute) {
        buf +=" Institute was not found.";
    }
    if (!buf.isEmpty()) {
        errors.push_back(buf);
    }
    qDebug() << errors;
}

void StudentExpenses::findCafeCinema(Student &student, fileData& data) {
    bool find = false;
    bool city = false;
    bool cafe = false;
    bool address = false;
    bool cinema = false;
    for (int i = 0; i < data.size(); ++i) {
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._cafe) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._address) != data[i].end()
            && std::find(data[i].begin(), data[i].end(), student._cinema) != data[i].end()) {
            find = true;
            _cafeCost = data[i][3].toInt();
            _cinemaCost = data[i][5].toInt();
        }
        if (std::find(data[i].begin(), data[i].end(), student._city) != data[i].end()) {
            city = true;
        }
        if (std::find(data[i].begin(), data[i].end(), student._cafe) != data[i].end()) {
            cafe = true;
        }
        if (std::find(data[i].begin(), data[i].end(), student._address) != data[i].end()) {
            address = true;
        }
        if (std::find(data[i].begin(), data[i].end(), student._cinema) != data[i].end()) {
            cinema = true;
        }
    }
    QString buf;
    if (!find) {
        buf += "CafeCinema file error.";
    }
    if (!city) {
        buf +=" City was not found.";
    }
    if (!cafe) {
        buf +=" Cafe was not found.";
    }
    if (!address) {
        buf +=" Address was not found.";
    }
    if (!cinema) {
        buf +=" Cinema was not found.";
    }
    if (!buf.isEmpty()) {
        errors.push_back(buf);
    }
    qDebug() << errors;
}