# Установка минимальной версии CMake
cmake_minimum_required(VERSION 3.12)

# Определение названия проекта IsmaEngineCore
set(ENGINE_PROJECT_NAME IsmaEngineCore)

# Список публичных заголовочных файлов
set(ENGINE_PUBLIC_INCLUDES
	includes/IsmaEngineCore/Graphics/Camera.h
	includes/IsmaEngineCore/Graphics/CubeBuilder.h
	includes/IsmaEngineCore/Graphics/CubeSheet.h
	
	includes/IsmaEngineCore/Util/ColorShade.h
	includes/IsmaEngineCore/Util/DistanceNoise.h
	includes/IsmaEngineCore/Util/MathFunctions.h

	includes/IsmaEngineCore/World/Cube.h
	includes/IsmaEngineCore/World/CubeChunk.h
	
	includes/IsmaEngineCore/Application.h
	
	includes/IsmaEngineCore/test.h
)

# Список приватных исходных файлов
set(ENGINE_PRIVATE_SOURCES
	src/IsmaEngineCore/Graphics/Camera.cpp
	src/IsmaEngineCore/Graphics/CubeBuilder.cpp
	src/IsmaEngineCore/Graphics/CubeSheet.cpp
	
	src/IsmaEngineCore/Util/ColorShade.cpp
	src/IsmaEngineCore/Util/DistanceNoise.cpp
	src/IsmaEngineCore/Util/MathFunctions.cpp

	src/IsmaEngineCore/World/Cube.cpp
	src/IsmaEngineCore/World/CubeChunk.cpp

	src/IsmaEngineCore/Application.cpp

	src/IsmaEngineCore/test.cpp
)

# Общий список исходных файлов
set(ENGINE_ALL_SOURCE
	${ENGINE_PUBLIC_INCLUDES}
	${ENGINE_PRIVATE_SOURCES}
)

# Создание статической библиотеки с названием IsmaEngineCore
add_library(${ENGINE_PROJECT_NAME} STATIC ${ENGINE_ALL_SOURCE})

# Группировка файлов в структуру проекта в IDE
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_ALL_SOURCE})

# Добавление путей к заголовочным файлам для внешних пользователей и для компиляции
target_include_directories(${ENGINE_PROJECT_NAME}
	PUBLIC
		includes
	PRIVATE
		src
)

# Установка стандарта C++ для компиляции
target_compile_features(${ENGINE_PROJECT_NAME} PUBLIC cxx_std_17)

# ------------------------------------------------------------------------------------- #

# Интеграция SFML

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Линковка с SFML
target_link_libraries(${ENGINE_PROJECT_NAME} PUBLIC sfml-graphics)

# Копирование OpenAL DLL (если это необходимо)
if(WIN32)
    add_custom_command(
        TARGET ${ENGINE_PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${ENGINE_PROJECT_NAME}>
        VERBATIM)
endif()

# Установка цели
install(TARGETS ${ENGINE_PROJECT_NAME})

# ------------------------------------------------------------------------------------- #