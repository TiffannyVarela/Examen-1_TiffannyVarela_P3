#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <cstdlib>
#include <vector>
using std::vector;


int menu();
//Provisionar la matriz de chars
char** provisionarMatriz(int);

//liberar memoria de la matriz
void liberarMatriz(char**&,int);

//imprimir la matriz
void printMatrix(char**,int);

//leer la matriz
char** readMatriz(char**,int);


int sacar1(string);
int sacar2(string);
int val(int, int);
bool ganannegras(char**, int);
bool gananblancas(char**, int);

int main(){
        int size=11;
        int opc=0;
        char** matriz = NULL;
	string coor, coor2;
	int coorx, coory;
	int contador=0;
	int salir=0;
        do {//inicio do while
                switch(opc=menu()){//inicio switch
                        case 1:
                                matriz = provisionarMatriz(size);
				readMatriz(matriz, size);
				printMatrix(matriz,size);
				do{
					//cout<<"Ingrese coordenada: "<<endl;
					//cin>>coor;
					//cout<<sacar1(coor);
					//cout<<sacar2(coor);
					if(contador==0 || contador%2==0){
						cout<<"Ingrese coordenada (de pieza n): "<<endl;
		                                cin>>coor;
						if(sacar1(coor)==20|| sacar2(coor)==20){
							cout<<"Ingrese una coordenada valida: "<<endl;
							cin>>coor;
							val(sacar1(coor),sacar2(coor));
						}

						if(matriz[sacar1(coor)][sacar2(coor)]!='n'){
							cout<<"Ingrese una coordenada valida (n): "<<endl;
                                                        cin>>coor;
                                                        val(sacar1(coor),sacar2(coor));
						}

						//coorx=sacar1(coor);
						//coory-sacar2(coor);
						cout<<"Ingrese coordenada(donde mover): "<<endl;
	                                        cin>>coor2;
						if(sacar1(coor2)==20|| sacar2(coor2)==20){
                                                        cout<<"Ingrese una coordenada valida: "<<endl;
                                                        cin>>coor2;
                                                        val(sacar1(coor2),sacar2(coor2));
                                                }

						if(matriz[sacar1(coor2)][sacar2(coor2)]!=' '){
                                                        cout<<"Ingrese una coordenada desocupada: "<<endl;
                                                        cin>>coor2;
                                                        val(sacar1(coor2),sacar2(coor2));
                                                }

						if(matriz[sacar1(coor)][sacar2(coor)]=='n' && matriz[sacar1(coor2)][sacar2(coor2)]=='x'){
							cout<<"Ingrese una coordenada valida (esa pieza no puede ir a ese punto): "<<endl;
                                                        cin>>coor2;
                                                        val(sacar1(coor2),sacar2(coor2));
						}

						matriz[sacar1(coor)][sacar2(coor)]=' ';
						matriz[sacar1(coor2)][sacar2(coor2)]='n';
						if(matriz[sacar1(coor2)-1][sacar2(coor2)]=='b' && matriz[sacar1(coor2)+1][sacar2(coor2)]=='b' || matriz[sacar1(coor2)][sacar2(coor2)-1]=='b' && matriz[sacar1(coor2)][sacar2(coor2)+1]=='b'){
							cout<<"Comido"<<endl;
							matriz[sacar1(coor2)][sacar2(coor2)]=' ';
						}
						printMatrix(matriz, size);
						

					}
					contador++;	

					if(contador%2!=0){
                                                cout<<"Ingrese coordenada (de pieza b o pieza w): "<<endl;
                                                cin>>coor;
                                                if(sacar1(coor)==20|| sacar2(coor)==20){
                                                        cout<<"Ingrese una coordenada valida: "<<endl;
                                                        cin>>coor;
                                                        val(sacar1(coor),sacar2(coor));
                                                }

                                                if(matriz[sacar1(coor)][sacar2(coor)]!='b' || matriz[sacar1(coor)][sacar2(coor)]!='w'){
                                                        cout<<"Ingrese una coordenada valida (b o w): "<<endl;
                                                        cin>>coor;
                                                        val(sacar1(coor),sacar2(coor));
                                                }

                                                //coorx=sacar1(coor);
                                                //coory-sacar2(coor);
                                                cout<<"Ingrese coordenada(donde mover): "<<endl;
                                                cin>>coor2;
                                                if(sacar1(coor2)==20|| sacar2(coor2)==20){
                                                        cout<<"Ingrese una coordenada valida: "<<endl;
                                                        cin>>coor2;
                                                        val(sacar1(coor2),sacar2(coor2));
                                                }

                                                if(matriz[sacar1(coor2)][sacar2(coor2)]!=' '){
                                                        cout<<"Ingrese una coordenada desocupada: "<<endl;
                                                        cin>>coor2;
                                                        val(sacar1(coor2),sacar2(coor2));
                                                }

                                                if(matriz[sacar1(coor)][sacar2(coor)]=='b' && matriz[sacar1(coor2)][sacar2(coor2)]=='x'){
                                                        cout<<"Ingrese una coordenada valida (esa pieza no puede ir a ese punto): "<<endl;
                                                        cin>>coor2;
                                                        val(sacar1(coor2),sacar2(coor2));
                                                }

						if(matriz[sacar1(coor)][sacar2(coor)]=='w' && matriz[sacar1(coor2)][sacar2(coor2)]=='x'){
                                                        matriz[sacar1(coor)][sacar2(coor)]=' ';
	                                                matriz[sacar1(coor2)][sacar2(coor2)]='w';

                                                }
						
						if(matriz[sacar1(coor)][sacar2(coor)]=='b'){
                                                	matriz[sacar1(coor)][sacar2(coor)]=' ';
                                                	matriz[sacar1(coor2)][sacar2(coor2)]='b';
						}

						if(matriz[sacar1(coor)][sacar2(coor)]=='w'){
                                                        matriz[sacar1(coor)][sacar2(coor)]=' ';
                                                        matriz[sacar1(coor2)][sacar2(coor2)]='w';
                                                }
                                                if(matriz[sacar1(coor2)-1][sacar2(coor2)]=='n' && matriz[sacar1(coor2)+1][sacar2(coor2)]=='n' || matriz[sacar1(coor2)][sacar2(coor2)-1]=='n' && matriz[sacar1(coor2)][sacar2(coor2)+1]=='n'){
                                                        cout<<"Comido"<<endl;
                                                        matriz[sacar1(coor2)][sacar2(coor2)]=' ';
                                                }
                                                printMatrix(matriz, size);


                                        }

					if(ganannegras(matriz, size)==true){
						salir=-4;
					}

					if(gananblancas(matriz, size)==true){
						salir=-4;
					}

					salir=-4;
				//	Este salir es para pruebas de dolo correr una vez
				}while(salir!=-4);
                                liberarMatriz(matriz, size);
                        break;

                        case 2:
                        cout<<"Fin del programa"<<endl;
                        break;
                }
        }while (opc!=2);

        return 0;
}

