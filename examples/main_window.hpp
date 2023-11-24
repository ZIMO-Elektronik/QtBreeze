#pragma once

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <memory>
#include "mdi_area.hpp"

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow();

private slots:
  void open();
  void close();
  void about();

private:
  QToolBar* _file_toolbar{addToolBar(tr("File"))};
  QMenu* _file_menu{menuBar()->addMenu(tr("&File"))};
  QMenu* _about_menu{menuBar()->addMenu(tr("&About"))};

  MdiArea* mdi_area_{new MdiArea{this}};
};
