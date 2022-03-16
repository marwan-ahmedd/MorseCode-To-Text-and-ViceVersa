#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

std::map <char, std::string> morse{
    {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."}, {'e', "."}, {'f', "..-."}, {'g', "--."},
    {'h', "...."}, {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."}, {'m', "--"}, {'n', "-."},
    {'o', "---"}, {'p', ".--."}, {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"}, {'u', "..-"},
    {'v', "...-"}, {'w', ".--"}, {'x', "-..-"}, {'y', "-.--"}, {'z', "--.."}, {' ', " "},
    {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, 
    {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"}, {',', "--..--"}, {'.', ".-.-.-"},
    {'?', "..--.."}, {'/', "-..-."}, {'-', "-....-"}, {'(', "-.--."}, {')', "-.--.-"}
};


void Encrypt(string message)
{
    cout << "Enter a message to encrypt: ";
    cin >> message;
    
    for (int i = 0; i < message.length(); i++)
    {
        message[i] = tolower(message[i]);
    }
    
    string encryption;
    for (char letter : message)
    {
        encryption += morse[letter];
        encryption += " ";
    }
    cout << "Encryption: " << encryption << endl ;
}


void Decrypt(string code)
{
    istringstream scin;
    string token, decryption;
    cout << "Enter encrypted message: ";
    cin.ignore();
    getline(cin, code);
    scin.str(code);
    scin >> token;
    
    while (scin)
    {
        for (char letter = 32; letter <= 122; letter++)
        {
            if (morse[letter] == token){
                decryption += letter;
                break;
            }
        }
        scin >> token;    
    }
    cout << "Decryption: " << decryption << endl;
}


int main()
{
    cout << "Ahlan ya user ya habibi." << endl;
    int choice;

    while (true){   
        cout << "\nWhat do you like to do today?" << endl
            << "1- Cipher a message" << endl << "2- Decipher a message" << endl << "3- End" << endl << ">> ";

        cin >> choice;

        if (choice == 1){
            string message;
            Encrypt(message);
            
        }
        else if (choice == 2)
        {
            string encrypted_messg;
            Decrypt(encrypted_messg);

        }
        else if (choice == 3)
        {
            cout << "Program ENDED !";
            return 0;
        }
    }
    
}