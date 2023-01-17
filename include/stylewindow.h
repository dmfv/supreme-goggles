#ifndef STYLEWINDOW_H
#define STYLEWINDOW_H

#include <QDockWidget>
#include <QListWidget>

class StyleWindow : public QDockWidget
{
    Q_OBJECT
public:
    explicit StyleWindow(const QString& str = "Style", QWidget *parent = nullptr);

signals:
    void itemClicked(QListWidgetItem *item);
private:
    QListWidget* listWidget;

};

#endif // STYLEWINDOW_H
