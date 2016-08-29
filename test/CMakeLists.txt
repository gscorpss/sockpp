
find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS} SYSTEM
    ${CMAKE_SOURCE_DIR}/src/libs SYSTEM
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


add_executable(Ipv4AddrTest
    Ipv4AddrTest.cpp
    )

target_link_libraries(Ipv4AddrTest
    ${GTEST_BOTH_LIBRARIES}
    pthread
    sockpp
    )

add_test(
    NAME Ipv4AddrTest
    COMMAND $<TARGET_FILE:Ipv4AddrTest>
    )

add_executable(EpollerTest
    EpollerTest.cpp
    )

target_link_libraries(EpollerTest
    ${GTEST_BOTH_LIBRARIES}
    pthread
    sockpp
    )

add_test(
    NAME EpollerTest
    COMMAND $<TARGET_FILE:EpollerTest>
    )
