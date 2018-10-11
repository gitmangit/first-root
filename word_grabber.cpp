#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{

string english[52] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"
                     ,"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
int i, x, y, z, j;

char ch;
string st;
string st1;
string st2;
string words[10];
vector <string> vwords;
vector <string> vexceptions;

// Ввод слов - исключений. ////////////////////////////////////////////////////////////

ifstream in ("exceptions.txt");
if(!in) { cout << "Невозможно открыть файл exceptions.txt\n"; return 1; }
i = 0;
while(in) { in >> st2; vexceptions.push_back(st2); i++; }
in.close();

// Посимвольное считывание текста с последующей обработкой ////////////////////////////

FILE *resurs;

if((resurs = fopen("source.txt", "r"))==NULL) { cout << "Невозможно открыть файл source.txt" << endl; return 1; } 
rewind(resurs);

y = 0; st1="";
while(!feof(resurs))
{

ch = getc(resurs);
st = ch;

i = 0; x = 0;
while(i<52&&x==0) { if(st==english[i]) { x=1; } i++; }

if(x==1)          { st1 = st1 + st; }
if(x==0&&st1!="") {

i = 0; z = 0;
while(i<y&&y>0&&z==0) { if(st1+"[]"==vwords[i]) { z=1; } i++;  }
i = 0; j = 0;
while(i<vexceptions.size()&&j==0) { if(st1+"[]"==vexceptions[i]) { j=1; } i++; }

 if(z==0&&j==0) { vwords.push_back(st1+"[]"); y++; } st1=""; }

}
i = 0;
while(i<vwords.size())
{
cout << vwords[i] << endl; i++;
}
cout << vwords.size() << endl;


// Вывод результата в текстовый файл ////////////////////////////////////////////////

ofstream out ("result.txt");
if(!out) { cout << "Невозможно открыть файл result.txt\n"; return 1; }

i = 0;
while(i<vwords.size())
{
out << vwords[i] << endl; i++;
}
out << vwords.size() << endl;
out.close();

return 0;
}
