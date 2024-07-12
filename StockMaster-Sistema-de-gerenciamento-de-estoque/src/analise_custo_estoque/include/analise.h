#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

struct Item {
    string nome;
    double preco;
    int quantidade;
};

int main() {
    int numItens;

    cout << "Quantos itens deseja analisar? ";
    cin >> numItens;

    vector<Item> estoque(numItens);

    for (int i = 0; i < numItens; ++i) {
        cout << "\nItem #" << i+1 << endl;
        cout << "Nome: ";
        cin >> estoque[i].nome;
        cout << "Preço por unidade: R$ ";
        cin >> estoque[i].preco;
        cout << "Quantidade: ";
        cin >> estoque[i].quantidade;
    }

  
    double custoTotal = 0.0;
    for (const auto& item : estoque) {
        custoTotal += item.preco * item.quantidade;
    }

    cout << "\nCusto total do estoque: R$ " << fixed << setprecision(2) << custoTotal << endl;

    return 0;
}
