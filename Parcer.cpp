#include "Parcer.h"

// TODO rewrite all for to iterators

Parcer::Parcer(int n) {
    _filesData.resize(n);
    _filesPathes.resize(n);
}

void Parcer::storeFile(QString& filePath, int fileNum) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << file.errorString();
//        return;
        throw "File open error";
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

void Parcer::restoreFile(int fileNum) {
    QFile file(_filesPathes[fileNum]);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << file.errorString();
//        return;
        throw "File open error";
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

QVector<QString> Parcer::findData(fileData& data, QVector<QString> toFind) {
    QVector<QString> output;
    for (int i = 0; i < data.size(); ++i) {
        bool flag = true;
        for (QString str : toFind) {
            if (std::find(data[i].begin(), data[i].end(), str) == data[i].end()) {
                flag = false;
            }
        }
        if (flag) {
            for (int j = 0; j < data[i].size(); ++j) {
                if (std::find(toFind.begin(), toFind.end(), data[i][j]) == toFind.end()) {
                    output.push_back(data[i][j]);
                }
            }
        }
    }
    if (output.empty()) {
        throw "Can't find data. ";
    }
    return output;
}


fileData& Parcer::operator[](int i) {
    return _filesData[i];
}

void Parcer::clearData(int fileNum) {
    _filesData[fileNum].clear();
    _filesPathes[fileNum].clear();
}
