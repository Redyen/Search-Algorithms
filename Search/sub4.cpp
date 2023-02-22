#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

string convert (char a[3][3]){
    string out = "";
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            out.push_back(a[i][j]);
        }
    }
    return out;
}

string makeMove(char mat[3][3], string direc){
    int xi;
    int yi;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(mat[i][j] == '#'){
                xi = i;
                yi = j;
            }
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

    return convert(mat);
}

vector<string> moves(string x){
    string direc;
    char mat[3][3];
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

    vector<string> movers;
    //up
    if(xi > 0){
        movers.push_back("UP");
    }
    //down
    if(xi < 2){
        movers.push_back("DOWN");
    }
    //left
    if(yi > 0){
        movers.push_back("LEFT");
    }
    //right
    if(yi < 2){
        movers.push_back("RIGHT");
    }

    return movers;
}

int solve(string init,int counter ,string fin){
    char initmat[3][3];
    char fmat[3][3];

    int c = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            initmat[i][j] = init[c];
            c++;
        }
    }
    c = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            fmat[i][j] = fin[c];
            c++;
        }
    }

    bool solved = true;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (initmat[i][j] != fmat[i][j]){
                    solved = false;
            }
        }
    }
    if (solved){
        cout << counter;
        return 0;
    }
    vector<string> tMoves = moves(init);

    if (find(tMoves.begin(), tMoves.end(), "UP") != tMoves.end()){
        solve(makeMove(initmat, "UP"), counter + 1, fin);
    }
    if (find(tMoves.begin(), tMoves.end(), "DOWN") != tMoves.end()){
        solve(makeMove(initmat, "DOWN"), counter + 1, fin);
    }
    if (find(tMoves.begin(), tMoves.end(), "LEFT") != tMoves.end()){
        solve(makeMove(initmat, "LEFT"), counter + 1, fin);
    }
    if (find(tMoves.begin(), tMoves.end(), "RIGHT") != tMoves.end()){
        solve(makeMove(initmat, "RIGHT"), counter + 1, fin);
    }

}






int main (){
    string x; //matrix entered
    int moveMade = 0;
    string y; // solution
    cin >> x;
    cin >> y;
    vector<string> avail = moves(x); //these are the available moves

    solve(x, moveMade, y);


}
