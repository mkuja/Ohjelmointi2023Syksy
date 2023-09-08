
qt_add_executable(tehtava2)
target_sources(tehtava2 PRIVATE main.cpp src/Button.cpp src/Calculator.cpp)
target_link_libraries(tehtava2 PRIVATE Qt6::Widgets)
