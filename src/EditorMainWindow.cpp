#include "EditorMainWindow.hpp"
#include "ui_EditorMainWindow.h"
#include "NodeView.hpp"
#include "NodePortView.hpp"

#include "RenderPassUi.h"

using namespace Qiwi;


EditorMainWindow::EditorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditorMainWindow)
{
    ui->setupUi(this);

    ui->verticalLayout->addWidget(new RenderPassUi());

    ui->graphicsView->setScene( &_scene );
    ui->graphicsView->setRenderHints( QPainter::Antialiasing );
    ui->graphicsView->setViewportUpdateMode( QGraphicsView::FullViewportUpdate );

    NodeView* n1 = new NodeView( QPointF(0,0), "node 1", 4, 3, 1, 0);
    n1->addToScene(&_scene);

    NodeView* n2 = new NodeView( QPointF(200,0), "node 2", 3, 4, 1, 0);
    n2->addToScene(&_scene);

    NodeView* n3 = new NodeView( QPointF(400,0), "node 3", 3, 4, 1, 0);
    n3->addToScene(&_scene);

    n1->port(READER_OUTPUT, 0)->connect( n2->port(READER_INPUT, 0) );
    n1->port(READER_OUTPUT, 0)->connect( n2->port(READER_INPUT, 1) );
}

EditorMainWindow::~EditorMainWindow()
{
    delete ui;
}