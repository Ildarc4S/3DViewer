#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Hello World"); // Устанавливаем заголовок окна
    resize(400, 300); // Размер окна
}