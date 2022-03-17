set(BLACK_WINTER_CLI_SRC
    main.cpp
    framework.cpp)
add_executable(black-winter-cli ${BLACK_WINTER_CLI_SRC})
target_link_libraries(black-winter-cli ${CONAN_LIBS})