#ifndef MONITOR_H
#define MONITOR_H

#include <string>
#include <map>
#include <vector>

class MonitoramentoEstoque {
public:
    // Construtor
    MonitoramentoEstoque();

    // Adicionar um item ao estoque
    void adicionarItem(const std::string& nome, int quantidade);

    // Remover um item do estoque
    void removerItem(const std::string& nome, int quantidade);

    // Verificar a quantidade de um item no estoque
    int verificarItem(const std::string& nome) const;

    // Imprimir o estado atual do estoque
    void imprimirEstoque() const;

private:
    std::map<std::string, int> estoque;  // Mapa para armazenar itens e suas quantidades

    // Método auxiliar para verificar se um item existe no estoque
    bool itemExiste(const std::string& nome) const;
};

#endif // MONITOR_H
