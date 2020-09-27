# Lista-Duplamente-Encadeada-Circular
	void pushBack(int key);                 //Insere um inteiro key ao final da lista.
	int popBack();                          //Remove elemento do final da lista e retorna seu valor.
	void insertAfter(int key, int k);       //Insere um novo nó com valor key após o k-ésimo nó da lista.
	void remove(int key);                   //Remove da lista a primeira ocorrência do inteiro key
	void removeAll(int key);                //Remove da lista todas as ocorrências do inteiro key.
	int removeNodeAt(int k);                //Remove o k-ésimo nó da lista encadeada e retorna o seu valor.                                                                     
	void print();                           //Imprime os elementos da lista.
	void printReverse();                    //Imprime os elementos da lista em ordem reversa.
	bool empty();                           //Retorna true se a lista estiver vazia e false caso contrário.
	int size();                             //Retorna o número de nós da lista.
	void clear();                           //Remove todos os elementos da lista e deixa apenas o nó cabeça.
	void concat(List *lst);                 //Concatena a lista atual com a lista lst passada por parâmetro.
	List *copy();                           //Retorna um ponteiro para uma cópia desta lista.
	void copyArray(int n, int arr[]);       //Copia os elementos do array arr para a lista.
	bool equal(List *lst);                  //Determina se a lista passada por parâmetro é igual à lista em questão.
