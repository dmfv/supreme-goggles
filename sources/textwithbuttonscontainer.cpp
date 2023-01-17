#include "textwithbuttonscontainer.h"

TextWithButtonsContainer::TextWithButtonsContainer(QWidget *parent)
    : QWidget{parent}
{
    boxLayout = new QVBoxLayout();
    setLayout(boxLayout);
    CreateNewTextWithButtons();

    // retain when hidden
    QSizePolicy sp_retain = sizePolicy(); // TODO: move this to based class RetainedWidget
    sp_retain.setRetainSizeWhenHidden(true);
    setSizePolicy(sp_retain);
}

void TextWithButtonsContainer::CreateNewTextWithButtons()
{
    TextWithButtons* newWidget = new TextWithButtons(QString("Text_" + QString::number(innerCounter++)));
    boxLayout->addWidget(newWidget);
    textWithButtonsSet.insert(newWidget);
    // connect signals
    connect(newWidget, &TextWithButtons::okButtonClicked, this, [this](const QString& str){emit message(str);});
    connect(newWidget, &TextWithButtons::closeButtonClicked, this, &TextWithButtonsContainer::DeleteLastTextWithButtons);
}

void TextWithButtonsContainer::DeleteLastTextWithButtons(TextWithButtons* widgetPtr)
{
    boxLayout->removeWidget(widgetPtr);
    textWithButtonsSet.remove(widgetPtr);
    delete widgetPtr;
}

void TextWithButtonsContainer::ClearText()
{
    for (auto i = textWithButtonsSet.begin(); i != textWithButtonsSet.end(); ++i) {
        (*i)->ClearText();
    }
}
