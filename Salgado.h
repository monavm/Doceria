#pragma once
#include <iostream>
#include <string>
#include "Produto.h"

using namespace std;

class Salgado : public Produto{
private:
    string tipoMassa;
    bool requerAquecimento;

public:
    Salgado() : Produto(){
        tipoMassa = "";
        requerAquecimento = false;
    }

    Salgado(int id, string nome, double preco, int estoque, int d, int m, int a, string tipoMassa, bool requerAquecimento)
        : Produto(id, nome, preco, estoque, d, m, a){
        this->tipoMassa = tipoMassa;
        this->requerAquecimento = requerAquecimento;
    }

    string getTipoMassa(){
        return tipoMassa;
    }
    bool getRequerAquecimento(){
        return requerAquecimento;
    }
    void setTipoMassa(string tipoMassa){
        this->tipoMassa = tipoMassa;
    }
    void setRequerAquecimento(bool requerAquecimento){
        this->requerAquecimento = requerAquecimento;
    }

    string getTipo() override{
        return "Salgado";
    }

    void lerDadosExtras() override{
        cout << "Tipo de massa: ";
        getline(cin, tipoMassa);
        cout << "Requer aquecimento (1/0): ";
        cin >> requerAquecimento;
    }

    void salvarExtra(ostream& out) override{
        out << tipoMassa << endl;
        out << requerAquecimento << endl;
    }

    void carregarExtra(istream& in) override{
        getline(in, tipoMassa);
        in >> requerAquecimento;
        in.ignore();
    }

    void exibir() override{
        cout << "\nSalgado:" << endl;
        Produto::exibir();
        cout << "Tipo da massa: " << tipoMassa << endl;
        cout << "Requer aquecimento: " << (requerAquecimento ? "Sim" : "Nao") << endl;
    }
};
