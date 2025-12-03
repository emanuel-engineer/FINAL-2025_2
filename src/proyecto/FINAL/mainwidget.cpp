#include "mainwidget.h"
#include "ui_mainwidget.h"

mainwidget::mainwidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainwidget)
{
    ui->setupUi(this);
}

mainwidget::~mainwidget()
{
    delete ui;
}

void mainwidget::on_nivel1_btn_clicked()
{
    nivel1 *w = new nivel1;
    close();
    w->show();
}

