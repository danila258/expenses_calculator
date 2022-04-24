#include "FileEditWidget.h"

FileEditWidget::FileEditWidget(const QStringList& tableHeader, std::vector<std::vector<std::string>> &file,
                               QWidget *parent) : _file(file) {
    move(parent->pos());
    resize(600, 600);

    fileTable(tableHeader);

    QPushButton* buttonDeleteRow = new QPushButton("Delete Row");
    QPushButton* buttonAddRow = new QPushButton("Add row");
    QPushButton* buttonCancelFile = new QPushButton("Cancel");
    QPushButton* buttonSaveFile = new QPushButton("Save");

    connect(buttonDeleteRow, SIGNAL(clicked()), SLOT(deleteRow()));
    connect(buttonAddRow, SIGNAL(clicked()), SLOT(addRow()));
    connect(buttonCancelFile, SIGNAL(clicked()), SLOT(cancelEditFile()));
    connect(buttonSaveFile, SIGNAL(clicked()), SLOT(saveNewFile()));

    QGridLayout* buttonsWidgetLayout = new QGridLayout();

    buttonsWidgetLayout->addWidget(buttonDeleteRow, 0, 0);
    buttonsWidgetLayout->addWidget(buttonAddRow, 0, 1);
    buttonsWidgetLayout->addWidget(buttonCancelFile, 1, 0);
    buttonsWidgetLayout->addWidget(buttonSaveFile, 1, 1);

    QVBoxLayout* fileEditWidgetLayout = new QVBoxLayout();

    fileEditWidgetLayout->addWidget(_table);
    fileEditWidgetLayout->addLayout(buttonsWidgetLayout);

    setLayout(fileEditWidgetLayout);
}

FileEditWidget::~FileEditWidget() {
    delete _table;
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
    this->close();
    this->setResult(QDialog::Rejected);
}

void FileEditWidget::saveNewFile() {
    std::vector<std::vector<std::string>> file(_table->rowCount());

    for (int i = 0; i < 10 /*_table->rowCount()*/; ++i) {
        for (int k = 0; k < _table->columnCount(); ++k) {
            file[i].push_back(_table->item(i, k)->text().toStdString());
        }
    }

    _file = std::move(file);

    this->close();
    this->setResult(QDialog::Accepted);
}