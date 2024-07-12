#include "entrada.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


class Produto
{
private:
    int id;
    string nome;
    int quantidade;

public:
   
    Produto(int id, string nome, int quantidade)
        : id(id), nome(nome), quantidade(quantidade) {}

    
    int getId() const { return id; }
    string getNome() const { return nome; }
    int getQuantidade() const { return quantidade; }

  
    void setQuantidade(int quantidade) { this->quantidade = quantidade; }

    
    void mostrarProduto() const {
        cout << "ID: " << id << ", Nome: " << nome << ", Quantidade: " << quantidade << endl;
    }
};


class Estoque 
{
private:
    vector<Produto> produtos;

public:
    
    void adicionarProduto() 
    {
        int numProdutos;
        int id, qtd;
        string nome;

        cout << "Quantos produtos deseja adicionar? ";
        cin >> numProdutos;

        for (int i = 0; i < numProdutos; ++i) {
            cout << "Informe o ID, Nome e Quantidade do Produto " << i + 1 << ":" << endl;
            cout << "ID: ";
            cin >> id;
            cin.ignore(); 
            cout << "Nome: ";
            getline(cin, nome);
            cout << "Quantidade: ";
            cin >> qtd;

            produtos.push_back(Produto(id, nome, qtd));
            cout << "Produto adicionado com sucesso!" << endl;
        }
    }

    
    void entradaProduto(int id, int quantidade) 
    {
        for (auto& produto : produtos) {
            if (produto.getId() == id) {
                produto.setQuantidade(produto.getQuantidade() + quantidade);
                return;
            }
        }
        cout << "Produto não encontrado!" << endl;
    }

   
    void saidaProduto(int id, int quantidade)
    {
        for (auto& produto : produtos) {
            if (produto.getId() == id) {
                if (produto.getQuantidade() >= quantidade) {
                    produto.setQuantidade(produto.getQuantidade() - quantidade);
                } else {
                    cout << "Quantidade insuficiente no estoque!" << endl;
                }
                return;
            }
        }
        cout << "Produto não encontrado!" << endl;
    }

    
    void mostrarEstoque() const {
        if (produtos.empty()) {
            cout << "Estoque vazio." << endl;
        } else {
            for (const auto& produto : produtos) {
                produto.mostrarProduto();
            }
        }
    }

 
    void ordenarPorNome() {
        sort(produtos.begin(), produtos.end(), [](const Produto& a, const Produto& b)
        {
            return a.getNome() < b.getNome();
        });
    }


    Produto* buscarProduto(int id)
    {
        for (auto& produto : produtos)
        {
            if (produto.getId() == id) 
            {
                return &produto;
            }
        }
        return nullptr;
    }
};

int main() 
{
    Estoque estoque;

    int escolha;
    int id, quantidade;
    Produto* produtoEncontrado = nullptr;

    do {
       
       
        cout << "\n Menu " << endl;
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Mostrar Estoque" << endl;
        cout << "3. Entrada de Produto" << endl;
        cout << "4. Saída de Produto" << endl;
        cout << "5. Ordenar Estoque por Nome" << endl;
        cout << "6. Buscar Produto por ID" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha)
        {
            case 1:
                estoque.adicionarProduto();
                break;
            case 2:
                estoque.mostrarEstoque();
                break;
            case 3:
                cout << "Informe o ID do Produto e a Quantidade a ser adicionada:" << endl;
                cin >> id >> quantidade;
                estoque.entradaProduto(id, quantidade);
                break;
            case 4:
                cout << "Informe o ID do Produto e a Quantidade a ser retirada:" << endl;
                cin >> id >> quantidade;
                estoque.saidaProduto(id, quantidade);
                break;
            case 5:
                estoque.ordenarPorNome();
                cout << "Estoque ordenado por nome:" << endl;
                estoque.mostrarEstoque();
                break;
            case 6:
                cout << "Informe o ID do Produto:" << endl;
                cin >> id;
                produtoEncontrado = estoque.buscarProduto(id);
                if (produtoEncontrado != nullptr) {
                    cout << "Produto encontrado:" << endl;
                    produtoEncontrado->mostrarProduto();
                } else {
                    cout << "Produto não encontrado!" << endl;
                }
                break;
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida! Escolha novamente." << endl;
                break;
        }
    }
    while (escolha != 0);

    return 0;
}

