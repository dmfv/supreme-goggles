#ifndef STYLEWINDOW_H
#define STYLEWINDOW_H

#include <QDockWidget>
#include <QListWidget>
#include <QHash>

class StyleWindow : public QDockWidget
{
    Q_OBJECT
public:
    explicit StyleWindow(const QString& str = "Style", QWidget *parent = nullptr);

signals:

private:
    void ChangeStyle(QListWidgetItem*);
    void WriteCurrentStyle();

    QListWidgetItem* currentItem;
    QListWidget* listWidget;
    QString configName = "config.ini";
};

#endif // STYLEWINDOW_H
