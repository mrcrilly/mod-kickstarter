AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/Kickstarter.cpp")
AC_ADD_SCRIPT_LOADER("Kickstarter" "${CMAKE_CURRENT_LIST_DIR}/src/loader.h")

AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/kickstarter.conf.dist")
