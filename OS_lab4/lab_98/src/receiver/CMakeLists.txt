# ��������� ���������� ��� ������ ����
add_library(message_file STATIC
    ../common/message_file.h
    ../common/message_file.cpp
)

# ����������� ���� ��������� ��� ����������
target_include_directories(message_file PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../)

# ��������� ����������� ���� ���������
add_executable(receiver
    receiver.cpp
)

# ��������� � ����� �����������
target_link_libraries(receiver PRIVATE message_file)