cmake_minimum_required (VERSION 2.8)

project (demolib2)

set (${PROJECT_NAME}_VERSION_MAJOR 0)
set (${PROJECT_NAME}_VERSION_MINOR 1)
set (${PROJECT_NAME}_VERSION_PATCH 0)

include_directories(inc)

file (GLOB DIR_LIB_HEADERS "inc/*.h")
aux_source_directory(src DIR_LIB_SRCS)

find_package(demolib1 REQUIRED)

add_library(${PROJECT_NAME} SHARED ${DIR_LIB_SRCS})
target_link_libraries(${PROJECT_NAME} demolib1::demolib1)

target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
        $<INSTALL_INTERFACE:inc>)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${DIR_LIB_HEADERS}")

install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    PUBLIC_HEADER DESTINATION inc
)
install(EXPORT ${PROJECT_NAME}
    NAMESPACE ${PROJECT_NAME}::
    FILE ${PROJECT_NAME}-config.cmake
    DESTINATION lib/cmake
)
