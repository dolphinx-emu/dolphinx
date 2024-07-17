add_executable(dolphin-nx
  Platform.cpp
  Platform.h
  PlatformSwitch.cpp
  MainNX.cpp
)

target_sources(dolphin-nx PRIVATE PlatformSwitch.cpp)

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

nx_create_nro(dolphin-nx)