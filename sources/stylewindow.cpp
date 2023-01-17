#include "stylewindow.h"
#include <QStringList>

StyleWindow::StyleWindow(const QString& str, QWidget *parent)
    : QDockWidget{str, parent}
{
    setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    listWidget = new QListWidget(this);
    listWidget->addItems(QStringList()
                         << "Grey"
                         << "Red"
                         << "Green"
                         << "Blue");

    setWidget(listWidget);
}
