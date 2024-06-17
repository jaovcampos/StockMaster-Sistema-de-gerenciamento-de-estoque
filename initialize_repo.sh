#!/bin/bash

# Criar diretórios principais
mkdir -p StockMaster-Sistema-de-gerenciamento-de-estoque/{docs,src,tests}

# Criar subdiretórios em src
mkdir -p StockMaster-Sistema-de-gerenciamento-de-estoque/src/{monitoramento_estoque,gestao_entrada_saida,classificacao_categoria,controle_acesso,analise_custo_estoque}

# Criar subdiretórios include e src para cada módulo
for module in monitoramento_estoque gestao_entrada_saida classificacao_categoria controle_acesso analise_custo_estoque; do
    mkdir -p StockMaster-Sistema-de-gerenciamento-de-estoque/src/$module/{include,src}
done

# Criar CMakeLists.txt para cada módulo
for module in monitoramento_estoque gestao_entrada_saida classificacao_categoria controle_acesso analise_custo_estoque; do
    touch StockMaster-Sistema-de-gerenciamento-de-estoque/src/$module/CMakeLists.txt
done

# Criar arquivos .h e .cpp de exemplo para cada módulo
echo -e '#ifndef MONITOR_H\n#define MONITOR_H\n\n// Funções de monitoramento de estoque\n\n#endif // MONITOR_H' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/monitoramento_estoque/include/monitor.h
echo -e '#include "monitor.h"\n\n// Implementação das funções de monitoramento' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/monitoramento_estoque/src/monitor.cpp

echo -e '#ifndef ENTRADA_H\n#define ENTRADA_H\n\n// Funções de entrada de produtos\n\n#endif // ENTRADA_H' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/gestao_entrada_saida/include/entrada.h
echo -e '#include "entrada.h"\n\n// Implementação das funções de entrada' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/gestao_entrada_saida/src/entrada.cpp
echo -e '#ifndef SAIDA_H\n#define SAIDA_H\n\n// Funções de saída de produtos\n\n#endif // SAIDA_H' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/gestao_entrada_saida/include/saida.h
echo -e '#include "saida.h"\n\n// Implementação das funções de saída' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/gestao_entrada_saida/src/saida.cpp

echo -e '#ifndef CLASSIFICACAO_H\n#define CLASSIFICACAO_H\n\n// Funções de classificação de produtos\n\n#endif // CLASSIFICACAO_H' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/classificacao_categoria/include/classificacao.h
echo -e '#include "classificacao.h"\n\n// Implementação das funções de classificação' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/classificacao_categoria/src/classificacao.cpp
echo -e '#ifndef CATEGORIA_H\n#define CATEGORIA_H\n\n// Funções de categorização de produtos\n\n#endif // CATEGORIA_H' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/classificacao_categoria/include/categoria.h
echo -e '#include "categoria.h"\n\n// Implementação das funções de categorização' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/classificacao_categoria/src/categoria.cpp

echo -e '#ifndef AUTENTICACAO_H\n#define AUTENTICACAO_H\n\n// Funções de autenticação\n\n#endif // AUTENTICACAO_H' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/controle_acesso/include/autenticacao.h
echo -e '#include "autenticacao.h"\n\n// Implementação das funções de autenticação' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/controle_acesso/src/autenticacao.cpp
echo -e '#ifndef AUTORIZACAO_H\n#define AUTORIZACAO_H\n\n// Funções de autorização\n\n#endif // AUTORIZACAO_H' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/controle_acesso/include/autorizacao.h
echo -e '#include "autorizacao.h"\n\n// Implementação das funções de autorização' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/controle_acesso/src/autorizacao.cpp

echo -e '#ifndef ANALISE_H\n#define ANALISE_H\n\n// Funções de análise de custo de estoque\n\n#endif // ANALISE_H' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/analise_custo_estoque/include/analise.h
echo -e '#include "analise.h"\n\n// Implementação das funções de análise de custo' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/analise_custo_estoque/src/analise.cpp

