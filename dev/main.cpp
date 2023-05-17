#include "view.h"

int main() {
    /* ----- INSERT ----- */
    /*Record R;

    string n = "alex";
    string p = "2341";
    string a = "rua f";

    //strcpy(R.name, n.c_str());
	//strcpy(R.phone, p.c_str());
	//strcpy(R.address, a.c_str());

    //insertRecord(R);
    insert(n, p, a);*/
    /* ------------------ */
    
    while(true) {
        cout << "----------- MENU -----------" << endl;
        cout << "1. List all records" << endl;
        cout << "2. Search by name" << endl;
        cout << "3. Search by phone" << endl;
        cout << "4. Insert record" << endl;
        cout << "5. Remove by name" << endl;
        cout << "6. Remove by phone" << endl;
        cout << "7. Remove all records" << endl;
        cout << "8. Exit" << endl;
        
        char ch;
        cin >> ch;

        if(ch == '1') {
            listAll();
        }

        if(ch == '2') {
            string name;
            cout << "Enter the name: " << endl;
            cin >> name;
            //getline(cin, name);
            nameSearch(name);
        }

        if(ch == '3') {
            string phone;
            cout << "Enter the phone: " << endl;
            cin >> phone;
            //getline(cin, name);
            phoneSearch(phone);
        }

        if(ch == '4') {
            string name;
            string phone;
            string address;
            
            cout << endl;
            cout << "Digite o nome: " << endl;
            cin >> name;
            //getline(cin, name);
            cout << "Digite o telefone: " << endl;
            cin >> phone;
            //getline(cin, phone);
            cout << "Digite o endereço: " << endl;
            cin >> address;
            //getline(cin, address);

            insert(name, phone, address);
        }

        if(ch == '5') {
            string name;
            cout << "Enter the name: " << endl;
            cin >> name;
            //getline(cin, name);
            nameRemove(name);
        }

        if(ch == '6') {
            string phone;
            cout << "Enter the phone: " << endl;
            cin >> phone;
            //getline(cin, name);
            phoneRemove(phone);
        }

        if(ch == '7') {
            removeAll();
        }

        if(ch == '8') break;
    }
}