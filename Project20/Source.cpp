#include "Notepad.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;

int main()
{
    char data;
    string word, replacement;
    static Nodepad obj;
    bool check = true;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\t\t\t\t\t\t\tNOTE PAD C++\n";
    SetConsoleTextAttribute(hConsole, 10);
    cout << "\n\n\t\t\t\t\t\tAbubakar Mehboob 1023\n\t\t\t\t\t\tIbrahim Shakawat 0301\n\t\t\t\t\t\tTanzeel Haider\n\n\n";
    SetConsoleTextAttribute(hConsole, 4);
    cout << "\t\t\t\t\t             ||" << SetConsoleTextAttribute(hConsole, 4) << "    Notepad Keys || ";
    SetConsoleTextAttribute(hConsole, 10);
    cout << endl;
    cout << "\n\t\t\t\t\t||Search a Word     " << "Enter + Key                ||" << endl;
    cout << "\t\t\t\t\t||Replace a word     " << "Enter - key               ||" << endl;
    cout << "\t\t\t\t\t||Start a Note Pad     " << "Enter Space key         ||" << endl;
    cout << "\t\t\t\t\t||End Note Pad     " << "Enter * Key                 ||" << endl;
    cout << "\t\t\t\t\t||Copy and paste the string     " << "Enter Tab key  ||" << endl;
    cout << "\t\t\t\t\t||Display a Note pad Data     " << "Enter / key      ||" << endl;
    cout << "\t\t\t\t\t||Total word Count     " << "Enter shift Key         ||" << endl;
    cout << "\t\t\t\t\t||Delete a word     " << "Enter Backspace Key        ||" << endl;
    cout << "\t\t\t\t\t||For new line     " << "Enter Enter Key             ||" << endl;
    cout << "\t\t\t\t\t||For instruction page " << "   Enter ? Key          ||" << endl;

    


    while (check)
    {
        data = _getch();
        system("cls");

        string last, start;

        if (data == 42) {

            return 0;

        }
        else if (data == 32) {
            system("cls");
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Start Typing.........";
            system("pause");
            system("cls");
            {

                while (check == true)
                {
                    data = _getch();
                    system("cls");
                    switch (data) {
                    case 13:
                        obj.Enter_Data('\n');
                        break;
                    case 47:
                        obj.display_Notpad();
                        break;
                    case 8:
                        obj.Delete_Data();
                        break;
                    case 43:
                        SetConsoleTextAttribute(hConsole, 4);
                        cout << "Enter word for Search\t";
                        cin >> word;
                        obj.Search_Word(word);
                        break;

                    case 45:
                        SetConsoleTextAttribute(hConsole, 8);
                        cout << "Enter word for Replacement\t";
                        cin >> word;
                        cout << "Enter the new word \t";
                        cin >> replacement;
                        char arr[20];
                        for (int i = 0; i < word.size(); i++) {
                            arr[i] = word[i];
                        }
                        char replaced_word[20];
                        for (int i = 0; i < replacement.size(); i++)
                            replaced_word[i] = replacement[i];
                        obj.Insert_Replacement(word, word.size(), replacement.size(), arr, replaced_word);
                        break;
                    case 14 || 15:
                        SetConsoleTextAttribute(hConsole, 10);
                        obj.Count_word();
                        break;

                    case 9:
                        SetConsoleTextAttribute(hConsole, 3);
                        cout << "Enter start\t";
                        cin >> start;
                        cout << "Enter last\t";
                        cin >> last;
                        obj.copy_data(start, last, obj);
                        break;
                    case 42:

                        return 0;
                        break;
                    case 63:
                        cout << "\t\t\t\t\t             ||" << SetConsoleTextAttribute(hConsole, 4) << "    Notepad Keys || ";
                        SetConsoleTextAttribute(hConsole, 10);
                        cout << endl;
                        cout << "\n\t\t\t\t\t||Search a Word     " << "Enter + Key                ||" << endl;
                        cout << "\t\t\t\t\t||Replace a word     " << "Enter - key               ||" << endl;
                        cout << "\t\t\t\t\t||Start a Note Pad     " << "Enter Space key         ||" << endl;
                        cout << "\t\t\t\t\t||End Note Pad     " << "Enter * Key                 ||" << endl;
                        cout << "\t\t\t\t\t||Copy and paste the string     " << "Enter Tab key  ||" << endl;
                        cout << "\t\t\t\t\t||Display a Note pad Data     " << "Enter / key      ||" << endl;
                        cout << "\t\t\t\t\t||Total word Count     " << "Enter shift Key         ||" << endl;
                        cout << "\t\t\t\t\t||Delete a word     " << "Enter Backspace Key        ||" << endl;
                        cout << "\t\t\t\t\t||For new line     " << "Enter Enter Key             ||" << endl;
                        cout << "\t\t\t\t\t||For instruction page " << "   Enter ? Key          ||" << endl;
                        break;
                    default:
                        SetConsoleTextAttribute(hConsole, 7);
                        obj.Enter_Data(data);
                    }
                    obj.display_Notpad();

                }
            }
        }
        else {
            system("cls");

            cout << "\t\t\t\t\t             ||" << SetConsoleTextAttribute(hConsole, 4) << "    Notepad Keys || ";
            SetConsoleTextAttribute(hConsole, 10);
            cout << endl;
            cout << "\n\t\t\t\t\t||Search a Word     " << "Enter + Key                ||" << endl;
            cout << "\t\t\t\t\t||Replace a word     " << "Enter - key               ||" << endl;
            cout << "\t\t\t\t\t||Start a Note Pad     " << "Enter Space key         ||" << endl;
            cout << "\t\t\t\t\t||End Note Pad     " << "Enter * Key                 ||" << endl;
            cout << "\t\t\t\t\t||Copy and paste the string     " << "Enter Tab key  ||" << endl;
            cout << "\t\t\t\t\t||Display a Note pad Data     " << "Enter / key      ||" << endl;
            cout << "\t\t\t\t\t||Total word Count     " << "Enter shift Key         ||" << endl;
            cout << "\t\t\t\t\t||Delete a word     " << "Enter Backspace Key        ||" << endl;
            cout << "\t\t\t\t\t||For new line     " << "Enter Enter Key             ||" << endl;
            cout << "\t\t\t\t\t||For instruction page " << "   Enter ? Key          ||" << endl;
        }

        


    }
    return 0;
}
