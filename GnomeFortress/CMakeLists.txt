# CMakeList.txt : CMake project for GnomeFortress, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (GnomeFortress "main.cpp" "GnomeFortress.h" "Map.h" "Map.cpp" "MapCoord.cpp" "MapCoord.h" "Player.h" "Player.cpp" "Game.h" "Game.cpp" "Entity.h" "Entity.cpp" "Log.h" "Log.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GnomeFortress PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
