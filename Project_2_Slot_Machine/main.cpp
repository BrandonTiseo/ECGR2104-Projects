#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    int userBalance = 10;
    srand(time(0));

    while(userBalance > 0){
        string userInput = "";

        //Initial Input
        cout << "---------------------------------------------" << endl;
        cout << "Balance: " << userBalance << endl;
        cout << "Do you want to play the slot machine? (Y/N): " << endl;
        cin >> userInput;

        if(userInput == "N" || userInput == "n") 
            break;
        else if(userInput == "Y" || userInput == "y"){
            userBalance -= 1;
            string result = "";

            //Random Number Generation
            for(int i = 0; i < 3; i++){
                int randomVal = rand() % 4;
                //Mapping random number to a symbol
                switch(randomVal){
                    case 0:
                        result += "7";
                        break;
                    case 1:
                        result += "$";
                        break;
                    case 2:
                        result += "#";
                        break;
                    default:
                        result += "X";
                }
            }
            //Game Result
            cout << result << endl;
            if(result == "777"){
                cout << "You won $100!" << endl;
                userBalance += 100;
            }
            else if(result == "$$$"){
                cout << "You won $50!" << endl;
                userBalance += 50;
            }
            else if(result == "###"){
                cout << "You won $25!" << endl;
                userBalance += 25;
            }
            else if(result == "XXX"){
                cout << "You won $10!" << endl;
                userBalance += 10;
            }
            else
                cout << "You did not win anything." << endl;
        }
        else cout << 
            "INVALID INPUT" << endl;
    }

    cout << "Thank you for playing!" << endl;
    return 0;
}