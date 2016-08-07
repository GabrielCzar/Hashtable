#include <iostream>
#include "hashtable.h"
#include <unordered_map>
#include <cstdio>
#include <time.h>
#include "screen.h"

using namespace std;

int main(){

    screen scr(20, 70); //para ajudar a escrever na tela
    hashtable<string> ht(10, &scr); //constroi hash para 10 elementos

    string in;

    while(true){
        cout << " I insert (key value) " << endl;
        cout << " E exist  (key) " << endl;
        cout << " G get    (key) " << endl;
        cout << " R remove (key) " << endl;
        cout << " Q quit " << endl;

        cin >> in;

        if(in == "i" || in == "I"){
            int key;
            string value;
            cin >> key >> value;
            ht.insert(key, value);
            ht.show();
        }
        if(in == "e" || in == "E"){
            int key;
            cin >> key;
            cout << (ht.exists(key) ? "Existe" : "Nao existe") << endl;
        }
        if(in == "g" || in == "G"){
            int key;
            cin >> key;
            cout << "Valor " << ht.get(key) << endl;
        }
        if(in == "r" || in == "R"){
            int key;
            cin >> key;
            ht.remove(key);
            ht.show();
        }
        if(in == "q" || in == "Q")
            break;
    }

    cout << endl;
    return 0;
}

