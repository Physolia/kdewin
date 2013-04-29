# KDEWIN_HAVE_... cmake variables are intended to enable or disable parts 
# in public header files depending on how kdewin is configured. 
# When a HAVE_... ist defined, KDEWIN_HAVE_... has to be set to zero. 
# KDEWIN_HAVE_... definitions have to be added to include/kdewin_export.h.cmake.  

if (MINGW)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set (MINGW64 1)
        set (MINGW_W64 1)
    else()
        set (MINGW32 1)
    endif()
endif (MINGW)
    
INCLUDE(CheckTypeSize)
INCLUDE(CheckFunctionExists)
INCLUDE(CheckSymbolExists)

SET(CMAKE_EXTRA_INCLUDE_FILES unistd.h)
CHECK_TYPE_SIZE(size_t KDEWIN_HAVE_SIZE_T)

CHECK_FUNCTION_EXISTS(usleep        KDEWIN_HAVE_USLEEP)
CHECK_FUNCTION_EXISTS(sleep         KDEWIN_HAVE_SLEEP)
CHECK_FUNCTION_EXISTS(fork          KDEWIN_HAVE_FORK)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/kdewin_config.h)
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/kdewin_config.h DESTINATION include)


