# version
cmake_minimum_required(VERSION 3.9)

project(crumpet-engine)
set(crumpet-engine_VERSION_MAJOR 1)
set(crumpet-engine_VERSION_MINOR 0)

set(EXEName crumpet-engine.o)
set(BuildDIR ./bin)
set(SrcDIR ./src)
set(IncludeDIR ${SrcDIR}/include)

find_package(SDL2 REQUIRED)
include_directories(${SLD_INCLUDE_DIRS})

include_directories(${IncludeDIR})

add_executable(${BuildDIR}/${EXEName} ${SrcDIR}/main.cpp)
target_link_libraries(${BuildDIR}/${EXEName} ${SDL2_LIBRARIES})
