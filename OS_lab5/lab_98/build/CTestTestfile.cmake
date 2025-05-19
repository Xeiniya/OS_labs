# CMake generated Testfile for 
# Source directory: D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98
# Build directory: D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(unit_tests "D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/build/Debug/tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/CMakeLists.txt;85;add_test;D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(unit_tests "D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/build/Release/tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/CMakeLists.txt;85;add_test;D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(unit_tests "D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/build/MinSizeRel/tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/CMakeLists.txt;85;add_test;D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(unit_tests "D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/build/RelWithDebInfo/tests.exe")
  set_tests_properties(unit_tests PROPERTIES  _BACKTRACE_TRIPLES "D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/CMakeLists.txt;85;add_test;D:/ЛАБЫ/Лабы_оси/OS_lab5/lab_98/CMakeLists.txt;0;")
else()
  add_test(unit_tests NOT_AVAILABLE)
endif()
subdirs("_deps/googletest-build")
