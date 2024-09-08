add_executable("Sandbox"
)
set_target_properties("Sandbox" PROPERTIES OUTPUT_NAME Sandbox)
set_target_properties("Sandbox" PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY_DEBUG "sandbox/bin/Debug"
  LIBRARY_OUTPUT_DIRECTORY_DEBUG "sandbox/bin/Debug"
  RUNTIME_OUTPUT_DIRECTORY_DEBUG "sandbox/bin/Debug"
  ARCHIVE_OUTPUT_DIRECTORY_RELEASE "sandbox/bin/Release"
  LIBRARY_OUTPUT_DIRECTORY_RELEASE "sandbox/bin/Release"
  RUNTIME_OUTPUT_DIRECTORY_RELEASE "sandbox/bin/Release"
)
add_dependencies("Sandbox"
  "Cirno"
)
target_include_directories("Sandbox" PRIVATE
  /Users/atai/Dev/personal/cirno-engine-mk2/engine/include
)
target_compile_definitions("Sandbox" PRIVATE
  $<$<CONFIG:Debug>:DEBUG>
  $<$<CONFIG:Release>:NDEBUG>
)
set_target_properties("Sandbox" PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED YES
  CXX_EXTENSIONS NO
  POSITION_INDEPENDENT_CODE False
  INTERPROCEDURAL_OPTIMIZATION False
)
target_compile_options("Sandbox" PRIVATE
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
target_link_libraries("Sandbox"
  Cirno
)
