#pragma once

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include "mdi_area.hpp"

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow();

private slots:
  void open();
  void about();

private:
  QToolBar* _file_toolbar{addToolBar(tr("File"))};
  QToolBar* _about_toolbar{addToolBar(tr("About"))};
  QMenu* _file_menu{menuBar()->addMenu(tr("&File"))};
  QMenu* _about_menu{menuBar()->addMenu(tr("&About"))};
  MdiArea* _mdi_area{new MdiArea{this}};
};
