#include "Database.h"

//TODO rewrite all for to iterators
// TODO выбираешь вместо Costs file - institute file

Database::Database(int n) {
    _filesData.resize(n);
    _filesPathes.resize(n);
}

void Database::storeFile(std::string& filePath, int fileNum) {
    QFile file(QString::fromStdString(filePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return;
    }
    _filesPathes[fileNum] = QString::fromStdString(filePath);

    QStringList buf;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        buf.append(line.split(','));
        _filesData[fileNum].push_back(buf);
        buf.clear();
    }
    qDebug() << _filesData[fileNum];
}

void Database::restoreFile(int fileNum) {
    QFile file(_filesPathes[fileNum]);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << file.errorString();
        return;
    }
    for (int i = 0; i < _filesData[fileNum].size(); ++i) {
        for (int j = 0; j < _filesData[fileNum][j].size(); ++j) {
            file.write(_filesData[fileNum][i][j].toUtf8());
            if (j != _filesData[fileNum][j].size() - 1) {
                file.write(",");
            }
        }
        file.write("\n");
    }
    qDebug() << _filesData[fileNum];
}

fileData& Database::operator[](int i) {
    return _filesData[i];
}
