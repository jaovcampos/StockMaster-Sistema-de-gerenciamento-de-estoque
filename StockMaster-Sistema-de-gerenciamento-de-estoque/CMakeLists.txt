cmake_minimum_required(VERSION 3.10)

project(StockMaster)

# Adicionar subdiretórios para cada módulo
add_subdirectory(src/monitoramento_estoque)
# Você pode adicionar mais subdiretórios para outros módulos aqui

add_executable(StockMaster src/main.cpp)

# Incluir diretórios para cada módulo
target_include_directories(StockMaster PRIVATE src/monitoramento_estoque/include)
# Você pode adicionar mais diretórios de inclusão para outros módulos aqui

# Ligar biblioteca do módulo ao executável
target_link_libraries(StockMaster PRIVATE monitoramento_estoque)
