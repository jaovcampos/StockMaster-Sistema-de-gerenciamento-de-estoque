#include "monitor.h"
#include <iostream>

MonitoramentoEstoque::MonitoramentoEstoque() {
    // Construtor padrão
}

void MonitoramentoEstoque::adicionarItem(const std::string& nome, int quantidade) {
    estoque[nome] += quantidade;
    std::cout << "Adicionado " << quantidade << " de " << nome << " ao estoque.\n";
}

void MonitoramentoEstoque::removerItem(const std::string& nome, int quantidade) {
    if (itemExiste(nome)) {
        if (estoque[nome] >= quantidade) {
            estoque[nome] -= quantidade;
            std::cout << "Removido " << quantidade << " de " << nome << " do estoque.\n";
        } else {
            std::cout << "Erro: Não há quantidade suficiente de " << nome << " no estoque.\n";
        }
    } else {
        std::cout << "Erro: Item " << nome << " não encontrado no estoque.\n";
    }
}

int MonitoramentoEstoque::verificarItem(const std::string& nome) const {
    auto it = estoque.find(nome);
    if (it != estoque.end()) {
        return it->second;
    } else {
        return 0;  // Retorna 0 se o item não for encontrado
    }
}

void MonitoramentoEstoque::imprimirEstoque() const {
    std::cout << "Estado atual do estoque:\n";
    for (const auto& item : estoque) {
        std::cout << "- " << item.first << ": " << item.second << "\n";
    }
}

bool MonitoramentoEstoque::itemExiste(const std::string& nome) const {
    return estoque.find(nome) != estoque.end();
}
