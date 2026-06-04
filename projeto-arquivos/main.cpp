#include <list>
#include <clocale>
#include "menu.hpp"
#include "usuarios.hpp"
#include "carro.hpp"
#include "utils.hpp"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil.1252");

    list<Usuario> usuarios;
    Usuario *usuario_logado = nullptr;
    Carro carro_temp;

    Usuario usuario_load;
    usuario_load.LoadUsuario(usuarios);

    Usuario policial;
    policial.setNome("Policia");
    policial.setCpf("11111111111");
    policial.setEmail("policiarodoviaria@detran.com");
    policial.setSenha("PoliciaRodoviaria-Detran");
    usuarios.push_front(policial); 

    if (usuario_logado == nullptr)
    {
        MenuInicial(usuarios, usuario_logado, carro_temp);
    }
    else
    {
        MenuPrincipal(usuarios, usuario_logado, carro_temp);
    }

    return 0;
}