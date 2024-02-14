cmake_minimum_required(VERSION 3.16)

set(TARGET QSanguosha)
project(${TARGET} VERSION 2.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(AUDIO_SUPPORT TRUE)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Widgets Multimedia Quick Core5Compat LinguistTools)
find_package(SWIG REQUIRED COMPONENTS lua)
find_package(Threads REQUIRED)
find_package(Lua REQUIRED)
find_package(Freetype REQUIRED)

include(${SWIG_USE_FILE})
qt_standard_project_setup()

qt_add_executable(${TARGET}
    src/dialog/cardoverview.ui
    src/dialog/configdialog.ui
    src/dialog/connectiondialog.ui
    src/dialog/generaloverview.ui
    src/dialog/mainwindow.ui
    src/dialog/mainwindowserverlist.ui
    src/dialog/dialogslsettings.ui

    src/main.cpp
    src/client/aux-skills.cpp
    src/client/client.cpp
    src/client/clientplayer.cpp
    src/client/clientstruct.cpp
    src/core/banpair.cpp
    src/core/card.cpp
    src/core/engine.cpp
    src/core/general.cpp
    src/core/json.cpp
    src/core/lua-wrapper.cpp
    src/core/player.cpp
    src/core/protocol.cpp
    src/core/settings.cpp
    src/core/skill.cpp
    src/core/structs.cpp
    src/core/util.cpp
    src/dialog/cardeditor.cpp
    src/dialog/cardoverview.cpp
    src/dialog/choosegeneraldialog.cpp
    src/dialog/configdialog.cpp
    src/dialog/connectiondialog.cpp
    src/dialog/customassigndialog.cpp
    src/dialog/distanceviewdialog.cpp
    src/dialog/generaloverview.cpp
    src/dialog/mainwindow.cpp
    src/dialog/playercarddialog.cpp
    src/dialog/roleassigndialog.cpp
    src/dialog/scenario-overview.cpp
    src/package/exppattern.cpp
    src/package/god.cpp
    src/package/maneuvering.cpp
    src/package/nostalgia.cpp
    src/package/package.cpp
    src/package/standard.cpp
    src/package/standard-cards.cpp
    src/package/standard-generals.cpp
    src/package/standard-skillcards.cpp
    src/package/thicket.cpp
    src/package/wind.cpp
    src/scenario/boss-mode-scenario.cpp
    src/scenario/couple-scenario.cpp
    src/scenario/guandu-scenario.cpp
    src/scenario/miniscenarios.cpp
    src/scenario/scenario.cpp
    src/scenario/scenerule.cpp
    src/scenario/zombie-scenario.cpp
    src/server/ai.cpp
    src/server/gamerule.cpp
    src/server/generalselector.cpp
    src/server/room.cpp
    src/server/roomthread.cpp
    src/server/roomthread1v1.cpp
    src/server/roomthread3v3.cpp
    src/server/roomthreadxmode.cpp
    src/server/server.cpp
    src/server/serverplayer.cpp
    src/ui/button.cpp
    src/ui/cardcontainer.cpp
    src/ui/carditem.cpp
    src/ui/chatwidget.cpp
    src/ui/clientlogbox.cpp
    src/ui/dashboard.cpp
    src/ui/indicatoritem.cpp
    src/ui/magatamas-item.cpp
    src/ui/photo.cpp
    src/ui/pixmapanimation.cpp
    src/ui/qsanbutton.cpp
    src/ui/rolecombobox.cpp
    src/ui/roomscene.cpp
    src/ui/sprite.cpp
    src/ui/startscene.cpp
    src/ui/window.cpp
    src/util/detector.cpp
    src/util/nativesocket.cpp
    src/util/recorder.cpp
    src/core/record-analysis.cpp
    src/package/hegemony.cpp
    src/scenario/fancheng-scenario.cpp
    src/core/room-state.cpp
    src/core/wrapped-card.cpp
    src/ui/bubblechatbox.cpp
    src/ui/generic-cardcontainer-ui.cpp
    src/ui/qsan-selectable-item.cpp
    src/ui/skin-bank.cpp
    src/ui/table-pile.cpp
    src/ui/timed-progressbar.cpp
    src/ui/ui-utils.cpp
    src/package/assassins.cpp
    src/package/bgm.cpp
    src/package/boss.cpp
    src/package/fire.cpp
    src/package/h-formation.cpp
    src/package/h-momentum.cpp
    src/package/jiange-defense.cpp
    src/package/joy.cpp
    src/package/ling.cpp
    src/package/mountain.cpp
    src/package/sp.cpp
    src/package/special1v1.cpp
    src/package/special3v3.cpp
    src/package/wisdom.cpp
    src/package/yitian.cpp
    src/package/yjcm.cpp
    src/package/yjcm2012.cpp
    src/package/yjcm2013.cpp
    src/package/yjcm2014.cpp
    src/package/yjcm2015.cpp
    swig/sanguosha_wrap.cxx
    src/dialog/banipdialog.cpp
    src/package/tw.cpp
    src/package/ol.cpp
    src/package/jsp.cpp
    src/dialog/mainwindowserverlist.cpp
    src/dialog/dialogslsettings.cpp
    src/server/qtupnpportmapping.cpp

    src/client/aux-skills.h
    src/client/client.h
    src/client/clientplayer.h
    src/client/clientstruct.h
    src/core/audio.h
    src/core/banpair.h
    src/core/card.h
    src/core/compiler-specific.h
    src/core/engine.h
    src/core/general.h
    src/core/json.h
    src/core/lua-wrapper.h
    src/core/player.h
    src/core/protocol.h
    src/core/settings.h
    src/core/skill.h
    src/core/structs.h
    src/core/util.h
    src/dialog/cardeditor.h
    src/dialog/cardoverview.h
    src/dialog/choosegeneraldialog.h
    src/dialog/configdialog.h
    src/dialog/connectiondialog.h
    src/dialog/customassigndialog.h
    src/dialog/distanceviewdialog.h
    src/dialog/generaloverview.h
    src/dialog/mainwindow.h
    src/dialog/playercarddialog.h
    src/dialog/roleassigndialog.h
    src/dialog/scenario-overview.h
    src/package/exppattern.h
    src/package/god.h
    src/package/maneuvering.h
    src/package/nostalgia.h
    src/package/package.h
    src/package/standard.h
    src/package/standard-equips.h
    src/package/standard-skillcards.h
    src/scenario/boss-mode-scenario.h
    src/scenario/couple-scenario.h
    src/scenario/guandu-scenario.h
    src/scenario/miniscenarios.h
    src/scenario/scenario.h
    src/scenario/scenerule.h
    src/scenario/zombie-scenario.h
    src/server/ai.h
    src/server/gamerule.h
    src/server/generalselector.h
    src/server/room.h
    src/server/roomthread.h
    src/server/roomthread1v1.h
    src/server/roomthread3v3.h
    src/server/roomthreadxmode.h
    src/server/server.h
    src/server/serverplayer.h
    src/ui/button.h
    src/ui/cardcontainer.h
    src/ui/carditem.h
    src/ui/chatwidget.h
    src/ui/clientlogbox.h
    src/ui/dashboard.h
    src/ui/indicatoritem.h
    src/ui/magatamas-item.h
    src/ui/photo.h
    src/ui/pixmapanimation.h
    src/ui/qsanbutton.h
    src/ui/rolecombobox.h
    src/ui/roomscene.h
    src/ui/sprite.h
    src/ui/startscene.h
    src/ui/window.h
    src/util/detector.h
    src/util/nativesocket.h
    src/util/recorder.h
    src/util/socket.h
    src/core/record-analysis.h
    src/package/hegemony.h
    src/scenario/fancheng-scenario.h
    src/package/assassins.h
    src/package/bgm.h
    src/package/boss.h
    src/package/fire.h
    src/package/h-formation.h
    src/package/h-momentum.h
    src/package/jiange-defense.h
    src/package/joy.h
    src/package/ling.h
    src/package/mountain.h
    src/package/sp.h
    src/package/special1v1.h
    src/package/special3v3.h
    src/package/wisdom.h
    src/package/yitian.h
    src/package/yjcm.h
    src/package/yjcm2012.h
    src/package/yjcm2013.h
    src/package/yjcm2014.h
    src/package/yjcm2015.h
    src/core/room-state.h
    src/core/wrapped-card.h
    src/ui/bubblechatbox.h
    src/ui/generic-cardcontainer-ui.h
    src/ui/qsan-selectable-item.h
    src/ui/skin-bank.h
    src/ui/table-pile.h
    src/ui/timed-progressbar.h
    src/ui/ui-utils.h
    src/package/thicket.h
    src/package/wind.h
    src/dialog/banipdialog.h
    src/package/tw.h
    src/package/ol.h
    src/package/jsp.h
    src/dialog/mainwindowserverlist.h
    src/dialog/dialogslsettings.h
    src/core/defines.h
    src/server/qtupnpportmapping.h
)
 
