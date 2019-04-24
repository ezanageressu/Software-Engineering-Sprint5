cmake_minimum_required(VERSION 3.1.0)

project(Pencil-Producer)

# set Qt for MACOS
set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/5.12.1/clang_64)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Network REQUIRED)
# Populate a CMake variable with the sources
set(pencilproducer_SRCS
    Pencil-Producer/pencilproducer.ui
    Pencil-Producer/pencilproducer.cpp
    Pencil-Producer/main.cpp
    Pencil-Producer/wallet.cpp
    Pencil-Producer/material_inventory.cpp
    Pencil-Producer/wood_inventory.cpp
    Pencil-Producer/graphite_inventory.cpp
    Pencil-Producer/pencil_inventory.cpp
    Pencil-Producer/apm2000_inventory.cpp
)
# Tell CMake to create the pencilproducer executable
add_executable(pencilproducer ${pencilproducer_SRCS})
# Use the Widgets module from Qt 5
target_link_libraries(pencilproducer Qt5::Widgets)
target_link_libraries(pencilproducer Qt5::Widgets Qt5::Network)
