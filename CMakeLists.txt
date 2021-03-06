cmake_minimum_required(VERSION 3.2)
project(FastLSH)

#import OpenMP
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()


#import libhdfs
set(HDFS_FOUND "NO")
find_package(JNI)

if (JNI_FOUND)
    message (STATUS "JNI_INCLUDE_DIRS=${JNI_INCLUDE_DIRS}")
    message (STATUS "JNI_LIBRARIES=${JNI_LIBRARIES}")
endif()

if(JAVA_INCLUDE_PATH)

    find_path( HDFS_INCLUDE_PATH NAMES hdfs.h PATHS /usr/local/hadoop/include )
    find_path( HDFS_LIBRARY_PATH libhdfs.so PATHS /usr/local/hadoop/lib/native )
    find_library( HDFS_LIBRARY NAMES libhdfs.so PATHS /usr/local/hadoop/lib/native  )
    if(HDFS_INCLUDE_PATH)
        if(HDFS_LIBRARY_PATH)
            if(HDFS_LIBRARY)
                set( HDFS_FOUND "YES")
                set( HDFS_INCLUDE_DIRS ${HDFS_INCLUDE_PATH} ${JNI_INCLUDE_DIRS} )
                set( HDFS_LIBRARIES ${HDFS_LIBRARY} ${JNI_LIBRARIES} )
                message( STATUS "Found HDFS" ${HDFS_INCLUDE_PATH} )

            endif()
        endif()
    endif()
endif()

#complie with openmp
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")

include_directories( ${HDFS_INCLUDE_DIRS} )

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        README.md  include/LSH.h src/LSH.cpp
        src/InMemoryStore/memcached.cpp
        src/InMemoryStore/redis.cpp
        src/Normalizer.cpp
        include/otherClasses/FileLoader.h
        include/otherClasses/Computer.h  include/otherClasses/ParameterHolder.h
        include/otherClasses/Generator.h src/Generator.cpp src/Computer/PthreadComputer.cpp
        src/Computer/SingleThreadComputer.cpp src/Computer/OpenMPComputer.cpp src/Computer/StdThreadComputer.cpp
        src/FileLoader/LfsLoader.cpp src/FileLoader/FileLoader.cpp src/FileLoader/HdfsLoader.cpp)


#add_executable(FastLSH ${SOURCE_FILES})
add_library(FastLSH ${SOURCE_FILES})


target_link_libraries (FastLSH ${HDFS_LIBRARIES} memcached hiredis mpi)

