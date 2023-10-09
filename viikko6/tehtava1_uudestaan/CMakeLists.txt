
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

qt_add_executable(tehtava1_uudestaan)
target_sources(tehtava1_uudestaan PRIVATE main.cpp)
target_link_libraries(tehtava1_uudestaan PRIVATE Qt6::Widgets)
