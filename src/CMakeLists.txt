if (BLACK_WINTER_BUILD_CLI)
  message(${BLACK_WINTER_MSG_PREFIX}"black winter CLI tool enabled")
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cli)
endif ()
if (BLACK_WINTER_BUILD_CORE)
  message(${BLACK_WINTER_MSG_PREFIX}"black winter core library enabled")
  add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/library/core)
endif ()

