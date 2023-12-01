file(GLOB_RECURSE SRC *.cpp)
add_executable(QtBreezeImageViewer ${SRC})

target_compile_features(QtBreezeImageViewer PUBLIC cxx_std_23)

target_common_warnings(QtBreezeImageViewer PRIVATE)

if(Qt6_FOUND)
  find_package(Qt6 REQUIRED COMPONENTS Widgets)
elseif(Qt5_FOUND)
  find_package(Qt5 REQUIRED COMPONENTS Widgets)
endif()

target_link_libraries(
  QtBreezeImageViewer PRIVATE Qt::BreezeIcons Qt::BreezeStyleSheets Qt::Core
                              Qt::Widgets)
