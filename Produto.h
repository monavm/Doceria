#pragma once
#include <iostream>
#include <string>
#include "DataValidade.h"

using namespace std;

class Produto : public DataValidade {
protected:
    int id;
    string nome;
    double preco;
    int estoque;
public:
    Produto() : DataValidade(1, 1, 2000){
        id = 0;
        nome = "";
        preco = 0;
        estoque = 0;
    }
    Produto(int id, string nome, double preco, int estoque, int d, int m, int a): DataValidade(d, m, a){
        this->id = id;
        this->nome = nome;
        this->preco = preco;
        this->estoque = estoque;
    }
    virtual ~Produto(){}
    int getID(){
        return id;
    }
    string getNome(){
        return nome;
    }
    double getPreco(){
        return preco;
    }
    int getEstoque(){
        return estoque;
    }
    void setId(int id){
        this->id = id;
    }
    void setNome(string nome){
        this->nome = nome;
    }
    void setPreco(double preco){
        this->preco = preco;
    }
    void setEstoque(int estoque){
        this->estoque = estoque;
    }
    void setValidade(int d, int m, int a){
        dia = d;
        mes = m;
        ano = a;
    }
    virtual string getTipo() = 0;

    virtual void lerDadosExtras() = 0;
    virtual void salvarExtra(ostream& out) = 0;
    virtual void carregarExtra(istream& in) = 0;

    virtual void exibir(){
        cout << "\nProduto:" << "\nID: " << id << "\nNome: " << nome << "\nPreco: R$ " << preco << "\nEstoque: " << estoque << endl;
        DataValidade :: exibir();
    }
};
