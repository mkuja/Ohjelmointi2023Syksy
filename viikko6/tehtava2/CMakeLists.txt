find_package(Qt6 CONFIG REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

qt_add_executable(viikko6_tehtava2)
target_sources(viikko6_tehtava2 PRIVATE main.cpp src/Button.cpp src/Calculator.cpp)
target_link_libraries(viikko6_tehtava2 PRIVATE Qt6::Widgets)
