# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/software/Code/AkieMusicPlay/3rdParty/catch2/406a07db1ac202c2253293c0369ea576800cb47e"
  "E:/software/Code/AkieMusicPlay/build/_deps/catch2-build"
  "E:/software/Code/AkieMusicPlay/build/_deps/catch2-subbuild/catch2-populate-prefix"
  "E:/software/Code/AkieMusicPlay/build/_deps/catch2-subbuild/catch2-populate-prefix/tmp"
  "E:/software/Code/AkieMusicPlay/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
  "E:/software/Code/AkieMusicPlay/build/_deps/catch2-subbuild/catch2-populate-prefix/src"
  "E:/software/Code/AkieMusicPlay/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/software/Code/AkieMusicPlay/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/software/Code/AkieMusicPlay/build/_deps/catch2-subbuild/catch2-populate-prefix/src/catch2-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
