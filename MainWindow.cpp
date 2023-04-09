#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
{
    setWindowTitle("Photo Filter");
    resize(1000,1000);
    camWidget=new CamWidget;
    setCentralWidget(camWidget);
}

MainWindow::~MainWindow()
{
}