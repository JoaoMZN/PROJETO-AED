#pragma once

#include <list>
#include <string>
#include "usuarios.hpp"
#include "carro.hpp"

using namespace std;

void MenuSair(Usuario *&usuario_logado);

void MenuInicial(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);

void MenuCadastrarUsuario(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);

void MenuLogin(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);

void MenuPrincipal(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);

void MenuNormal(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);

void MenuPolicial(Usuario *&usuario_logado, list<Usuario> &usuarios);

void MenuRegistroVeiculo(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);

void MenuChecarVeiculos(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);

void MenuCRLV(Usuario *&usuario_logado, Carro &carro_temp);