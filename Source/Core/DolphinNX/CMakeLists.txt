add_executable(dolphin-nx
  Platform.cpp
  Platform.h
  PlatformSwitch.cpp
  MainNX.cpp
)

find_package(Libnx REQUIRED)

target_sources(dolphin-nx PRIVATE PlatformSwitch.cpp)
target_link_libraries(dolphin-nx PRIVATE switch::libnx)

set_target_properties(dolphin-nx PROPERTIES
        OUTPUT_NAME dolphin-emu-nx
        APP_TITLE "Dolphitch"
        APP_AUTHOR "Dolphin team, SimoneN64"
        APP_VERSION "0.1.0")

target_link_libraries(dolphin-nx
PRIVATE
  core
  uicommon
  cpp-optparse
)

add_nro_target(dolphin-nx)