int menu(){
        while(true){
        cout<<"MENU"<<endl
        <<"1.- Ejercicio 1"<<endl
        <<"2.- Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        int opcion =0;
        cin>>opcion;
        if(opcion>=1 && opcion<= 2){
                return opcion;
          }
          else{

        cout<<"La opcion elegida no es valida, ingrese 1 o 2"<<endl;
  }
  }//end del while
        return 0;
}


char** provisionarMatriz(int size){
        char** matrix = new char* [size];
        for(int i=0; i<size; i++){
                matrix[i]=new char[size];
        }
        return matrix;
}

char** readMatriz(char** matriz, int size){
	for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
			matriz[i][j]=' ';
		}
	}
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
			matriz[0][0]='x';
			matriz[0][10]='x';
			matriz[10][0]='x';
			matriz[10][10]='x';

                        matriz[0][4]='n';
			matriz[0][5]='n';
			matriz[0][6]='n';
			matriz[1][4]='n';
			matriz[1][6]='n';
			matriz[2][5]='n';
			matriz[4][0]='n';
			matriz[4][1]='n';
			matriz[4][9]='n';
			matriz[4][10]='n';
			matriz[5][0]='n';
			matriz[5][2]='n';
			matriz[5][8]='n';
			matriz[5][10]='n';
			matriz[6][0]='n';
			matriz[6][1]='n';
			matriz[6][9]='n';
			matriz[6][10]='n';
			matriz[8][5]='n';
			matriz[9][4]='n';
			matriz[9][6]='n';
			matriz[10][4]='n';
			matriz[10][5]='n';
			matriz[10][6]='n';
			matriz[3][5]='b';
			matriz[4][4]='b';
			matriz[4][5]='b';
			matriz[4][6]='b';
			matriz[5][3]='b';
			matriz[5][4]='b';
			matriz[5][6]='b';
			matriz[5][7]='b';
			matriz[6][4]='b';
			matriz[6][5]='b';
		       	matriz[6][6]='b';
                        matriz[7][5]='b';
                        matriz[5][5]='w';

                }
        }
        return matriz;
}

