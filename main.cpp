#include <iostream>
#include "List.h"
using namespace std;


//Marcos Paulo Rocha Rodrigues 403581


int main(){
    
    int op, nLista, auxNLista, auxKey, k;
    bool start = true;
    List listas[3];


    string str = ("\n-------------------------------------------------------------------------\n\t\t:::LISTA CIRCULAR OPERAÇÕES:::\n");
    str+= ">listas: 0 1 2\n";
    str+=("1.pushBack(int x)\t\t | \t 11. clear()\n");
    str+=("2. print()\t\t\t | \t 12. concat(List *lst)\n");
    str+=("3. size()\t\t\t | \t 13. Copy()\n");
    str+=("4. isEmpty()\t\t\t | \t 14. copyArray(int *arr, int n)\n");
    str+=("5. popBack()\t\t\t | \t 15. equal(List *lst)\n");
    str+=("6. insertAfter(int key, int k)\n");
    str+=("7. remove(int key)\n");
    str+=("8. removeAll(int key)\n");
    str+=("9. removeNodeAt(int k)\n");
    str+=("10. printReverse()\n");
    str+=("0. Finalizar\n");
    


    while(start){
        cout << str;
        cout << "--------------\nDigite Uma operação:";
        cin >> op;
        system("clear");
        switch(op){
            case 0:
                start = false;
                cout << "<<<FIM DE PROGRAMA>>>"<<endl;
                break;
            
            case 1:
                cout << "\tpushBack(int x)"<<endl;
                cout << "Qual lista? ";
                cin >> nLista;
                if(nLista >=0 && nLista < 3){
                    int x;
                    cout << "adiciona:";
                    cin >> x;
                    listas[nLista].pushBack(x);
                }else cout << "Numero de lista inválido"<<endl;
                break;
            
            case 2:
                cout << "\tprint()"<<endl;
                for(int i = 0; i < 3; i++){
                    cout << "lista["<<i<<"] = ";
                    listas[i].print();
                }
                break;
            case 3:
                cout << "\tsize()"<<endl;
                for(int i = 0; i < 3;i++){
                    cout <<"Tamanho da "<< i <<" = "<<listas[i].size()<<endl;
                }
                break;
            case 4:
                cout << "\tisEmpty()"<<endl;
                cout << "Qual lista? ";
                cin >> nLista;
                if(nLista >=0 && nLista < 3){
                    if(listas[nLista].empty()) cout << "Lista está vazia"<<endl;
                    else cout << "Lista não está vazia"<<endl;
                }else cout << "Numero de lista inválido"<<endl;
                break;
            case 5:
                cout << "\tpopBack()"<<endl;
                cout << "Qual lista? ";
                cin >> nLista;
                if(nLista >=0 && nLista < 3)
                    cout << "Valor retirado da lista = " <<listas[nLista].popBack()<<endl;
                else
                    cout << "Numero de lista inválido"<<endl;
                break;
            case 6:
                cout << "\tinsertAfter(int key, int k)"<<endl;
                cout << "Qual lista? ";
                cin >> nLista;
                if(nLista >=0 && nLista < 3){
                    cout<<"valor a ser incluido: ";
                    cin >> auxKey;
                    cout << "posição k: ";
                    cin >> k;
                    listas[nLista].insertAfter(auxKey,k);
                }else cout << "Numero de lista inválido"<<endl;
                break;
            case 7:
                cout << "\tremove(int key)"<<endl;
                cout << "Qual lista? ";
                cin >> nLista;
                if(nLista >=0 && nLista < 3){
                    cout << "Valor a ser removido: ";
                    cin >> auxKey;
                    listas[nLista].remove(auxKey);
                }else cout << "Numero de lista inválido"<<endl;
                break;
            case 8:
                cout << "\tremoveAll(int key)"<<endl;
                cout << "Qual lista? ";
                cin >> nLista;
                if(nLista >=0 && nLista < 3){
                    cout << "Valor a ser removido: ";
                    cin >> auxKey;
                    listas[nLista].removeAll(auxKey);
                }else cout << "Numero de lista inválido"<<endl;
                break;
            case 9:
                cout << "\tremoveNodeAt(int k)"<<endl;
                cout << "Qual lista? ";
                cin >> nLista;
                if(nLista >=0 && nLista < 3){
                    cout << "k-ésimo: ";
                    cin >> k;
                    listas[nLista].removeNodeAt(k);
                }else cout << "Numero de lista inválido"<<endl;
                break;
            case 10:
                for(int i = 0; i < 3; i++){
                    cout << "lista["<<i<<"] = ";
                    listas[i].printReverse();
                }
                break;
            case 11:
                cout << "\t11. clear()"<<endl;
                cout << "Qual lista? ";
                cin >> nLista;
                if(nLista >=0 && nLista < 3){
                    listas[nLista].clear();
                }else cout << "Numero de lista inválido"<<endl;
                break;
            case 12:
                cout << "12. concat(List *lst)"<<endl;
                cout << "Quais listas concatenar: ";
                cin >> nLista;
                cin >> auxNLista;
                if((nLista >=0 && nLista < 3) && (auxNLista >=0 && auxNLista < 3)){
                    listas[nLista].concat(&listas[auxNLista]);
                }else cout << "Numero de lista inválido"<<endl;
                break;
            case 13:
            
                cout << "\t13. Copy()"<<endl;
                cout << "lista a ser copiada: ";
                cin >> nLista;
                cout << "armazenar copia em que lista: ";
                cin >> auxNLista;
                if((nLista >=0 && nLista < 3) && (auxNLista >=0 && auxNLista < 3)){
                    listas[auxNLista] = *listas[nLista].copy();
                }else cout << "Numero de lista inválido"<<endl;
             
                break;
            case 14:
                cout << "\t14. copyArray(int *arr, int n)"<<endl;
                cout << "Qual lista? ";
                cin >> nLista;
                if(nLista >=0 && nLista < 3){
                    int n;
                    cout << "tamanho do vetor: ";
                    cin >> n;
                    int vec[n];
                    cout << "elementos do vetor: ";
                    for(int i = 0;i < n;i++){
                        cin >> vec[i];
                    }
                    listas[nLista].copyArray(n,vec);
                }else cout << "Numero de lista inválido"<<endl;
                break;
            case 15:
                cout << "\t15. equal(List *lst)"<<endl;
                cout << "Quais listas comparar? ";
                cin >> nLista;
                cin >> auxNLista;
                if((nLista >=0 && nLista < 3) && (auxNLista >=0 && auxNLista < 3)){
                    if(listas[nLista].equal(&listas[auxNLista])){
                        cout << "As listas são iguais"<<endl;
                    }else cout << "As listas não são iguais"<<endl;
                }else cout << "Numero de lista inválido"<<endl;
                break;
            default:
                cout << "Valor de operação inválido"<<endl;
                break;
        }   
    }

    return 0;
}