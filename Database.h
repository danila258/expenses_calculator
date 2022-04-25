#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include <string>
#include <vector>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>

typedef QVector<QStringList> fileData;

class Database {
public:
    Database() = default;
    explicit Database(int n);

    void storeFile(std::string& filePath, int fileNum);
    void restoreFile(int fileNum);

    fileData& operator[](int i);


private:
    std::vector<fileData> _filesData;
    std::vector<QString> _filesPathes;
};

#endif //DATABASE_H