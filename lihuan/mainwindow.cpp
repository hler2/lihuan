#include "mainwindow.h"


mainwindow::mainwindow(DMainWindow *parent)
    :DMainWindow(parent)
    ,m_chooseISO(new chooseISO)//选择ISO
    ,m_SelectFrame (new SelectFrame())//选择架构
    ,m_ProgramConfiguration(new ProgramConfiguration) //程序配置
    ,m_Preparation (new  Preparation())//前期准备
    ,m_MidInstallation(new MidInstallation)
    ,m_PostCleaning(new PostCleaning)
    ,m_ChooseKermel(new  ChooseKermel)
    ,m_Output(new Output)
    ,timelable (new QLabel )
    ,newHelp(new QAction)
    ,m_pCentralWidget (new QWidget())
    , m_pStackedWidget (new QStackedWidget())
    , m_pDListView (new DListView())
        //m_pCentralWidget (new DMainWindow()),
      //m_pStackedWidget (new QStackedWidget()),
      //m_pDTitlebarWidget (new DTitlebar),
      //m_MyWidget (new MyWidget())
      //m_pDLineEditWidget (new DLineEdit(this))
{

      qDebug() << "!2222222:" ;
    // setCentralWidget(m_chooseISO);



     //titlebar()设置标题
     titlebar()->setIcon(QIcon::fromTheme("iso_logo"));
     titlebar()->setTitle(tr("ISO定制工具"));//显示标题内容


     //statusBar 状态栏显示
     this->statusBar()->setSizeGripEnabled(false);

     //设置时间状态栏
//     QTimer *timer = new QTimer(this);
//     timer->start(1000);//间隔为1秒
//     connect(timer,&QTimer::timeout,this,&mainwindow::timeUpdata);

     //设置菜单栏
     DMenu *pDMenu = new DMenu;
     newHelp = new QAction(tr("帮助"),this);

     pDMenu->addAction(newHelp);
     titlebar()->setMenu(pDMenu);

     connect(newHelp,&QAction::triggered,this,&mainwindow::slotActionHlep);
    //有DFrame框架布局
     m_pMainLayout = new QHBoxLayout();
     DFrame *left = new DFrame();
     left->setFixedSize(220, 520);
     m_pMainLayout->addWidget(left);

     DFrame *right = new DFrame();
     right->setFixedSize(550, 520);
     m_pMainLayout->addWidget(right);

     //将listview布局加到frame中
     QHBoxLayout *m_pHBoxLayoutlist = new QHBoxLayout();
     m_pHBoxLayoutlist->addWidget(m_pDListView);
     left->setLayout(m_pHBoxLayoutlist);

     //将StackedWidget布局加到frame中
     QHBoxLayout *m_pHBoxLayoutstack = new QHBoxLayout();
     m_pHBoxLayoutstack->addWidget(m_pStackedWidget);
     right->setLayout(m_pHBoxLayoutstack);

     // 嵌套布局（嵌套进去布局乱了，未选择）
     //m_pDListView = new DListView(left);
     //m_pStackedWidget = new QStackedWidget(right);

     //无DFrame框架布局
     //m_pHBoxLayout = new QHBoxLayout();
    // m_pHBoxLayout->addWidget(m_pDListView, 3);
    // m_pHBoxLayout->addWidget(m_pStackedWidget, 7);

     pItemModel = new QStandardItemModel(this);


     pItemchooseISO = new DStandardItem("选择ISO");
     pItemchooseISO->setIcon(QIcon::fromTheme("iso_inactive1"));

     m_pStackedWidget->addWidget(m_chooseISO);
     m_has_ItemName_ItemWiget.insert("选择ISO", m_chooseISO);
     pItemModel->appendRow(pItemchooseISO);
     // connect函数，最后一个参数需要注意，不能使用默认
     //connect(m_chooseISO, SIGNAL(toSelectframe()), this, SLOT(fromchooseISO()), Qt::QueuedConnection);

     pItemSelectFrame = new DStandardItem("选择架构");
     pItemSelectFrame->setIcon(QIcon::fromTheme("iso_inactive2"));
     pItemSelectFrame->setEnabled(false);
     m_pStackedWidget->addWidget(m_SelectFrame);
     //m_pStackedWidget->setEnabled(false);
     m_has_ItemName_ItemWiget.insert("选择架构", m_SelectFrame);
     pItemModel->appendRow(pItemSelectFrame);
    //connect(m_SelectFrame, SIGNAL(toProgramConfiguration()), this, SLOT(fromSelectframe()), Qt::QueuedConnection);



     pItemProgramConfiguration = new DStandardItem("程序配置");
     pItemProgramConfiguration->setIcon(QIcon::fromTheme("iso_inactive3"));
      pItemProgramConfiguration->setEnabled(false);
     m_pStackedWidget->addWidget(m_ProgramConfiguration);
     m_has_ItemName_ItemWiget.insert("程序配置", m_ProgramConfiguration);
     pItemModel->appendRow(pItemProgramConfiguration);
     //connect(m_ProgramConfiguration, SIGNAL(toPreparation()), this, SLOT(fromProgramConfiguration()), Qt::QueuedConnection);


     pItemPreparation = new DStandardItem("前期准备");
     pItemPreparation->setIcon(QIcon::fromTheme("iso_inactive4"));
      pItemPreparation->setEnabled(false);
     m_pStackedWidget->addWidget(m_Preparation);
     m_has_ItemName_ItemWiget.insert("前期准备", m_Preparation);
     pItemModel->appendRow(pItemPreparation);
     //connect(m_Preparation, SIGNAL(toMidInstallation()), this, SLOT(fromPreparation()), Qt::QueuedConnection);

     pItemMidInstallation = new DStandardItem("中期安装");
     pItemMidInstallation->setIcon(QIcon::fromTheme("iso_inactive5"));
      pItemMidInstallation->setEnabled(false);
     m_pStackedWidget->addWidget(m_MidInstallation);
     m_has_ItemName_ItemWiget.insert("中期安装", m_MidInstallation);
     pItemModel->appendRow(pItemMidInstallation);
     //connect(m_MidInstallation, SIGNAL(toPostCleaning()), this, SLOT(fromMidInstallation()), Qt::QueuedConnection);

     pItemPostCleaning = new DStandardItem("后期清理");
     pItemPostCleaning->setIcon(QIcon::fromTheme("iso_inactive6"));
      pItemPostCleaning->setEnabled(false);
     m_pStackedWidget->addWidget(m_PostCleaning);
     m_has_ItemName_ItemWiget.insert("后期清理", m_PostCleaning);
     pItemModel->appendRow(pItemPostCleaning);
     //connect(m_PostCleaning, SIGNAL(toChooseKermel()), this, SLOT(fromPostCleaning()), Qt::QueuedConnection);


     pItemChooseKermel = new DStandardItem("选择Kermel");
     pItemChooseKermel->setIcon(QIcon::fromTheme("iso_inactive7"));
      pItemChooseKermel->setEnabled(false);
     m_pStackedWidget->addWidget(m_ChooseKermel);
     m_has_ItemName_ItemWiget.insert("选择Kermel", m_ChooseKermel);
     pItemModel->appendRow(pItemChooseKermel);
     //connect(m_ChooseKermel, SIGNAL(toOutput()), this, SLOT(fromChooseKermel()), Qt::QueuedConnection);



     pItemOutput = new DStandardItem("输出");
     pItemOutput->setIcon(QIcon::fromTheme("iso_inactive8"));
      pItemOutput->setEnabled(false);
     m_pStackedWidget->addWidget(m_Output);
     m_has_ItemName_ItemWiget.insert("输出", m_Output);
     pItemModel->appendRow(pItemOutput);



     connect(m_chooseISO, &chooseISO::toSelectframe, this, &mainwindow::slotListViewItem);
     connect(m_SelectFrame, &SelectFrame::toProgramConfiguration, this, &mainwindow::slotListViewItem);
     connect(m_ProgramConfiguration, &ProgramConfiguration::toPreparation, this, &mainwindow::slotListViewItem);
     connect(m_Preparation, &Preparation::toMidInstallation, this, &mainwindow::slotListViewItem);
     connect(m_MidInstallation, &MidInstallation::toPostCleaning, this, &mainwindow::slotListViewItem);
     connect(m_PostCleaning, &PostCleaning::toChooseKermel, this, &mainwindow::slotListViewItem);
     connect(m_ChooseKermel, &ChooseKermel::toOutput, this, &mainwindow::slotListViewItem);

     m_pDListView->setModel(pItemModel);
     m_pDListView->setCurrentIndex(m_pDListView->model()->index(0,0));

    // m_pStackedWidget->setCurrentWidget(m_chooseISO);//默认显示页面
     connect(m_pDListView, &DListView::pressed, this, &mainwindow::slotListViewItemClicked, Qt::QueuedConnection);
     m_pCentralWidget->setLayout(m_pMainLayout);
    setCentralWidget(m_pCentralWidget);


}
mainwindow::~mainwindow()
{

}
void mainwindow::timeUpdata()
{

//    QDateTime CurrentTime = QDateTime::currentDateTime();
//    QString Timerstr = CurrentTime.toString("yyyy年-MM月-dd日 hh:mm:ss");
//    timelable->setText(Timerstr);
//    this->statusBar()->addWidget(timelable);

}

void mainwindow::slotActionHlep()
{
    qDebug() << "Help" ;


}

void mainwindow::slotListViewItemClicked(const QModelIndex &index)
{
    QString strItemName = index.data().toString();
    qDebug() << "strItemName:" << strItemName;

    m_pStackedWidget->setCurrentWidget(m_has_ItemName_ItemWiget.value(strItemName));


}
void mainwindow::slotListViewItem()
{
        int index = m_pDListView->currentIndex().row();
        QStandardItemModel *tem = pItemModel;
        tem->item(index)->setCheckState(Qt::Checked);
        tem->item(index+1)->setEnabled(true);
        m_pDListView->setCurrentIndex(tem->indexFromItem(tem->item(index + 1)));
        m_pStackedWidget->setCurrentIndex(index+1);
}

