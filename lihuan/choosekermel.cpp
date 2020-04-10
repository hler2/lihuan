#include "choosekermel.h"

ChooseKermel::ChooseKermel(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *pMainLayout = new QVBoxLayout();
    //pMainLayout->setSpacing(20);
    //pMainLayout->addStretch();

    QHBoxLayout *pHBoxLayout3 = new QHBoxLayout();
    DLabel *pDLabel = new DLabel(tr("选择Kernel"));
    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    pDLabel->setFont(font);
    pHBoxLayout3->addWidget(pDLabel);
    pMainLayout->addLayout(pHBoxLayout3);

    QHBoxLayout *pHBoxLayoutdeb = new QHBoxLayout();
    DLabel *pDLabelker = new DLabel(tr("Kernel"));
    pHBoxLayoutdeb->addWidget(pDLabelker);
    pMainLayout->addLayout(pHBoxLayoutdeb);

    QHBoxLayout *pHBoxLayout1 = new QHBoxLayout();
    openfileKernel = new DFileChooserEdit();
    openfileKernel->setNameFilters(QStringList("*.iso"));
    pHBoxLayout1->addWidget(openfileKernel);
    pMainLayout->addLayout(pHBoxLayout1);

    QHBoxLayout *pHBoxLayoutdeb1 = new QHBoxLayout();
    DLabel *pDLabelin = new DLabel(tr("initrd"));
    pHBoxLayoutdeb1->addWidget(pDLabelin);
    pMainLayout->addLayout(pHBoxLayoutdeb1);

    QHBoxLayout *pHBoxLayoutin = new QHBoxLayout();
    openfileInitrd = new DFileChooserEdit();
    openfileInitrd->setNameFilters(QStringList("*.iso"));
    pHBoxLayoutin->addWidget(openfileInitrd);
    pMainLayout->addLayout(pHBoxLayoutin);


    pMainLayout->addStretch(100);

    QHBoxLayout *pHBoxLayout2 = new QHBoxLayout();
    //pHBoxLayout2->addStretch();
    pDpushBtn2 = new DPushButton(QStringLiteral("下一步"));
     pDpushBtn2->setEnabled(false);
    connect(pDpushBtn2, &DPushButton::clicked, this, &ChooseKermel::slotDpushBtnNextClicked);
    pDpushBtn2->setFixedWidth(300);

    pHBoxLayout2->addWidget(pDpushBtn2);
    pMainLayout->addLayout(pHBoxLayout2);

    pMainLayout->addStretch();
    this->setLayout(pMainLayout);

}
void ChooseKermel::slotDpushBtnNextClicked()
{
    emit toOutput();

}
void ChooseKermel::slotDpushBtnOpenClicked()
{
    qDebug()<<"open";
}
