#ifndef MIDINSTALLATION_H
#define MIDINSTALLATION_H

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

class MidInstallation : public QWidget
{
    Q_OBJECT
public:
    explicit MidInstallation(QWidget *parent = nullptr);

signals:
    void toPostCleaning();

private:
    DFloatingMessage *pDLabeldeb;
    DPushButton *pDpushBtn2;
    DLabel *pDLabelChoose;
public slots:
    void slotDpushBtnNextClicked();
    void slotDpushBtnClearClicked();
};

#endif // MIDINSTALLATION_H
