# 引入Boost
# REF: https://cmake.org/cmake/help/latest/module/FindBoost.html
set(Boost_DEBUG					ON)
set(Boost_NO_BOOST_CMAKE		ON)
#set(BOOST_ROOT /usr/local/Cellar/boost/1.71.0)
set(BOOST_ROOT /usr/local/Cellar/boost/1.72.0_1)
#set(BOOST_INCLUDEDIR ${BOOST_ROOT}/include)
#set(BOOST_LIBRARYDIR ${BOOST_ROOT}/lib)
set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     OFF)
# 设置使用的Boost组件
# REF: Boost Library Documentation: https://www.boost.org/doc/libs/
#find_package(Boost 1.71.0 REQUIRED COMPONENTS log)
find_package(Boost 1.72.0 REQUIRED COMPONENTS log)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  
  MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
  MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
  MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
  
  ## log 
  #add_executable(example_boost_log src/boost/example_boost_log.cpp)
  #target_link_libraries(example_boost_log ${Boost_LIBRARIES})
  ## typeindex
  add_executable(example_boost_typeindex src/boost/example_boost_typeindex.cpp)
  target_link_libraries(example_boost_typeindex ${Boost_LIBRARIES})
endif()