cmake_minimum_required(VERSION 2.6)
project(toutatis)

set(PROJECT_NAME toutatis)
set(PROJECT_BRIEF_DESCRIPTION "A simple forum in Wt and C++")
set(DOCUMENTATION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/doc)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules)
set(CMAKE_TOOLCHAIN_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchains)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

### Find needed Packages

find_package(Boost 1.60.0 COMPONENTS system filesystem thread program_options regex date_time timer random log chrono REQUIRED)
find_package(Doxygen)
find_package(Libharu)
find_package(Wt)

add_library(Core src/Core.cpp)

add_library(Model_Session src/Model/Session.cpp)

add_library(Model_Object src/Model/Object.cpp)

add_library(Model_Link src/Model/Link.cpp)

add_library(Model_Attribute src/Model/Attribute.cpp)

add_library(Page_Login src/Page/Login.cpp)

add_library(Page_Forum src/Page/Forum.cpp)
target_link_libraries(Page_Forum Widget_PostEditor)

add_library(Menu_Help src/Menu/Help.cpp)

add_library(Menu_Main src/Menu/Main.cpp)
target_link_libraries(Menu_Main Page_Login Page_Forum Menu_Help)

add_library(Widget_PostEditor src/Widget/PostEditor.cpp)

add_executable(toutatis src/main.cpp)
target_link_libraries(toutatis Core Model_Session Menu_Main ${Boost_LIBRARIES} ${Wt_LIBRARIES})

add_executable(Test_WtDboPtrCast src/Test/WtDboPtrCast.cpp)
target_link_libraries(Test_WtDboPtrCast ${Boost_LIBRARIES} ${Wt_LIBRARIES})

add_executable(Test_Object src/Test/Object.cpp)
target_link_libraries(Test_Object Model_Object Model_Link Model_Attribute ${Boost_LIBRARIES} ${Wt_LIBRARIES})

install(TARGETS toutatis RUNTIME DESTINATION bin)
