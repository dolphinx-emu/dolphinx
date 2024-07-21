add_executable(dolphin-nx
  Platform.cpp
  Platform.h
  PlatformSwitch.cpp
  MainNX.cpp
)

nx_generate_nacp (dolphin-nx.nacp
	NAME "Dolphitch"
	AUTHOR "Dolphin authors; SimoneN64"
)

nx_create_nro (dolphin-nx
	NACP dolphin-nx.nacp
)

target_link_libraries(dolphin-nx
PRIVATE
  core
  uicommon
  cpp-optparse
)