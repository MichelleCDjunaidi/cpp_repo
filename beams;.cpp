int numrods;
int rods[1050];

int main(){
    cin >>numrods;
    for (int i=0; i<numrods; i++ ){
        cin>> rods[i];
    }
    sort(rods, rods+numrods);
        for (int i=0; i<numrods; i++ ){
        cout<< rods[i];
    }
}