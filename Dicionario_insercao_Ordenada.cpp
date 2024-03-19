#include <iostream>
#include <utility>
using namespace std;

struct Dicionario{
    static constexpr int tam_v = 5;
    char c[tam_v];
    float v[tam_v];
    int n;
    int i;
};

void inicializar (Dicionario &D){
    D.i=-1;
    D.n=-1;
}

bool vazio (Dicionario &D){
    return (D.i == -1);
}

bool cheio (Dicionario &D){
    return (D.n == D.tam_v-1);
}

pair<int, bool> consultar(Dicionario &D, char c){
    int inicio = D.i;
    int final = D.n;
    while(inicio <= final){
        int m = inicio + ((final - inicio) / 2);
        if(D.c[m] == c){
            return make_pair(m, true);
        } else if(D.c[m] < c){
            inicio = m + 1;
        } else {
            final = m - 1;
        }
    }
    return make_pair(inicio, false);
}

bool inserir(Dicionario &D,char c, float v){
    if(cheio(D)){
        cout << "Dicionário cheio.\n";
        return false;
    }
    else{
        pair<int, bool> resultado = consultar(D, c);
        if(resultado.second == false){
            D.n++;
            if(vazio(D)) D.i = 0; 
            for(int m = D.n; m > resultado.first; m--){
                D.c[m] = D.c[m-1];
                D.v[m] = D.v[m-1];
            }
            D.c[resultado.first] = c;
            D.v[resultado.first] = v;
        } else {
            cout << "Chave já está cadastrada\n";
            return false;
        }
    }
    return true;
}
bool remover(Dicionario &D, char c){
    if(vazio(D)){
        cout << "Dicionário está vazio.\n";
    }
    else{
        pair<int, bool> resultado = consultar(D, c);
        if(resultado.second==true){
            
            int m = resultado.first;
            for(m;m<D.n;m++){
                D.c[m]=D.c[m+1];
                D.v[m]=D.v[m+1];
            }
            if(m == D.n){
                D.n--;
                if(D.n == -1) D.i = -1;
            }
        }else return false;
        
    }
    return true;
}

void imprimir(Dicionario &D){
    if(vazio(D)){
        cout << "O dicionário está vazio!\n";
    }
    else{
        for(int i=0;i<=D.n;i++){
            cout << "Chave: "
                 << D.c[i]
                 << "\n"
                 << "Valor: "
                 << D.v[i]
                 << "\n";
        }
    }
}
int main()
{
  Dicionario D;
  inicializar(D);
  
//Teste automático
  inserir(D, 'a', 1.0);
  imprimir(D);
  cout << "\n";
  inserir(D, 'd', 2.0);
  imprimir(D);
  inserir(D, 'c', 3.0);
  imprimir(D);
  cout<< "\n";
  inserir(D, 'b', 2.0);
  imprimir(D);
  cout<< "\n";

  // Teste de chave já existente
  inserir(D, 'a', 4.0);

  inserir(D, 'g', 2.0);
  imprimir(D);
  cout<< "\n";
  inserir(D, 'f', 2.0);
  imprimir(D);
  cout<< "\n";
  
  remover(D, 'a');
  imprimir(D);
  cout<< "\n";
  
  remover(D, 'b');
  imprimir(D);
  cout<< "\n";

  remover(D, 'd');
  imprimir(D);
  cout<< "\n";
 
  remover(D, 'g');
  imprimir(D);
  cout<< "\n";
  
  remover(D, 'c');
  imprimir(D);
  cout<< "\n";
  /*//Teste Manual
  for(;;)
  {
    cout << "Operacoes: I - Inserir, R - Remover, C - Consultar, P - Imprimir, S - Sair\n";
    char opcao;
    cin >> opcao;

    if(opcao == 'I')
    {
      cout << "Chave a ser inserida:\n";
      char chave;
      cin >> chave;

      cout << "Valor a ser inserido:\n";
      float valor;
      cin >> valor;

      if(inserir (D, chave, valor)) cout << "Inserido!\n";
      
      
    }
    else if(opcao == 'R')
    {
      cout << "Chave a ser removida:\n";
      char chave;
      cin >> chave;

      if(remover(D, chave)) cout << "Removido!\n";
      else cout << "Chave não existe\n";
    }
    else if(opcao == 'C'){
      cout << "Insira a chave:\n";
      char chave;
      cin >> chave;

      pair<int, bool> resposta = consultar(D, chave);
      if(resposta.second == true){
        cout << "Valor = " << D.v[resposta.first] << "\n";
      }
      else cout << "Chave não encontrada\n";
    }
    else if(opcao == 'P'){
        imprimir(D);
    }
    else if (opcao == 'S') break;
    else cout << "Opcao invalida!\n";
  }*/
}
