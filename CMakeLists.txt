# This file is a part of Cluster - Application for image clustering.
# Copyright (C) 2020 Krzysztof Adamkiewicz <kadamkiewicz835@gmail.com>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.5)

project(app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -fconcepts")

include_directories(utils/include)
include_directories(extLibs/mathtoolbox/include)
include_directories(extLibs/pyclustering/include)
link_directories("extLibs/build/mathtoolbox/")
link_directories("extLibs/build/pyclustering/")

add_subdirectory(utils)
add_subdirectory(magic)
add_subdirectory(app)
