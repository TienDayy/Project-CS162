#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void login(){
    string user, pass; //user types here
    cout << "Username : ";
    cin >> user;
    cout << "Password : ";
    cin >> pass;

    ifstream in; 
    in.open("listOfUser.txt"); //read data from listOfUser
    string check;
    bool find = false;
    while (!find && in >> check){ //check if username exists or not
        if (check == user) find = true;
    }

    if (!find) cout << "Your username does not exist";
    else{
        string check_pass; //check if password is right or wrong
        in >> check_pass;
        in.close();
        while (check_pass != pass){
            cout << "Your password is not correct. Try again : ";
            cin >> pass;
        }
        cout << "Login successfully !";
    }
}