cmake_minimum_required(VERSION 3.25 FATAL_ERROR)
include(FetchContent)

FetchContent_Declare(
  CMakeModules
  GIT_REPOSITORY https://github.com/ZIMO-Elektronik/CMakeModules
  GIT_TAG v0.7.0)
FetchContent_MakeAvailable(CMakeModules)

version_from_git()
project(QtBreeze VERSION ${VERSION_FROM_GIT})

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_qt(REQUIRED COMPONENTS Core)

cpmaddpackage(
  NAME
  breeze-icons
  GITHUB_REPOSITORY
  KDE/breeze-icons
  VERSION
  ${PROJECT_VERSION}
  DOWNLOAD_ONLY
  TRUE)
cpmaddpackage(
  NAME
  BreezeStyleSheets
  GITHUB_REPOSITORY
  Alexhuszagh/BreezeStyleSheets
  GIT_TAG
  69d2e7476428216e66143ff7b5c99553d7a2784f
  DOWNLOAD_ONLY
  TRUE)

set(SRC ${breeze-icons_SOURCE_DIR}/qtbreeze_icons.qrc)
add_library(QtBreezeIcons ${SRC})
add_library(Qt::BreezeIcons ALIAS QtBreezeIcons)

# Generate .qrc file for breeze-icons
file(GLOB_RECURSE ABS_ICONS ${breeze-icons_SOURCE_DIR}/icons/*.svg
     ${breeze-icons_SOURCE_DIR}/icons-dark/*.svg)
file(WRITE ${SRC} "<RCC>\n<qresource>\n")
foreach(ABS_ICON ${ABS_ICONS})
  file(RELATIVE_PATH REL_ICON ${breeze-icons_SOURCE_DIR} ${ABS_ICON})
  file(APPEND ${SRC} "    <file>${REL_ICON}</file>\n")
endforeach()
file(APPEND ${SRC} "</qresource>\n</RCC>")

set(SRC ${BreezeStyleSheets_SOURCE_DIR}/dist/qrc/qtbreeze_stylesheets.qrc)
add_library(QtBreezeStyleSheets ${SRC})
add_library(Qt::BreezeStyleSheets ALIAS QtBreezeStyleSheets)

# Generate .rqc file for BreezeStyleSheets (comes with python script)
find_package(Python REQUIRED COMPONENTS Interpreter)
execute_process(
  COMMAND ${Python_EXECUTABLE} configure.py --extensions=all --styles=all
          --resource qtbreeze_stylesheets.qrc
  WORKING_DIRECTORY ${BreezeStyleSheets_SOURCE_DIR})

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  file(
    DOWNLOAD
    https://raw.githubusercontent.com/ZIMO-Elektronik/.clang-format/master/.clang-format
    ${CMAKE_CURRENT_LIST_DIR}/.clang-format)
  file(GLOB_RECURSE SRC examples/*.*pp)
  add_clang_format_target(QtBreezeFormat OPTIONS -i FILES ${SRC})
  add_subdirectory(examples)
endif()
