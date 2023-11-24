#include "mdi_area.hpp"
#include <QApplication>
#include <QFile>
#include <QMdiSubWindow>

///
MdiArea::MdiArea(QWidget* parent) : QMdiArea{parent} {}

///
QMdiSubWindow* MdiArea::addSubWindow(QWidget* widget,
                                     Qt::WindowFlags windowFlags) {
  auto retval{findSubWindowByObjectName(widget)};
  if (retval) return retval;
  retval = QMdiArea::addSubWindow(widget, windowFlags);
  retval->setObjectName(widget->objectName());
  removeQtIcon(retval);
  retval->show();
  retval->setStyleSheet(qApp->styleSheet());  // Why the fuck is this necessary?
  return retval;
}

///
QMdiSubWindow* MdiArea::findSubWindowByObjectName(QWidget* widget) {
  auto const sub_window_list{subWindowList()};
  auto found{
    std::ranges::find_if(sub_window_list, [&widget](QMdiSubWindow* sub_window) {
      return sub_window->objectName() == widget->objectName();
    })};
  return found != sub_window_list.end() ? *found : nullptr;
}

///
void MdiArea::removeQtIcon(QWidget* widget) {
  QPixmap pixmap{32, 32};
  pixmap.fill(Qt::transparent);
  widget->setWindowIcon(QIcon{pixmap});
}