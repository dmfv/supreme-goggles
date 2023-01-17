#include "mainwindow.h"
#include <QApplication>

#include <QFile>
#include <QDebug>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // creation
    styleWindow = new StyleWindow("Style", this);
    addDockWidget(Qt::LeftDockWidgetArea, styleWindow);

    centralWidget = new CentralWidget(this);
    menuBar = new QMenuBar(this);
    menu1 = new QMenu("First menu", this);
    menu2 = new QMenu("Second menu", this);

    QAction* exitAction = new QAction("Exit", this);
    QAction* action1 = new QAction("Action1", this);
    QAction* action2 = new QAction("Action2", this);
    QAction* action3 = new QAction("Action3", this);
    QMenu*   subMenu = new QMenu("SubMenu", this);

    connect(exitAction, &QAction::triggered, [](bool){QApplication::quit();});
    connect(action1, &QAction::triggered, this, [this](bool) { statusBar->showMessage("Action1"); });
    connect(action2, &QAction::triggered, this, [this](bool) { statusBar->showMessage("Action2"); });
    connect(action3, &QAction::triggered, this, [this](bool) { statusBar->showMessage("Action3"); });

    subMenu->addAction(action2);
    subMenu->addAction(action3);

    menu1->addAction(exitAction);
    menu2->addAction(action1);
    menu2->addMenu(subMenu);

    statusBar = new QStatusBar();

    // assignment
    menuBar->addMenu(menu1);
    menuBar->addMenu(menu2);

    connect(styleWindow, &StyleWindow::visibilityChanged, this, [this](bool visible){centralWidget->SetStyleWindowHidden(styleWindow->isHidden());});

    connect(centralWidget, &CentralWidget::message, this, [this](const QString& str){statusBar->showMessage(str);});
    connect(centralWidget, &CentralWidget::showHideStyleWindowPushed, this, &MainWindow::ShowHideStyleWindow);
    setCentralWidget(centralWidget);

    setMenuBar(menuBar);
    setStatusBar(statusBar);
    resize(16*70, 9*70);
    statusBar->showMessage("Hello user");
}

void MainWindow::ShowHideStyleWindow(bool hide)
{
    qDebug() << "ShowHideStyleWindow called hide: " << hide;
    if (hide)
        styleWindow->hide();
    else
        styleWindow->show();
    centralWidget->SetStyleWindowHidden(hide);
}
