#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <map>

using namespace std;


class Usuario {
private:

    string nomeUsuario;
    string senha;

public:
    Usuario(string nomeUsuario, string senha)
        : nomeUsuario(nomeUsuario), senha(senha) {}

    string getNomeUsuario() const { return nomeUsuario; }
    string getSenha() const { return senha; }
};


class SistemaLogin 
{
private:
    vector<Usuario> usuarios;

public:
    void cadastrarUsuario() 
    {
        string nomeUsuario, senha;
        cout << "Digite o nome de usuário: ";
        cin >> nomeUsuario;
        cout << "Digite a senha: ";
        cin >> senha;

        usuarios.push_back(Usuario(nomeUsuario, senha));
        cout << "Usuário cadastrado com sucesso!" << endl;
    }
    
    bool fazerLogin() 
    {
        string nomeUsuario, senha;
        cout << "Digite o nome de usuário: ";
        cin >> nomeUsuario;
        cout << "Digite a senha: ";
        cin >> senha;

        for (const auto& usuario : usuarios) 
        {
            if (usuario.getNomeUsuario() == nomeUsuario && usuario.getSenha() == senha)
            {
                cout << "Login bem-sucedido!" << endl;
                return true;
            }
        }
        cout << "Nome de usuário ou senha incorretos!" << endl;
        return false;
    }
};


class Produto {
private:
    int id;
    string nome;
    int quantidade;
    double preco; 
    string categoria;

public:
    Produto(int id, string nome, int quantidade, double preco, string categoria)
        : id(id), nome(nome), quantidade(quantidade), preco(preco), categoria(categoria) {}

    int getId() const { return id; }
    string getNome() const { return nome; }
    int getQuantidade() const { return quantidade; }
    double getPreco() const { return preco; }
    string getCategoria() const { return categoria; } 

    void setQuantidade(int quantidade) { this->quantidade = quantidade; }
    void setCategoria(string categoria) { this->categoria = categoria; } 

    void mostrarProduto() const
    {
        cout << "ID: " << id << ", Nome: " << nome << ", Quantidade: " << quantidade << ", Preço: R$ " << fixed << setprecision(2) << preco << ", Categoria: " << categoria << endl;
    }
};


class Estoque 
{
private:
    vector<Produto> produtos;
    map<string, vector<Produto>> categorias; 

public:
    void adicionarProduto() 
    {
        int numProdutos;
        int id, qtd;
        double preco;
        string nome, categoria;

        cout << "Quantos produtos deseja adicionar? ";
        cin >> numProdutos;

        for (int i = 0; i < numProdutos; ++i)
        {
            cout << "Informe o ID, Nome, Quantidade, Preço e Categoria do Produto " << i + 1 << ":" << endl;
            cout << "ID: ";
            cin >> id;
            cin.ignore(); 
            cout << "Nome: ";
            getline(cin, nome);
            cout << "Quantidade: ";
            cin >> qtd;
            cout << "Preço: R$ ";
            cin >> preco;
            cin.ignore(); 
            cout << "Categoria: ";
            getline(cin, categoria);

            Produto produto(id, nome, qtd, preco, categoria);
            produtos.push_back(produto);
            categorias[categoria].push_back(produto); 
            cout << "Produto adicionado com sucesso!" << endl;
        }
    }

    void entradaProduto(int id, int quantidade) 
    {
        for (auto& produto : produtos) 
        {
            if (produto.getId() == id) 
            {
                produto.setQuantidade(produto.getQuantidade() + quantidade);
                return;
            }
        }
        cout << "Produto não encontrado!" << endl;
    }

    void saidaProduto(int id, int quantidade) 
    {
        for (auto& produto : produtos) 
        {
            if (produto.getId() == id)
            {
                if (produto.getQuantidade() >= quantidade) 
                {
                    produto.setQuantidade(produto.getQuantidade() - quantidade);
                } else {
                    cout << "Quantidade insuficiente no estoque!" << endl;
                }
                return;
            }
        }
        cout << "Produto não encontrado!" << endl;
    }

    void mostrarEstoque() const 
    {
        if (produtos.empty()) 
        {
            cout << "Estoque vazio." << endl;
        } else {
            for (const auto& produto : produtos)
            {
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

    void analisarItens() const 
    {
        double custoTotal = 0.0;
        for (const auto& produto : produtos) 
        {
            
            
            custoTotal += produto.getPreco() * produto.getQuantidade();
        }
        cout << "\nCusto total do estoque: R$ " << fixed << setprecision(2) << custoTotal << endl;
    }

    void listarPorCategoria(const string& categoria) const
    {
        auto it = categorias.find(categoria);
        if (it != categorias.end()) {
            cout << "Produtos na categoria \"" << categoria << "\":" << endl;
            for (const auto& produto : it->second) 
            {
                produto.mostrarProduto();
            }
        } else 
        {
            cout << "Categoria não encontrada." << endl;
        }
    }
};


int main() 
{
    SistemaLogin sistemaLogin;
    Estoque estoque;

    int escolha;
    int id, quantidade;
    string categoria;
    Produto* produtoEncontrado = nullptr;

    do {
        cout << "\n Menu " << endl;
        cout << "1. Cadastrar Usuário" << endl;
        cout << "2. Fazer Login" << endl;
        cout << "3. Adicionar Produto" << endl;
        cout << "4. Mostrar Estoque" << endl;
        cout << "5. Entrada de Produto" << endl;
        cout << "6. Saída de Produto" << endl;
        cout << "7. Ordenar Estoque por Nome" << endl;
        cout << "8. Buscar Produto por ID" << endl;
        cout << "9. Analisar custo do  Estoque" << endl;
        cout << "10. Listar Produtos por Categoria" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha)
        {
            case 1:
                sistemaLogin.cadastrarUsuario();
                break;
            case 2:
                if (sistemaLogin.fazerLogin()) 
                {
                    break;
                } else {
                    continue;
                }
            case 3:
                estoque.adicionarProduto();
                break;
            case 4:
                estoque.mostrarEstoque();
                break;
            case 5:
                cout << "Informe o ID do Produto e a Quantidade a ser adicionada:" << endl;
                cin >> id >> quantidade;
                estoque.entradaProduto(id, quantidade);
                break;
            case 6:
                cout << "Informe o ID do Produto e a Quantidade a ser retirada:" << endl;
                cin >> id >> quantidade;
                estoque.saidaProduto(id, quantidade);
                break;
            case 7:
                estoque.ordenarPorNome();
                cout << "Estoque ordenado por nome:" << endl;
                estoque.mostrarEstoque();
                break;
            case 8:
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
            case 9:
                estoque.analisarItens();
                break;
            case 10:
                cout << "Informe a categoria:" << endl;
                cin.ignore();
                getline(cin, categoria);
                estoque.listarPorCategoria(categoria);
                break;
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida!." << endl;
                break;
        }
    } while (escolha != 0);

    return 0;
}
