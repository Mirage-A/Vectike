cmake_minimum_required(VERSION 3.12)
project(Vectike)

set(CMAKE_CXX_STANDARD 17)

add_executable(Vectike main.cpp imagebuilder/image.cpp imagebuilder/color.cpp imagebuilder/vector.cpp imagebuilder/image-builder.cpp editor/editor-frame.cpp imagebuilder/drawable.h imagebuilder/transform.h imagebuilder/drawable.cpp imagebuilder/vector.h imagebuilder/transform.cpp imagebuilder/color.h imagebuilder/image.h imagebuilder/image-builder.h editor/editor-frame.h math/matrix.cpp math/matrix.h)