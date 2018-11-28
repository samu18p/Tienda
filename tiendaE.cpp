#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
//estructura tienda 
struct Tienda{
	char clave[20];//clave del producto 
	char nombre[25];//nombre del producto
	int cantidad;//cantidad de producto
	int precio;//precio del producto
};

// declarando nodo
struct Nodo{
	Tienda producto;//producto variable para la estructura tienda
	Nodo *siguiente;//Nodo tipo puntero siguiente
};

void menu();
void agregarProducto(Tienda &);
void insertarProducto(Nodo *&,Nodo *&,Tienda);
bool vacio(Nodo *);
void mostrarProductos(Nodo *&,Nodo *&,Tienda &);
void venta(Nodo *&,int &);

int main(){
	Nodo *frente=NULL;//nodo que apuntara siempre al frente de la cola
	Nodo *fin=NULL;//nodo que apuntara a el final de la cola
	Nodo *aux=NULL;//auxiliar para imprimir datos sin alterar a nodo frente
	Tienda producto;
	char opcion;//variable para el switch
	int vender;//almacenara la clave del producto que se desea vender
	double caja=0;
	
	do{
		menu();
		cin>>opcion;
		fflush(stdin);//vacia el buffer
    	switch(opcion){
	    	case '1':
		    	agregarProducto(producto);//llamando a funcion para agregar productos
		    	
		    	insertarProducto(frente,fin,producto);//llamando funcion para insertar los nodos a la cola
			    break;
    		case '2':
    			/*cout<<"Introducir la clave del elemento a vender: "; cin>>vender;
	    		venta(producto,vender);*/
		    	break;
    		case '3':
    			cout<<"Mostrando productos."<<endl;
    			aux=frente;//nodo aux toma valor de frente para poder usar todos los datos de elnodo frente
    			cout<<"CLAVE"<<"\tNOMBRE"<<"\t\t\tPRECIO"<<"\t\tCANTIDAD"<<endl;
	    		while(aux !=NULL){
	    			cout<<aux->producto.clave<<"\t"<<aux->producto.nombre<<"\t\t\t"<<aux->producto.precio++<<"\t\t"<<aux->producto.cantidad<<endl;
		  	     	aux=aux->siguiente;//operacion para recorrer los nodos 
				}
				cout<<"Dinero en caja: "<<caja;//imprime dinero en caja
		    	break;
   	        case '4':
   	        	cout<<"Salio del programa..."<<endl;
   	        	break;
      	    default:
      	    	cout<<"\nOpcion invalida."<<endl;
      	    	break;
    	}
    	getch();//pausa para evitar que se limpie pantalla sin que el usuario la vea
    	system("cls");//Limpia pantalla
    }while(opcion !='4');
	return 0;//retorna un 0 si no hay errores
}

//funcion que muestra menu al usuario
void menu(){
	cout<<"\nBienvenido"<<endl;
	cout<<"1.Ingresar producto."<<endl
	    <<"2.Vender producto."<<endl
	    <<"3.Mostrar productos."<<endl
	    <<"4.Salir"<<endl
	    <<"Ingresar una opcion del menu: ";
}

//Pide datos del producto 
void agregarProducto(Tienda &producto){
	cout<<"Ingresar clave del producto: "; cin.getline(producto.clave,20,'\n');
    cout<<"\nIngresar nombre del producto: "; cin.getline(producto.nombre,25,'\n');
   	cout<<"\nIngresar precio del producto: "; cin>>producto.precio;
   	cout<<"\nIngresar cantidad del producto: "; cin>>producto.cantidad;
}

//Inserta los nodos y agrega un nuevo nodo
void insertarProducto(Nodo *&frente,Nodo *&fin,Tienda producto){
	Nodo *nuevo_nodo = new Nodo();//creando nodo
	nuevo_nodo->producto=producto;//insertando la estructura al nuevo nodo 
	nuevo_nodo->siguiente=NULL; //el nodo siguiente se iguala a null no contiene valor
	
	if(vacio(frente)){
		frente = nuevo_nodo;//si la cola esta vacia frente sera = al nuevo nodo creado
	}else{
		fin->siguiente = nuevo_nodo;//si hay mas de un nodo se agregara el nodo siguiente
	}
	fin = nuevo_nodo;//el nuevo nodo introducido siempre sera el nodo final
}

//retorna true si la cola esta vacia o false si hay mas nodos
bool vacio(Nodo *frente){
	return (frente==NULL)? true : false;//si frente = a NULL no hay nodos introducidos 
}

/*void venta(Nodo *&frente,int &n){
	
	if(buscar(n)){
		
	}
	
}*/
