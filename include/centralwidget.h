#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>

#include "tablewithbuttons.h"
#include "textwithbuttonscontainer.h"

class CentralWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CentralWidget(QWidget *parent = nullptr);

private:
    QGridLayout* gridLayout;
    QHBoxLayout* buttonsLayout;

    TableWithButtons* tableWithButtons;
    TextWithButtonsContainer* textWithButtonsContainer;

    bool isStyleWindowHidden = false;
    QPushButton* hideStyleButton;
    QPushButton* hideTableButton;
    QPushButton* hideTextPanelButton;
    QPushButton* clearTextFieldsButton;
    QPushButton* addTextFieldButton;
signals:
    void message(const QString&); // this signal which should be connected to status bar
    void showHideStyleWindowPushed(bool isShow);
public slots:
    void SetStyleWindowHidden(bool styleWindowHidden) {isStyleWindowHidden = styleWindowHidden;}
private slots:
    void hideStyleButtonHandler();
    void hideTableButtonHandler();
    void hideTextPanelButtonHandler();
    void clearTextFieldsButtonHandler();
    void addTextFieldButtonHandler();
};

#endif // CENTRALWIDGET_H
