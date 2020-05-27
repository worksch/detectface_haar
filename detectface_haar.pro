QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

## include path for opencv
INCLUDEPATH += $$(OPENCV_ROOT)/include

## library path for opencv
LIBS += -L$$(OPENCV_ROOT)/x64/vc14/lib -lopencv_core331 \
    -lopencv_highgui331 -lopencv_imgproc331 -lopencv_videoio331 \
    -lopencv_imgcodecs331 -lopencv_flann331 -lopencv_features2d331 \
    -lopencv_objdetect331

SOURCES += \
    src/main.cpp
