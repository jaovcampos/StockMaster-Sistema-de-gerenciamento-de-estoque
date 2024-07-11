#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definição da classe ItemEstoque
class ItemEstoque {
private:
    string nome;
    string categoria;
    int quantidade;
    float preco;

public:
    // Construtor
    ItemEstoque(string nome, string categoria, int quantidade, float preco) {
        this->nome = nome;
        this->categoria = categoria;
        this->quantidade = quantidade;
        this->preco = preco;
    }

    // Método para inserir dados do item
    void inserirDados() {
        cout << "Digite o nome do item: ";
        cin >> nome;

        cout << "Digite a categoria do item: ";
        cin >> categoria;

        cout << "Digite a quantidade em estoque: ";
        cin >> quantidade;

        cout << "Digite o preço unitário do item: ";
        cin >> preco;
    }

    // Métodos para acessar informações do item
    string getNome() const {
        return nome;
    }

    string getCategoria() const {
        return categoria;
    }

    int getQuantidade() const {
        return quantidade;
    }

    float getPreco() const {
        return preco;
    }

    // Método para alterar a quantidade em estoque
    void setQuantidade(int novaQuantidade) {
        quantidade = novaQuantidade;
    }

    // Método para exibir informações do item
    void exibirInformacoes() const {
        cout << "Nome: " << nome << endl;
        cout << "Categoria: " << categoria << endl;
        cout << "Quantidade: " << quantidade << endl;
        cout << "Preço: " << preco << endl;
    }
};

// Função principal
int main() {
    // Criando um item de estoque
    ItemEstoque item1("", "", 0, 0.0);

    // Inserindo dados do item através do método
    cout << "Insira os dados do item:" << endl;
    item1.inserirDados();
    cout << endl;

    // Exibindo informações do item inserido
    cout << "Informações do item inserido:" << endl;
    item1.exibirInformacoes();

    return 0;
}
