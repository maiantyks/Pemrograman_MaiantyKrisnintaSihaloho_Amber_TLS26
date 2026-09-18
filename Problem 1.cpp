#include <iostream>

using namespace std;

int findEliminated (int position, int K, int remaining){
    return (position + K - 1) % remaining;
}

int main (){
    int K, N;
    cout << "N : ";
    cin >> N;
    cout << "K : ";
    cin >> K;

    int *astronauts = new int [N];

    for (int i = 0; i < N; i++){
        astronauts [i]= i + 1;
    }

    int remaining = N;
    int position = 0; 

    while (remaining >1){
        int eliminated = findEliminated(position, K, remaining);
        int eliminatedNumber = astronauts [eliminated];
        cout << eliminatedNumber << " ";

        for (int i = eliminated; i < remaining - 1; i++){
            astronauts [i] = astronauts [i + 1];
        }

    remaining--;

    if (eliminatedNumber % 2 == 0){
        K = K + 2;
    }
    else {
        K = K - 1;
    }

    if (K < 2){
        K = 2;
    }

    position = eliminated;

    if (position >= remaining){
        position = 0;
        }
    }
    cout << endl;
    cout << "Last astronaut: " << astronauts [0] << endl;
    delete [] astronauts;
    return 0;
}