void liberarMatriz(char**& matrix, int size){
        for(int i=0;i<size;i++){
                if (matrix[i]!=NULL){
                         delete[]matrix[i];
                        matrix[i]=NULL;
                }
        }

        if(matrix!=NULL){
                delete[] matrix;
                matrix=NULL;
        }
}

void printMatrix(char** matriz, int size){
        for(int i=0;i<size;i++){
                for(int j=0;j<size;j++)
                        cout<<"["<<matriz[i][j]<<"]";

                cout<<endl;
        }
}

int sacar1( string coor){
	int parte1=0;
	string pri;
	string delimiter="-";	
	int found;
	vector<string> separar;
	found = coor.find(delimiter);
        separar.push_back(coor.substr(0,found));
        separar.push_back(coor.substr(found+1,coor.size()));
	pri=separar[0];
	if(pri=="A" || pri=="a"){
		parte1=0;
	}
	else if(pri=="B" || pri=="b"){
                parte1=1;
        }
	else if(pri=="C" || pri=="c"){
                parte1=2;
        }
	else if(pri=="D" || pri=="d"){
                parte1=3;
        }
	else if(pri=="E" || pri=="e"){
                parte1=4;
        }
	else if(pri=="F" || pri=="f"){
                parte1=5;
        }
	else if(pri=="G" || pri=="g"){
                parte1=6;
        }
	else if(pri=="H" || pri=="h"){
                parte1=7;
        }
	else if(pri=="I" || pri=="i"){
                parte1=8;
        }
	else if(pri=="J" || pri=="j"){
                parte1=9;
        }
	else if(pri=="K" || pri=="k"){
                parte1=10;
        }
	else{
		parte1=20;
	}

       return parte1;     
}

int sacar2( string coor){
        int parte2=0;
        string pri;
        string delimiter="-";
        int found;
        vector<string> separar;
        found = coor.find(delimiter);
        separar.push_back(coor.substr(0,found));
        separar.push_back(coor.substr(found+1,coor.size()));
        pri=separar[1];
        if(pri=="0"){
                parte2=0;
        }
	else if(pri=="1"){
                parte2=1;
	}
	else if(pri=="2"){
                parte2=2;
        }
	else if(pri=="3"){
                parte2=3;
        }
	else if(pri=="4"){
		parte2=4;
        }
	else if(pri=="5"){
                parte2=5;
        }
	else if(pri=="6"){
                parte2=6;
        }
	else if(pri=="7"){
                parte2=7;
        }
	else if(pri=="8"){
                parte2=8;
        }
	else if(pri=="9"){
                parte2=9;
        }
	else if(pri=="10"){
                parte2=10;
        }
	else {
		parte2=20;
	}

       return parte2;
}

int val(int x, int y){
	if(x==20){
		return 2;
	}
	if(y==20){
		return 2;
	}
	return 0;
}

bool ganannegras( char** matriz, int size){
	bool resp=false;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(matriz[i][j]=='w'){
				if(matriz[i+1][j]=='n' && matriz[i-1][j]=='n' && matriz[i][j+1]=='n' && matriz[i][j-1]=='n'){
					cout<<"Ganan los negros(n)"<<endl;
					resp=true;
				}
			}
		}
	}
	return resp;
}

bool gananblancas( char** matriz,int size){
	bool resp=false;
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(matriz[0][0]=='w' || matriz [0][10]=='w' || matriz [10][0]=='w' || matriz[10][10]=='w'){
				cout<<"Ganan los blancos"<<endl;
				resp=true;
			}
		}
	}
	return resp;
}
