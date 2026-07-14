#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "ItemPedido.h"

using namespace std;

class Pedido{
private:
    int id;
    string status;
    string data;
    string clienteNome;
    vector<ItemPedido> itens;

public:
    Pedido(){
        id = 0;
        status = "";
        data = "";
        clienteNome = "";
    }

    Pedido(int id, string clienteNome, string data, string status = "Aberto"){
        this->id = id;
        this->clienteNome = clienteNome;
        this->data = data;
        this->status = status;
    }

    int getId(){
        return id;
    }
    string getStatus(){
        return status;
    }
    string getData(){
        return data;
    }
    string getClienteNome(){
        return clienteNome;
    }
    void setId(int id){
        this->id = id;
    }
    void setStatus(string status){
        this->status = status;
    }
    void setData(string data){
        this->data = data;
    }
    void setClienteNome(string clienteNome){
        this->clienteNome = clienteNome;
    }

    void adicionarItem(Produto* produto, int quantidade){
        itens.push_back(ItemPedido(produto, quantidade));
    }

    int getQuantidadeItens(){
        return itens.size();
    }

    double calcularTotal(){
        double total = 0;
        for(int i = 0; i < (int)itens.size(); i++){
            total += itens[i].calcularSubTotal();
        }
        return total;
    }

    void exibir(){
        cout << "\nPEDIDO" << "\nID: " << id << "\nCliente: " << clienteNome << "\nData: " << data << "\nStatus: " << status << endl;

        if(itens.empty()){
            cout << "(sem itens)" << endl;
        }
        else{
            for(int i = 0; i < (int)itens.size(); i++){
                itens[i].exibir();
            }
        }

        cout << "\nTotal: R$ " << calcularTotal() << endl;
    }
};
