TARGET = harbour-clubcode

CONFIG += sailfishapp

SOURCES += \
    src/MainViewModel.cpp \
    src/CodeViewModel.cpp \
    src/AddNewCodePageViewModel.cpp \
    src/EditCodePageViewModel.cpp \
    src/main.cpp

OTHER_FILES += \
    qml/cover/CoverPage.qml \
    rpm/harbour-clubcode.changes.in \
    translations/*.ts \
    qml/pages/ViewCodePage.qml \
    qml/EditCodeTemplate.qml \
    qml/pages/EditCodePage.qml \
    qml/pages/AddNewCodePage.qml \
    qml/pages/HomePage.qml \
    qml/harbour-clubcode.qml \
    rpm/harbour-clubcode.yaml \
    rpm/harbour-clubcode.spec \
    harbour-clubcode.desktop

CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/ClubeCode-de.ts

HEADERS += \
    src/MainViewModel.h \
    src/CodeViewModel.h \
    src/AddNewCodePageViewModel.h \
    src/EditCodePageViewModel.h

RESOURCES += \
    Resources.qrc

resources.files = cover.png
resources.path = /usr/share/$${TARGET}

INSTALLS += resources

