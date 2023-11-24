file(GLOB_RECURSE SRC *.cpp)
add_executable(QtBreezeExamples ${SRC})

target_compile_features(QtBreezeExamples PUBLIC cxx_std_23)

sanitize("address,undefined")

target_common_warnings(QtBreezeExamples PRIVATE)

target_link_libraries(
  QtBreezeExamples PRIVATE QtBreeze::Icons QtBreeze::StyleSheets Qt::Core
                           Qt::Widgets)
