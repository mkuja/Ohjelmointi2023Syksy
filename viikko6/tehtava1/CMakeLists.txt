
qt_add_executable(tehtava1)
target_sources(tehtava1 PRIVATE main.cpp src/Counter.cpp src/Button.cpp)
target_link_libraries(tehtava1 PRIVATE Qt6::Widgets)