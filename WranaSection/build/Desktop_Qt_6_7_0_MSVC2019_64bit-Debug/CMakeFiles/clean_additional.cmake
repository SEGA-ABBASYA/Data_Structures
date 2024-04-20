# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\WranaSection_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\WranaSection_autogen.dir\\ParseCache.txt"
  "WranaSection_autogen"
  )
endif()
