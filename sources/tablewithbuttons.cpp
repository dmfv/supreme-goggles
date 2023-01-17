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
    //tableWidget->removeRow();

    addLineButton = new QPushButton("Add line");
    deleteLineButton = new QPushButton("Delete line");

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
