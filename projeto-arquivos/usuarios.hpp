#pragma once 

#include <iostream>
#include <fstream>
#include <string>
#include <list>
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

    void setDebitos(float d);
    float getDebitos() const;

    void cadastrarCPF(Usuario &usuario_temp, list<Usuario> &usuarios);

    void cadastrarNome(Usuario &usuario_temp);

    void cadastrarEmail(Usuario &usuario_temp, list<Usuario> &usuarios);

    void cadastrarSenha(Usuario &usuario_temp);

    void OdernaçãoPorInsercaoCpfUsuarios(list<Usuario> &usuarios);

    Usuario *BuscaBinariaUsuarioPorCpf(list<Usuario> &usuarios, string cpf);

    bool SalvarUsuario(list<Usuario> &usuarios, Usuario &usuario_temp);

    void ExportarUsuario(Usuario &usuarios);

    void LoadUsuario(list<Usuario> &usuarios);

    void ChecagemCnh(list<Usuario> &usuarios);

};