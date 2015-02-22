#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;
const char* word(int);
bool ganar(const char*,const char*);
void falla(int);
int progress(const char*,char*,char);
string palabra();

int main(int argc, char** argv){

int resp = 1;
while(resp == 1){

        cout << "       EL AHORCADO (x.x)" << endl;
        cout << "1. Facil \n2. Medio \n3. Dificil \nNivel de dificultad:  ";
        int dif;
        cin >> dif;
        int num ;
        string w = palabra();
        const char* word = w.c_str();
       
        char guess[strlen(word)];
        
        for(int i = 0; i < strlen(word); i++){
                guess[i] = '_';
        }
        cout << guess << endl;

        char letters[20] = "";
        bool x = false;
        int f = 0;
        int pos = 0;
        while (x == false && f < 9){ //oportunidades
                cout << " 1. Letra \n 2. Palabra \n Ingrese opcion: ";
                int op;
                cin >> op;

                if (op == 1){
                cout << "Letra: ";
                char c;
                cin >> c;

                        if(progress(word,guess,c) == 0){
                                f+=1;
                         }
                        falla(f);
                        x = ganar(word,guess);

                        letters[pos] = c;
                        pos++;
                        cout << "Letras: " << letters << endl;
                }
                

                else if (op == 2){
                     cout << "Palabra: ";
                     string c;
                     cin >> c;
                     const char* pal = c.c_str();
                     x = ganar(pal,word);   
                }

                else cout << "Opcion inválida!" << endl;
                cout << " 1. Letra \n 2. Palabra \n Ingrese opcion: ";
                cin >> op;
                
        }

        if (x == false){
                cout << "HAS PERDIDO :(" << endl << "La palabra era ";
                cout << word << endl;
        }

        else {
                cout << "FELICIDADES! Has acertado la palabra :D" << endl;
        }
	
        cout << "Desea jugar de nuevo[1.SI/2.NO]?: ";
        cin >> resp;

        while(resp < 1 || resp > 2){
                cout << "Opción inválida!" << endl;
                cout << "Desea jugar de nuevo[1.SI/2.NO]?: ";
                cin >> resp;
        }
        delete word;
} //fin resp usuario



return 0;
}

bool ganar(const char* str1, const char* str2){
	int num1 = strlen(str1);
	int num2 = strlen(str2);
	int cont = 0;
	for(int i = 0; i < num1; i++){
		if(str1[i] == str2[i]) 
			cont++;
	}
	
	if (cont == num1)
		return true;
	else 
		return false;
	
}

void falla(int num){
	if (num == 1){
	cout << "     [][][][][]" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;         
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "            [[]]" << endl;
	}
	else if (num == 2){
	cout << "     [][][][][]" << endl;
        cout << "             []" << endl;
        cout << "    (o.o)    []" << endl;         
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "            [[]]" << endl;
	}
	else if (num == 3){
	cout << "     [][][][][]" << endl;
        cout << "             []" << endl;
        cout << "   (o.o)     []" << endl;         
        cout << "    |W|      []" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "            [[]]" << endl;
	}
	else if (num == 4){
	cout << "     [][][][][]" << endl;
        cout << "             []" << endl;
        cout << "    (o.o)    []" << endl;         
        cout << "   / |W|     []" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "            [[]]" << endl;
	}
	else if (num == 5){
	cout << "     [][][][][]" << endl;
        cout << "             []" << endl;
        cout << "    (o.o)    []" << endl;         
        cout << "   / |W| \\   []" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "            [[]]" << endl;
	}
	else if (num == 6){
	cout << "     [][][][][]" << endl;
        cout << "             []" << endl;
        cout << "    (o.o)    []" << endl;         
        cout << "   / |W| \\   []" << endl;
        cout << "     |-|     []" << endl;
        cout << "             []" << endl;
        cout << "             []" << endl;
        cout << "            [[]]" << endl;
	}
	else if (num == 7){
	cout << "     [][][][][]" << endl;
        cout << "             []" << endl;
        cout << "    (o.o)    []" << endl;         
        cout << "   / |W| \\   []" << endl;
        cout << "     |-|     []" << endl;
        cout << "    _|       []" << endl;
        cout << "             []" << endl;
        cout << "            [[]]" << endl;
	}
	else if (num == 8){
	cout << "     [][][][][]" << endl;
        cout << "             []" << endl;
        cout << "    (o.o)    []" << endl;         
        cout << "   / |W| \\   []" << endl;
        cout << "     |-|     []" << endl;
        cout << "    _| |_    []" << endl;
        cout << "             []" << endl;
        cout << "            [[]]" << endl;
	}
	else if(num == 9){
	cout << "     [][][][][]" << endl;
        cout << "      |      []" << endl;
        cout << "    (x.x)    []" << endl;         
        cout << "   / |W| \\   []" << endl;
        cout << "     |-|     []" << endl;
        cout << "    _| |_    []" << endl;
        cout << "             []" << endl;
        cout << "            [[]]" << endl;
	}
        else


cout << endl;
}

int progress(const char* w, char* w2, char a){
        int c = 0;
        for (int i = 0; i < strlen(w); i++){
                if(w[i] == a){
                        w2[i] = a;
                        c = 1;
                }

        }
        cout << w2 << endl;
        return c;
}

string palabra(){

        vector<string> v1;
        vector<string> v2;
        vector<string> v3;
        fstream words("diccionario.txt");
        string w;
        int num;

        while(getline(words,w)){
                words >> num >> w;
                if (num == 1)
                        v1.push_back(w);
                else if(num == 2)
                        v2.push_back(w);
                else if(num == 3)
                        v3.push_back(w); 
        }
        srand(time(0));
        int r = rand() % 20;
        if (num == 1)
                return v1[r];
        else if(num == 2)
                return v2[r];
        else if(num == 3)
                return v3[r];

}

