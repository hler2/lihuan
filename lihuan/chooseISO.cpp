#include "chooseISO.h"

#include <QFileDialog>
chooseISO::chooseISO(QWidget *parent)
    : QWidget(parent)


{
    qDebug()<<"333333";

    QVBoxLayout *pMainLayout = new QVBoxLayout();
    //pMainLayout->setSpacing(20);
    //pMainLayout->addStretch();

    QHBoxLayout *pHBoxLayout3 = new QHBoxLayout();
    DLabel *pDLabel = new DLabel(tr("选择ISO"));
    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    pDLabel->setFont(font);
    pHBoxLayout3->addWidget(pDLabel);
    pMainLayout->addLayout(pHBoxLayout3);

    QHBoxLayout *pHBoxLayout1 = new QHBoxLayout();
    m_pDLineEdit = new DLineEdit();
    pHBoxLayout1->addWidget(m_pDLineEdit);

    DPushButton *pDPusBtn = new DPushButton(tr("..."));
    pDPusBtn->setStyleSheet("background-color:#0081FF;");
    connect(pDPusBtn, &DPushButton::clicked, this, [=] {
        DFileDialog *pDFileDialog = new DFileDialog();
        pDFileDialog->setAcceptMode(QFileDialog::AcceptOpen); //文件对话框为打开文件类型
        pDFileDialog->setDirectory("./Desktop");
        pDFileDialog->setNameFilter(tr("*.iso"));
        //pDFileDialog->setFileMode(QFileDialog::ExistingFiles); //可同时选择打开多个文件
        pDFileDialog->show();
        pDFileDialog->exec();

        QStringList strlistSelectedName = pDFileDialog->selectedFiles();
        for (QString strSelectFile : strlistSelectedName) {
            QFileInfo fileInfo(strSelectFile);
            m_pDLineEdit->setText(fileInfo.filePath());
            if(m_pDLineEdit->text() == fileInfo.filePath())
            {
                pDpushBtn2->setEnabled(true);
            }


        }
    });

    pHBoxLayout1->addWidget(pDPusBtn);
    pMainLayout->addLayout(pHBoxLayout1);

    pMainLayout->addStretch(100);

    QHBoxLayout *pHBoxLayout2 = new QHBoxLayout();
    //pHBoxLayout2->addStretch();
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
    qDebug()<<"open";
}
void chooseISO::slotDpushBtnNextClicked()
{
    qDebug()<<"next";
   // pItemchooseISO->setIcon(QIcon(":/icons/deepin/builtin/light/NO_inactive1.svg"));


    emit toSelectframe();




}


