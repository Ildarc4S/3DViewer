#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class GLWidget
  : public QOpenGLWidget,
    protected QOpenGLFunctions {
  Q_OBJECT
public:
  explicit GLWidget(QWidget* parent = nullptr);
protected:
  void initializeGL() override;
  void resizeGL(int width, int height) override;
  void paintGL() override;
};

class MainWindow
  : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
private:
  GLWidget* gl_widget;
};

#endif // MAINWINDOW_H
