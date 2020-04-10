#ifndef CHOOSEKERMEL_H
#define CHOOSEKERMEL_H

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
#include <QWidget>

class ChooseKermel : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseKermel(QWidget *parent = nullptr);

signals:
    void toOutput();

private:
    DLineEdit *m_pDLineEdit ;
    DLineEdit *m_pDLineEdit1 ;
    DPushButton *pDpushBtn2;
    DFileChooserEdit *openfileKernel;
    DFileChooserEdit *openfileInitrd;



public slots:
    void slotDpushBtnOpenClicked();
    void slotDpushBtnNextClicked();
};

#endif // CHOOSEKERMEL_H
