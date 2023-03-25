cmake_minimum_required(VERSION 3.24)

project(TestSTates)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS FALSE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "~/VSCodeProjs/TestSTates/bin")
set(SOURCE_FILES 
src/main.cpp 
src/base.hpp
src/base.cpp
)
add_definitions(-DSDL_MAIN_HANDLED -DGLEW_STATIC)

add_executable(TestSTates ${SOURCE_FILES})
target_include_directories(TestSTates PUBLIC "/usr/include/")
#target_link_libraries(TESTSDL SDL2 GLEW GL GLU SDL2_image SDL2_ttf)



# target_include_directories(TESTSDL PUBLIC "C:\\3dLIBS\\SDL2_image-2.6.3\\include")
# target_include_directories(TESTSDL PUBLIC "C:\\3dLIBS\\SDL2_ttf-2.20.2\\include")
# target_include_directories(TESTSDL PUBLIC "C:\\3dLIBS\\glew-2.2.0-win32\\glew-2.2.0\\include")
# target_include_directories(TESTSDL PUBLIC "C:\\3dLIBS\\glm-0.9.9.8\\glm")
target_link_libraries(TestSTates PUBLIC "/usr/lib/x86_64-linux-gnu/libSDL2.so")
target_link_libraries(TestSTates PUBLIC "/usr/lib/x86_64-linux-gnu/libSDL2main.a")
target_link_libraries(TestSTates PUBLIC "/usr/lib/x86_64-linux-gnu/libSDL2_image.so")
target_link_libraries(TestSTates PUBLIC "/usr/lib/x86_64-linux-gnu/libSDL2_mixer.so")
target_link_libraries(TestSTates PUBLIC "/usr/lib/x86_64-linux-gnu/libGLEW.so")
target_link_libraries(TestSTates PUBLIC "/usr/lib/x86_64-linux-gnu/libGL.so")
target_link_libraries(TestSTates PUBLIC "/usr/lib/x86_64-linux-gnu/libGLU.so")
target_link_libraries(TestSTates PUBLIC "/usr/lib/x86_64-linux-gnu/libSDL2_ttf.so")
target_link_libraries(TestSTates PUBLIC "/usr/lib/x86_64-linux-gnu/libSDL2_net.so")
target_compile_features(TestSTates PUBLIC cxx_std_23)
