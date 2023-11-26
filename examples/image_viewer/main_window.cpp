#include "main_window.hpp"
#include <QApplication>
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>

// Add menu and toolbar
MainWindow::MainWindow() {
  // Add menu and toolbar to add image
  QIcon const open_icon{":/icons-dark/actions/16/insert-image.svg"};
  auto open_act{new QAction{open_icon, tr("&Open image"), this}};
  open_act->setShortcuts(QKeySequence::Open);
  open_act->setStatusTip(tr("Open image"));
  connect(open_act, &QAction::triggered, this, &MainWindow::open);
  _file_menu->addAction(open_act);
  _file_toolbar->addAction(open_act);

  // Add menu and toolbar to exit application
  QIcon const exit_icon{":/icons-dark/actions/16/application-exit.svg"};
  auto exit_act{new QAction{exit_icon, tr("&Exit"), this}};
  exit_act->setShortcuts(QKeySequence::Quit);
  exit_act->setStatusTip(tr("Exit the application"));
  connect(exit_act, &QAction::triggered, this, &QWidget::close);
  _file_menu->addSeparator();
  _file_menu->addAction(exit_act);
  _file_toolbar->addAction(exit_act);

  // Add menu and toolbar to show about message box
  QIcon const about_icon{":/icons-dark/actions/16/help-about.svg"};
  auto about_act{new QAction{about_icon, tr("&About"), this}};
  about_act->setStatusTip(tr("Show the application's About box"));
  connect(about_act, &QAction::triggered, this, &MainWindow::about);
  _about_menu->addAction(about_act);
  _about_toolbar->addAction(about_act);

  // Set MDI area as central widget
  setCentralWidget(_mdi_area);
}

// Add image to MDI area
void MainWindow::open() {
  auto const path{QFileDialog::getOpenFileName(
    this, tr("Open image"), "", tr("Images (*.bmp *.jpg *.png *.svg)"))};
  if (!QFileInfo{path}.exists()) return;
  QPixmap image{path};
  auto label{new QLabel};
  label->setPixmap(image);
  _mdi_area->addSubWindow(label, Qt::WindowMinimizeButtonHint);
}

// Show about message box
void MainWindow::about() {
  QMessageBox::about(
    this, tr("QtBreezeExamples"), tr("This is an about window!"));
}
