#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DApplication>
#include <DMainWindow>
#include <QHBoxLayout>
#include <DListView>
#include <QStackedWidget>
#include <DTextEdit>
#include <DTitlebar>
#include <DSearchEdit>
#include <DButtonBox>
#include <DApplicationHelper>

#include <DStandardPaths>
#include <qsettingbackend.h>
#include <DSettingsDialog>
#include <QtDebug>

#include "chooseISO.h"
#include <QPushButton>
#include <QWidget>

#include <QTimer>
#include <QDateTime>
#include <DLineEdit>

#include <QTextEdit>
#include <QLabel>
#include <DDesktopServices>
#include <DDialog>

#include <DSlider>

#include <QString>
#include <DStatusBar>
#include <DFrame>
#include <QFrame>

#include "chooseISO.h"
#include "selectframe.h"
#include "programconfiguration.h"
#include "preparation.h"
#include "midinstallation.h"
#include "postcleaning.h"
#include "choosekermel.h"
#include "output.h"

DWIDGET_USE_NAMESPACE
class mainwindow : public DMainWindow
{
    Q_OBJECT
public:
    explicit mainwindow(DMainWindow *parent = nullptr);
    ~mainwindow();
private:
     DWidget *m_pCentralWidget;
     chooseISO * m_chooseISO;
     SelectFrame *m_SelectFrame;
     ProgramConfiguration *m_ProgramConfiguration;
     Preparation *m_Preparation;
     MidInstallation *m_MidInstallation;
     PostCleaning *m_PostCleaning;
     ChooseKermel *m_ChooseKermel;
     Output *m_Output;

     DStandardItem *pItemchooseISO;//1
     DStandardItem *pItemSelectFrame;//2
     DStandardItem *pItemProgramConfiguration;
     DStandardItem *pItemPreparation;
     DStandardItem *pItemMidInstallation;
     DStandardItem *pItemPostCleaning;
     DStandardItem *pItemChooseKermel;
     DStandardItem *pItemOutput;


     QHBoxLayout *m_pHBoxLayout;
      QHBoxLayout *m_pMainLayout;
     DListView   *m_pDListView;
     QStackedWidget *m_pStackedWidget;
     QHash<QString, QWidget*> m_has_ItemName_ItemWiget;

     QLabel * timelable;
     QAction * newHelp;

     QStandardItemModel *pItemModel;




signals:

public slots:
     void slotActionHlep();
     void slotListViewItemClicked(const QModelIndex &index);
     void fromchooseISO();
     void fromSelectframe();
     void fromProgramConfiguration();
     void fromPreparation();
     void fromMidInstallation();
     void fromPostCleaning();
     void fromChooseKermel();
     //void fromOutput();

 private:
     void timeUpdata();
};

#endif // MAINWINDOW_H
