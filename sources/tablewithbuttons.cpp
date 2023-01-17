 #include "tablewithbuttons.h"
#include <QHeaderView>

TableWithButtons::TableWithButtons(QWidget *parent)
    : QWidget{parent}
{
    // creation
    gridLayout = new QGridLayout(this);
    tableWidget = new QTableWidget(0, 3, this);

    tableWidget->setHorizontalHeaderLabels(QStringList() << "Id" << "Parameter" << "Value");
    tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    addLineButton = new QPushButton("Add line");
    deleteLineButton = new QPushButton("Delete line");

    connect(addLineButton, &QPushButton::clicked, this, &TableWithButtons::addLineToTable);
    connect(deleteLineButton, &QPushButton::clicked, this, &TableWithButtons::deleteLineFromTable);

    // assignment
    setLayout(gridLayout);

    gridLayout->addWidget(tableWidget, 1, 1, 1, 2);
    gridLayout->addWidget(addLineButton, 2, 1, 1, 1);
    gridLayout->addWidget(deleteLineButton, 2, 2, 1, 1);

    // retain when hidden
    QSizePolicy sp_retain = sizePolicy(); // TODO: move this to based class RetainedWidget
    sp_retain.setRetainSizeWhenHidden(true);
    setSizePolicy(sp_retain);
}

void TableWithButtons::addLineToTable()
{
    int row = tableWidget->rowCount(), column = tableWidget->columnCount();
    tableWidget->insertRow( row );
    QTableWidgetItem* item0 = new QTableWidgetItem("Id_" + QString::number(rowsCounter));
    QTableWidgetItem* item1 = new QTableWidgetItem("Parameter_" + QString::number(rowsCounter));
    QTableWidgetItem* item2 = new QTableWidgetItem("Value_" + QString::number(rowsCounter));
    ++rowsCounter;
    tableWidget->setItem(row, 0, item0);
    tableWidget->setItem(row, 1, item1);
    tableWidget->setItem(row, 2, item2);
}

void TableWithButtons::deleteLineFromTable()
{
    tableWidget->removeRow(tableWidget->rowCount() - 1);
}
