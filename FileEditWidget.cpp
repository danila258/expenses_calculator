#include "FileEditWidget.h"

FileEditWidget::FileEditWidget(QVector<QStringList>& file, QWidget *parent) : _file(file), _tableHeader(_file[0]) {
    move(parent->pos());
    setWindowFlags(Qt::Window);
    resize(600, 600);

    fileTable();

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

void FileEditWidget::fileTable() {
    _table = new QTableWidget(_file.size() - 1, _file[0].size(), this);
    _table->setHorizontalHeaderLabels(_tableHeader);
    _table->setShowGrid(true);

    for (int i = 1; i < _file.size(); ++i) {
        for (int k = 0; k < _file[0].size(); ++k) {
            QTableWidgetItem* item = new QTableWidgetItem(_file[i][k]);
            _table->setItem(i - 1, k, item);
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
    QVector<QStringList> file(_table->rowCount() + 1);
    file[0] = _tableHeader;

    for (int i = 0; i < _table->rowCount(); ++i) {
        for (int k = 0; k < _table->columnCount(); ++k) {
            if (_table->item(i, k) == nullptr) {
                file[i + 1].push_back("0");
            }
            else {
                file[i + 1].push_back(_table->item(i, k)->text());
            }
        }
    }

    _file = std::move(file);

    this->close();
    this->setResult(QDialog::Accepted);
}