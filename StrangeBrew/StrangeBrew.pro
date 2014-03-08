#-------------------------------------------------
#
# Project created by QtCreator 2014-02-08T10:28:01
#
#-------------------------------------------------

# Copies the given files to the destination directory
defineTest(copyToDestdir) {
    files = $$1

    for(FILE, files) {
        DDIR = $$DESTDIR

        # Replace slashes in paths with backslashes for Windows
        win32:FILE ~= s,/,\\,g
        win32:DDIR ~= s,/,\\,g

        QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FILE) $$quote($$DDIR) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}

defineTest(copyAllToDestdir) {
    files = $$1

    for(FILE, files) {
        DDIR = $$DESTDIR

        # Replace slashes in paths with backslashes for Windows
        win32:FILE ~= s,/,\\,g
        win32:DDIR ~= s,/,\\,g

        win32 { QMAKE_POST_LINK += $$QMAKE_COPY -y $$quote($$FILE) $$quote($$DDIR) $$escape_expand(\\n\\t) }
        unix {
            QMAKE_POST_LINK += $$QMAKE_COPY -r $$quote($$FILE) $$quote($$DDIR) $$escape_expand(\\n\\t)
        }
    }

    export(QMAKE_POST_LINK)
}

QT       += core gui xml sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StrangeBrew
TEMPLATE = app

ICON = brew.ico
QMAKE_CXXFLAGS += -frtti

SOURCES += main.cpp\
        strangebrew.cpp \
    sbstringutils.cpp \
    importxml.cpp \
    recipe.cpp \
    options.cpp \
    hop.cpp \
    fermentable.cpp \
    ingredient.cpp \
    misc.cpp \
    converter.cpp \
    quantity.cpp \
    primesugar.cpp \
    yeast.cpp \
    mash.cpp \
    mashstep.cpp \
    style.cpp \
    fermentstep.cpp \
    note.cpp \
    waterprofile.cpp \
    salt.cpp \
    chemicaleffect.cpp \
    acid.cpp \
    brewcalcs.cpp \
    database.cpp \
    promashimport.cpp \
    xmlhandler.cpp \
    hopsmodel.cpp \
    maltmodel.cpp \
    hopitemdelegate.cpp \
    maltitemdelegate.cpp \
    stylemodel.cpp \
    miscmodel.cpp \
    newingrdialog.cpp \
    newingrtable.cpp \
    newingrdelegate.cpp \
    miscitemdelegate.cpp \
    notesmodel.cpp \
    mashmodel.cpp \
    mashitemdelegate.cpp \
    fermmodel.cpp \
    fermitemdelegate.cpp \
    preferences.cpp \
    edit_dialogs/newfermentable.cpp \
    edit_dialogs/newhop.cpp \
    edit_dialogs/newprimesugar.cpp \
    edit_dialogs/newmisc.cpp \
    edit_dialogs/newyeast.cpp \
    tool_dialogs/resizerecipe.cpp \
    tool_dialogs/refracttool.cpp \
    tool_dialogs/maltpercentdialog.cpp \
    tool_dialogs/extractdialog.cpp \
    tool_dialogs/hydrodialog.cpp \
    tool_dialogs/conversiontool.cpp \
    remoterecipes.cpp \
    recipemodel.cpp \
    cloudcontrol.cpp

HEADERS  += strangebrew.h \
    importxml.h \
    sbstringutils.h \
    recipe.h \
    options.h \
    hop.h \
    fermentable.h \
    ingredient.h \
    misc.h \
    converter.h \
    quantity.h \
    primesugar.h \
    yeast.h \
    mash.h \
    mashstep.h \
    style.h \
    fermentstep.h \
    note.h \
    waterprofile.h \
    salt.h \
    chemicaleffect.h \
    acid.h \
    brewcalcs.h \
    database.h \
    promashimport.h \
    xmlhandler.h \
    hopsmodel.h \
    maltmodel.h \
    hopitemdelegate.h \
    maltitemdelegate.h \
    stylemodel.h \
    miscmodel.h \
    miscitemdelegate.h \
    newingrdialog.h \
    newingrtable.h \
    newingrdelegate.h \
    notesmodel.h \
    mashmodel.h \
    mashitemdelegate.h \
    fermmodel.h \
    fermitemdelegate.h \
    preferences.h \
    constants.h \
    edit_dialogs/newyeast.h \
    edit_dialogs/newfermentable.h \
    edit_dialogs/newhop.h \
    edit_dialogs/newmisc.h \
    edit_dialogs/newprimesugar.h \
    tool_dialogs/resizerecipe.h \
    tool_dialogs/refracttool.h \
    tool_dialogs/maltpercentdialog.h \
    tool_dialogs/extractdialog.h \
    tool_dialogs/hydrodialog.h \
    tool_dialogs/conversiontool.h \
    remoterecipes.h \
    recipemodel.h \
    BasicRecipe.h \
    cloudcontrol.h

FORMS    += strangebrew.ui \
    edit_dialogs/newfermentable.ui \
    edit_dialogs/newhop.ui \
    edit_dialogs/newingrdialog.ui \
    edit_dialogs/newmisc.ui \
    edit_dialogs/newprimesugar.ui \
    edit_dialogs/newyeast.ui \
    edit_dialogs/preferences.ui \
    tool_dialogs/resizerecipe.ui \
    tool_dialogs/refracttool.ui \
    tool_dialogs/maltpercentdialog.ui \
    tool_dialogs/extractdialog.ui \
    tool_dialogs/hydrodialog.ui \
    tool_dialogs/conversiontool.ui \
    remoterecipes.ui

RESOURCES += \
    SB_Images.qrc

INCLUDEPATH += "edit_dialogs/"

message ($$CONFIG)
linux32 {
    DESTDIR = ../build/linux/x86
}

linux64 {
    DESTDIR = ../build/linux/x64
}

copyAllToDestdir(../data)
copyAllToDestdir(../Recipes)
