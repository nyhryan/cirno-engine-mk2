add_library("Cirno" STATIC
  ../engine/src/Test.cpp
)
set_target_properties("Cirno" PROPERTIES OUTPUT_NAME Cirno)
set_target_properties("Cirno" PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY_DEBUG "engine/bin/Debug"
  LIBRARY_OUTPUT_DIRECTORY_DEBUG "engine/bin/Debug"
  RUNTIME_OUTPUT_DIRECTORY_DEBUG "engine/bin/Debug"
  ARCHIVE_OUTPUT_DIRECTORY_RELEASE "engine/bin/Release"
  LIBRARY_OUTPUT_DIRECTORY_RELEASE "engine/bin/Release"
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "engine/bin/Release"
)
target_include_directories("Cirno" PRIVATE
  D:/Dev/Personal/c_cpp/cirno-engine-mk2/engine/include
)
target_compile_definitions("Cirno" PRIVATE
  CIRNO_EXPORTS
  $<$<CONFIG:Debug>:DEBUG>
  $<$<CONFIG:Release>:NDEBUG>
)
set_target_properties("Cirno" PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
  POSITION_INDEPENDENT_CODE False
  INTERPROCEDURAL_OPTIMIZATION False
)
target_compile_options("Cirno" PRIVATE
  $<$<CONFIG:Debug>:$<$<COMPILE_LANG_AND_ID:C,MSVC>:/MDd>>
  $<$<CONFIG:Debug>:$<$<COMPILE_LANG_AND_ID:C,MSVC>:/Z7>>
  $<$<CONFIG:Release>:$<$<COMPILE_LANG_AND_ID:C,MSVC>:/Ot>>
  $<$<CONFIG:Release>:$<$<COMPILE_LANG_AND_ID:C,MSVC>:/MD>>
  $<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/EHsc>
  $<$<CONFIG:Debug>:$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/MDd>>
  $<$<CONFIG:Debug>:$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/Z7>>
  $<$<CONFIG:Release>:$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/Ot>>
  $<$<CONFIG:Release>:$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/MD>>
  $<$<CONFIG:Debug>:$<$<AND:$<NOT:$<C_COMPILER_ID:MSVC>>,$<COMPILE_LANGUAGE:C>>:-g>>
  $<$<CONFIG:Release>:$<$<AND:$<NOT:$<C_COMPILER_ID:MSVC>>,$<COMPILE_LANGUAGE:C>>:-O2>>
  $<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<COMPILE_LANGUAGE:CXX>>:-std=c++20>
  $<$<CONFIG:Debug>:$<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<COMPILE_LANGUAGE:CXX>>:-g>>
  $<$<CONFIG:Release>:$<$<AND:$<NOT:$<CXX_COMPILER_ID:MSVC>>,$<COMPILE_LANGUAGE:CXX>>:-O2>>
)
target_link_libraries("Cirno"
  glfw
  glad
)
target_link_options("Cirno" PRIVATE
  /NOLOGO
)
