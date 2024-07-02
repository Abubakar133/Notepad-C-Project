#include "Notepad.h"
Nodepad::Nodepad()
{
    end_N = NULL;root = NULL;exe_line = NULL;
}
void Nodepad::Count_word() {
    int num = 0;
    node* ptr = root;
    while (ptr != NULL)
    {
        if (ptr->word != ' ')
        {
            num++;
        }
        ptr = ptr->Right;
    }

    cout << "\nTotal words in a File is ->  " << num;
    cout << endl;

}
void Nodepad::display_Notpad()
{
    node* N1 = root;
    while (N1 != NULL)
    {
        cout << N1->word;
        N1 = N1->Right;
    }
}
void Nodepad::Insert_Replacement(string str, int G_Length, int R_Length, char List[], char replaced_word[])
{
    if (Search_Word(str) == true) {
        node* exe1 = root;
        node* exe3 = exe1;
        node* exe2 = NULL;
        int F1 = -1; int F2 = -1;
        Nodepad pad;
        while (exe1 != NULL)
        {
            if (exe1->word == List[0])
            {

                F2 = 0;
                exe2 = exe1;
                for (int i = 0; i < G_Length; i++)
                {
                    if (exe2 != NULL)
                    {
                        if (exe2->word != List[i])
                        {
                            F2 = false;
                            break;
                        }
                    }
                    else
                        break;
                    exe2 = exe2->Right;
                }
                if (F2 == 0)
                    F1 = 0;
                F2 = 0;
            }
            exe3 = root;
            if (F1 == 0)
            {
                while (exe3 != NULL)
                {
                    if (exe3 == exe1)
                    {
                        for (int i = 0; i < R_Length; i++)
                        {
                            pad.Enter_Data(replaced_word[i]);
                        }
                        for (int i = 0; i < G_Length; i++)
                        {
                            exe3 = exe3->Right;
                        }
                    }
                    pad.Enter_Data(exe3->word);
                    exe3 = exe3->Right;
                }
                this->root = pad.Getroot();
                this->end_N = pad.return_Last();
                exe1 = root;
                exe3 = root;
                break;
            }
            exe1 = exe1->Right;
            F1 = -1;
            F2 = 0;
        }
    }
    else {
        cout << "No this type of data is found\n";
    

    }
}


bool Nodepad::Search_Word(string str) {
    string stri;
    node* r1;
    r1 = root;
    node* r2;
    r2 = r1;
    int count = 0;
    while (r1->Right != NULL) {
        while (r2->Right) {

            if (r2->word == ' ') {
                break;
            }
            stri = stri + r2->word;

            r2 = r2->Right;
        }
        if (stri == str) {
            count++;

        }
        r2 = r1;
        r1 = r1->Right;
        stri = "";
    }
    if (count != 0) {
        cout << "\nResult found " << count << " Times \n" << endl;
        return true;
    }
    else if (count == 0) {
        cout << "\nResult not found\n";
        return false;
    }
    
}
void Nodepad::Enter_Data(char Ch)
{

    node* New_1 = new node;
    New_1->Down = NULL;
    New_1->Left = NULL;

    New_1->Uper = NULL;

    New_1->Right = NULL;
    New_1->word = Ch;
    if (root != NULL) {

        end_N->Right = New_1;
        New_1->Left = end_N;
        end_N = New_1;
        W_counter++;
    }
    else if (root == NULL)
    {

        root = New_1;
        end_N = New_1;
        W_counter++;
        obj1.l_head = Set_size(obj1.l_head, obj1.H_Siz);
        obj1.l_head[obj1.H_Siz - 1] = root;
        exe_line = root;

        return;
    } if (Ch == '\n')
    {
        exe_line = obj1.l_head[obj1.H_Siz - 1];
        obj1.l_end = Set_size(obj1.l_end, obj1.T_Siz);
        obj1.l_end[obj1.T_Siz - 1] = end_N;
        obj1.l_head = Set_size(obj1.l_head, obj1.H_Siz);
        obj1.l_head[obj1.H_Siz - 1] = NULL;
        while ((W_counter - (W_counter / 120) * 120) != 0)
        {
            W_counter++;
        }
        W_counter++;
        chg_Line++;
    }
    if ((end_N->Left->word == '\n')) {
        obj1.l_head[obj1.H_Siz - 1] = end_N;
    }
   
    int Check = W_counter / 120;
    if (obj1.T_Siz != 0)
    {
        end_N->Uper = exe_line;
        exe_line->Down = end_N;
        if (exe_line->word != '\n')
            exe_line = exe_line->Right;
    }

    if ((Check) == chg_Line)
    {
        node* temp = New_1;
        Enter_Data('\n');
        chg_Line = chg_Line + 1;
    }


}
void Nodepad::copy_data(string start, string last, Nodepad& obj) {
    if (Search_Word(start) == true && Search_Word(last) == true) {
        string stri;
        node* r1;
        r1 = root;
        node* r2;
        r2 = r1;
        int count = 0, wc = 0, wc2 = 0;
        while (r1->Right != NULL) {
            while (r1->Right) {

                if (r1->word == ' ') {
                    break;
                    wc++;
                } wc++;
                stri = stri + r1->word;

                r1 = r1->Right;

            }
            if (stri == start) {
                break;
            }

            r1 = r1->Right;
            stri = "";
        }
        r1 = root;
        string st1;
        while (r1->Right != NULL) {
            while (r1->Right) {

                if (r1->word == ' ') {
                    break;
                    wc2++;
                }
                wc2++;
                st1 = st1 + r1->word;

                r1 = r1->Right;

            }
            if (st1 == last) {
                break;
            }
            r1 = r1;
            r1 = r1->Right;
            st1 = "";
        }

        wc = wc - start.length();
        cout << "\nwc " << wc + 1;
        cout << "\nwc2  " << wc2;
        cout << endl;
        node* t = root;
        char List[1000];
        r1 = root;
        int i = 0;
        for (int j = 0; j <= wc2 + 8; j++) {
            if (t->Right != NULL) {
                if (j < wc + 1) {
                    t = t->Right;
                }
                else {

                    List[i] = t->word;
                    //cout << t->data;
                    t = t->Right;
                    i++;
                }
            }
            else
                break;


        }
        /*cout << "\nwc2  " << i;*/
        cout << "\ncopy Array\n";
        for (int j = 0; j < i; j++) {
            cout << List[j];

        }
        char y;
        cout << "\nif you want to paste press y\t";
        cin >> y;
        cout << endl;
        if (y == 'y') {
            paste_data(List, obj, i);
        }
    }
    else {
        cout << "No this type of data is found\n";
    }
}

node**Set_size(node** N2, int& S)
{
    node** N1 = new node * [S + 1];
    for (int j = 0; j < S; j++)
        N1[j] = N2[j];
    S++;
    delete[]N2;
    return N1;
}
void Nodepad::paste_data(char List[], Nodepad& obj, int length) {
    char input;
    for (int i = 0; i < length; i++) {
        input = List[i];
        obj.Enter_Data(input);
    }
    cout << "\nPaste data succesfully\n";

}
void Nodepad::Delete_Data() {

    if (root != NULL)
    {
        node* N1 = end_N->Left;
        N1->Right = NULL;
        free(end_N);
        end_N = N1;
        W_counter--;
    }
    if (root == NULL)
        return;
    else if (end_N->Left == NULL)
        root = NULL;
    else if (end_N->word == '\n')
    {
        chg_Line--;
        obj1.H_Siz--;
        obj1.T_Siz--;
    }
    if (end_N == NULL) {
        return;
    }
    
}
