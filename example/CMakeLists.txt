cmake_minimum_required(VERSION 3.2)
project(DemoProject)

set(CMAKE_CXX_STANDARD 11)


#import OpenMP
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

#complie with openmp
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")


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

include_directories( ${HDFS_INCLUDE_DIRS} )




set(SOURCE_FILES main.cpp)
add_executable(DemoProject ${SOURCE_FILES})
target_link_libraries(DemoProject ${CMAKE_SOURCE_DIR}/libFastLSH.a pthread ${HDFS_LIBRARIES})

