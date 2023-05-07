QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    abstract_factory.h \
    class_unit.h \
    class_unit_c_sharp.h \
    class_unit_cpp.h \
    class_unit_java.h \
    method_unit.h \
    method_unit_c_sharp.h \
    method_unit_cpp.h \
    method_unit_java.h \
    print_operator_unit.h \
    print_operator_unit_c_sharp.h \
    print_operator_unit_cpp.h \
    print_operator_unit_java.h \
    unit.h
