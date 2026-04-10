cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_CXX_STANDARD 17)

# The executable name
add_executable(calculator src/main.cpp)

# Static linking ensures the .exe runs on Windows without missing .dll files
if(WIN32)
    set_target_properties(calculator PROPERTIES LINK_FLAGS "-static-libgcc -static-libstdc++ -static")
endif()
