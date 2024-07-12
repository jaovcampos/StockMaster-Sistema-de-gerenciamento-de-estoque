#include <iostream>
#include <string>
#include <map>

using namespace std;

class MonitoramentoEstoque {
public:
    MonitoramentoEstoque();

    void adicionarItem(const string& nome, int quantidade);
    void removerItem(const string& nome, int quantidade);
    int verificarItem(const string& nome) const;
    void imprimirEstoque() const;

private:
    map<string, int> estoque;  
    bool itemExiste(const string& nome) const;
};

MonitoramentoEstoque::MonitoramentoEstoque() {}

void MonitoramentoEstoque::adicionarItem(const string& nome, int quantidade) {
    estoque[nome] += quantidade;
    cout << "Adicionado " << quantidade << " de " << nome << " ao estoque.\n";
}

void MonitoramentoEstoque::removerItem(const string& nome, int quantidade) {
    if (itemExiste(nome)) {
        if (estoque[nome] >= quantidade) {
            estoque[nome] -= quantidade;
            cout << "Removido " << quantidade << " de " << nome << " do estoque.\n";
        } else {
            cout << "Erro: Não há quantidade suficiente de " << nome << " no estoque.\n";
        }
    } else {
        cout << "Erro: Item " << nome << " não encontrado no estoque.\n";
    }
}

int MonitoramentoEstoque::verificarItem(const string& nome) const {
    auto it = estoque.find(nome);
    if (it != estoque.end()) {
        return it->second;
    } else {
        return 0; 
    }
}

void MonitoramentoEstoque::imprimirEstoque() const {
    cout << "Estado atual do estoque:\n";
    for (const auto& item : estoque) {
        cout << "- " << item.first << ": " << item.second << "\n";
    }
}

bool MonitoramentoEstoque::itemExiste(const string& nome) const {
    return estoque.find(nome) != estoque.end();
}

int main() {
    MonitoramentoEstoque estoque;
    estoque.adicionarItem("item1", 10);
    estoque.adicionarItem("item2", 5);
    estoque.removerItem("item1", 3);
    estoque.imprimirEstoque();
    cout << "Quantidade de item1: " << estoque.verificarItem("item1") << "\n";
    return 0;
}
