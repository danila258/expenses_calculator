#ifndef FILEEDITWIDGET_H
#define FILEEDITWIDGET_H

#include <QtWidgets>
#include <string>
using std::string;


class FileEditWidget : public QDialog {
    Q_OBJECT

public:
    FileEditWidget (QVector<QStringList>& file, QWidget* parent = nullptr);
    ~FileEditWidget();

private slots:
    void deleteRow();
    void addRow();
    void cancelEditFile();
    void saveNewFile();

private:
    void fileTable();

    QVector<QStringList>& _file;
    const QStringList& _tableHeader;

    QTableWidget* _table;
};


#endif //FILEEDITWIDGET_H