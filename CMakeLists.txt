cmake_minimum_required(VERSION 3.5)
project(Diff_EQ_Calc)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES Diff_eq_calc.cpp Folhdeccic.cpp Folhdeccic.h Lhdeccic.cpp Lhdeccic.h Signal.cpp Signal.h)

# create unittests
add_executable(Diff_eq_calc Diff_eq_calc.cpp Folhdeccic.cpp Folhdeccic.h Lhdeccic.cpp Lhdeccic.h Signal.cpp Signal.h${SOURCE})

