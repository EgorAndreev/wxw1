cmake_minimum_required (VERSION 3.16)
project (wxw1)
IF (WIN32)
  add_executable(wxw1 WIN32 src/main.cpp)
add_custom_command(TARGET wxw1 POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:wxw1> $<TARGET_FILE_DIR:wxw1>
  COMMAND_EXPAND_LISTS
  )
ELSE()
  add_executable(wxw1 src/main.cpp)
ENDIF()

target_include_directories(wxw1 PUBLIC src)
add_subdirectory(external/wxWidgets)
target_link_libraries(wxw1 wx::base wx::core wx::aui wx::gl wx::html wx::media wx::net wx::propgrid wx::adv wx::qa wx::ribbon wx::richtext wx::stc wx::webview wx::xml wx::xrc)