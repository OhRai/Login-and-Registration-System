#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIN () {

    string username, password, un, pw;

    cout << "Enter a Username: "; cin >> username; 
    cout << "Enter a Password: "; cin >> password; 

    ifstream read(username + ".txt"); 
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password) {
        return true;
    } else {
        return false;
    }

}

int main() {

    int choice; 

    cout << "1) Register" << endl;
    cout << "2) Login" << endl;
    cout << "What is your choice?: "; cin >> choice; 

    if (choice == 1) {

        string username, password; 
        
        cout << "Select a Username: "; cin >> username; 
        cout << "Select a Password: "; cin >> password; 

        ofstream file; 
        file.open(username + ".txt");
        file << username << endl << password; 
        file.close();

        main();

    }

    else if (choice == 2) {

        bool status = IsLoggedIN();
        
        if (!status) {

            cout << "Login Failed!" << endl;
            return 0;
        } else {

            cout << "Login Successful!" << endl;
            return 1;

        }

    }
        
}
