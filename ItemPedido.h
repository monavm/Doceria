#pragma once
#include <iostream>
#include "Produto.h"

using namespace std;

class ItemPedido{
private:
    Produto* produto;
    int quantidade;
    double precoUnitario;

public:
    ItemPedido(){
        produto = nullptr;
        quantidade = 0;
        precoUnitario = 0;
    }
    ItemPedido(Produto* produto, int quantidade){
        this->produto = produto;
        this->quantidade = quantidade;
        this->precoUnitario = (produto != nullptr) ? produto->getPreco() : 0;
    }

    Produto* getProduto(){
        return produto;
    }
    int getQuantidade(){
        return quantidade;
    }
    double getPrecoUnitario(){
        return precoUnitario;
    }
    void setProduto(Produto* produto){
        this->produto = produto;
    }
    void setQuantidade(int quantidade){
        this->quantidade = quantidade;
    }
    void setPrecoUnitario(double precoUnitario){
        this->precoUnitario = precoUnitario;
    }

    double calcularSubTotal(){
        return precoUnitario * quantidade;
    }

    void exibir(){
        if(produto == nullptr)
            return;
        cout << "\nProduto: " << produto->getNome() << "\nQuantidade: " << quantidade << "\nPreco unitario: R$ " << precoUnitario;
        cout << "\nSubtotal: R$ " << calcularSubTotal() << endl;
    }
};
