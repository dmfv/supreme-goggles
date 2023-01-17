#include <QStringList>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QApplication>

#include "stylewindow.h"

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
    connect(listWidget, &QListWidget::itemPressed, this, &StyleWindow::ChangeStyle);
    setWidget(listWidget);
    ChangeStyle(listWidget->item(0));
}

void StyleWindow::ChangeStyle(QListWidgetItem* item)
{
    if (item == currentItem)
        return;
    currentItem = item;
    // it's necessary to put config folder with files near app
    QFile file(QDir::currentPath() + "/config/" + item->text() + ".stylesheet"); // looks urgly

    if (!file.exists()) {
        // react
        qDebug() << "FILE(" << file.filesystemSymLinkTarget() << ") DOESN'T EXIST" << "\n";
        return;
    }
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll()); // TODO: move this actions to
    qApp->setStyleSheet(styleSheet);
    WriteCurrentStyle();
}

void StyleWindow::WriteCurrentStyle()
{
    QFile file(QDir::currentPath() + "/config/" + configName);
    if (!file.exists()) {
        // react
        qDebug() << "FILE(" << file.filesystemFileName() << ") DOESN'T EXIST add this file" << "\n";
        return;
    }
    file.open(QFile::WriteOnly);
    QTextStream Stream(&file);
    Stream << "[view]\n";
    Stream << "style = " << currentItem->text();
}