# Criar arquivo principal main.cpp
echo -e '#include <iostream>\n\nint main() {\n    std::cout << "StockMaster Sistema de Gerenciamento de Estoque" << std::endl;\n    return 0;\n}' > StockMaster-Sistema-de-gerenciamento-de-estoque/src/main.cpp

# Criar CMakeLists.txt raiz
echo -e 'cmake_minimum_required(VERSION 3.10)\n\nproject(StockMaster)\n\nadd_subdirectory(src/monitoramento_estoque)\nadd_subdirectory(src/gestao_entrada_saida)\nadd_subdirectory(src/classificacao_categoria)\nadd_subdirectory(src/controle_acesso)\nadd_subdirectory(src/analise_custo_estoque)\n\nadd_executable(StockMaster src/main.cpp)' > StockMaster-Sistema-de-gerenciamento-de-estoque/CMakeLists.txt

# Criar .gitignore
echo -e '# Compiled object files\n*.o\n*.obj\n\n# Precompiled Headers\n*.gch\n\n# Libraries\n*.lib\n*.a\n*.la\n*.lo\n\n# Executables\n*.exe\n*.out\n*.app\n\n# Build directories\n/build\n/CMakeFiles\n\n# CMake specific files\nCMakeCache.txt\nCMakeFiles\nMakefile\ncmake_install.cmake\ninstall_manifest.txt\ncompile_commands.json\n\n# Other files to ignore\n.idea\n.vscode\n' > StockMaster-Sistema-de-gerenciamento-de-estoque/.gitignore

# Criar README.md
echo -e '# StockMaster - Sistema de Gerenciamento de Estoque\n\n## Descrição\nEste projeto é um sistema de gerenciamento de estoque desenvolvido em C++. Ele fornece funcionalidades para monitoramento de estoque, gestão de entrada e saída, classificação e categorização de produtos, controle de acesso e análise de custo de estoque.\n\n## Estrutura do Projeto\n\n- **docs/**: Documentação do projeto.\n- **src/**: Código-fonte principal.\n- **tests/**: Testes unitários e de integração.\n- **.gitignore**: Arquivos e diretórios a serem ignorados pelo Git.\n- **README.md**: Documentação principal do projeto.\n- **CMakeLists.txt**: Arquivo de build raiz para o projeto inteiro.\n\n## Como Compilar\nPara compilar o projeto, use o CMake:\n\n```sh\nmkdir build\ncd build\ncmake ..\nmake\n./StockMaster\n```\n' > StockMaster-Sistema-de-gerenciamento-de-estoque/README.md

# Criar arquivos de teste de exemplo
mkdir -p StockMaster-Sistema-de-gerenciamento-de-estoque/tests/{include,src}
echo -e '#ifndef TEST_MONITORAMENTO_ESTOQUE_H\n#define TEST_MONITORAMENTO_ESTOQUE_H\n\n// Testes para monitoramento de estoque\n\n#endif // TEST_MONITORAMENTO_ESTOQUE_H' > StockMaster-Sistema-de-gerenciamento-de-estoque/tests/include/test_monitoramento_estoque.h
echo -e '#include "test_monitoramento_estoque.h"\n\n// Implementação dos testes de monitoramento de estoque' > StockMaster-Sistema-de-gerenciamento-de-estoque/tests/src/test_monitoramento_estoque.cpp

# Adicionar CMakeLists.txt para os testes
echo -e 'cmake_minimum_required(VERSION 3.10)\n\nproject(StockMasterTests)\n\nadd_executable(test_monitoramento_estoque tests/src/test_monitoramento_estoque.cpp)' > StockMaster-Sistema-de-gerenciamento-de-estoque/tests/CMakeLists.txt

# Mensagem de finalização
echo "Estrutura do projeto StockMaster criada com sucesso."

