#include <iostream>
#include "monitoramento_estoque/include/monitor.h"

int main() {
    MonitoramentoEstoque estoque;

    estoque.adicionarItem("ProdutoA", 50);
    estoque.adicionarItem("ProdutoB", 20);
    estoque.removerItem("ProdutoA", 10);
    estoque.imprimirEstoque();

    int quantidadeProdutoB = estoque.verificarItem("ProdutoB");
    std::cout << "Quantidade de ProdutoB no estoque: " << quantidadeProdutoB << "\n";

    return 0;
}
