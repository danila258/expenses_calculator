#include "Database.h"

// TODO rewrite all for to iterators

Database::Database(int n) {
    _filesData.resize(n);
    _filesPathes.resize(n);
}

void Database::storeFile(QString& filePath, int fileNum) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
        return;
    }
    _filesData[fileNum].clear();

    _filesPathes[fileNum] = filePath;

    QStringList buf;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        buf.append(line.split(','));
        // columnsNum I can check there
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
