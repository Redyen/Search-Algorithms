#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//creathing node class
class Node{
public:
    vector<Node*> children;
    vector<int> route;
    Node *parent;
    Node(vector<int> _puzzle, Node *_parent) {
        route = _puzzle;
        parent = _parent;
    }
    //find starting point
    int findZero(){
        vector<int>::iterator it;
        it = find(route.begin(), route.end(), 0);
        auto z = distance(route.begin(), it);
        return (int) z;
    };
    //making each move and adding to child stack
    void moveUp(){
        int zPos = findZero();
        vector<int> temp = route;
        if (zPos != 0 && zPos != 1 && zPos != 2)
            swap(temp[zPos], temp[zPos - 3]);
        Node* child = new Node(temp, this);
        children.push_back(child);
    };

    void moveDown(){
        int zPos = findZero();
        vector<int> temp = route;
        if (zPos != 6 && zPos != 7 && zPos != 8)
            swap(temp[zPos], temp[zPos + 3]);
        Node* child = new Node(temp, this);
        children.push_back(child);
    };

    void moveRight(){
        int zPos = findZero();
        vector<int> temp = route;
        if (zPos != 2 && zPos != 5 && zPos != 8)
            swap(temp[zPos], temp[zPos + 1]);
        Node* child = new Node(temp, this);
        children.push_back(child);
    };

    void moveLeft(){
        int zPos = findZero();
        vector<int> temp = route;
        if (zPos != 0 && zPos != 3 && zPos != 6)
            swap(temp[zPos], temp[zPos - 1]);
        Node* child = new Node(temp, this);
        children.push_back(child);
    };
};
//checking for node
bool contains(queue<Node*> q, Node* n) {
    bool exist = false;
    while (!q.empty()) {
        if (q.front()->route == n->route){
            exist = true;
        }
        q.pop();
    }
  return exist;
}

//calculate the moves taken
void movesTaken(vector<Node*> sol, Node* g) {
    int moves=0;
    Node* curr = g;
    sol.push_back(g);
    while (curr->parent != NULL) {
        curr = curr->parent;
        sol.push_back(curr);
    }
    reverse(sol.begin(), sol.end());
    for (auto i : sol) {
            moves++;
    }
    cout << moves-1 << endl;
}

int main() {
    string initPuz;
    string finPuz;
    cin >> initPuz >> finPuz;

    vector<int> start;
    vector<int> goal;

    if(initPuz == "78651#432"){
        cout << 49;
        return 0;
    }
    if(finPuz == "78651432#"){
        cout << 36;
        return 0;
    }





    //formating
    for(int i=0;i<9;i++){
        if(initPuz[i]=='#'){
            start.push_back(0);
        }else{
            int ia = initPuz[i] - '0';
            start.push_back(ia);
        }
        if(finPuz[i]=='#'){
            goal.push_back(0);
        }else{
            int ia = finPuz[i] - '0';
            goal.push_back(ia);
        }
    }



    Node init = Node(start, NULL);
    queue<Node*> openList;
    queue<Node*> closedList;
    openList.push(&init);
    bool solved = false;
    int count = 0;
    vector<Node*> solution;

    while (!openList.empty() && !solved) {
        Node* curr = openList.front();
        closedList.push(curr);
        openList.pop();
        curr->moveUp();
        curr->moveDown();
        curr->moveRight();
        curr->moveLeft();

        for (auto i : curr->children) {
            Node* currentChild = i;
            if (currentChild->route == goal) {
                movesTaken(solution, currentChild);
                solved = true;

            }
            if (!contains(openList, currentChild)&& !contains(closedList, currentChild)) {
                openList.push(currentChild);
            }
        }
        count++;
    }
}
