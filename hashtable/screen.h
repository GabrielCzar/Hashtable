#ifndef SCREEN_H
#define SCREEN_H

#include <vector>
#include <iostream>
#include <sstream>

namespace std{

class screen
{
    vector<string> mat;

public:

    screen(int nl = 15, int nc = 70):
        mat(nl, string(nc, ' '))
    {
    }

    string& operator[](int l){
        return mat[l];
    }

    //max = maximo de caracteres a serem inseridos
    //max == 0 -> tantos quantos possível
    void write(int l, int c, int max, const string &str){
        int num = 0; //numero de caracteres escritos
        for(int i = 0; i < (int) str.size(); i++){
            if(c + i < (int) mat[0].size())
                if(l < (int) mat.size()){
                    mat[l][c + i] = str[i];
                    num++;
                    if(num == max)
                        return;
                }
        }
    }

    void show(){
        cout << string(mat[0].size() + 2, '#') << endl;
        for(auto linha : mat)
            cout << "#" << linha << "#" << endl;
        cout << string(mat[0].size() + 2, '#') << endl;
    }

    //espera qualquer entrada de dados
    void wait(){
        string s;
        cin.ignore(1000, '\n');
        getline(cin, s);
    }

    void clear() {
        // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
        std::cout << "\x1B[2J\x1B[H";
        //std::cout << "\x1B[H";
        for(auto &linha : mat)
            for(auto &c : linha)
                c = ' ';
    }

    int sizeL(){
        return mat.size();
    }

    int sizeC(){
        return mat[0].size();
    }
};
}//namespace std
#endif // SCREEN_H
