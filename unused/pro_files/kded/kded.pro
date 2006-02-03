TEMPLATE	= app

include( $(KDELIBS)/win/common.pro )

LIBS += $$KDELIBDESTDIR\dcop$$KDELIB_SUFFIX $$KDELIBDESTDIR\kio$$KDELIB_SUFFIX

# icon
LIBS+=$(KDELIBS)/win/resources/kbuildsycoca.res

INCLUDEPATH += $(KDELIBS)/kded

system( bash kmoc )

TARGET		= kbuildsycoca

SOURCES = \
kbuildsycoca.cpp \
kbuildimageiofactory.cpp \
kbuildprotocolinfofactory.cpp \
kbuildservicefactory.cpp \
kbuildservicegroupfactory.cpp \
kbuildservicetypefactory.cpp \
kctimefactory.cpp \
vfolder_menu.cpp

HEADERS		=

TRANSLATIONS    = kbuildsycoca_pl.ts

