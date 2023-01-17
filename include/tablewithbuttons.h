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

private:
    QGridLayout* gridLayout;

    QTableWidget* tableWidget;
    //QList<QTableWidgetItem>* tableRows;

    QPushButton*  addLineButton;
    QPushButton*  deleteLineButton;


};

#endif // TABLEWITHBUTTONS
