#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QWidget>
#include <DPushButton>
#include <QVBoxLayout>
#include <DApplicationHelper>
#include <DTextEdit>
#include <QDebug>
#include <DMessageManager>
#include <DListView>
#include <DSlider>
#include <DArrowRectangle>
#include <DLabel>



class SelectFrame : public QWidget
{
    Q_OBJECT
public:
    explicit SelectFrame(QWidget *parent = nullptr);
    ~SelectFrame();

signals:
    void toProgramConfiguration();
private:
    DListView *m_pDListView;
    DPushButton *pDpushBtn2;


public slots:
    void slotDpushBtnNextClicked();

};

#endif // PUSHBUTTON_H
