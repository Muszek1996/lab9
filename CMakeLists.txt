cmake_minimum_required(VERSION 3.13)
project(zad1 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp -lm")
include_directories(SYSTEM ./lab11)


add_executable(zad1 zad1.c)
add_executable(zad2 zad2.c)
add_executable(zad3 zad3.c)
add_executable(zad4 zad4.c)
add_executable(zad6 zad6.c)
add_executable(openmp_watki_zmienne lab10/openmp_watki_zmienne.c)
add_executable(openmp_petle lab10/openmp_petle.c)
add_executable(search_max_openmp lab11/search_max_openmp.c)



set(LIBS ./lab11)
include_directories(${LIBS})
set(
        SOURCE_FILES
        ${LIBS}/search_max_openmp.c
        ${LIBS}/search_max_openmp.h
)

add_library (my_library STATIC ./lab11/search_max_openmp.h)

add_executable(test_search_max_openmp ./lab11/test_search_max_openmp.c ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(openmp_petle m)
TARGET_LINK_LIBRARIES(search_max_openmp m)

TARGET_LINK_LIBRARIES(test_search_max_openmp ${my_library} m)


add_executable(ex lab11/ex.c)