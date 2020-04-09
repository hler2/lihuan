#include "output.h"

Output::Output(QWidget *parent) : QWidget(parent)
{
    m_ptimer = new QTimer();
    m_ptimer->setInterval(100);
    connect(m_ptimer, &QTimer::timeout, this, &Output::slotTimerOut);
    QVBoxLayout *pVBoxLayout = new QVBoxLayout(this);
    //pVBoxLayout->addWidget(m_pStackedWidget);

//    pVBoxLayout->setSpacing(20);
//    pVBoxLayout->addStretch();

    QHBoxLayout *pHBoxLayout3 = new QHBoxLayout();
    pHBoxLayout3->addSpacing(110);
    pDLabel = new DLabel(tr("准备输出"));

    pHBoxLayout3->addSpacing(110);
    QFont font;
    font.setPointSize(20);
    font.setBold(true);

    pDLabel->setFont(font);
    pHBoxLayout3->addWidget(pDLabel);
    pVBoxLayout->addLayout(pHBoxLayout3);

    pVBoxLayout->addStretch(50);

    QHBoxLayout *pHBoxLayouticon = new QHBoxLayout();
    pHBoxLayouticon->addStretch();
    labicon = new  DLabel();
    labicon->resize(110,110);
    labicon->setPixmap(QPixmap(":/icons/deepin/builtin/light/icons/iso_progress_110px.svg"));
    labicon->hide();
    pHBoxLayouticon->addWidget(labicon);
     pHBoxLayouticon->addStretch();
    pVBoxLayout->addLayout(pHBoxLayouticon);

    QHBoxLayout *pHBoxLayouticonfalse = new QHBoxLayout();
    pHBoxLayouticonfalse->addStretch();
    labiconfalse = new  DLabel();
    labiconfalse->resize(110,110);
    labiconfalse->setPixmap(QPixmap(":/icons/deepin/builtin/light/icons/iso_fail_110px.svg"));
    labiconfalse->hide();
    pHBoxLayouticonfalse->addWidget(labiconfalse);
     pHBoxLayouticonfalse->addStretch();
    pVBoxLayout->addLayout(pHBoxLayouticonfalse);


    QHBoxLayout *pHBoxLayout = new QHBoxLayout();
    pHBoxLayout->addStretch();
    m_pDWaterProgress = new DWaterProgress();
    m_pDWaterProgress->setTextVisible(true);
    m_pDWaterProgress->setValue(m_valus);
    pHBoxLayout->addWidget(m_pDWaterProgress);
    pHBoxLayout->addStretch();
    pVBoxLayout->addLayout(pHBoxLayout);

    QHBoxLayout *pHBoxLayout1 = new QHBoxLayout();
    pHBoxLayout1->addSpacing(115);
    laboutput = new  DLabel(tr("正在制作，请稍后..."));
    pHBoxLayout1->addSpacing(115);
    laboutput->hide();
    pHBoxLayout1->addWidget(laboutput);
    pVBoxLayout->addLayout(pHBoxLayout1);

    QHBoxLayout *pHBoxLayoutfail = new QHBoxLayout();
    pHBoxLayoutfail->addSpacing(100);
    laboutputfail = new  DLabel(tr("失败原因：解压失败"));
    pHBoxLayoutfail->addSpacing(100);
    laboutputfail->hide();
    pHBoxLayoutfail->addWidget(laboutputfail);
    pVBoxLayout->addLayout(pHBoxLayoutfail);

     pVBoxLayout->addStretch(50);

     QHBoxLayout *pHBoxLayoutok = new QHBoxLayout();
     pHBoxLayoutok->addSpacing(50);
     m_pDPushButtonok = new DPushButton(tr("完成"));
     //m_pDPushButton->setCheckable(true);
     m_pDPushButtonok->setFixedWidth(220);
     pHBoxLayoutok->addWidget(m_pDPushButtonok);

     m_pDPushButtonchakan = new DPushButton(tr("查看"));
     m_pDPushButtonok->setFixedWidth(220);

     pHBoxLayoutok->addWidget(m_pDPushButtonchakan);
     m_pDPushButtonok->hide();
     m_pDPushButtonchakan->hide();

     pHBoxLayoutok->addSpacing(50);
     pVBoxLayout->addLayout(pHBoxLayoutok);


    QHBoxLayout *pHBoxLayout2 = new QHBoxLayout();
    pHBoxLayout2->addStretch();
    m_pDPushButton = new DPushButton(tr("下一步"));
    //m_pDPushButton->setCheckable(true);
    connect(m_pDPushButton, &DPushButton::clicked, this, &Output::slotDpushBtnNextClicked);
    m_pDPushButton->setFixedWidth(300);
    pHBoxLayout2->addWidget(m_pDPushButton);

    pHBoxLayout2->addStretch();
    pVBoxLayout->addLayout(pHBoxLayout2);

    pVBoxLayout->addStretch();
    this->setLayout(pVBoxLayout);
}

void Output::slotDpushBtnNextClicked()
{
     m_pDPushButton->setEnabled(false);
     laboutput->show();

      m_ptimer->start();
      pDLabel->setText(tr("正在输出"));


}

void Output::slotTimerOut()
{
    m_valus += 1;
    if(m_valus == 100)
    {
        //m_valus = 0;
        m_ptimer->stop();
        pDLabel->setText(tr("输出成功"));
         //m_pStackedWidget->addWidget(m_falseWidget);
        m_pDWaterProgress->hide();
        labicon->show();
       laboutput->setText(tr("制作成功"));
       m_pDPushButton->hide();
       m_pDPushButtonok->show();
       m_pDPushButtonchakan->show();
       connect(m_pDPushButtonchakan, &DPushButton::clicked, this, &Output::slotDpushBtnfalseClicked);

    }
    m_pDWaterProgress->setValue(m_valus);
    update();
}
void Output::slotDpushBtnfalseClicked()
{
    pDLabel->setText(tr("输出失败"));
    laboutput->setText(tr("制作失败"));
    m_pDPushButton->show();
    m_pDPushButton->setEnabled(true);
    m_pDPushButton->setText(tr("关闭"));
    labiconfalse->show();
    labicon->hide();
    laboutputfail->show();
    m_pDPushButtonok->hide();
    m_pDPushButtonchakan->hide();


}

