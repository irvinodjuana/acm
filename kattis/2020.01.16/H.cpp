#include <iostream>
#include <vector>
using namespace std;
int TC(int, vector<int>,vector<int>,int);
int main() {
    int ncoa=0; // number of coaches
    cin >> ncoa;
    vector<int> psg;//number of passengers in each segment
    for(int i=0; i<ncoa;i++){int x; cin >> x; psg.push_back(x);}
    vector<int> idx; // order of blowing up segments
    for(int i=0; i<ncoa;i++){int x; cin >> x; idx.push_back(x);}
    int Ctrain=0, totalpsg=0;
    for(int i=0; i<ncoa;i++){totalpsg+=psg[i];}
    Ctrain=totalpsg+10-(totalpsg%10); // chaos of a continuous train
    TC(ncoa,psg,idx,Ctrain);
    return 0;
}

int TC(int ncoa,vector<int> psg,vector<int> idx,int Ctrain){
    int max=Ctrain;
    int Tc=0;//total chaos
    int n=0;
    while(n<ncoa){
        psg[idx[n]]=0;
        int psgInCoach=0;
        for(int i=0;i<ncoa;i++){
            psgInCoach += psg[i];
            if(psg[i]==0){psgInCoach = psgInCoach+10-(psgInCoach%10); Tc += psgInCoach; psgInCoach = 0;}
        }
        if(Tc > max){max=Tc;}
        n++;
    }
    return max;
}