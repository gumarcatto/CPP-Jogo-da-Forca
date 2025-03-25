#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "nao_acertou.hpp"
#include "letra_existe.hpp"
#include "nao_enforcou.hpp"
#include "imprime_cabecalho.hpp"
#include "le_arquivo.hpp"
#include "imprime_erros.hpp"
#include "imprime_palavra.hpp"
#include "chuta.hpp"
#include "sorteia_palavra.hpp" 
#include "adiciona_palavra.hpp"
#include "nao_acertou.hpp"
using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;

int main() {
    imprime_cabecalho();

    le_arquivo();
    sorteia_palavra();

    while(nao_acertou() && nao_enforcou()){
        imprime_erros();

        imprime_palavra();

        chuta();
    }

    cout << "Fim de Jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;   
    if(nao_acertou()){
        cout << "Voce perdeu! tente novamente!" << endl;
    }
    else {
        cout << "Parabens! Voce acertou a palavra secreta!" << endl;
        cout << "Voce deseja adicionar uma nova palavra ao banco? (S/N)" << endl;
        char resposta;
        cin >> resposta;
        if(resposta == 'S'){
            adiciona_palavra();
        }
    }
}