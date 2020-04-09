#include "selectframe.h"

SelectFrame::SelectFrame(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *pMainLayout = new QVBoxLayout();
//    pMainLayout->setSpacing(40);
//    pMainLayout->addStretch();


    QHBoxLayout *pHBoxLayout = new QHBoxLayout();
    DLabel *pDLabel = new DLabel(tr("选择架构"));
    pHBoxLayout->addWidget(pDLabel);
    pMainLayout->addLayout(pHBoxLayout);

    QFont font;
    font.setPointSize(20);
    font.setBold(true);
    pDLabel->setFont(font);

    QHBoxLayout *pHBoxLayout1 = new QHBoxLayout();
    //pHBoxLayout->addStretch();

    m_pDListView = new DListView();

     QStandardItemModel *pItemModel = new QStandardItemModel();
    DStandardItem *pItem1 = new DStandardItem(tr("ARM"));
    pItemModel->appendRow(pItem1);
   // pItem1->setCheckState(Qt::Unchecked);
    DStandardItem *pItem2 = new DStandardItem(tr("X86"));
    pItemModel->appendRow(pItem2);
   // pItem2->setCheckState(Qt::Unchecked);
    DStandardItem *pItem3 = new DStandardItem(tr("MIPS"));
    pItemModel->appendRow(pItem3);
   //pItem3->setCheckState(Qt::Unchecked);
    m_pDListView->setModel(pItemModel);

    //setFocusPolicy(Qt::NoFocus); // 得到焦点时，不显示虚线框


    pHBoxLayout1->addWidget(m_pDListView);


    pMainLayout->addLayout(pHBoxLayout1);

    QHBoxLayout *pHBoxLayout2 = new QHBoxLayout();
    pMainLayout->addLayout(pHBoxLayout2);

    pMainLayout->addStretch(100);
    QHBoxLayout *pHBoxLayout3 = new QHBoxLayout();

    DPushButton *pDpushBtn2 = new DPushButton(QStringLiteral("下一步"));
    pDpushBtn2->setEnabled(false);
    connect(pDpushBtn2, &DPushButton::clicked, this, &SelectFrame::slotDpushBtnNextClicked);
    pDpushBtn2->setFixedWidth(300);

    pHBoxLayout3->addWidget(pDpushBtn2);
    pMainLayout->addLayout(pHBoxLayout3);

    pMainLayout->addStretch();
    this->setLayout(pMainLayout);

    connect(m_pDListView, &DListView::clicked,[=](const QModelIndex &index){
        for (int i = 0;i < index.row();i++) {
            pItemModel->item(index.row())->setCheckState(Qt::Unchecked);
        }
        pItemModel->item(index.row())->setCheckState(Qt::Checked);
        pDpushBtn2->setEnabled(true);
    });

}

SelectFrame::~SelectFrame()
{

}
void SelectFrame::slotDpushBtnNextClicked()
{
    emit toProgramConfiguration();

}

