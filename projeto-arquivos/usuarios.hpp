#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include "sistema.hpp"
#include "carro.hpp"

using namespace std;

class Carro;

class Usuario
{
private:
    string nome, cpf, email, senha;

protected:
    int pontos;

    int multas_leves, multas_medias, multas_graves, multas_gravissimas;

public:
    list<Carro> carros;
    list<Carro>::iterator carrosIT;

    Usuario();

    void setNome(string n);
    string getNome();

    void setCpf(string c);
    string getCpf();

    void setEmail(string e);
    string getEmail();

    void setSenha(string s);
    string getSenha();

    void setPontos(int p);
    int getPontos();

    void setMultasLeves(int ml);
    int getMultasLeves() const;

    void setMultasMedias(int mm);
    int getMultasMedias() const;

    void setMultasGraves(int mg);
    int getMultasGraves() const;

    void setMultasGravissimas(int mgravissima);
    int getMultasGravissimas() const;

    void cadastrarCPF(Sistema &sistema, Usuario &usuario_temp);

    void cadastrarNome(Usuario &usuario_temp);

    void cadastrarEmail(Sistema &sistema, Usuario &usuario_temp);

    void cadastrarSenha(Usuario &usuario_temp);

    void OdernacaoPorInsercaoCpfUsuarios(Sistema &sistema);

    Usuario *BuscaBinariaUsuarioPorCpf(Sistema &sistema, string cpf);

    bool SalvarUsuario(Sistema &sistema, Usuario &usuario_temp);

    void ExportarUsuario(Sistema &sistema);

    void LoadUsuario(Sistema &sistema);

    void ChecagemCnh(Sistema &sistema);
};