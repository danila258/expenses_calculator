#include "StudentsDatabase.h"

void Database::setCosts(std::string filePath) {
    std::ifstream file(filePath);

    _costsPath = filePath;

    std::string buf, buf2;
    int r = 0;
    int c = 0;

    _costsData.resize(100);
    // rework this

    getline(file, buf);
    getline(file, buf);
    while (!file.eof()) {
        std::stringstream strStream(buf);

        for (int i = 0; i < _costsDataColumns; ++i) {
            getline(strStream, buf2, ',');
            _costsData.at(r).push_back(buf2);
            ++c;
        }

        getline(file, buf);

        c = 0;
        r++;
    }
    _costsDataRows = r;

}

void Database::setInstitute(std::string filePath) {
    std::ifstream file(filePath);


    _institutePath = filePath;

    std::string buf, buf2;
    int r = 0;
    int c = 0;

    _instituteData.resize(100);
    // rework this

    getline(file, buf);
    getline(file, buf);
    while (!file.eof()) {
        std::stringstream strStream(buf);

        for (int i = 0; i < _instituteDataColumns; ++i) {
            getline(strStream, buf2, ',');
            _instituteData.at(r).push_back(buf2);
            ++c;
        }

        getline(file, buf);

        c = 0;
        r++;
    }
    _instituteDataRows = r;
}

void Database::setTransport(std::string filePath) {
    std::ifstream file(filePath);


    _transportPath = filePath;

    std::string buf, buf2;
    int r = 0;
    int c = 0;

    _transportData.resize(100);
    // rework this

    getline(file, buf);
    getline(file, buf);
    while (!file.eof()) {
        std::stringstream strStream(buf);

        for (int i = 0; i < _transportDataColumns; ++i) {
            getline(strStream, buf2, ',');
            _transportData.at(r).push_back(buf2);
            ++c;
        }

        getline(file, buf);

        c = 0;
        r++;
    }
    _transportDataRows = r;
}

void Database::setCafeCinema(std::string filePath) {
    std::ifstream file(filePath);


    _cafeCinemaPath = filePath;

    std::string buf, buf2;
    int r = 0;
    int c = 0;

    _cafeCinemaData.resize(100);
    // rework this

    getline(file, buf);
    getline(file, buf);
    while (!file.eof()) {
        std::stringstream strStream(buf);

        for (int i = 0; i < _cafeCinemaDataColumns; ++i) {
            getline(strStream, buf2, ',');
            _cafeCinemaData.at(r).push_back(buf2);
            ++c;
        }

        getline(file, buf);

        c = 0;
        r++;
    }
    _cafeCinemaDataRows = r;
}

//std::string Database::getCostsDataStr() const {
//    std::string buf;
//    std::ostringstream oss;
//
//    for (int i = 0; i < _costsDataRows; ++i) {
//        std::copy(_costsData.at(i).begin(), _costsData.at(i).end()-1,
//                  std::ostream_iterator<std::string>(oss, ","));
//        oss << _costsData.at(i).back();
//        buf += oss.str();
////        std::cout << buf;
//        buf += "\n";
//    }
//    buf.erase(buf.size()- 1, 1);
//    return buf;
//}

//std::vector<std::vector<std::string>>& Database::getCostsData() {
//    return _costsData;
//};
//
//std::vector<std::vector<std::string>>& Database::getInstituteData() {
//    return _instituteData;
//};
//
//std::vector<std::vector<std::string>>& Database::getTransportData() {
//    return _transportData;
//};
//
//std::vector<std::vector<std::string>>& Database::getCafeCinemaData() {
//    return _cafeCinemaData;
//};

void Database::resetCosts() {
    std::ofstream file(_costsPath, std::ios_base::trunc);
    if (!file.is_open()) {
        // throw
    }

    file << "City,Age,Average food cost per month,Other costs\n";

    std::string buf;
    for (int i = 0; i < _costsDataRows; ++i) {
        for (int j = 0; j < _costsDataColumns - 1; ++j) {
            buf += _costsData[i][j] + ",";
        }
        buf += _costsData[i][_costsDataColumns - 1] + "\n";
        file << buf;
        buf.clear();
    }
}

