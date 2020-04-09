#ifndef PREPARATION_H
#define PREPARATION_H

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

class Preparation : public QWidget
{
    Q_OBJECT
public:
    explicit Preparation(QWidget *parent = nullptr);
    ~Preparation();

signals:
    void toMidInstallation();
private:
    DFloatingMessage *pDLabeldeb;
    DPushButton *pDpushBtn2;

public slots:
    void slotDpushBtnNextClicked();
    void slotDpushBtnClearClicked();
};

#endif // PREPARATION_H
