#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Produto.h"
#include "DataValidade.h"
#include "Doce.h"
#include "Salgado.h"
#include "Pedido.h"

using namespace std;

class Gerenciador{
private:
    vector<Produto*> produtos;
    vector<Pedido> pedidos;
    int proximoNumeroPedido;

public:
    Gerenciador(){
        proximoNumeroPedido = 1;
    }

    ~Gerenciador(){
        for(int i = 0; i < (int)produtos.size(); i++)
            delete produtos[i];
    }

    void inserir(){
        int tipo;

        cout << "\n1 - Doce";
        cout << "\n2 - Salgado";
        cout << "\nEscolha: ";
        cin >> tipo;

        if(tipo != 1 && tipo != 2){
            cout << "\nTipo invalido!\n";
            return;
        }

        int id;
        string nome;
        double preco;
        int estoque;

        cout << "ID: ";
        cin >> id;

        cin.ignore();

        cout << "Nome: ";
        getline(cin, nome);

        cout << "Preco: ";
        cin >> preco;

        cout << "Estoque: ";
        cin >> estoque;

        int dia, mes, ano;

        cout << "Validade (dia mes ano): ";
        cin >> dia >> mes >> ano;

        Produto* p = (tipo == 1)
            ? (Produto*) new Doce(id, nome, preco, estoque, dia, mes, ano, 0, false)
            : (Produto*) new Salgado(id, nome, preco, estoque, dia, mes, ano, "", false);

        cin.ignore();
        p->lerDadosExtras();

        produtos.push_back(p);

        cout << "\nProduto cadastrado com sucesso!\n";
    }

    void listarTodos(){
        if(produtos.empty()){
            cout << "\nNenhum produto cadastrado.\n";
            return;
        }

        for(int i = 0; i < (int)produtos.size(); i++){
            cout << "\nIndice: " << i << endl;
            produtos[i]->exibir();
            cout << endl;
        }
    }

    int pesquisar(string nome){
        vector<int> indices;

        for(int i = 0; i < (int)produtos.size(); i++){
            string nomeProduto = produtos[i]->getNome();

            if(nomeProduto.find(nome) == 0)
                indices.push_back(i);
        }

        if(indices.empty()){
            cout << "\nProduto nao encontrado.\n";
            return -1;
        }

        if(indices.size() == 1){
            cout << "\nResultado encontrado:\n";
            produtos[indices[0]]->exibir();
            return indices[0];
        }

        cout << "\nResultados encontrados:\n";
        for(int i = 0; i < (int)indices.size(); i++){
            cout << "\nIndice: " << indices[i] << endl;
            produtos[indices[i]]->exibir();
        }

        int indice;
        cout << "\nDigite o indice desejado: ";
        cin >> indice;

        if(indice < 0 || indice >= (int)produtos.size()){
            cout << "\nIndice invalido.\n";
            return -1;
        }

        return indice;
    }

    void exibirUm(string nome){
        int pos = pesquisar(nome);

        if(pos == -1)
            return;

        cout << "\nPRODUTO\n";
        produtos[pos]->exibir();
    }

    void alterar(string nome){
        int pos = pesquisar(nome);

        if(pos == -1)
            return;

        string novoNome;
        double novoPreco;
        int novoEstoque;

        if(cin.peek() == '\n')
            cin.ignore();

        cout << "\nNovo nome: ";
        getline(cin, novoNome);

        cout << "Novo preco: ";
        cin >> novoPreco;

        cout << "Novo estoque: ";
        cin >> novoEstoque;

        int dia, mes, ano;

        cout << "Nova validade (dia mes ano): ";
        cin >> dia >> mes >> ano;

        produtos[pos]->setNome(novoNome);
        produtos[pos]->setPreco(novoPreco);
        produtos[pos]->setEstoque(novoEstoque);
        produtos[pos]->setValidade(dia, mes, ano);

        cin.ignore();
        produtos[pos]->lerDadosExtras();

        cout << "\nProduto alterado com sucesso!\n";
    }

    void remover(string nome){
        int pos = pesquisar(nome);

        if(pos == -1)
            return;

        delete produtos[pos];
        produtos.erase(produtos.begin() + pos);

        cout << "\nProduto removido com sucesso!\n";
    }

