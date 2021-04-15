#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>

using namespace std;

void menu_help() {
    cout << "Main Menu\n";
    cout << "Please make your selection\n";
    cout << "s - Start\n";
    cout << "o - Options\n";
    cout << "h - Help\n";
    cout << "q - Quit\n\n";
}


void menu (std::function<void()> program) 
{
    
    char choice = 0;
    menu_help();
    do {
        cout << "Selection: ";
        while (isspace((choice = getchar())));
        cout << endl;
        switch(choice) {
            case 's':
                cout << "Program starting ..!\n";
                program();
                break;
            case 'o':
                cout << "Max Entries:";
                cin >> entries_count;
                cout << "Delay time in milliseconds:";
                cin >> delay_time;
                break;
            case 'h':
                menu_help();
                break;
            case 'q':
                cout << "Program terminate";
                break;
            default:
                cout << "No valid choice\n";
                break;
        }
    }  while(choice !='q');                         
}
#endif