#pragma once

#include <list>
#include <string>
#include <vector>
#include "usuarios.hpp"
#include "sistema.hpp"
#include "carro.hpp"

// algoritmo dbj2 para tabela hash

using namespace std;

void MenuSair(Usuario *&usuario_logado);

void MenuInicial(Sistema &sistema, Usuario *usuario_logado, Carro &carro_temp);

void MenuCadastrarUsuario(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros, vector<list<Carro*>> &carrosHash, vector<list<Usuario*>> &usuariosHash);

void MenuLogin(Usuario *&usuario_logado, Carro &carro_temp, Sistema &sistema);

void MenuPrincipal(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros, vector<list<Carro*>> &carrosHash);

void MenuNormal(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, vector<list<Carro*>> &carrosHash, list<Carro> &carros);

void MenuPolicial(Usuario *&usuario_logado, list<Usuario> &usuarios, list<Carro> &carros, Carro &carro_temp, vector<list<Carro*>> &carrosHash);

void MenuRegistroVeiculo(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, vector<list<Carro*>> &carrosHash, list<Carro> &carros);

void MenuChecarVeiculos(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros);

void MenuCRLV(Usuario *&usuario_logado, Carro &carro_temp);

void MenuAplicarMulta(list<Carro> &carros, Usuario *usuario_logado, Carro &carro_temp, list<Usuario> &usuarios, vector<list<Carro*>> &carrosHash);

void MenuChecarCnh(list<Usuario> &usuarios, Usuario *&usuario_logado);