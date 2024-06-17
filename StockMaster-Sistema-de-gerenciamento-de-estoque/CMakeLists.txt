cmake_minimum_required(VERSION 3.10)

project(StockMaster)

add_subdirectory(src/monitoramento_estoque)
add_subdirectory(src/gestao_entrada_saida)
add_subdirectory(src/classificacao_categoria)
add_subdirectory(src/controle_acesso)
add_subdirectory(src/analise_custo_estoque)

add_executable(StockMaster src/main.cpp)
