#ifndef LIST_H 
#define LIST_H

//Marcos Paulo Rocha Rodrigues 403581


struct Node;
class List{
    private:
        Node *head;
    public:
        List();                                 //Construtor                                                                                                                        ok
        ~List();                                //Destrutor                                                                                                                         ok
        void pushBack(int key);                 //Insere um inteiro key ao final da lista.                                                                                          ok                                                                                          
        int popBack();                          //Remove elemento do final da lista e retorna seu valor.                                                                            ok
        void insertAfter(int key, int k);       //Insere um novo nó com valor key após o k-ésimo nó da lista.                                                                       ok
        void remove(int key);                   //Remove da lista a primeira ocorrência do inteiro key                                                                              ok
        void removeAll(int key);                //Remove da lista todas as ocorrências do inteiro key.                                                                              ok
        int removeNodeAt(int k);                /*Remove o k-ésimo nó da lista encadeada e retorna o seu valor.                                                                     ok
                                                Caso o k-ésimo nó não exista, o programa retorna o valor especial
                                                INT MIN definido no cabeçalho climits.*/                                                                                            
        void print();                           //Imprime os elementos da lista.                                                                                                    ok
        void printReverse();                    //Imprime os elementos da lista em ordem reversa.                                                                                   ok
        bool empty();                           //Retorna true se a lista estiver vazia e false caso contrário.                                                                     ok
        int size();                             //Retorna o número de nós da lista.                                                                                                 ok
        void clear();                           //Remove todos os elementos da lista e deixa apenas o nó cabeça.                                                                    ok
        void concat(List *lst);                 /*Concatena a lista atual com a lista lst passada por parâmetro.                                                                    ok
                                                Após essa operação ser executada, lst será uma lista vazia, ou seja, o
                                                único nó de lst será o nó cabeça.*/
        List *copy();                           //Retorna um ponteiro para uma cópia desta lista.                                                                                   ok
        void copyArray(int n, int arr[]);       /*Copia os elementos do array arr para a lista.                                                                                     ok
                                                O array arr tem n elementos. Todos os elementos anteriores da lista são
                                                mantidos e os elementos do array arr devem ser adicionados após os elementos originais.*/
        bool equal(List *lst);                  /*Determina se a lista passada por parâmetro é igual à lista em questão.                                                            ok
                                                Duas listas são iguais se elas possuem o mesmo tamanho e o valor
                                                do k-ésimo elemento da primeira lista é igual ao k-ésimo elemento da segunda lista.*/
};

#endif