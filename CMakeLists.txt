# version
cmake_minimum_required(VERSION 3.7)
project(crumpet-engine)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} CMakeFiles/)
cmake_policy(SET CMP0037 OLD)

set(EXEName crumpet-engine)
set(BuildDIR bin)
set(SrcDIR src)
set(EngineDIR ${SrcDIR}/crumpet-engine)
set(IncludeDIR include)

if (WIN32)
    set(SDL2_PATH E:/Games/Librarys/SDL2-2.0.8)
    set(SDL2_INCLUDE_DIR E:/Games/Librarys/SDL2-2.0.8/include)
    set(SDL2_LIBRARY E:/Games/Librarys/SDL2-2.0.8/lib/x64)
    set(SDL2_IMAGE_INCLUDE_DIR E:/Games/Librarys/SDL2_image-2.0.4/VisualC/external/include)
    set(SDL2_IMAGE_LIBRARY  E:/Games/Librarys/SDL2_image-2.0.4/VisualC/external/lib/x64)
endif (WIN32)

if (UNIX)
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
endif (UNIX)

include_directories(${BuildDIR}/ ${SDL2_INCLUDE_DIR})
include_directories(${BuildDIR}/ ${SDL2_IMAGE_INCLUDE_DIR})
include_directories(${BuildDIR}/ ${IncludeDIR})

file(GLOB_RECURSE SourceFiles 
    ${SrcDIR}/*
    ${EngineDIR}/*
    ${EngineDIR}/input/*
    ${EngineDIR}/renderengine/*
    ${EngineDIR}/resourcemanager/*
    ${EngineDIR}/entitymanager/*
)

add_executable(${BuildDIR}/${EXEName} ${SourceFiles})
target_link_libraries(${BuildDIR}/${EXEName} ${SDL2_LIBRARIES})
target_link_libraries(${BuildDIR}/${EXEName} ${SDL2_IMAGE_LIBRARY})
