#include "mdi_area.hpp"
#include <QApplication>
#include <QFile>
#include <QMdiSubWindow>

MdiArea::MdiArea(QWidget* parent) : QMdiArea{parent} {}

// Add widget as QMdiSubWindow
QMdiSubWindow* MdiArea::addSubWindow(QWidget* widget,
                                     Qt::WindowFlags windowFlags) {
  auto retval{QMdiArea::addSubWindow(widget, windowFlags)};
  retval->setObjectName(widget->objectName());
  removeQtIcon(retval);
  retval->show();
  retval->setStyleSheet(qApp->styleSheet());  // Why the fuck is this necessary?
  return retval;
}

// Remove ugly green Qt logo from QMdiSubWindow
void MdiArea::removeQtIcon(QWidget* widget) {
  QPixmap pixmap{32, 32};
  pixmap.fill(Qt::transparent);
  widget->setWindowIcon(QIcon{pixmap});
}