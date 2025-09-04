#include "mainwindow.h"

GLWidget::GLWidget(QWidget* parent)
: QOpenGLWidget(parent) {
  setMinimumSize(800, 600);
}

void GLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor(1.0f, 0.5f, 0.0f, 1.0f);
}

void GLWidget::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
}

void GLWidget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(-0.6f, -0.4f, 0.0f);

  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.6f, -0.4f, 0.0f);

  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(0.0f, 0.6f, 0.0f);
  glEnd();
}

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent) {
  setWindowTitle("3D Viewer");
  resize(1000, 700);

  gl_widget = new GLWidget(this);
  setCentralWidget(gl_widget);
}