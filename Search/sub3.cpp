#include <iostream>
#include <string>
#include <array>
using namespace std;
int main (){
    string x;
    string direc;
    char mat[3][3];
    cin >> x;
    //cin >> direc;
    string space = "";
    string moves;
    int c = 0;
    int xi;
    int yi;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            space = "";
            space.push_back(x[c]);
            if(space == "#"){
                xi = i;
                yi = j;
            }
            space = "";
            mat[i][j] = x[c];
            c++;
        }
    }

    //up
    if(xi > 0){
        cout << "UP" << "\n";
    }
    //down
    if(xi < 2){
        cout << "DOWN"<< "\n";
    }
    //left
    if(yi > 0){
        cout << "LEFT"<< "\n";
    }
    //right
    if(yi < 2){
        cout << "RIGHT"<< "\n";
    }
}

