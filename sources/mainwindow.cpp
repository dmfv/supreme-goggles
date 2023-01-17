#include "mainwindow.h"
#include <QApplication>

#include <QFile>
#include <QDebug>
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QFile file("C:/Projects/QtProjects/Test/config/blue.stylesheet");
    auto a = file.symLinkTarget();
    if (!file.exists()) {
        // react
        qDebug() << "FILE DOESN'T EXIST" << "\n";
    }
    qDebug() << a;
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    qDebug() << styleSheet;
    qApp->setStyleSheet(styleSheet);

    // creation
    styleWindow = new StyleWindow("Style", this);
    addDockWidget(Qt::LeftDockWidgetArea, styleWindow);

    centralWidget = new CentralWidget(this);
    menuBar = new QMenuBar(this);
    menu1 = new QMenu("First menu", this);
    menu2 = new QMenu("Second menu", this);

    QAction* action = new QAction("exit", this); // QApplication::quit();
    connect(action, &QAction::triggered, [](bool){QApplication::quit();});
    menu1->addAction(action);

    statusBar = new QStatusBar();

    // assignment
    menuBar->addMenu(menu1);
    menuBar->addMenu(menu2);

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
    if (hide)
        styleWindow->hide();
    else
        styleWindow->show();
    centralWidget->SetStyleWindowHidden(styleWindow->isHidden());
}
