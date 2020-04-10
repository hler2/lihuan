#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QGridLayout>

#include <DPasswordEdit>
#include <DPushButton>
#include <DLabel>
#include <DTextEdit>
#include <DLineEdit>
#include <QDebug>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <DMessageManager>
#include <DApplicationHelper>
#include <DFileDialog>
#include <dfilechooseredit.h>

//#include "mainwindow.h"


DWIDGET_USE_NAMESPACE

class chooseISO : public QWidget
{
    Q_OBJECT
public:
    explicit chooseISO(QWidget *parent = nullptr);
    ~chooseISO();
private:
// DLineEdit *m_pDLineEdit ;
 DPushButton *pDpushBtn2;

 DFileChooserEdit *openfile;

signals:
 void toSelectframe();

public slots:
    void slotDpushBtnOpenClicked();
    void slotDpushBtnNextClicked();

};

#endif // MYWIDGET_H
