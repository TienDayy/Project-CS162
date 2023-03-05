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
        if (check[0] == 'u' && user.length() == check.length() - 9){ //since "user:..." starts with 'u'
            find = true;
            for (int i = 9 ; i < check.length() ; i++){
                if (check[i] != user[i - 9]){
                    find = false;
                    break;
                }
            }
        }
    }

    string read_pass, check_pass = ""; //check if password is right or wrong
    in >> read_pass;
    for (int i = 9 ; i < read_pass.length() ; i++) check_pass += read_pass[i];
    in.close();
    while (check_pass != pass){
        cout << "Your password is not correct. Try again : ";
        cin >> pass;
    }
    cout << "Login successfully !";
}