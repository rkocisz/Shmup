# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Projects/cpp/visual studio/Shmup/build/_deps/sfml-src"
  "C:/Projects/cpp/visual studio/Shmup/build/_deps/sfml-build"
  "C:/Projects/cpp/visual studio/Shmup/build/_deps/sfml-subbuild/sfml-populate-prefix"
  "C:/Projects/cpp/visual studio/Shmup/build/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "C:/Projects/cpp/visual studio/Shmup/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "C:/Projects/cpp/visual studio/Shmup/build/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "C:/Projects/cpp/visual studio/Shmup/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs Debug)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Projects/cpp/visual studio/Shmup/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Projects/cpp/visual studio/Shmup/build/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
