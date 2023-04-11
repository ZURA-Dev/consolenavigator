#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>
using namespace std;
/*37(left arrow)
38(up arrow)
39(right arrow)             _getch()
40(down arrow)*/

struct menuitems{
    string name;
    bool selected = false;
};
vector<menuitems> menu= {{"option 1", false}, {"option 2", false}, {"option 3", false},{"option 4", false}, {"option 5", false}, {"option 6", false}};
int currentselection = 0;


void printmenu(){
    system("cls");
    for(int i = 0; i < menu.size(); i++){
        if (i == currentselection){
            cout << "--> ";
        }else{
            cout << "    ";
        }
        if(menu[i].selected == true){
            cout << "[" << menu[i].name << "]" << endl;
        }else {
            cout << menu[i].name << endl;
        }
    }
}
void menuone(){
    system("cls");
    cout << "option 1" << endl;
}
void menutwo(){
    system("cls");
    cout << "option 2" << endl;
}
void menuthree(){
    system("cls");
    cout << "option 3" << endl;
}
void menuenter(int position){
for (int i = 0; i < menu.size(); i++){
    if(menu[position].selected ==  true){
        if (position == 1){
            menuone();
        }
        if (position == 2){
            menutwo();
        }
        if (position == 3){
            menuthree();
        }
    }
}
}
int main(){
    int c;
    printmenu();
    while(true){
        int c = _getch();
        printmenu();
        c = _getch();
    switch(c) {
        case 80: // down
        currentselection = min(currentselection + 1, (int)menu.size() - 1);
        printmenu();
        break;
        case 72: // up
        currentselection = max(currentselection - 1, 0);
        printmenu();
        break;
        case 77: // right arrow
        menu[currentselection].selected == true;
        printmenu();
        //menuenter(currentselection);
        break;
        case 75:
        return 0;
        
    }
    }
}

