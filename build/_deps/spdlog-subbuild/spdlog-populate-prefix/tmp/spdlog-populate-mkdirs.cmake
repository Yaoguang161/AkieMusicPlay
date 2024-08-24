# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/software/Code/AkieMusicPlay/3rdParty/spdlog/be9796fe42cf4cd102be04c44dd3c83ff2a4d1c0"
  "E:/software/Code/AkieMusicPlay/build/_deps/spdlog-build"
  "E:/software/Code/AkieMusicPlay/build/_deps/spdlog-subbuild/spdlog-populate-prefix"
  "E:/software/Code/AkieMusicPlay/build/_deps/spdlog-subbuild/spdlog-populate-prefix/tmp"
  "E:/software/Code/AkieMusicPlay/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
  "E:/software/Code/AkieMusicPlay/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src"
  "E:/software/Code/AkieMusicPlay/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/software/Code/AkieMusicPlay/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/software/Code/AkieMusicPlay/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
