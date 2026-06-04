#pragma once 

#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

class Carro;

class Usuario
{
private:
    string nome, cpf, email, senha;

protected:
    int pontos;

public:
    list<Carro> carros;
    list<Carro>::iterator carrosIT;

    Usuario()
    { // construtor
        carrosIT = carros.end();
    };

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

    void cadastrarCPF(Usuario &usuario_temp, list<Usuario> &usuarios);

    void cadastrarNome(Usuario &usuario_temp);

    void cadastrarEmail(Usuario &usuario_temp, list<Usuario> &usuarios);

    void cadastrarSenha(Usuario &usuario_temp);

    void OdernaçãoPorInsercaoCpfUsuarios(list<Usuario> &usuarios);

    Usuario *BuscaBinariaUsuarioPorCpf(list<Usuario> &usuarios, string cpf);

    bool SalvarUsuario(list<Usuario> &usuarios, Usuario &usuario_temp);

    void ExportarUsuario(Usuario &ususarios);

    void LoadUsuario(list<Usuario> &usuarios);

    void ChecagemCnh(list<Usuario> &usuarios);

};