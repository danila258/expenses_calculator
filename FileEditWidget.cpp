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

    QGridLayout* FileEditWidgetLayout = new QGridLayout();

    FileEditWidgetLayout->addWidget(_table, 0, 0);
    FileEditWidgetLayout->addWidget(buttonDeleteRow, 1, 0);
    FileEditWidgetLayout->addWidget(buttonAddRow, 1, 1);
    FileEditWidgetLayout->addWidget(buttonCancelFile, 2, 0);
    FileEditWidgetLayout->addWidget(buttonSaveFile, 2, 1);

    setLayout(FileEditWidgetLayout);
}

void FileEditWidget::fileTable(const QStringList& tableHeader) {
    _table = new QTableWidget(_file.size(), tableHeader.size(), this);
    _table->setHorizontalHeaderLabels(tableHeader);
    _table->setShowGrid(true);

    for (int i = 0; i < 10 /*_file.size()*/; ++i) {
        for (int k = 0; k < tableHeader.size(); ++k) {
            QTableWidgetItem* item = new QTableWidgetItem(QString::fromStdString(_file[i][k]));
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

    for (int i = 1; i < _table->rowCount(); ++i) {
        for (int k = 0; k < _table->columnCount(); ++k) {
            file[i][k] = _table->itemAt(i, k)->text().toStdString();
        }
    }

    _file = std::move(file);
    cancelEditFile();
}