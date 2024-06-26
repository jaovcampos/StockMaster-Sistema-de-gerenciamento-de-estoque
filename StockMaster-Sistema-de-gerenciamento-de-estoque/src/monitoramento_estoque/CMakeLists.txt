cmake_minimum_required(VERSION 3.10)

project(MonitoramentoEstoque)

add_library(monitoramento_estoque
    src/monitor.cpp
)

target_include_directories(monitoramento_estoque PUBLIC include)
