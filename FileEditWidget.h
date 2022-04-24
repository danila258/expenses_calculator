#ifndef FILEEDITWIDGET_H
#define FILEEDITWIDGET_H

#include <QtWidgets>
#include <string>
using std::string;


class FileEditWidget : public QDialog {
    Q_OBJECT

public:
    FileEditWidget (const QStringList& tableHeader, std::vector<std::vector<string>>& file, QWidget* parent = nullptr);
    ~FileEditWidget();

private slots:
    void deleteRow();
    void addRow();
    void cancelEditFile();
    void saveNewFile();

private:
    void fileTable(const QStringList& headerLabels);

    std::vector< std::vector<string> >& _file;

    QTableWidget* _table;
};


#endif //FILEEDITWIDGET_H