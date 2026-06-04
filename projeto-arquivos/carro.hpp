#pragma once 

#include <iostream>
#include <fstream>
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

protected:
    int multas_leves, multas_medias, multas_graves, multas_gravissimas = 0;

public:
    Carro();
    Carro(string placa_cinza, string placa_mercosul, string ano, string cor,
          string modelo, string renavam, string status_crlv);

    void setPlacaCinza(string pc);
    string getPlacaCinza() const;

    void setPlacaMercosul(string pm);
    string getPlacaMercosul() const;

    void setAno (string a);
    string getAno () const;

    void setCor(string c);
    string getCor() const;

    void setModelo(string m);
    string getModelo() const;

    void setRenavam(string r);
    string getRenavam() const;

    void setCrlv (string cr);
    string getCrlv();

    void setNomeDono (string nd);
    string getNomeDono();

    void setCpfDono (string cpfd);
    string getCpfDono() const;

    void setMultasLeves(int ml);
    int getMultasLeves();

    void setMultasMedias(int mm);
    int getMultasMedias();

    void setMultasGraves(int mg);
    int getMultasGraves();

    void setMultasGravissimas(int mgravissima);
    int getMultasGravissimas();

    void cadastrarPlacaCinza(Carro &carro_temp);

    void cadastrarPlacaMercosul(Carro &carro_temp);

    void cadastrarAno(Carro &carro_temp);

    void cadastrarCor(Carro &carro_temp);

    void cadastrarModelo(Carro &carro_temp);

    void cadastrarRenavam(Carro &carro_temp);
    
    void OdernaçãoPorInsercaoRenavamCarro(list<Carro> &carros);
    
    Carro *BuscaBinariaCarroPorModelo(list<Carro> &carros, string modelo); 
    
    bool SalvarCarro(Usuario *usuario_logado, Carro &carro_temp);
    
    void ExportarVeiculo(list<Usuario> &usuarios);

    void LoadVeiculos(list<Usuario> &usuarios);

    void VeiculosRegistrados(list<Carro> &carros);

    void ExcluirVeiculos(list<Carro> &carros);
    
    void AlterarVeiculo(list<Carro> &carros, Usuario *usuario_logado, list<Usuario> &usuarios);

    void Multas(list<Carro> &carros);

    void GerarCrlv(list<Carro> &carros, Usuario *usuario_logado);

    void ExportarCrlv(list<Carro> &carros, Usuario *usuario_logado);

    void ListarVeiculos_CRLV(list<Carro> &carros);

    void LoadVeiculosPolicia(Usuario *usuario_logado);
    
    void MultaPlaca(list<Carro> &carros, Usuario *usuario_logado);
};