if (AUDIO_SUPPORT)
  target_compile_definitions(${TARGET} PRIVATE AUDIO_SUPPORT)
  target_sources(${TARGET} PRIVATE src/core/audio.cpp)
endif()

if (TRUE)
  # lua
  target_sources(${TARGET} PRIVATE
    src/lua/lzio.c
    src/lua/lvm.c
    src/lua/lundump.c
    src/lua/ltm.c
    src/lua/ltablib.c
    src/lua/ltable.c
    src/lua/lstrlib.c
    src/lua/lstring.c
    src/lua/lstate.c
    src/lua/lparser.c
    src/lua/loslib.c
    src/lua/lopcodes.c
    src/lua/lobject.c
    src/lua/loadlib.c
    src/lua/lmem.c
    src/lua/lmathlib.c
    src/lua/llex.c
    src/lua/liolib.c
    src/lua/linit.c
    src/lua/lgc.c
    src/lua/lfunc.c
    src/lua/ldump.c
    src/lua/ldo.c
    src/lua/ldebug.c
    src/lua/ldblib.c
    src/lua/lctype.c
    src/lua/lcorolib.c
    src/lua/lcode.c
    src/lua/lbitlib.c
    src/lua/lbaselib.c
    src/lua/lauxlib.c
    src/lua/lapi.c
  )
