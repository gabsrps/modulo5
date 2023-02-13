#include "hash.h" 
#include <iostream>
using namespace std;

Hash::Hash(int max) {  
  length = 0;
  max_items = max;
  structure = new Cliente[max_items];   
}

Hash::~Hash(){
  delete [] structure;
}
bool Hash::isFull() const {
  return (length == max_items);
}
int Hash::getLength() const {
  return length;
}


void Hash::retrieveItem(Cliente& cliente, bool& found) {
  int location = getHash(cliente);
  Cliente aux    = structure[location];
  if (cliente.getImei() != aux.getImei()) {
    found      = false;
  } else {
    found      = true;
    cliente      = aux;
  }
}

void Hash::insertItem(Cliente cliente) {
  int location = getHash(cliente);
  structure[location] = cliente;
  length++;
}
void Hash::deleteItem(Cliente cliente) {
  int location = getHash(cliente);
  structure[location] = Cliente();
  length--; 
}

void Hash::print() {
  for (int i = 0; i < max_items; i++) {
    cout << i <<":"<<
      structure[i].getImei()<<", "<<
      structure[i].getLogin()<<endl;
  }
}

int Hash::getHash(Cliente cliente){
  return cliente.getImei() % max_items;
}