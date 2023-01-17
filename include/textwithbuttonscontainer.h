#ifndef TEXTWITHBUTTONSCONTAINER_H
#define TEXTWITHBUTTONSCONTAINER_H

#include <QWidget>
#include <QVBoxLayout>

#include "textwithbuttons.h"

class TextWithButtonsContainer : public QWidget
{
    Q_OBJECT
public:
    explicit TextWithButtonsContainer(QWidget *parent = nullptr);
    void CreateNewTextWithButtons();
    void DeleteLastTextWithButtons(TextWithButtons*);
public slots:
    void ClearText();
    void AddTextField() {CreateNewTextWithButtons();}
signals:
    void message(const QString&); // ok button clicked
private:
    qint32 innerCounter = 1;
    QVBoxLayout* boxLayout;
    QSet<TextWithButtons*> textWithButtonsSet;
};

#endif // TEXTWITHBUTTONSCONTAINER_H
