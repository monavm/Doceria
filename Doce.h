#pragma once
#include <iostream>
#include <string>
#include "Produto.h"

using namespace std;

class Doce : public Produto{
private:
    double teorAcucarGramos;
    bool possuiLactose;

public:
    Doce() : Produto(){
        teorAcucarGramos = 0;
        possuiLactose = false;
    }

    Doce(int id, string nome, double preco, int estoque, int d, int m, int a, double teorAcucarGramos, bool possuiLactose)
        : Produto(id, nome, preco, estoque, d, m, a){
        this->teorAcucarGramos = teorAcucarGramos;
        this->possuiLactose = possuiLactose;
    }

    double getTeorAcucarGramos(){
        return teorAcucarGramos;
    }
    bool getPossuiLactose(){
        return possuiLactose;
    }
    void setTeorAcucarGramos(double teorAcucarGramos){
        this->teorAcucarGramos = teorAcucarGramos;
    }
    void setPossuiLactose(bool possuiLactose){
        this->possuiLactose = possuiLactose;
    }

    string getTipo() override{
        return "Doce";
    }

    void lerDadosExtras() override{
        cout << "Teor de acucar (g): ";
        cin >> teorAcucarGramos;
        cout << "Possui lactose (1/0): ";
        cin >> possuiLactose;
    }

    void salvarExtra(ostream& out) override{
        out << teorAcucarGramos << endl;
        out << possuiLactose << endl;
    }

    void carregarExtra(istream& in) override{
        in >> teorAcucarGramos;
        in >> possuiLactose;
        in.ignore();
    }

    void exibir() override{
        cout << "\nDoce:" << endl;
        Produto::exibir();
        cout << "Teor de acucar: " << teorAcucarGramos << "g" << endl;
        cout << "Possui lactose: " << (possuiLactose ? "Sim" : "Nao") << endl;
    }
};
