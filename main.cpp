#include <iostream>
#include <string>
#include "Gerenciador.h"

using namespace std;

int main(){
    Gerenciador sistema;
    sistema.carregarArquivo();

    int opcao;
    string nome;

    do{
        cout << "\nDOCERIA DOCE SABOR";
        cout << "\n1 - Inserir Produto";
        cout << "\n2 - Listar Produtos";
        cout << "\n3 - Pesquisar Produto";
        cout << "\n4 - Alterar Produto";
        cout << "\n5 - Remover Produto";
        cout << "\n6 - Relatorio";
        cout << "\n7 - Criar Pedido";
        cout << "\n8 - Listar Pedidos";
        cout << "\n0 - Sair";
        cout << "\nOpcao: ";
        cin >> opcao;
        cin.ignore();

        switch(opcao){
        case 1:
            sistema.inserir();
            break;
        case 2:
            sistema.listarTodos();
            break;
        case 3:
            cout << "\nDigite o nome: ";
            getline(cin, nome);
            sistema.exibirUm(nome);
            break;
        case 4:
            cout << "\nDigite o nome: ";
            getline(cin, nome);
            sistema.alterar(nome);
            break;
        case 5:
            cout << "\nDigite o nome: ";
            getline(cin, nome);
            sistema.remover(nome);
            break;
        case 6:
            sistema.exibirRelatorio();
            break;
        case 7:
            sistema.criarPedido();
            break;
        case 8:
            sistema.listarPedidos();
            break;
        case 0:
            sistema.salvarArquivo();
            cout << "\nDados salvos com sucesso!";
            cout << "\nPrograma encerrado!\n";
            break;
        default:
            cout << "\nOpcao invalida!\n";
        }
    } while(opcao != 0);

    return 0;
}
