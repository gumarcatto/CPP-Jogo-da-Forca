#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "letra_existe.hpp"

extern std::map<char, bool> chutou;
extern std::vector<char> chutes_errados;

void chuta(){
    std::cout << "Seu Chute: "; 
        char chute;
        std::cin >> chute;

        chutou[chute] = true;

        if(letra_existe(chute)){
            std::cout << "voce acertou! seu chute esta na palavra." << std::endl;
        } 
        else {
            std::cout << "voce errou! seu chute nao esta na palavra." << std::endl;
            chutes_errados.push_back(chute);
        }
        std::cout << std::endl;
}