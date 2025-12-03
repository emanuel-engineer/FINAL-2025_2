#ifndef NIVEL1_H
#define NIVEL1_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>

namespace Ui {
class nivel1;
}

class nivel1 : public QWidget
{
    Q_OBJECT

public:
    explicit nivel1(QWidget *parent = nullptr);
    ~nivel1();
protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    //Movimiento Fondo
    QTimer *timer;
    QGraphicsPixmapItem *backgroundItem1;
    QGraphicsPixmapItem *backgroundItem2;
    int velocidadBajo; // Velocidad de desplazamiento del fondo
    void actualizarFondo();

    Ui::nivel1 *ui;
    // Declarar el puntero a las escenas (Sprite avion, etc)
    QGraphicsScene *escena;
    QGraphicsScene *fondoESC;
    //AVION
    void configurarGV();
    void mostraravion();
    QGraphicsPixmapItem *avionItem;

    const int velocidad = 15;
    int posXavion = 0 ;
    int posYavion = 0;

};

#endif // NIVEL1_H
