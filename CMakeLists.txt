cmake_minimum_required(VERSION 3.19)
project(Todo LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

find_package(Qt6 REQUIRED COMPONENTS Sql)

qt_standard_project_setup()

qt_add_executable(Todo
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    createtask.h createtask.cpp createtask.ui
    task.h task.cpp task.ui
    corelogic.h corelogic.cpp

)

qt_add_translations(
    TARGETS Todo
    TS_FILES Todo_ru_RU.ts
)

target_link_libraries(Todo
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Sql
)

include(GNUInstallDirs)

install(TARGETS Todo
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Todo
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
