#include <iostream>
#include "hash.h" 

using namespace std;

int main(){
  Hash clientesHash(10);
   int   imei[7]   = {
     12704, 31300, 1234,
     49001, 52202, 65606,
     91234};
  string login[7] = {
    "Pedro", "Raul", "Paulo",
    "Carlos", "Lucas", "Maria",
    "Samanta"}; 

  //inserir um novo item na tabela
  cout << "CT1: Devem ser inseridos na tabela hash os logins respectivos aos imeis, Pedro e Paulo não devem aparecer no print devido à colisão" << endl;
  for (int i = 0; i < 7; i++) {
    Cliente cliente = Cliente(imei[i], login[i]);
    clientesHash.insertItem(cliente);
  }
  clientesHash.print();  
  cout << "------------------------------" <<  endl;

  //checar logins específicos dentro da tabela
  cout << "CT2: Chechando se o login de imei 12704 esta na tabela deve ser retornado 0 " << endl;
  
  Cliente cliente(12704,"");  
  bool     found = false;
  clientesHash.retrieveItem(cliente, found);
  cout << cliente.getLogin() << " -> " << found << endl;
  
  cout << "------------------------------" <<  endl;

  //deletar item da tabela
  cout << "CT3: O login que está no indice do mod do imei 12704 deve estar vazio" << endl;
  clientesHash.deleteItem(cliente);
  clientesHash.print();
 

  cout << "------------------------------" <<  endl;
 //tamanho do hash
  cout << "CT4: Verificando o tamanho do hash" << endl;
  cout << "Tamanho do Hash: " << clientesHash.getLength() << endl;
  
  //Verificar se ta cheia o hash
  cout << "CT5: Verificando se a tabela está cheia" << endl;
  cout << "A tabela está cheia? " << clientesHash.isFull() <<endl;
  cout << "Fim";
  return 0;
}
  