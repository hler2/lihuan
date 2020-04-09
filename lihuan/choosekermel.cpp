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
    m_pDLineEdit = new DLineEdit();
    pHBoxLayout1->addWidget(m_pDLineEdit);

    DPushButton *pDPusBtn = new DPushButton(tr("..."));
    pDPusBtn->setStyleSheet("background-color:#0081FF;");

    connect(pDPusBtn, &DPushButton::clicked, this, [=] {
        DFileDialog *pDFileDialog = new DFileDialog();
        pDFileDialog->setAcceptMode(QFileDialog::AcceptOpen); //文件对话框为打开文件类型
        pDFileDialog->setDirectory("./Desktop");
        pDFileDialog->setNameFilter(tr("*.txt"));
        //pDFileDialog->setFileMode(QFileDialog::ExistingFiles); //可同时选择打开多个文件
        pDFileDialog->show();
        pDFileDialog->exec();

        QStringList strlistSelectedName = pDFileDialog->selectedFiles();
        for (QString strSelectFile : strlistSelectedName) {
             QFileInfo fileInfo(strSelectFile);
            m_pDLineEdit->setText(fileInfo.filePath());


        }
    });

    pHBoxLayout1->addWidget(pDPusBtn);
    pMainLayout->addLayout(pHBoxLayout1);

    QHBoxLayout *pHBoxLayoutdeb1 = new QHBoxLayout();
    DLabel *pDLabelin = new DLabel(tr("initrd"));
    pHBoxLayoutdeb1->addWidget(pDLabelin);
    pMainLayout->addLayout(pHBoxLayoutdeb1);

    QHBoxLayout *pHBoxLayoutin = new QHBoxLayout();
    m_pDLineEdit1 = new DLineEdit();
    pHBoxLayoutin->addWidget(m_pDLineEdit1);

    DPushButton *pDPusBtnin = new DPushButton(tr("..."));
    pDPusBtnin->setStyleSheet("background-color:#0081FF;");
    connect(pDPusBtnin, &DPushButton::clicked, this, [=] {
        DFileDialog *pDFileDialog = new DFileDialog();
        pDFileDialog->setAcceptMode(QFileDialog::AcceptOpen); //文件对话框为打开文件类型
        pDFileDialog->setDirectory("./Desktop");
        pDFileDialog->setNameFilter(tr("*.txt"));
        //pDFileDialog->setFileMode(QFileDialog::ExistingFiles); //可同时选择打开多个文件
        pDFileDialog->show();
        pDFileDialog->exec();

        QStringList strlistSelectedName1 = pDFileDialog->selectedFiles();
        for (QString strSelectFile1 : strlistSelectedName1) {
            QFileInfo fileInfo1(strSelectFile1);
            m_pDLineEdit1->setText(fileInfo1.filePath());
            if((m_pDLineEdit->text() != "") && (m_pDLineEdit1->text() == fileInfo1.filePath()))
            {
                pDpushBtn2->setEnabled(true);
            }
        }
    });

    pHBoxLayoutin->addWidget(pDPusBtnin);
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
