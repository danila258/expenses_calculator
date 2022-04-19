#ifndef DATABASE_H
#define DATABASE_H

#include <string>
using std::string;

class Database {
public:
    Database(const string& costsFile, const string& instituteFile, const string& transportFile,
             const string& caffeCinemaFile);

    bool initDatabase();

    bool userInputCheck(size_t age, const string& city, const string& address, const string& institute,
                        const string& caffe, const string& cinema);

    size_t getOtherMonthlyCosts() const;
    size_t getHomeFoodCost() const;
    size_t getCinemaCost() const;
    size_t getCoffeeCost() const;
    size_t getInstituteDinnerCost() const;
    size_t getTransportCost() const;

    static size_t getWorkdays(size_t month);
    static size_t getDaysCount(size_t month);

private:
    string _costsFile;
    string _instituteFile;
    string _transportFile;
    string _caffeCinemaFile;

    size_t _otherCost;
    size_t _homeFoodCost;
    size_t _transportCost;
    size_t _instituteDinnerCost;
    size_t _cinemaCost;
    size_t _caffeCost;

    bool costsLoad(const string& city, size_t age);
    bool instituteLoad(const string& city, const string& institute);
    bool transportLoad(const string& city, const string& address, const string& institute);
    bool pastimeLoad(const string& city, const string& address, const string& caffe, const string& cinema);
};

#endif //DATABASE_H
