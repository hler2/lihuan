#ifndef PROGRAMCONFIGURATION_H
#define PROGRAMCONFIGURATION_H

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


class ProgramConfiguration : public QWidget
{
    Q_OBJECT
public:
    explicit ProgramConfiguration(QWidget *parent = nullptr);
    ~ProgramConfiguration();

signals:
    void toPreparation();
private:

    DFloatingMessage *pDLabeldeb;
    DPushButton *pDpushBtn2;
public slots:
    void slotDpushBtnNextClicked();
    void slotDpushBtnClearClicked();
};

#endif // PROGRAMCONFIGURATION_H
