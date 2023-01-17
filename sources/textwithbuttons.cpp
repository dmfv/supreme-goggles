#include "textwithbuttons.h"

#include <QDebug>

TextWithButtons::TextWithButtons(const QString& text, QWidget *parent)
    : QWidget{parent}
{
    // creation
    gridLayout = new QGridLayout(this);
    textEdit = new QTextEdit(text, this);
    okButton = new QPushButton("OK", this);
    closeButton = new QPushButton("X", this);

    // button signals
    connect(okButton, &QPushButton::clicked, [this](){qInfo("debug info");    emit okButtonClicked(textEdit->toPlainText());});
    connect(closeButton, &QPushButton::clicked, [this](){qInfo("debug info"); emit closeButtonClicked(this);});

    // assignment
    setLayout(gridLayout);
    gridLayout->addWidget(textEdit, 1, 1, 3, 1);
    gridLayout->addWidget(okButton, 1, 2, 1, 1);
    gridLayout->addWidget(closeButton, 3, 2, 1, 1);

    textEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    okButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    closeButton->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
}
