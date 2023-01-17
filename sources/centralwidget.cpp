#include "centralwidget.h"
#include <QDebug> // TODO delete this

CentralWidget::CentralWidget(QWidget *parent)
    : QWidget{parent}
{
    // creation
    gridLayout = new QGridLayout(this);
    buttonsLayout = new QHBoxLayout(this);

    tableWithButtons = new TableWithButtons(this);
    textWithButtonsContainer = new TextWithButtonsContainer(this);

    // buttons
    hideStyleButton = new QPushButton("Hide style panel");
    hideTableButton = new QPushButton("Hide table");
    hideTextPanelButton = new QPushButton("Hide text panel");
    clearTextFieldsButton = new QPushButton("Clear text fields");
    addTextFieldButton = new QPushButton("Add text field");

    // buttons handler
    connect(hideStyleButton, &QPushButton::clicked, this, &CentralWidget::hideStyleButtonHandler);
    connect(hideTableButton, &QPushButton::clicked, this, &CentralWidget::hideTableButtonHandler);
    connect(hideTextPanelButton, &QPushButton::clicked, this, &CentralWidget::hideTextPanelButtonHandler);
    connect(clearTextFieldsButton, &QPushButton::clicked, this, &CentralWidget::clearTextFieldsButtonHandler);
    connect(addTextFieldButton, &QPushButton::clicked, this, &CentralWidget::addTextFieldButtonHandler);

    // text with buttons container signal:
    connect(textWithButtonsContainer, &TextWithButtonsContainer::message, this, [this](const QString& str){emit message(str);});

    // assignment
    buttonsLayout->addWidget(hideStyleButton);
    buttonsLayout->addWidget(hideTableButton);
    buttonsLayout->addWidget(hideTextPanelButton);
    buttonsLayout->addWidget(clearTextFieldsButton);
    buttonsLayout->addWidget(addTextFieldButton);

    setLayout(gridLayout);
    gridLayout->addWidget(tableWithButtons, 2, 1);
    gridLayout->addLayout(buttonsLayout, 1, 1, 1, 2);
    gridLayout->addWidget(textWithButtonsContainer, 2, 2);
}

void CentralWidget::hideStyleButtonHandler()
{
    if (isStyleWindowHidden == false) {
        emit showHideStyleWindowPushed(true);
        SetStyleWindowHidden(true);
    }
    else {
        emit showHideStyleWindowPushed(false);
        SetStyleWindowHidden(false);
    }
}

void CentralWidget::hideTableButtonHandler()
{
    if (tableWithButtons->isHidden()) {
        tableWithButtons->show();
        tableWithButtons->raise();
        hideTableButton->setText("Hide table"); // TODO: move this same code to specific class of at least specific function
    }
    else {
        tableWithButtons->hide();
        tableWithButtons->lower();
        hideTableButton->setText("Show table");
    }
}

void CentralWidget::hideTextPanelButtonHandler()
{
    if (textWithButtonsContainer->isHidden()) {
        textWithButtonsContainer->show();
        hideTextPanelButton->setText("Hide text panel");
    }
    else {
        textWithButtonsContainer->hide();
        hideTextPanelButton->setText("Show text panel");
    }
}

void CentralWidget::clearTextFieldsButtonHandler()
{
    qInfo("clearTextFieldsButton pushed");
    textWithButtonsContainer->ClearText();
}

void CentralWidget::addTextFieldButtonHandler()
{
    qInfo("addTextFieldButton pushed");
    textWithButtonsContainer->AddTextField();
}

void CentralWidget::SetStyleWindowHidden(bool isHidden)
{
    isStyleWindowHidden = isHidden;
    if (isHidden) {
        hideStyleButton->setText("Show text panel");
    }
    else {
        hideStyleButton->setText("Hide text panel");
    }
}
