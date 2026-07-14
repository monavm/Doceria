#pragma once
#include <iostream>
#include <string>

using namespace std;

class DataValidade{
    protected:
        int dia, mes, ano;
    public:
        DataValidade(int d, int m, int a){ dia = d; mes = m; ano = a; }
        int getDia(){
            return dia;
        }
        int getMes(){
        return mes;
        }
        int getAno(){
        return ano;
        }
        void exibir(){
        cout << "Data de Validade: " << dia << "/" << mes << "/" << ano << endl;
        }
};
