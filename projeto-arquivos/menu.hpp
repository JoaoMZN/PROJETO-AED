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

void MenuCadastrarUsuario(Sistema &sistema, Usuario *usuario_logado, Carro &carro_temp);

void MenuLogin(Usuario *&usuario_logado, Carro &carro_temp, Sistema &sistema);

void MenuPrincipal(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp);

void MenuNormal(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp);

void MenuPolicial(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp);

void MenuRegistroVeiculo(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp);

void MenuChecarVeiculos(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp);

void MenuCRLV(Sistema &sistema ,Usuario *&usuario_logado, Carro &carro_temp);

void MenuAplicarMulta(Sistema &sistema, Usuario *&usuario_logado, Carro &carro_temp);

void MenuChecarCnh(Sistema &sistema, Usuario *&usuario_logado);