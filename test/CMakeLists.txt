
find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS} SYSTEM
    ${CMAKE_SOURCE_DIR}/src SYSTEM
    ${CMAKE_SOURCE_DIR}/src/libs/ SYSTEM
    )

add_executable(SocketTest
    SocketTest.cpp
    )

target_link_libraries(SocketTest
    ${GTEST_BOTH_LIBRARIES}
    pthread
    sockpp
    )

add_test(
    NAME SocketTest
    COMMAND $<TARGET_FILE:SocketTest>
    )