endif()

target_include_directories(${TARGET} PRIVATE
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/include/freetype
  ${CMAKE_SOURCE_DIR}/src/lua
  ${CMAKE_SOURCE_DIR}/src/client
  ${CMAKE_SOURCE_DIR}/src/core
  ${CMAKE_SOURCE_DIR}/src/dialog
  ${CMAKE_SOURCE_DIR}/src/package
  ${CMAKE_SOURCE_DIR}/src/scenario
  ${CMAKE_SOURCE_DIR}/src/server
  ${CMAKE_SOURCE_DIR}/src/ui
  ${CMAKE_SOURCE_DIR}/src/util
)

qt_add_translations(${TARGET} TS_FILES sanguosha.ts)
set_source_files_properties(sanguosha.ts PROPERTIES OUTPUT_LOCATION ${CMAKE_SOURCE_DIR})

set_property(SOURCE ${CMAKE_SOURCE_DIR}/swig/sanguosha.i PROPERTY CPLUSPLUS ON)
swig_add_library(swig_sanguosha TYPE STATIC LANGUAGE lua SOURCES ${CMAKE_SOURCE_DIR}/swig/sanguosha.i)

target_precompile_headers(swig_sanguosha PRIVATE ${CMAKE_SOURCE_DIR}/src/pch.h)
target_precompile_headers(${TARGET} REUSE_FROM swig_sanguosha)

target_link_libraries(swig_sanguosha PRIVATE Threads::Threads)
target_link_libraries(${TARGET} PRIVATE Threads::Threads)

# message("include dir is ${Qt6Core_INCLUDE_DIRS} ---")
# set_source_files_properties(${CMAKE_SOURCE_DIR}/src/pch.h PROPERTIES COMPILE_FLAGS "${Qt6Core_INCLUDE_DIRS}")

set_property(TARGET swig_sanguosha PROPERTY INCLUDE_DIRECTORIES
  ${CMAKE_SOURCE_DIR}/include/freetype
  ${CMAKE_SOURCE_DIR}/src/lua
  ${CMAKE_SOURCE_DIR}/src/core
  ${CMAKE_SOURCE_DIR}/src/server
  ${CMAKE_SOURCE_DIR}/src/client
  ${CMAKE_SOURCE_DIR}/src/package
  ${Qt6Core_INCLUDE_DIRS}
  ${Qt6Network_INCLUDE_DIRS}
  ${Qt6Widgets_INCLUDE_DIRS}
  ${Qt6Core5Compat_INCLUDE_DIRS}
  ${Qt6Quick_INCLUDE_DIRS}
)
message("hhhh ${LUA_LIBRARIES}")

target_link_libraries(${TARGET} PRIVATE
  Qt6::Core Qt6::Network Qt6::Widgets Qt6::Multimedia Qt6::Quick Qt6::Core5Compat
  swig_sanguosha
  ${LUA_LIBRARIES}
  ${FREETYPE_LIBRARIES}
)

set_target_properties(${TARGET} PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
