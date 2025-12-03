#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <nivel1.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class mainwidget;
}
QT_END_NAMESPACE

class mainwidget : public QWidget
{
    Q_OBJECT

public:
    mainwidget(QWidget *parent = nullptr);
    ~mainwidget();

private slots:
    void on_nivel1_btn_clicked();

private:
    Ui::mainwidget *ui;
};
#endif // MAINWIDGET_H
