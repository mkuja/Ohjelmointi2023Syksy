find_package(Qt6 CONFIG REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

qt_add_executable(tehtava7)
target_sources(tehtava7 PRIVATE main.cpp src/chessclock.cpp src/chessclock.ui)
target_link_libraries(tehtava7 PRIVATE Qt6::Core Qt6::Widgets)
