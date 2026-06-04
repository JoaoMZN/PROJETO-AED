#pragma once

#include <list>
#include <string>
#include "usuarios.hpp"
#include "carro.hpp"

using namespace std;

void MenuPrincipal(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);
void MenuCadastroLogin(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);
void MenuCadastrarUsuario(list<Usuario> &usuarios, Usuario *&usuario_logado);
void MenuLogin(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);
void MenuRegistroVeiculo(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);
void MenuChecarVeiculos(list<Usuario> &usuarios, Usuario *&usuario_logado, Carro &carro_temp);
void MenuCRLV(Usuario *&usuario_logado, Carro &carro_temp);
void MenuSair(Usuario *&usuario_logado);
void MenuPolicial(Usuario *&usuario_logado, list<Usuario> &usuarios);