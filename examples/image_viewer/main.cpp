#include <QApplication>
#include <QFile>
#include "main_window.hpp"

int main(int argc, char* argv[]) {
  // Add executable path (+/plugins) to library path
  auto const qstr_path{QString::fromStdString(
    std::filesystem::path{argv[0uz]}.parent_path().string())};
  QCoreApplication::addLibraryPath(qstr_path);
  QCoreApplication::addLibraryPath(qstr_path + "/plugins");

  // Enable high DPI
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif

  // Create an application instance
  QApplication app{argc, argv};

  // Initialize resources
  Q_INIT_RESOURCE(qtbreeze_icons);
  Q_INIT_RESOURCE(qtbreeze_stylesheets);

  // Apply breeze stylesheet
  QFile file{":/dark/stylesheet.qss"};
  file.open(QFile::ReadOnly | QFile::Text);
  QTextStream stream{&file};
  app.setStyleSheet(stream.readAll());

  MainWindow w{};
  w.show();
  return app.exec();
}
