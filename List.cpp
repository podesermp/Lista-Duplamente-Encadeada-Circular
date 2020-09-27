#include <climits>
#include <iostream>
#include "List.h"

//Marcos Paulo Rocha Rodrigues 403581


using namespace std;

struct Node{
    int value;
    Node *next;
    Node *previous;
};

//Construtor
List::List(){
    head = new Node;
    head->next = head;
    head->previous = head;
}

//Destrutor
List::~List(){
    clear();
    delete head;
    cout << "Lista destruida" << endl;
}

//Remove todos os elementos da lista e deixa apenas o nó cabeça.
void List::clear(){
    while (head->next != head){   
        Node *aux = head->next;
        head->next = aux->next;
        head->next->previous = head;
        delete aux;
    }
}

//Insere um inteiro key ao final da lista.
void List::pushBack(int key){    
    Node *novo = new Node;
    Node *aux = head->next;
    while (aux->next != head){
        aux = aux->next;
    }
    novo->value = key;
    aux->next = novo;
    novo->previous = aux;
    novo->next = head;
    head->previous = novo;
}

//Imprime os elementos da lista.
void List::print(){
    if(!empty()){
        Node *aux = head->next;
        while (aux != head){
            cout << "[ " <<aux->value << " ]";
            aux = aux->next;
        }
        cout << endl;
    }else cout << "Lista está vazia"<<endl;
}

//Retorna true se a lista estiver vazia e false caso contrário.
bool List::empty(){
    if(head->next == head){
        return true;
    }
    return false;
}

//Retorna o número de nós da lista.
int List::size(){
    Node *aux = head->next;
    int size = 0;
    while(aux != head){
        size++;
        aux = aux->next;
    }
    return size;
}

//Remove da lista a primeira ocorrência do inteiro key
void List::remove(int key){
    if(!empty()){ 
        Node *aux = head->previous;
        Node *noRem;
        while(aux != head){
            if(aux->value == key){
                noRem = aux;
            }
            aux = aux->previous;
        }
        noRem->previous->next = noRem->next;
        noRem->next->previous = noRem->previous;
        delete noRem;
    }else{
        cout << "A lista está vazia"<< endl;
    }
}

//Remove elemento do final da lista e retorna seu valor.
int List::popBack(){
    if(!empty()){
        Node *aux = head->next;
        while (aux->next != head){
            aux = aux->next;
        }
        int retorno = aux->value;
        aux->previous->next = head;
        head->previous = aux->previous;
        delete aux;
        return retorno;
    }else{
        cout << "lista está vazia"<<endl;
        return INT_MIN;
    }
}

//Imprime os elementos da lista em ordem reversa.
void List::printReverse(){
    if(!empty()){
        Node *aux = head->previous;
        while (aux != head){
            cout << "[ " <<aux->value << " ]";
            aux = aux->previous;
        }
        cout << endl;
    }else cout << "Lista está vazia"<<endl;
}

//Insere um novo nó com valor key após o k-ésimo nó da lista.
void List::insertAfter(int key, int k){
    if(k >= 1 && k <= size()){
    int i = 1;
    Node *after;
    Node *adc = new Node;
    adc->value = key;
    Node *aux = head->next;
        while(aux != head){
            if(i == k){
                after = aux;
                after->next->previous = adc;
                adc->previous = aux;
                adc->next = after->next;
                after->next = adc;
            }
            aux = aux->next;
            i++;
        }
    }else {
        cout << "posição não existe"<<endl;
    }
}

//Remove da lista todas as ocorrências do inteiro key.
void List::removeAll(int key){
    if(!empty()){
        Node *aux = head->next;
        while(aux != head){
            if(aux->value == key){
                Node *noRem = aux;
                noRem->previous->next = noRem->next;
                noRem->next->previous = noRem->previous;
                delete noRem;
            }
            aux = aux->next;
        }
    }else cout << "Lista está vazia"<<endl;
}

//Remove o k-ésimo nó da lista encadeada e retorna o seu valor.
int List::removeNodeAt(int k){
    if(!empty()){
        int i = 1;
        Node *aux = head->next;
        Node *noRem;
        if(k >= 1 && k <= size()){
            while(aux != head){
                if(i == k){
                    noRem = aux;
                }
                aux = aux->next;
                i++;
            }
            noRem->previous->next = noRem->next;
            noRem->next->previous = noRem->previous;
            int retorno = noRem->value;
            delete noRem;
            return retorno;
        }else {
            cout << "posição não existe"<<endl;
        }
    }else cout << "Lista está vazia"<<endl;
}

//Copia os elementos do array arr para a lista.
void List::copyArray(int n, int arr[]){
    for(int i = 0; i < n; i++){
        pushBack(arr[i]);
    }
}

//Concatena a lista atual com a lista lst passada por parâmetro.
void List::concat(List *lst){
    Node *aux = lst->head->next;
    while(aux!=lst->head){
        pushBack(aux->value);
        aux = aux->next;
    }
    lst->clear();
}

//Retorna um ponteiro para uma cópia desta lista.
List* List::copy(){
    List *lst;
    if(!empty()){    
        lst = new List;
        Node *aux = head->next;
        while (aux != head){
            lst->pushBack(aux->value);
            aux = aux->next;
        }
    }
    return lst;
}

//Determina se a lista passada por parâmetro é igual à lista em questão.
bool List::equal(List *lst){
    if(size() == lst->size()){
        Node *aux = head->next;
        Node *aux2 = lst->head->next;
        while(aux != head){
            if(aux->value != aux2->value){
                return false;
            }
            aux = aux->next;
            aux2 = aux2->next;
        }
        return true;
    }
    return false;
}