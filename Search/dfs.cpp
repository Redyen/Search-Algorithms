#include <iostream>
#include <string>
#include <array>
#include <stdlib.h>
using namespace std;

string availMoves (string mat){
    int index = mat.find('#');
    string temp = "";
    if(index > 2){
        temp += "UP";
    }
    if(index < 6){
        temp += "DOWN";
    }
    if(index != 0 && index != 3 && index != 6){
        temp += "LEFT";
    }
    if(index != 2 && index != 5 && index != 8){
        temp += "RIGHT";
    }
    return temp;
}

string makeMove (string sMat, string direc){

    string space = "";
    int c = 0;
    int xi;
    int yi;
    char mat[3][3];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            space = "";
            space.push_back(sMat[c]);
            if(space == "#"){
                xi = i;
                yi = j;
            }
            space = "";
            mat[i][j] = sMat[c];
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
    string fMat;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            fMat += mat[i][j];
        }
    }

    return fMat;


}

void solve(string mat, int num ,string sol){
    if (mat == sol){
        cout << "Solution found" << " ";// << num;
        exit;
    }
    else{
        //check possible moves
        string matmoves = availMoves(mat);
        //solve each move made
        if(matmoves.find("UP") != string::npos){
            solve(makeMove(mat, "UP"), num , sol);
        }
        else if(matmoves.find("DOWN") != string::npos){
            solve(makeMove(mat, "DOWN"), num , sol);
        }
        else if(matmoves.find("LEFT") != string::npos){
            solve(makeMove(mat, "LEFT"), num , sol);
        }
        else if(matmoves.find("RIGHT") != string::npos){
            solve(makeMove(mat, "RIGHT"), num , sol);
        }

    }
}

int main (){
    string init;
    cin >> init;
    string fin;
    cin >> fin;

    solve(init, 0, fin);
}
