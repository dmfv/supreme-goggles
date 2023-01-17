#ifndef TABLEWITHBUTTONS
#define TABLEWITHBUTTONS

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QTableWidget>

class TableWithButtons : public QWidget
{
     Q_OBJECT
public:
    explicit TableWithButtons(QWidget *parent = nullptr);

signals:

private slots:
    void addLineToTable();
    void deleteLineFromTable();
private:
    QGridLayout* gridLayout;

    QTableWidget* tableWidget;

    QPushButton*  addLineButton;
    QPushButton*  deleteLineButton;

    qint32 rowsCounter = 0;
};

#endif // TABLEWITHBUTTONS
