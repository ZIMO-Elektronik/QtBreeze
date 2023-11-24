#pragma once

#include <QMdiArea>

class MdiArea : public QMdiArea {
  Q_OBJECT

public:
  explicit MdiArea(QWidget* parent = nullptr);
  QMdiSubWindow* addSubWindow(QWidget* widget,
                              Qt::WindowFlags windowFlags = Qt::WindowFlags());

private:
  QMdiSubWindow* findSubWindowByObjectName(QWidget* widget);
  void removeQtIcon(QWidget* widget);
};