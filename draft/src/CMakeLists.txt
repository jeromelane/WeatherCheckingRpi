qt5_add_resources(quicktest1_SRCS resources.qrc)
set_property(SOURCE main.cpp PROPERTY SKIP_AUTOGEN ON)
add_executable(quicktest1 main.cpp ${quicktest1_SRCS}) #ajout autres classes apres main.cpp
target_link_libraries(quicktest1 Qt5::Qml Qt5::Gui)

