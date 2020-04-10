#include "chooseISO.h"

#include <QFileDialog>
chooseISO::chooseISO(QWidget *parent)
    : QWidget(parent)


{
    qDebug()<<"333333";

    QVBoxLayout *pMainLayout = new QVBoxLayout();

    QHBoxLayout *pHBoxLayout3 = new QHBoxLayout();

    DLabel *pDLabel = new DLabel(tr("选择ISO"));
    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    pDLabel->setFont(font);
    pHBoxLayout3->addWidget(pDLabel);
    pMainLayout->addLayout(pHBoxLayout3);

    QHBoxLayout *pHBoxLayout1 = new QHBoxLayout();

    openfile = new DFileChooserEdit();
    openfile->setNameFilters(QStringList("*.iso"));
    pHBoxLayout1->addWidget(openfile);
    pMainLayout->addLayout(pHBoxLayout1);
    connect(openfile, &DFileChooserEdit::textChanged, this, &chooseISO::slotDpushBtnOpenClicked);


    pMainLayout->addStretch(90);

    QHBoxLayout *pHBoxLayout2 = new QHBoxLayout();
    pDpushBtn2 = new DPushButton(QStringLiteral("下一步"));
    pDpushBtn2->setEnabled(false);
    connect(pDpushBtn2, &DPushButton::clicked, this, &chooseISO::slotDpushBtnNextClicked);
    pDpushBtn2->setFixedWidth(300);
    pHBoxLayout2->addWidget(pDpushBtn2);
    pMainLayout->addLayout(pHBoxLayout2);
    pMainLayout->addStretch();
    this->setLayout(pMainLayout);

}
chooseISO::~chooseISO()
{

}
void chooseISO::slotDpushBtnOpenClicked()
{
    pDpushBtn2->setEnabled(true);
}
void chooseISO::slotDpushBtnNextClicked()
{
    qDebug()<<"next"; 
    emit toSelectframe();
}


