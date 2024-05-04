# Установка минимальной версии CMake
cmake_minimum_required(VERSION 3.12)

# Определение названия проекта
set(PROJECT_NAME IsmaEngine)
project(${PROJECT_NAME})

# Добавления поддиректории для модуля IsmaEngineCore (ядро движка)
add_subdirectory(IsmaEngineCore)

# Добавления поддиректории для модуля IsmaEngineEditor (запускаем файл приложения)
add_subdirectory(IsmaEngineEditor)

# Установка IsmaEngineEditor в качестве стартового проекта для Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT IsmaEngineEditor)