#include "nivel1.h"
#include "ui_nivel1.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

nivel1::nivel1(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::nivel1)
{
    ui->setupUi(this);

    escena = new QGraphicsScene(this);
    //escena->setSceneRect(0,0,700,600);
    ui->avion->setScene(escena);
    escena->setBackgroundBrush(Qt::transparent);
    fondoESC = new QGraphicsScene(this);
    ui->fondoq->setScene(fondoESC);


    configurarGV();
    mostraravion();
    setFocusPolicy(Qt::StrongFocus);

    // Cargar imagen reticulada como fondo
    QPixmap fondo(":/new/sprites/backgroundfinal.png");
    if (fondo.isNull()) {
        qDebug() << "Error al cargar la imagen del fondo.";
        return;
    }

    // Crear dos items de fondo
    backgroundItem1 = fondoESC->addPixmap(fondo);
    backgroundItem1->setPos(0, 0); // Primera posición inicial

    backgroundItem2 = fondoESC->addPixmap(fondo);
    backgroundItem2->setPos(0, fondo.height()); // Segunda posición por debajo de la primera

    velocidadBajo = 2; // Ajusta la velocidad de desplazamiento a tu gusto

    // Crear y configurar el temporizador
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &nivel1::actualizarFondo);
    timer->start(16); // Aproximadamente 60 FPS
}


void nivel1::actualizarFondo() {
    // Mover ambos items hacia arriba
    int posY1 = backgroundItem1->y() - velocidadBajo;
    int posY2 = backgroundItem2->y() - velocidadBajo;

    // Comprobar si el primer item se ha movido completamente fuera de la vista
    if (posY1 <= -backgroundItem1->pixmap().height()) {
        posY1 = backgroundItem2->y() + backgroundItem2->pixmap().height(); // Colocarlo debajo del segundo
    }

    // Comprobar si el segundo item se ha movido completamente fuera de la vista
    if (posY2 <= -backgroundItem2->pixmap().height()) {
        posY2 = backgroundItem1->y() + backgroundItem1->pixmap().height(); // Colocarlo debajo del primero
    }

    // Actualizar las posiciones
    backgroundItem1->setPos(0, posY1);
    backgroundItem2->setPos(0, posY2);
}
nivel1::~nivel1()
{
    delete ui;
    delete escena;

}
void nivel1::mostraravion(){
    //escena->clear();
    QPixmap imagen(":/new/sprites/avion.png");

    if (imagen.isNull()){
        qDebug()<<"Error al cargar el sprite del avion";
        return;
    }
    QPixmap imagenEscalada = imagen.scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    avionItem = escena->addPixmap(imagenEscalada);  // Solo añade el sprite una vez
    avionItem->setPos(posXavion, posYavion);
    avionItem->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
};
void nivel1::configurarGV()
{
    // Opcional: Configurar propiedades de la vista
    ui->avion->setRenderHint(QPainter::Antialiasing);
    ui->avion->setDragMode(QGraphicsView::ScrollHandDrag);
}
void nivel1::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()) {
    case Qt::Key_Left:
        posXavion -= velocidad;
        break;
    case Qt::Key_Right:
        posXavion += velocidad;
        break;
    case Qt::Key_Up:
        posYavion -= velocidad;
        break;
    case Qt::Key_Down:
        posYavion += velocidad;
        break;
    default:
        QWidget::keyPressEvent(event);
        return;
    }

    // Actualizar posición del sprite
    avionItem->setPos(posXavion, posYavion);


   // verificarInteraccion();
}
