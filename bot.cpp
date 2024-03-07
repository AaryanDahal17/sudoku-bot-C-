#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;


struct node{

node* parentNode;
};


void inputGameState(int arr[9][9]){

    cout << "Enter input of the row in the format -> 0 0 1 9 2 5 0 0 0 " << endl;

    // Getting the gameState from user

    for (int i = 0; i < 9 ; i++){

    cout << "Enter row no. " << i+1 << " : ";
       
    std::string userInput;

    std::getline(std::cin, userInput);

    std::stringstream ss(userInput);

    int num, index = 0;

    while (ss >> num && index < 9) {
        if(num > 9  || num < 0){
            cout << "Invalid input" << endl;
            exit(0);
        }
       arr[i][index++] = num;
    }

    cout << endl;

    }

}


int main(){

    
    int gameState[9][9];

    inputGameState(gameState);
    

   



    return 0;
}