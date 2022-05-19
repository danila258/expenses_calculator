#ifndef DATABASE_H
#define DATABASE_H

#include "Student.h"
#include <vector>
#include <exception>
#include <QFile>
#include <QStringList>
#include <QTextStream>
#include <QDebug>

typedef QVector<QStringList> fileData;

class Parcer {
public:
    Parcer() = default;
    explicit Parcer(int n);

    void storeFile(QString& filePath, int fileNum);
    void restoreFile(int fileNum);

    static QVector<QString> findData(fileData& data, QVector<QString> toFind);

    fileData& operator[](int i);

    void clearData(int fileNum);

private:
    std::vector<fileData> _filesData;
    std::vector<QString> _filesPathes;
};

#endif //DATABASE_H

// GET HEADER
// FIND