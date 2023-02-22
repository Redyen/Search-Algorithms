#include <iostream>
#include <string>
#include <array>
using namespace std;
int main (){
    string x;
    string direc;
    char mat[3][3];
    cin >> x;
    cin >> direc;
    string space = "";
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

    char temp;
    if(direc == "UP"){
        temp = (mat[xi-1][yi]);
        mat[xi-1][yi] = '#';
        mat[xi][yi] = temp;
    }
    if(direc == "DOWN"){
        temp = (mat[xi+1][yi]);
        mat[xi+1][yi] = '#';
        mat[xi][yi] = temp;
    }
    if(direc == "LEFT"){
        temp = (mat[xi][yi-1]);
        mat[xi][yi-1] = '#';
        mat[xi][yi] = temp;
    }
    if(direc == "RIGHT"){
        temp = (mat[xi][yi+1]);
        mat[xi][yi+1] = '#';
        mat[xi][yi] = temp;
    }


    cout << "1" << "\n";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << mat[i][j];
            if(j == 2){
                cout << "\n";
            }
            else{
                cout << " ";
            }
        }
    }



}
