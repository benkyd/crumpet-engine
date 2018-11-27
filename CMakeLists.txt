# version
cmake_minimum_required(VERSION 2.4)
project(crumpet-engine)

set(EXEName crumpet-engine)
set(BuildDIR ./bin)
set(SrcDIR ./src)
set(IncludeDIR ./include)

find_package(SDL2 REQUIRED)

include_directories(${BuildDIR}/${EXEName} ${SLD_INCLUDE_DIR})
include_directories(${BuildDIR}/${EXEName} ${IncludeDIR})

file(GLOB_RECURSE SourceFiles ${SrcDIR}/*.cpp)

add_executable(${BuildDIR}/${EXEName} ${SourceFiles})
target_link_libraries(${BuildDIR}/${EXEName} ${SDL2_LIBRARIES})
