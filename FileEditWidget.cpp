#include "FileEditWidget.h"

FileEditWidget::FileEditWidget(const QStringList& tableHeader, std::vector<std::vector<std::string>> &file,
                               QWidget *parent) : _file(file) {

    fileTable(tableHeader);

    QPushButton* buttonDeleteRow = new QPushButton("Delete Row");
    QPushButton* buttonAddRow = new QPushButton("Add row");
    QPushButton* buttonCancelFile = new QPushButton("Cancel");
    QPushButton* buttonSaveFile = new QPushButton("Save");

    connect(buttonDeleteRow, SIGNAL(clicked()), SLOT(deleteRow()));
    connect(buttonAddRow, SIGNAL(clicked()), SLOT(addRow()));
    connect(buttonCancelFile, SIGNAL(clicked()), SLOT(cancelEditFile()));
    connect(buttonSaveFile, SIGNAL(clicked()), SLOT(saveNewFile()));

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(buttonDeleteRow, 0, 0);
    layout->addWidget(buttonAddRow, 0, 1);
    layout->addWidget(buttonCancelFile, 1, 0);
    layout->addWidget(buttonSaveFile, 1, 1);

    setLayout(layout);
    show();
}

void FileEditWidget::fileTable(const QStringList& tableHeader) {
    _table = new QTableWidget(_file.size(), tableHeader.size(), this);
    _table->setHorizontalHeaderLabels(tableHeader);
    _table->setShowGrid(true);

    for (int i = 0; i < _file.size(); ++i) {
        for (int k = 0; k < tableHeader.size(); ++k) {
            QString str = QString::fromStdString(_file[i][k]);
            QTableWidgetItem* item = new QTableWidgetItem(str);
            _table->setItem(i, k, item);
        }
    }
}

void FileEditWidget::deleteRow() {
    _table->removeRow(_table->rowCount() - 1);
}

void FileEditWidget::addRow() {
    _table->insertRow(_table->rowCount());
}

void FileEditWidget::cancelEditFile() {
    QWidget::close();
}

void FileEditWidget::saveNewFile() {
    std::vector<std::vector<std::string>> file;
    string item;

    for (int i = 1; i < _table->rowCount(); ++i) {
        for (int k = 0; k < _table->columnCount(); ++k) {
            item = _table->itemAt(i, k)->text().toStdString();
            file[i][k] = item;
        }
    }

    _file = std::move(file);
    cancelEditFile();
}