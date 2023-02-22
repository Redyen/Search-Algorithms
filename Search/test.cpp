#include <iostream>
#include <string.h>
#include <array>
#include <vector>

using namespace std;

vector<int> getMin(vector<int> arr){
    int mini = 10000;
    int ind;
    for(int i = 0; i < arr.size(); i++){
        if(arr.at(i) < mini){
            mini = arr.at(i);
            ind = i;
        }
    }

    vector<int> x;
    x.push_back(ind);
    x.push_back(mini);
    return x;
}

vector<int> getMax(vector<int> arr){
    int mini = -1;
    int ind;
    for(int i = 0; i < arr.size(); i++){
        if(arr.at(i) > mini){
            mini = arr.at(i);
            ind = i;
        }
    }

    vector<int> x;
    x.push_back(ind);
    x.push_back(mini);
    return x;
}


int main(){
    int numBus, maxTime;
    cin >>numBus;
    cin >>maxTime;

    vector<int> arrMorning;
    vector<int> arrAfternooon;
    int temp;
    for(int i = 0; i < numBus; i++){
        cin >> temp;
        arrMorning.push_back(temp);
    }
    for(int i = 0; i < numBus; i++){
        cin >> temp;
        arrAfternooon.push_back(temp);
    }

    int total = 0;
    int tempSum;
    vector<int> morn;
    vector<int> noon;
    for(int i = 0; i < numBus; i++){
        morn = getMin(arrMorning);
        noon  = getMax(arrAfternooon);
        //int j, k;
        int j = morn.at(0);
        int k = noon.at(0);
        arrMorning.erase(arrMorning.begin()+j);
        arrAfternooon.erase(arrAfternooon.begin()+k);

        tempSum = morn.at(1) + noon.at(1);
        //cout << morn.at(1) << " "<< noon.at(1)<< " " << tempSum<< "\n";
        if (tempSum>maxTime){
            total += tempSum - maxTime;
        }

    }

    cout << total*200 << "\n";






}
