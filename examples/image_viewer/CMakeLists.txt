file(GLOB_RECURSE SRC *.cpp)
add_executable(QtBreezeImageViewer ${SRC})

target_compile_features(QtBreezeImageViewer PUBLIC cxx_std_23)

target_common_warnings(QtBreezeImageViewer PRIVATE)

find_qt(REQUIRED COMPONENTS Widgets)

target_link_libraries(
  QtBreezeImageViewer PRIVATE Qt::BreezeIcons Qt::BreezeStyleSheets Qt::Core
                              Qt::Widgets)
