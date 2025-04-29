#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    bool encryption; //If bool == true then encrypt, == false then decrypt.
    int key = 0;
    string inputFile;
    string outputFile;

    //cmd-line argument checking
    for(int i = 0; i < argc; i++){
        string param(argv[i]);
        
        if(param == "-e")
            encryption = true;
        if(param == "-d")
            encryption = false;
        
        if(param == "-k"){
            if(i+1 < argc){
                key =  atoi(argv[i+1]);
            }else{
                cout << "No key argument specified!" << endl;
                return 1;
            }
        }

        if(param == "-i"){
            if(i+1 < argc){
                inputFile = argv[i+1];
            }else{
                cout << "No input file argument specified!" << endl;
                return 1;
            }
        }
        if(param == "-o"){
            if(i+1 < argc){
                outputFile = argv[i+1];
            }else{
                cout << "No output file argument specified!" << endl;
                return 1;
            }
        }
    }

    //File Opening
    ifstream inFile;
    inFile.open(inputFile);
    if(!inFile.is_open()){
        cout << "Unable to open input file." << endl;
        return 1;
    }

    ofstream outFile;
    outFile.open(outputFile);
    if(!outFile.is_open()){
        cout << "Unable to open output file." << endl;
        return 1;
    }

    bool lower;
    string curr_line;
    string new_line;
    while(!inFile.eof()){
        getline(inFile,curr_line);
        new_line = "";

        for(int i = 0; i < curr_line.length(); i++){
            lower = true;
            char c = curr_line[i];
            if(!isalpha(c)){
                new_line += c;
                continue;
            }
            if(isupper(c))
                lower = false;
 
            int ascii_c = (int) c;
            if(encryption){
                ascii_c += key;
                if(lower && ascii_c > 122){
                    ascii_c -= 122; //Find out how much over the max ascii value.
                    ascii_c += 96; //Add that offset to the min ascii value - 1.
                }else if(!lower && ascii_c > 90){
                    ascii_c -= 90;
                    ascii_c += 64;
                }
            }else{
                ascii_c -= key;
                if(lower && ascii_c < 97){
                    ascii_c = 97 - ascii_c; //Find out how much under the min ascii value.
                    ascii_c = 123 - ascii_c; //Subtract that offset from the max ascii value + 1.
                }else if(!lower && ascii_c < 65){
                    ascii_c = 65 - ascii_c;
                    ascii_c = 93 - ascii_c;
                }
            }
            new_line += ascii_c;
        }
        outFile << new_line << endl;
    }
    inFile.close();
    outFile.close();
    return 0;
}
