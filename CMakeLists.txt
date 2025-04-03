cmake_minimum_required(VERSION 3.30)
project(Covid_genoma_analysis)

set(CMAKE_CXX_STANDARD 20)

set(DATA_DIR ${CMAKE_SOURCE_DIR}/data)

add_executable(Covid_genoma_analysis src/main.cpp)

# Configuração para copiar arquivos de dados para o diretório de build
file(COPY ${DATA_DIR}/ DESTINATION ${CMAKE_BINARY_DIR}/data)

# Define o diretório de execução (working directory) como a pasta do projeto
set_target_properties(Covid_genoma_analysis PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})