#pragma once

#include "sistema.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

class Usuario;

class Carro
{
private:
    string placa_cinza, placa_mercosul;
    string ano, cor, modelo;
    string renavam, status_crlv;
    string nome_dono, cpf_dono;
    bool multa = false;
    float debitos = 0.0;

    int funcaoHash(string &renavam);

    void montagemRenvamHash(Sistema &sistema);

public:
    Carro();
    Carro(string placa_cinza, string placa_mercosul, string ano, string cor,
          string modelo, string renavam, string status_crlv, float debitos);

    void setPlacaCinza(string pc);
    string getPlacaCinza() const;

    void setPlacaMercosul(string pm);
    string getPlacaMercosul() const;

    void setAno(string a);
    string getAno() const;

    void setCor(string c);
    string getCor() const;

    void setModelo(string m);
    string getModelo() const;

    void setRenavam(string r);
    string getRenavam() const;

    void setCrlv(string cr);
    string getCrlv() const;

    void setNomeDono(string nd);
    string getNomeDono() const;

    void setCpfDono(string cpfd);
    string getCpfDono() const;

    void setMulta(bool m);
    bool getMulta() const;

    void setDebitos(float d);
    float getDebitos() const;

    void cadastrarPlacaCinza(Carro &carro_temp);

    void cadastrarPlacaMercosul(Carro &carro_temp);

    void cadastrarAno(Carro &carro_temp);

    void cadastrarCor(Carro &carro_temp);

    void cadastrarModelo(Carro &carro_temp);

    void cadastrarRenavam(Carro &carro_temp);

    void OdernacaoPorInsercaoRenavamCarro(Sistema &sistema);

    Carro *BuscarRenavamHash(Sistema &sistema, string renavam);

    bool SalvarCarro(Sistema &sistema ,Usuario *usuario_logado, Carro &carro_temp);

    void ExportarVeiculo(Sistema &sistema);

    void LoadVeiculos(Sistema &sistema);

    void ExcluirVeiculos(list<Carro> &carros);

    void AlterarVeiculo(Sistema &sistema, Usuario *usuario_logado, Carro &carro_temp);

    void Multas(Sistema &sistema);

    void GerarCrlv(Sistema &sistema, Usuario *usuario_logado);

    void ExportarCrlv(Sistema &sistema, Usuario *usuario_logado);

    void ListarVeiculos_CRLV(Sistema &sistema);

    void LoadVeiculosPolicia(Usuario *usuario_logado);

    void MultaRenavam(Sistema &sistema, Usuario *usuario_logado);
};