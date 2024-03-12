aux_source_directory(. RENAMD_SRC)
add_library(renamd SHARED
    ${RENAMD_SRC}
)
target_include_directories(renamd
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)
target_compile_definitions(renamd
    PUBLIC
        RICH_FORCE_WINAPI
)
