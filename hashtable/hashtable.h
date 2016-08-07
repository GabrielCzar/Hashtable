#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "item.h"
#include "screen.h"
#define ALLOCACAO 2

using namespace std;

template<class T> class hashtable {

public:

    void show(int ind = -1, Item<T> it = Item<T>()){
        screen &s = *scr;
        s.clear();
        int step = 6;
        const int lkey = 9;//linha da chave

        int delta = 7;
        s.write(lkey - 1, 0, 0, "   Ind ");
        s.write(lkey    , 0, 0, "   Key ");
        s.write(lkey + 1, 0, 0, " Value ");
        for(int i = 0; i < _max; i++){
            s.write(lkey - 2, i * step + delta, step, string(step, '='));
            s.write(lkey - 1, i * step + delta, step, "|__" + to_string(i) + "__");
            s.write(lkey    , i * step + delta, step, "|" + to_string(_vet[i].key));
            s.write(lkey + 1, i * step + delta, step, "|" + _vet[i].value);
            s.write(lkey + 2, i * step + delta, step, string(step, '='));
        }

        int lfkey = lkey - 4;//linha da chave em foco
        if(ind != -1){
            s.write(lfkey    , ind * step + delta, step, "|" + to_string(it.key));
            s.write(lfkey + 1, ind * step + delta, step, "|" + it.value);
        }
        s.show();
        s.wait();
    }

private:
    const float max_alloc = 0.8;
    Item<T> * _vet;
    int _qtd;
    int _max;
    screen * scr;

    //realoca a tabela numa tabela com este novo tamanho
    void rebuild(int new_max_size){
        auto aux = _vet;
        _vet = new Item<T>[new_max_size];
        _qtd = 0;
        _max = new_max_size;
        for (int i = 0; i < (new_max_size / ALLOCACAO); ++i)
            insert(aux[i].key, aux[i].value);
        delete [] aux;

    }

    //retorna o indice da chave ou da primeira posição vazia após colisao
    //int find_pos(int key, string value = ""){
    int find_pos(int key){
        int pos = key % _max;
        while(_vet[pos].key != key && _vet[pos].key != VAZIO)
            pos = (pos + 1) % _max;
        return pos;
    }

public:

    hashtable(int size, screen * scr){
        this->scr = scr;
        _vet = new Item<T>[size];
        _max = size;
        _qtd = 0;
    }

    ~hashtable(){
        delete[] _vet;
    }

    int size(){
        return _qtd;
    }

    //se a chave ja existir, retorne false.
    //se não existe faça a inserção na tabela
    //se a ocupação passar de 80%, duplique o tamanho da tabela e
    //realoque todos os elementos
    bool insert(int key, T value){
        int pos = find_pos(key);
        if(key <= VAZIO || _vet[pos].value == value ) //Se ja tiver um valor nessa key, verifica se e o mesmo, se for cancela.
            return false;
        while(_vet[pos].key != VAZIO) pos = (pos + 1) % _max;
        _vet[pos] = Item<T>(key, value);
        _qtd++;
        if(_qtd > _max * max_alloc)
            rebuild(_max * ALLOCACAO);
        return true;
    }

    //se a chave existir retorne true
    bool exists(int key){
        return _vet[find_pos(key)].key != VAZIO;
    }

    //se a chave existir, retorne o dado. Se não existir, retorne ""
    T get(int key){
        return _vet[find_pos(key)].value;
    }

    //se a chave existir, remova da tabela e retorne true
    //realoque todos os elementos seguintes
    //se a chave não existir, retorne false
    bool remove(int key){
        int pos = find_pos(key);
        if(_vet[pos].key != VAZIO){
            auto valuePadrao = Item<T>();
            _vet[pos].key = VAZIO;
            _vet[pos].value = valuePadrao.value;
            _qtd--;
            pos = (pos + 1) % _max;
            while(_vet[pos].key != VAZIO){
                Item<T> item = _vet[pos];
                _vet[pos].key = VAZIO;
                _vet[pos].value = valuePadrao.value;
                _qtd--;
                insert(item.key, item.value);
            }
            return true;
        }
        return false;
    }
};

#endif // HASHTABLE_H