    void exibirRelatorio(){
        cout << "\nRELATORIO\n";

        double valorTotal = 0;
        int doces = 0;
        int salgados = 0;

        for(int i = 0; i < (int)produtos.size(); i++){
            valorTotal += produtos[i]->getPreco() * produtos[i]->getEstoque();

            if(produtos[i]->getTipo() == "Doce")
                doces++;
            else
                salgados++;
        }

        cout << "Quantidade total de produtos: " << produtos.size() << endl;
        cout << "Quantidade de doces: " << doces << endl;
        cout << "Quantidade de salgados: " << salgados << endl;
        cout << "Valor total do estoque: R$ " << valorTotal << endl;
    }

    void salvarArquivo(){
        ofstream arquivo("produtos.txt");

        if(!arquivo.is_open()){
            cout << "\nErro ao salvar arquivo!\n";
            return;
        }

        arquivo << produtos.size() << endl;

        for(int i = 0; i < (int)produtos.size(); i++){
            arquivo << produtos[i]->getTipo() << endl;
            arquivo << produtos[i]->getID() << endl;
            arquivo << produtos[i]->getNome() << endl;
            arquivo << produtos[i]->getPreco() << endl;
            arquivo << produtos[i]->getEstoque() << endl;
            arquivo << produtos[i]->getDia() << " "
                    << produtos[i]->getMes() << " "
                    << produtos[i]->getAno() << endl;

            produtos[i]->salvarExtra(arquivo);
        }

        arquivo.close();
    }

    void carregarArquivo(){
        ifstream arquivo("produtos.txt");

        if(!arquivo.is_open())
            return;

        for(int i = 0; i < (int)produtos.size(); i++)
            delete produtos[i];

        produtos.clear();

        int qtd;

        arquivo >> qtd;
        arquivo.ignore();

        for(int i = 0; i < qtd; i++){
            string tipo;
            int id;
            string nome;
            double preco;
            int estoque;

            getline(arquivo, tipo);

            arquivo >> id;
            arquivo.ignore();

            getline(arquivo, nome);

            arquivo >> preco;
            arquivo >> estoque;
            arquivo.ignore();

            int dia, mes, ano;
            arquivo >> dia >> mes >> ano;
            arquivo.ignore();

            Produto* p = (tipo == "Doce")
                ? (Produto*) new Doce(id, nome, preco, estoque, dia, mes, ano, 0, false)
                : (Produto*) new Salgado(id, nome, preco, estoque, dia, mes, ano, "", false);

            p->carregarExtra(arquivo);

            produtos.push_back(p);
        }

        arquivo.close();
    }

    void criarPedido(){
        if(produtos.empty()){
            cout << "\nNenhum produto cadastrado. Cadastre produtos antes de criar um pedido.\n";
            return;
        }

        string clienteNome, data;

        cout << "\nNome do cliente: ";
        getline(cin, clienteNome);

        cout << "Data do pedido: ";
        getline(cin, data);

        Pedido pedido(proximoNumeroPedido, clienteNome, data);

        char continuar = 's';

        while(continuar == 's' || continuar == 'S'){
            listarTodos();

            int indice, quantidade;

            cout << "\nIndice do produto: ";
            cin >> indice;

            if(indice < 0 || indice >= (int)produtos.size()){
                cout << "\nIndice invalido.\n";
            }
            else{
                cout << "Quantidade: ";
                cin >> quantidade;

                pedido.adicionarItem(produtos[indice], quantidade);
                cout << "\nItem adicionado ao pedido!\n";
            }

            cout << "\nAdicionar outro item? (s/n): ";
            cin >> continuar;
        }

        pedidos.push_back(pedido);
        proximoNumeroPedido++;

        cout << "\nPedido criado com sucesso!\n";
        pedido.exibir();
    }

    void listarPedidos(){
        if(pedidos.empty()){
            cout << "\nNenhum pedido registrado.\n";
            return;
        }

        for(int i = 0; i < (int)pedidos.size(); i++){
            pedidos[i].exibir();
        }
    }
};
