#include "programconfiguration.h"

ProgramConfiguration::ProgramConfiguration(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *pMainLayout = new QVBoxLayout();

    QHBoxLayout *pHBoxLayoutProgramConfiguration = new QHBoxLayout();
    DLabel *pDLabel = new DLabel(tr("程序配置"));
    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    pDLabel->setFont(font);
    DCommandLinkButton *pDCommandLinkButtonclear = new DCommandLinkButton(tr("全部清除"));
    pHBoxLayoutProgramConfiguration->addWidget(pDLabel);
    pHBoxLayoutProgramConfiguration->addStretch();
    pHBoxLayoutProgramConfiguration->addWidget(pDCommandLinkButtonclear);
    pDCommandLinkButtonclear->hide();
    pMainLayout->addLayout(pHBoxLayoutProgramConfiguration);

    QHBoxLayout *pHBoxLayoutdeb = new QHBoxLayout();
    pDLabeldeb = new DFloatingMessage();

    pHBoxLayoutdeb->addWidget(pDLabeldeb);
    pDLabeldeb->hide();
    pMainLayout->addLayout(pHBoxLayoutdeb);
    pMainLayout->addStretch(50);

    QHBoxLayout *pHBoxLayoutChoose = new QHBoxLayout();
    DLabel *pDLabelChoose = new DLabel(tr("请选择程序"));
    pHBoxLayoutChoose->setAlignment(Qt::AlignCenter);
    pHBoxLayoutChoose->addWidget(pDLabelChoose);
    pMainLayout->addLayout(pHBoxLayoutChoose);
    QFont font1;
    font1.setPointSize(20);
    pDLabelChoose->setFont(font1);
    pMainLayout->addStretch(50);

    QHBoxLayout *pWidetHBoxLayout = new QHBoxLayout();
    DCommandLinkButton *pDCommandLinkButton = new DCommandLinkButton(tr("选择程序deb包"));
    connect(pDCommandLinkButton, &DCommandLinkButton::clicked, this, [=] {
        DFileDialog *pDFileDialog = new DFileDialog();
        pDFileDialog->setAcceptMode(QFileDialog::AcceptOpen); //文件对话框为打开文件类型
        pDFileDialog->setDirectory("./Desktop");
        pDFileDialog->setNameFilter(tr("*.txt"));
        pDFileDialog->setFileMode(QFileDialog::ExistingFiles); //可同时选择打开多个文件
        pDFileDialog->show();
        pDFileDialog->exec();

        QStringList strlistSelectedName = pDFileDialog->selectedFiles();
        for (QString strSelectFile : strlistSelectedName) {
            QFileInfo fileInfo(strSelectFile);
            pDLabeldeb->setMessage(fileInfo.filePath());

            pDLabelChoose->hide();
            pDCommandLinkButtonclear->show();
            pDLabeldeb->show();
            connect(pDCommandLinkButtonclear, &DCommandLinkButton::clicked, this, &ProgramConfiguration::slotDpushBtnClearClicked);

        }
    });
    pWidetHBoxLayout->setAlignment(Qt::AlignCenter);
    pWidetHBoxLayout->addWidget(pDCommandLinkButton);
    pMainLayout->addLayout(pWidetHBoxLayout);



    QHBoxLayout *pHBoxLayout2 = new QHBoxLayout();
    //pHBoxLayout2->addStretch();
    pDpushBtn2 = new DPushButton(QStringLiteral("下一步"));

    connect(pDpushBtn2, &DPushButton::clicked, this, &ProgramConfiguration::slotDpushBtnNextClicked);
    pDpushBtn2->setFixedWidth(300);

    pHBoxLayout2->addWidget(pDpushBtn2);
    pMainLayout->addLayout(pHBoxLayout2);

    pMainLayout->addStretch();
    this->setLayout(pMainLayout);

}
ProgramConfiguration::~ProgramConfiguration()
{

}
void ProgramConfiguration::slotDpushBtnNextClicked()
{
    qDebug()<<"next";
    emit toPreparation();

}
void ProgramConfiguration::slotDpushBtnClearClicked()
{
    qDebug()<<"clear";
    pDLabeldeb->close();
}
