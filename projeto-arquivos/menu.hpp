#pragma once

#include <list>
#include <string>
#include "usuarios.hpp"
#include "carro.hpp"

using namespace std;

void MenuSair(Usuario *&usuario_logado);

void MenuInicial(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros);

void MenuCadastrarUsuario(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros);

void MenuLogin(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros);

void MenuPrincipal(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp, list<Carro> &carros);

void MenuNormal(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);

void MenuPolicial(Usuario *&usuario_logado, list<Usuario> &usuarios, list<Carro> &carros, Carro &carro_temp);

void MenuRegistroVeiculo(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);

void MenuChecarVeiculos(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);

void MenuCRLV(Usuario *&usuario_logado, Carro &carro_temp);

void MenuAplicarMulta(list<Carro> &carros, Usuario *usuario_logado, Carro &carro_temp);

void MenuChecarCnh(list<Usuario> &usuarios, Usuario *&usuario_logado);