cmake_minimum_required(VERSION 3.12)
project(Vectike)

set(CMAKE_CXX_STANDARD 17)

add_executable(Vectike main.cpp imagebuilder/image.cpp imagebuilder/color.cpp imagebuilder/drawables/vector.cpp imagebuilder/image-builder.cpp editor/editor-frame.cpp imagebuilder/drawables/drawable.h imagebuilder/transforms/transform.h imagebuilder/drawables/drawable.cpp imagebuilder/drawables/vector.h imagebuilder/transforms/transform.cpp imagebuilder/color.h imagebuilder/image.h imagebuilder/image-builder.h editor/editor-frame.h imagebuilder/math/matrix.cpp imagebuilder/math/matrix.h imagebuilder/transforms/move-transform.cpp imagebuilder/transforms/move-transform.h imagebuilder/transforms/rotate-transform.cpp imagebuilder/transforms/rotate-transform.h)