#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;


struct Item {
    int id;
    string nome;
    int quantidade;
};


enum class TipoUsuario {
    Administrador,
    UsuarioPadrao
};

struct Usuario {
    string nomeUsuario;
    string senha;
    TipoUsuario tipo;
};


class Estoque {
private:
    vector<Item> itens;
    int proximoId;

public:
    Estoque() : proximoId(1) {
        
        adicionarItem("Item1", 10);
        adicionarItem("Item2", 20);
        adicionarItem("Item3", 30);
    }

    void adicionarItem(const string& nome, int quantidade) {
        Item novoItem;
        novoItem.id = proximoId++;
        novoItem.nome = nome;
        novoItem.quantidade = quantidade;
        itens.push_back(novoItem);
    }

    void removerItem(int id) {
        for (auto it = itens.begin(); it != itens.end(); ++it) {
            if (it->id == id) {
                itens.erase(it);
                cout << "Item removido com sucesso!\n";
                return;
            }
        }
        cout << "Item com ID " << id << " não encontrado.\n";
    }

    void listarItens() const {
        if (itens.empty()) {
            cout << "O estoque está vazio.\n";
            return;
        }
        for (const auto& item : itens) {
            cout << "ID: " << item.id << ", Nome: " << item.nome << ", Quantidade: " << item.quantidade << "\n";
        }
    }
};

class ControleAcesso {
private:
    map<string, Usuario> usuarios; 
    TipoUsuario tipoUsuario;
    Usuario* usuarioLogado;

public:
    ControleAcesso() : tipoUsuario(TipoUsuario::UsuarioPadrao), usuarioLogado(nullptr) {}

    void cadastrarUsuario(const string& nomeUsuario, const string& senha, TipoUsuario tipo) {
        usuarios[nomeUsuario] = {nomeUsuario, senha, tipo};
        cout << "Usuário cadastrado com sucesso!\n";
    }

    bool fazerLogin(const string& nomeUsuario, const string& senha) {
        auto it = usuarios.find(nomeUsuario);
        if (it != usuarios.end() && it->second.senha == senha) {
            tipoUsuario = it->second.tipo;
            usuarioLogado = &it->second;
            return true;
        }
        return false;
    }

    void logout() {
        usuarioLogado = nullptr;
        tipoUsuario = TipoUsuario::UsuarioPadrao;
    }

    bool estaLogado() const {
        return usuarioLogado != nullptr;
    }

    bool temAcessoAdministrador() const {
        return tipoUsuario == TipoUsuario::Administrador;
    }
};

void mostrarMenu(ControleAcesso& controleAcesso) {
    cout << "1. Remover item";
    if (controleAcesso.temAcessoAdministrador()) {
        cout << " (Apenas administrador)";
    }
    cout << "\n";
    cout << "2. Listar itens\n";
    cout << "3. Cadastrar usuário\n";
    cout << "4. Login\n";
    cout << "5. Logout\n";
    cout << "6. Sair\n";
}

int main() {
    Estoque estoque;
    ControleAcesso controleAcesso;
    int escolha;

    controleAcesso.cadastrarUsuario("admin", "admin123", TipoUsuario::Administrador); 

    do {
        mostrarMenu(controleAcesso);
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha) {
            case 1: {
                if (controleAcesso.temAcessoAdministrador()) {
                    int id;
                    cout << "ID do item a ser removido: ";
                    cin >> id;
                    estoque.removerItem(id);
                } else {
                    cout << "Acesso negado. Opção disponível apenas para administradores.\n";
                }
                break;
            }
            case 2: {
                estoque.listarItens();
                break;
            }
            case 3: {
                string nomeUsuario, senha;
                int tipo;
                cout << "Nome de usuário: ";
                cin >> nomeUsuario;
                cout << "Senha: ";
                cin >> senha;
                cout << "Tipo de usuário (1 - Administrador, 2 - Usuário Padrão): ";
                cin >> tipo;
                TipoUsuario tipoUsuario = (tipo == 1) ? TipoUsuario::Administrador : TipoUsuario::UsuarioPadrao;
                controleAcesso.cadastrarUsuario(nomeUsuario, senha, tipoUsuario);
                break;
            }
            case 4: {
                string nomeUsuario, senha;
                cout << "Nome de usuário: ";
                cin >> nomeUsuario;
                cout << "Senha: ";
                cin >> senha;
                if (controleAcesso.fazerLogin(nomeUsuario, senha)) {
                    cout << "Login realizado com sucesso!\n";
                } else {
                    cout << "Falha no login. Verifique o nome de usuário e a senha.\n";
                }
                break;
            }
            case 5: {
                controleAcesso.logout();
                cout << "Logout realizado com sucesso!\n";
                break;
            }
            case 6: {
                cout << "Saindo...\n";
                break;
            }
            default: {
                cout << "Opção inválida. Tente novamente.\n";
                break;
            }
        }
    } while (escolha != 6);

    return 0;
}
