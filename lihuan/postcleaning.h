#ifndef POSTCLEANING_H
#define POSTCLEANING_H

#include <QWidget>
#include <QDebug>
#include <DPushButton>
#include <DLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFileDialog>
#include <DMessageManager>
#include <DCommandLinkButton>
#include <DFileDialog>
#include <DLineEdit>
#include <DFloatingMessage>


class PostCleaning : public QWidget
{
    Q_OBJECT
public:
    explicit PostCleaning(QWidget *parent = nullptr);

signals:
     void toChooseKermel();
private:
    DFloatingMessage *pDLabeldeb;
    DPushButton *pDpushBtn2;

public slots:
    void slotDpushBtnNextClicked();
    void slotDpushBtnClearClicked();
};

#endif // POSTCLEANING_H
