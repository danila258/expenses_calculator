#ifndef STUDENT_CALCULATOR_FILEEDITWIDGET_H
#define STUDENT_CALCULATOR_FILEEDITWIDGET_H

#include <QtWidgets>
#include <string>
using std::string;


class FileEditWidget : public QWidget {
    Q_OBJECT

public:
    FileEditWidget (const QStringList& tableHeader, std::vector<std::vector<string>>& file, QWidget* parent = nullptr);

private:
    void fileTable(const QStringList& tableHeader);

    void deleteRow();
    void addRow();
    void cancelEditFile();
    void saveNewFile();

    std::vector<std::vector<string>>& _file;

    QTableWidget* _table;

};


#endif //STUDENT_CALCULATOR_FILEEDITWIDGET_H