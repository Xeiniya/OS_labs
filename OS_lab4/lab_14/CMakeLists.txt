cmake_minimum_required(VERSION 3.14)
project(message_passing)

# ��������� ��������� C++ � ����� �����������
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ��������� ��������� ������������
include(CTest)
enable_testing()

# ���������� �����������
add_subdirectory(src/receiver)
add_subdirectory(src/sender)

# ���������� ������, ���� �������� ������������
if(BUILD_TESTING)
    # �������� GoogleTest
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    FetchContent_MakeAvailable(googletest)
    
    add_subdirectory(tests)
endif()