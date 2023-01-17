#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>

#include "centralwidget.h"
#include "stylewindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void ShowHideStyleWindow(bool);
private:
    CentralWidget* centralWidget;
    StyleWindow*   styleWindow;

    QMenuBar*    menuBar;
    QMenu*       menu1;
    QMenu*       menu2;

    QStatusBar*  statusBar;
};
#endif // MAINWINDOW_H
