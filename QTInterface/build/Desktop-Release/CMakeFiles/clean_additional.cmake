# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles/QTInterface_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/QTInterface_autogen.dir/ParseCache.txt"
  "QTInterface_autogen"
  )
endif()
