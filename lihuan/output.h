#ifndef OUTPUT_H
#define OUTPUT_H

#include <QWidget>
#include <DWaterProgress>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <DPushButton>
#include <QDebug>
#include <DLabel>
#include <QStackedWidget>

DWIDGET_USE_NAMESPACE
class Output : public QWidget
{
    Q_OBJECT
public:
    explicit Output(QWidget *parent = nullptr);

signals:

public slots:
    void slotDpushBtnNextClicked();
    void slotDpushBtnfalseClicked();
    void slotTimerOut();
private:
    QTimer *m_ptimer;
    DWaterProgress *m_pDWaterProgress;
    int m_timeNum = 0;
    DPushButton *m_pDPushButton;
     DPushButton *m_pDPushButtonok;
    DPushButton *m_pDPushButtonchakan;
    DLabel *pDLabel ;
    DLabel *laboutput;
    DLabel *laboutputfail;
    DLabel *labicon;
    DLabel *labiconfalse;



};

#endif // OUTPUT_H
