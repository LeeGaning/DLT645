INCLUDEPATH += $$PWD/inc/ $$PWD
#include($$PWD/cmu/mb_cmu.pri)
#INCLUDEPATH += $$PWD/cmu/
HEADERS  += $$PWD/dlt645_port.h \
            $$PWD/inc/dlt645.h \
            $$PWD/inc/dlt645_1997.h \
            $$PWD/inc/dlt645_1997_private.h \
            $$PWD/inc/dlt645_2007.h \
            $$PWD/inc/dlt645_2007_private.h \
            $$PWD/inc/dlt645_private.h
SOURCES  += \
            $$PWD/dlt645_port.c \
            $$PWD/src/dlt645.c \
            $$PWD/src/dlt645_data.c \
            $$PWD/src/dlt645_1997.c \
            $$PWD/src/dlt645_2007.c
