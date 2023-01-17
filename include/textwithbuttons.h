#ifndef TEXTWITHBUTTONS_H
#define TEXTWITHBUTTONS_H

#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>

class TextWithButtons : public QWidget
{
    Q_OBJECT
public:
    explicit TextWithButtons(const QString& text = "Text_Blank", QWidget *parent = nullptr);

public slots:
    void ClearText() {textEdit->setText("");}
signals:
    void okButtonClicked(const QString&);
    void closeButtonClicked(TextWithButtons*);
private:
    QGridLayout* gridLayout;
    QTextEdit*   textEdit;
    QPushButton* closeButton;
    QPushButton* okButton;
};

#endif // TEXTWITHBUTTONS_H
