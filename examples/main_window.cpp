#include "main_window.hpp"
#include <QApplication>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QMenu>
#include <QMessageBox>
#include <QProcess>
#include <QStatusBar>
#include <filesystem>

///
MainWindow::MainWindow() {
  //
  QIcon const open_icon{":/icons-dark/actions/16/document-open.svg"};
  auto open_act{new QAction{open_icon, tr("&Open .zpp"), this}};
  open_act->setShortcuts(QKeySequence::Open);
  open_act->setStatusTip(tr("Open .zpp"));
  connect(open_act, &QAction::triggered, this, &MainWindow::open);
  _file_menu->addAction(open_act);
  _file_toolbar->addAction(open_act);

  //
  QIcon const close_icon{":/icons/actions/16/document-close.svg"};
  auto close_act{new QAction{close_icon, tr("&Close .zpp"), this}};
  close_act->setShortcuts(QKeySequence::Close);
  close_act->setStatusTip(tr("Close .zpp"));
  connect(close_act, &QAction::triggered, this, &MainWindow::close);
  _file_menu->addAction(close_act);
  _file_toolbar->addAction(close_act);

  //
  QIcon const exit_icon{":/icons-dark/actions/16/application-exit.svg"};
  auto exit_act{new QAction{exit_icon, tr("&Exit"), this}};
  exit_act->setShortcuts(QKeySequence::Quit);
  exit_act->setStatusTip(tr("Exit the application"));
  connect(exit_act, &QAction::triggered, this, &QWidget::close);
  _file_toolbar->addAction(exit_act);
  _file_menu->addSeparator();
  _file_menu->addAction(exit_act);

  //
  auto about_act{new QAction{tr("&About"), this}};
  about_act->setStatusTip(tr("Show the application's About box"));
  connect(about_act, &QAction::triggered, this, &MainWindow::about);
  _about_menu->addAction(about_act);
}

///
void MainWindow::open() {
  auto const path{QFileDialog::getOpenFileName(
    this, tr("Open .zpp"), "", tr("Ready-to-use (*.zpp)"))};
  if (!QFileInfo{path}.exists()) return;
}

///
void MainWindow::close() {}

///
void MainWindow::about() {
  QMessageBox::about(
    this, tr("QtBreezeExamples"), tr("This is an about window!"));
}