void Database::resetInstitute() {
    std::ofstream file(_institutePath, std::ios_base::trunc);
    if (!file.is_open()) {
        // throw
    }

    file << "City,Institute,Dinner cost\n";

    std::string buf;
    for (int i = 0; i < _instituteDataRows; ++i) {
        for (int j = 0; j < _instituteDataColumns - 1; ++j) {
            buf += _instituteData[i][j] + ",";
        }
        buf += _instituteData[i][_instituteDataColumns - 1] + "\n";
        file << buf;
        buf.clear();
    }
}

void Database::resetTransport() {
    std::ofstream file(_transportPath, std::ios_base::trunc);
    if (!file.is_open()) {
        // throw
    }

    file << "City,District,Institute,Transport cost\n";

    std::string buf;
    for (int i = 0; i < _transportDataRows; ++i) {
        for (int j = 0; j < _transportDataColumns - 1; ++j) {
            buf += _transportData[i][j] + ",";
        }
        buf += _transportData[i][_transportDataColumns - 1] + "\n";
        file << buf;
        buf.clear();
    }
}

void Database::resetCafeCinema() {
    std::ofstream file(_cafeCinemaPath, std::ios_base::trunc);
    if (!file.is_open()) {
        // throw
    }

    file << "City,Address,Caffe,Average caffe cost,Cinema,Cinema cost\n";

    std::string buf;
    for (int i = 0; i < _cafeCinemaDataRows; ++i) {
        for (int j = 0; j < _cafeCinemaDataColumns - 1; ++j) {
            buf += _cafeCinemaData[i][j] + ",";
        }
        buf += _cafeCinemaData[i][_cafeCinemaDataColumns - 1] + "\n";
        file << buf;
        buf.clear();
    }
}

std::vector<std::string>& Database::findStudentInfo(Student& student) {
    findCosts(student);
    findInstitute(student);
    findTransport(student);
    findCafeCinema(student);

    return errors;
}

void Database::findCosts(Student& student) {
    bool find = false;
    for (int i = 0; i < _costsDataRows; ++i) {
        if (std::find(_costsData[i].begin(), _costsData[i].end(), student._city) != _costsData[i].end()
                && std::find(_costsData[i].begin(), _costsData[i].end(), std::to_string(student._age)) != _costsData[i].end()) {
            find = true;
            student._avgFoodCost = std::stoi(_costsData[i][2]);
            student._otherCost = std::stoi(_costsData[i][3]);
        }
    }
    if (!find) {
        errors.push_back("Costs file error.");
    }
}

void Database::findInstitute(Student &student) {
    bool find = false;
    for (int i = 0; i < _instituteDataRows; ++i) {
        if (std::find(_instituteData[i].begin(), _instituteData[i].end(), student._city) != _instituteData[i].end()
                && std::find(_instituteData[i].begin(), _instituteData[i].end(), student._institute) != _instituteData[i].end()) {
            find = true;
            student._instituteFoodCost = std::stoi(_instituteData[i][2]);
        }
    }
    if (!find) {
        errors.push_back("Institute file error.");
    }
}

void Database::findTransport(Student &student) {
    bool find = false;
    for (int i = 0; i < _transportDataRows; ++i) {
        if (std::find(_transportData[i].begin(), _transportData[i].end(), student._city) != _transportData[i].end()
                && std::find(_transportData[i].begin(), _transportData[i].end(), student._address) != _transportData[i].end()
                && std::find(_transportData[i].begin(), _transportData[i].end(), student._institute) != _transportData[i].end()) {
            find = true;
            student._transportCost = std::stoi(_transportData[i][3]);
        }
    }
    if (!find) {
        errors.push_back("Transport file error.");
    }
}

void Database::findCafeCinema(Student &student) {
    bool find = false;
    for (int i = 0; i < _cafeCinemaDataRows; ++i) {
        if (std::find(_cafeCinemaData[i].begin(), _cafeCinemaData[i].end(), student._city) != _cafeCinemaData[i].end()
                && std::find(_cafeCinemaData[i].begin(), _cafeCinemaData[i].end(), student._cafe) != _cafeCinemaData[i].end()
                && std::find(_cafeCinemaData[i].begin(), _cafeCinemaData[i].end(), student._address) != _cafeCinemaData[i].end()
                && std::find(_cafeCinemaData[i].begin(), _cafeCinemaData[i].end(), student._cinema) != _cafeCinemaData[i].end()) {
            find = true;
            student._cafeCost = std::stoi(_cafeCinemaData[i][3]);
            student._cinemaCost = std::stoi(_cafeCinemaData[i][5]);
        }
    }
    if (!find) {
        errors.push_back("Cinema file error.");
    }
}