set(BLACK_WINTER_CORE_LIBRARY_SRC
    server.cpp
    config.cpp
    request.cpp
    response.cpp
    session.cpp
    internal/file_loader.cpp
    )

add_library(black-winter-core ${BLACK_WINTER_CORE_LIBRARY_SRC})
target_link_libraries(black-winter-core ${CONAN_LIBS})