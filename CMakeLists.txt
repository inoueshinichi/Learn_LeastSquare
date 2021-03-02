cmake_minimum_required(VERSION 3.0.0)
project(lsm VERSION 0.1.0)

include(CTest)
enable_testing()

# add_executable(lsm main.cpp)
add_executable(line_lsm
    main_line_lsm.cpp
)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
