#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

//#include <algorithm>
//#include <iterator>

#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>

typedef QVector<QStringList> fileData;

class Database {
public:
    Database() = default;
//    StudentsDatabase(std::initializer_list<int> filesColNum);
    explicit Database(int n);

    void setFile(std::string& filePath, int fileNum);

    fileData& operator[](int i);

    /*      outdated                */
//    void setCosts(std::string filePath);
//    void setInstitute(std::string filePath);
//    void setTransport(std::string filePath);
//    void setCafeCinema(std::string filePath);


//    std::string getCostsDataStr() const;

//    std::vector<std::vector<std::string>>& getCostsData();
//    std::vector<std::vector<std::string>>& getInstituteData();
//    std::vector<std::vector<std::string>>& getTransportData();
//    std::vector<std::vector<std::string>>& getCafeCinemaData();

    void resetCosts();
    void resetInstitute();
    void resetTransport();
    void resetCafeCinema();

//    std::vector<std::string>& findStudentInfo(Student& student);

    std::vector<std::vector<std::string>> _costsData{};
    std::vector<std::vector<std::string>> _instituteData{};
    std::vector<std::vector<std::string>> _transportData{};
    std::vector<std::vector<std::string>> _cafeCinemaData{};
    /*      outdated                */

private:
    std::vector<fileData> _filesData;
    std::vector<std::string> _filesPathes;

    /*      outdated                */
//    void findCosts(Student& student);
//    void findInstitute(Student& student);
//    void findTransport(Student& student);
//    void findCafeCinema(Student& student);

    std::string _costsPath;
    std::string _institutePath;
    std::string _transportPath;
    std::string _cafeCinemaPath;

    int _costsDataRows{};
    int _costsDataColumns{4};

    int _instituteDataRows{};
    int _instituteDataColumns{3};

    int _transportDataRows{};
    int _transportDataColumns{4};

    int _cafeCinemaDataRows{};
    int _cafeCinemaDataColumns{6};
    /*      outdated                */
};

#endif //DATABASE_H