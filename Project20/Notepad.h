#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;
class node
{
public:
    int H_Siz = 0, T_Siz = 0;
    node** l_head = NULL, ** l_end = NULL, * Right, * Left, * Uper, * Down;
    char word;
    
    
    

};

static node obj1;
class Nodepad
{
    node* root=NULL,* end_N=NULL,* exe_line=NULL;
    
public:
    Nodepad();
    double chg_Line=1;
    bool Search_Word(string);
    void copy_data(string, string, Nodepad&);
    void Insert_Replacement(string data, int G_Length, int R_Length, char arr[], char replaced_word[]);
    void paste_data(char arr[], Nodepad&, int);
    void Enter_Data(char);
    void display_Notpad();
    void Delete_Data();
    void  Count_word();
    double W_counter=0;
    node* Getroot()
    {
        return root;
    }
    node* return_Last()
    {
        return end_N;
    }
}; node** Set_size(node**, int&);