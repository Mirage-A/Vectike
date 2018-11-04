cmake_minimum_required(VERSION 3.12)
project(Vectike)

set(CMAKE_CXX_STANDARD 17)

add_executable(Vectike main.cpp imagebuilder/Image.cpp imagebuilder/Color.cpp imagebuilder/Drawable.cpp imagebuilder/Vector.cpp imagebuilder/ImageBuilder.cpp editor/EditorFrame.cpp)