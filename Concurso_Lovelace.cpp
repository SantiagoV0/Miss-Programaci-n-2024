#include <iostream>
#include <cstring>  // Incluye la biblioteca para manipulación de cadenas de caracteres en C (como strcmp y strcpy)
#include <cstdlib> // Incluye la biblioteca estándar de C++ para funciones generales (como rand y srand)
#include <ctime>

using namespace std;

typedef char tcad[50];
const int MAXparticipantes=1000;
const int MAXjurados=6;
typedef char tparticipante[MAXparticipantes];

typedef struct Tproyectos{
				int proyectos_Finalizados;
				int proyectos_Ejecucion;
};

typedef struct Participantes{
				int ID_participante;
				tcad apellido;
				tcad primer_Nombre;
				tcad segundo_Nombre;
				int edad;
				float altura;
				int idiomas;
				tcad continente;
				int lenguaje_PROG;
				int experiencia;
				Tproyectos proyectos;
				int lider_Proyectos; // 0 a (Finalizados + Ejecucion)
				
				
};

typedef struct Jurados{
				tcad apellido;
				tcad nombre;
				tcad empresa;
				tcad cargo;
				int anio_Industria;
				
};

typedef struct habilidades{
				int vestuario;
				int elegancia;
				int  elocuencia;
				float idiomas;
};

typedef struct evaluacion_Candidatas{
				float promedioVestuario;
				float promedioElegancia;
				float promedioElocuencia;
				float promedioIdiomas;
				habilidades habilidades_Candidatas[MAXjurados];
				float puntajeTecnico;
				float puntaje_final_primera_etapa; // Puntaje acumulado de la primera etapa
				float puntaje_final_segunda_etapa; // Puntaje acumulado de la segunda etapa
				float puntaje_final;
};

typedef evaluacion_Candidatas evaluaciones[MAXparticipantes];

typedef Jurados datos_Jurados[MAXjurados];

typedef Participantes datos_Participantes[MAXparticipantes];

typedef float puntajeFinal[MAXparticipantes];


void menu_Principal(int op, datos_Participantes &participante, int &num_participantes, datos_Jurados &jurados, int &num_jurados, evaluaciones &Eval);

//---------------------------CORONACION----------------------------------------
void coronacion(datos_Participantes participante, int num_participantes, evaluaciones &Eval);

//---------------------------PRIMERA ETAPA----------------------------------------
void primera_Etapa(datos_Participantes &participante, int &num_participantes, datos_Jurados &jurados, int &num_jurados,evaluaciones &Eval);
void consultar_Evaluacion(datos_Participantes participantes, int num_participantes, evaluaciones evals);
void mostrar_Finalistas(evaluaciones eval, int numParticipantes);
void evaluar_Candidatas(datos_Participantes participante, int num_participantes, datos_Jurados jurados, int num_jurados,evaluaciones &Eval);
void ordenar_Finalistas(evaluaciones &eval, int num_participantes);

//---------------------------SEGUNDA ETAPA----------------------------------------
void segunda_Etapa(datos_Participantes participante, int num_participantes, datos_Jurados jurados, int num_jurados,evaluaciones &Eval);
void evaluar_Tecnica(datos_Participantes participante, int num_finalistas,datos_Jurados jurados,int  num_jurados,evaluaciones Eval);
void consultar_Evaluacion_Final(datos_Participantes participante, int num_participantes, int num_finalistas,evaluaciones evals);
void calcular_Puntaje_Final(evaluaciones Eval,int num_finalistas);
void mostrar_Semifinalistas(evaluaciones Eval, int num_finalistas);


//-----------------PARTICIPANTES----------------------
void gestion_Participantes(datos_Participantes &participante, int &num_participantes);
void registrar_Participantes(datos_Participantes &participante,int &num_participantes);
int num_Aleatorio(int inf, int sup);
float num_AleatorioAltura(int inf, int sup);
void registro_Manual(datos_Participantes &participante, int &num_participantes);
void registro_Automatico(datos_Participantes &participante,int &num_participantes);
bool validarDuplicados(tcad apellido, tcad primer_nombre, tcad segundo_nombre,int num_participantes,datos_Participantes participante);
void consultar_Participantes(datos_Participantes participante,int num_participantes);
bool consultar_Participantes_Recursivo(datos_Participantes participante, int i, int num_participantes, tcad nombre, tcad segundoNombre, tcad apellido);
void modificar_Participantes(datos_Participantes &participante, int &num_participantes);
void eliminar_Participantes(datos_Participantes &participante, int &num_participantes);
void listar_Participantes(datos_Participantes participante,int &num_participantes);


//-----------------JURADOS----------------------
void gestion_Jurados(datos_Jurados &jurados, int &num_jurados);
void registrar_Jurados(datos_Jurados &jurados, int &num_jurados);
void consultar_Jurados(datos_Jurados jurados, int num_jurados);
bool consultar_Jurados_Recursivo(datos_Jurados jurados, int i, int num_jurados,tcad nombre, tcad apellido);
void modificar_Jurados(datos_Jurados &jurados, int num_jurados);
void eliminar_Jurados(datos_Jurados &jurados, int &num_jurados);
void listar_Jurados(datos_Jurados jurados, int num_jurados);
bool validarDuplicadosJurado(tcad apellido, tcad nombre,int num_jurados,datos_Jurados jurados);

main(){
	datos_Participantes participante;
	datos_Jurados jurados;
	evaluaciones Eval;
	int op,num_participantes = 0, num_jurados=0;
	srand(time(NULL));

	menu_Principal(op, participante, num_participantes,jurados, num_jurados,Eval);
	

}

void menu_Principal(int op, datos_Participantes &participante, int &num_participantes, datos_Jurados &jurados, int &num_jurados, evaluaciones &Eval){
	do{
		cout<<"---------------------------"<<endl;
		cout<<"Bienvenido al Concurso!"<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"1) Gestion de Participantes"<<endl;
		cout<<"2) Gestion de Jurados"<<endl;
		cout<<"3) Primera Etapa"<<endl;
		cout<<"4) Segunda Etapa"<<endl;
		cout<<"5) Coronacion"<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"Digite una opcion: "<<endl;
		cin>>op;
		
		switch(op){
		case 1:
			gestion_Participantes(participante, num_participantes);			
			break;
		case 2:
			gestion_Jurados(jurados, num_jurados);
			break;
		case 3:
			primera_Etapa(participante, num_participantes, jurados, num_jurados,Eval);
			break;
		case 4: 
			segunda_Etapa(participante, num_participantes, jurados, num_jurados,Eval);
			break;
		case 5:
			coronacion(participante, num_participantes, Eval);
			break;
		default:
			cout<<"Por favor, ingrese un valor valido.."<<endl;
			break;
		};
	}while(op!=6);

}

void gestion_Participantes(datos_Participantes &participante, int &num_participantes){
	int op;
	do{
		cout<<"--------------Gestion de Participantes-------------"<<endl;
		cout<<"1) Registrar Participates. "<<endl;
		cout<<"2) Consultar Participantes"<<endl;
		cout<<"3) Modificar Participantes. "<<endl;
		cout<<"4) Elminar Participantes"<<endl;
		cout<<"5) Listar Participantes"<<endl;
		cout<<"6) Volver atras.."<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"Digite una opcion: "<<endl;
		cin>>op;
		switch(op){
			case 1:
				registrar_Participantes(participante,num_participantes);
				break;
			case 2:
				consultar_Participantes(participante,num_participantes);
				break;
			case 3:
				modificar_Participantes(participante,num_participantes);
				break;
			case 4: 
				eliminar_Participantes(participante,num_participantes);
				break;
			case 5:
				listar_Participantes(participante, num_participantes);
				break;
			case 6:
				break;
			default:
				cout<<"Por favor, ingrese un valor valido.."<<endl;
				break;
		};
	} while(op!=6);
}
	
void registrar_Participantes(datos_Participantes &participante,int &num_participantes){
	int op;
	do{
		cout<<"1) Registro Automatico. "<<endl;
		cout<<"2) Registro Manual. "<<endl;
		cout<<"3) Volver. "<<endl;
		cin>>op;
		switch(op){
			case 1: 
				registro_Automatico(participante,num_participantes);
				
				break;
			case 2:
				registro_Manual(participante,num_participantes);
				
				break;
			case 3:
				break;
			default:
				cout<<"valor incorrecto.."<<endl;
				break;
		}
	} while(op!=3);
}

	
	
//--------------------REGISTRO DE PARTICIPANTES--------------------

	
void registro_Automatico(datos_Participantes &participante, int &num_participantes){
	int cant= 0,i, suma_Proyectos,cantDuplicados=0;
	bool Pduplicado;
	
	if(num_participantes >= MAXparticipantes)
		cout<<"Numero maximo de participantes alcanzado.."<<endl;
	else{
		
		tcad apellidos[10] = {"Gomez", "Perez", "Lopez", "Martinez", "Rodriguez",
								"Fernandez", "Garcia", "Gonzalez", "Sanchez", "Ramirez"};
		tcad nombres[10] = {"Maria", "Lucia", "Josefina", "Ana", "Fernanda",
							"Agustina", "Sofia", "Paula", "Luz", "Andrea"};
		tcad continentes[5] = {"Africa", "America", "Asia", "Europa", "Oceania"};
		
		cout << "Ingrese la cantidad de participantes a generar: "<<endl;
		cin >> cant;
		
		if ((num_participantes + cant)>MAXparticipantes)
			cout << "La cantidad excede el límite máximo de participantes." << endl;
		else{
			
			for(i = 0; i < cant; i++){
				participante[i].ID_participante =num_participantes+ 1;
				
				
				strcpy(participante[i].apellido,apellidos[num_Aleatorio(0,9)]);
				strcpy(participante[i].primer_Nombre, nombres[num_Aleatorio(0,9)]);
				strcpy(participante[i].segundo_Nombre,nombres[num_Aleatorio(0,9)]);
				participante[i].edad = num_Aleatorio(21,41);
				participante[i].altura = num_AleatorioAltura(150.0,190.0); 
				participante[i].idiomas = num_Aleatorio(1,7);
				strcpy(participante[i].continente, continentes[num_Aleatorio(0, 4)]);
				participante[i].lenguaje_PROG = num_Aleatorio(1,7);
				participante[i].experiencia = num_Aleatorio(0,21);
				participante[i].proyectos.proyectos_Finalizados = num_Aleatorio(0,26);
				participante[i].proyectos.proyectos_Ejecucion = num_Aleatorio(0,5);
				suma_Proyectos = participante[i].proyectos.proyectos_Finalizados+participante[i].proyectos.proyectos_Ejecucion;
				participante[i].lider_Proyectos = num_Aleatorio(0,suma_Proyectos);
				//validacion de que si no hay experiencia, no hay proyectos_Finalizados ni en proyectos_Ejecucion
				if (participante[i].experiencia == 0) {
					participante[i].proyectos.proyectos_Finalizados = 0;
					participante[i].proyectos.proyectos_Ejecucion = 0;
				}
				Pduplicado = !validarDuplicados(participante[i].apellido, 
												participante[i].primer_Nombre, 
												participante[i].segundo_Nombre,num_participantes,
												participante);
				if (Pduplicado) 
					cantDuplicados++;
				else {
					participante[num_participantes] = participante[i];
					num_participantes++;
				}
			}
			if(cantDuplicados>=1)
				cout << "Hubieron una cantidad de "<< cantDuplicados <<" participantes duplicados, se cancelaron esos registros." << endl;
			
		}
		cout<<"Se realizo correctamente el registro!"<<endl;
	}
	
}

int num_Aleatorio(int inf, int sup){
	return rand() % (sup - inf + 1) + inf;
}


float num_AleatorioAltura(int inf, int sup){
	return (rand() % (sup - inf + 1) + inf)/100.0;
}

	
bool validarDuplicados(tcad apellido, tcad primer_nombre, tcad segundo_nombre,int num_participantes,datos_Participantes participante) {
	int i;
	for (i= 0; i < num_participantes; i++) {
		if (strcmp(participante[i].apellido, apellido) == 0 &&
			strcmp(participante[i].primer_Nombre, primer_nombre) == 0 &&
			strcmp(participante[i].segundo_Nombre, segundo_nombre) == 0) {
			return false;
		}
	}
	return true;
}

void registro_Manual(datos_Participantes &participante, int &num_participantes){
	int cant= 0,i, suma_Proyectos;
	
	if(num_participantes >= MAXparticipantes)
		cout<<"Numero maximo de participantes alcanzado.."<<endl;
	else{
		cout << "Ingrese la cantidad de participantes a generar: "<<endl;
		cin >> cant;
		
		if ((num_participantes + cant)>MAXparticipantes)
			cout << "La cantidad excede el límite máximo de participantes." << endl;
		else{
			for(i = 0; i < cant; i++){
				participante[i].ID_participante =num_participantes+ 1;
				
				cout<<"Ingrese su apellido: "<<endl;
				fflush(stdin);
				gets(participante[i].apellido);
				cout<<"Ingrese su primer nombre: "<<endl;
				fflush(stdin);
				gets(participante[i].primer_Nombre);
				cout<<"Ingrese su segundo nombre: "<<endl;
				gets(participante[i].segundo_Nombre);
				cout<<"Ingrese su edad: "<<endl;
				cin>>participante[i].edad;
				cout<<"Ingrese su altura: "<<endl;
				cin>>participante[i].altura;
				cout<<"Ingrese la cantidad de idiomas: "<<endl;
				cin>>participante[i].idiomas;
				cout<<"Ingrese su Continente: "<<endl;
				fflush(stdin);
				gets(participante[i].continente);
				cout<<"Ingrese la cantidad de Lenguajes de programacion: "<<endl;
				cin>>participante[i].lenguaje_PROG;
				cout<<"Ingrese su experiencia: "<<endl;
				cin>>participante[i].experiencia;
				cout<<"Ingrese la cantidad de proyectos Finalizados: "<<endl;
				cin>>participante[i].proyectos.proyectos_Finalizados;
				cout<<"Ingrese la cantidad de proyectos en Ejecucion: "<<endl;
				cin>>participante[i].proyectos.proyectos_Ejecucion;
				cout<<"Ingrese la cantidad de proyectos dirigidos: "<<endl;
				cin>>participante[i].lider_Proyectos;
				
				if (participante[i].experiencia == 0) {
					participante[i].proyectos.proyectos_Finalizados = 0;
					participante[i].proyectos.proyectos_Ejecucion = 0;
				}
				
				bool Pduplicado = !validarDuplicados(participante[i].apellido, participante[i].primer_Nombre, participante[i].segundo_Nombre,num_participantes,participante);
				if (Pduplicado) 
					cout << "Participante duplicado, registro cancelado." << endl;
				else {
					participante[num_participantes] = participante[i];
					num_participantes++;
				}
			}
			cout<<"Se realizo correctamente el registro!"<<endl;	
		}
		
	}
}
	
	//--------------------FIN DE REGISTRO DE PARTICIPANTES--------------------
	
	
	//--------------------CONSULTAR DE PARTICIPANTES--------------------------
	
void consultar_Participantes(datos_Participantes participante,int num_participantes) {
	tcad nombre, segundoNombre, apellido;
	
	if (num_participantes == 0) {
		cout << "El registro esta vacio.." << endl;
	} else {
		cout << "Ingrese el nombre de la participante: " << endl;
		fflush(stdin);
		gets(nombre);
		cout << "Ingrese el segundo nombre de la participante: " << endl;
		fflush(stdin);
		gets(segundoNombre);
		cout << "Ingrese el apellido de la participante: " << endl;
		fflush(stdin);
		gets(apellido);
		
		// Llama a la función recursiva para buscar a la participante
		if (!consultar_Participantes_Recursivo(participante, 0, num_participantes, nombre, segundoNombre, apellido)) {
			// Si la función recursiva retorna false, informa al usuario que no se encontró la participante
			cout << "La participante " << nombre << " " << segundoNombre << " " << apellido << " no se encontro." << endl;
		}
	}
}

bool consultar_Participantes_Recursivo(datos_Participantes participante, int i, int num_participantes, tcad nombre, tcad segundoNombre, tcad apellido) {
	if (i >= num_participantes) {
		return false;
	} else {
		if (strcmp(participante[i].apellido, apellido) == 0 && strcmp(participante[i].primer_Nombre, nombre) == 0 && strcmp(participante[i].segundo_Nombre, segundoNombre) == 0) {
			cout << "Se encontro su participante!" << endl;
			cout << "----------------------------" << endl;
			cout << "ID: " << participante[i].ID_participante << endl;
			cout << "Apellido: " << participante[i].apellido << endl;
			cout << "Primer Nombre: " << participante[i].primer_Nombre << endl;
			cout << "Segundo Nombre: " << participante[i].segundo_Nombre << endl;
			cout << "Edad: " << participante[i].edad << endl;
			cout << "Altura: " << participante[i].altura << endl;
			cout << "Cantidad de Idiomas: " << participante[i].idiomas << endl;
			cout << "Continente: " << participante[i].continente << endl;
			cout << "Cantidad de Lenguajes de Programación: " << participante[i].lenguaje_PROG << endl;
			cout << "Experiencia: " << participante[i].experiencia << endl;
			cout << "Proyectos Finalizados: " << participante[i].proyectos.proyectos_Finalizados << endl;
			cout << "Proyectos en Ejecución: " << participante[i].proyectos.proyectos_Ejecucion << endl;
			cout << "Proyectos Liderados: " << participante[i].lider_Proyectos << endl;
			cout << "---------------------------" << endl;
			return true; // Retorna true para indicar que se encontró la participante
		} else {
			// Si no se encuentra una coincidencia, llama recursivamente a sí misma con el siguiente índice (i + 1)
			return consultar_Participantes_Recursivo(participante, i + 1, num_participantes, nombre, segundoNombre, apellido);
		}
	}
}



	//--------------------FIN DE CONSULTAR DE PARTICIPANTES--------------------------




	//-----------------------MODIFICAR PARTICIPANTES--------------------------------
void modificar_Participantes(datos_Participantes &participante, int &num_participantes) {
	int i,edadNueva,opcion,idiomasNuevo,cantLengNuevo,expNuevo,proyecF, proyecE, proyectL;
	float alturaNueva;
	tcad nombre, apellido,segundoNombre,apellidoNuevo,nombreNuevo,segundoNnuevo;
	tcad continenteNuevo;
	
	if(num_participantes==0)
		cout<<"Aun no hay participantes.."<<endl;
	else{
		cout<<"Ingrese el nombre de la participante: "<<endl;
		fflush(stdin);
		gets(nombre);
		cout<<"Ingrese el segundo nombre de la participante: "<<endl;
		fflush(stdin);
		gets(segundoNombre);
		cout<<"Ingrese el apellido de la participante: "<<endl;
		fflush(stdin);
		gets(apellido);
		
		for (i=0;i<num_participantes;i++){
			if(strcmp(participante[i].apellido,apellido)==0 && strcmp(participante[i].primer_Nombre,nombre)==0 &&strcmp(participante[i].segundo_Nombre,segundoNombre)==0){
				
				do{
					cout << "---------------------------------" <<endl;
					cout << "1) Apellido " <<endl;
					cout << "2) Primer Nombre " <<endl;
					cout << "3) Segundo Nombre " <<endl;
					cout << "4) Edad " <<endl;
					cout << "5) Altura " <<endl;
					cout << "6) Cantidad de Idiomas "<< endl;
					cout << "7) Continente " <<endl;
					cout << "8) Cantidad de Lenguajes de Programación " << endl;
					cout << "9) Experiencia " <<endl;
					cout << "10) Proyectos Finalizados " <<endl;
					cout << "11) Proyectos en Ejecución " <<endl;
					cout << "12) Proyectos Liderados " <<endl;
					cout << "13) Volver atras.."<<endl;
					cout << "----------------------------------" <<endl;
					cout <<"Que desea modificar? Eliga un numero como opcion: "<<endl;
					cin >> opcion;
					switch(opcion){
						case 1: 
							cout<<"Como sera su nuevo apellido? escriba: "<<endl;
							fflush(stdin);
							gets(apellidoNuevo);
							strcpy(participante[i].apellido,apellidoNuevo);
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 2:
							cout<<"Como sera su nuevo primer nombre? escriba: "<<endl;
							fflush(stdin);
							gets(nombreNuevo);
							strcpy(participante[i].primer_Nombre,nombreNuevo);
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 3:
							cout<<"Como sera su nuevo segundo nombre? escriba: "<<endl;
							fflush(stdin);
							gets(segundoNnuevo);
							strcpy(participante[i].segundo_Nombre,segundoNnuevo);
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 4:
							cout<<"Como sera su nueva edad: "<<endl;
							cin>>edadNueva;
							participante[i].edad = edadNueva;
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 5:
							cout<<"Como sera su nueva altura: (escriba la altura con un '.')"<<endl;
							cin>>alturaNueva;
							participante[i].altura = alturaNueva;
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 6:
							cout<<"Cuentos de Idiomas: "<<endl;
							cin>>idiomasNuevo;
							participante[i].idiomas = idiomasNuevo;
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 7:
							cout<<"Cual es el continente nuevo: "<<endl;
							fflush(stdin);
							gets(continenteNuevo);
							strcpy(participante[i].continente,continenteNuevo);
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 8:
							cout<<"Cuantos lenguajes de programacion: "<<endl;
							cin>>cantLengNuevo;
							participante[i].lenguaje_PROG = cantLengNuevo;
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 9:
							cout<<"Años de expeciencia nuevo: "<<endl;
							cin>>expNuevo;
							participante[i].experiencia= expNuevo;
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 10:
							cout<<"Proyectos Finalizados nuevos: "<<endl;
							cin>>proyecF;
							participante[i].proyectos.proyectos_Finalizados = proyecF;
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 11:
							cout<<"Proyectos en Ejecucion nuevos: "<<endl;
							cin>>proyecE;
							participante[i].proyectos.proyectos_Ejecucion = proyecE;
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 12:
							cout<<"Cuantos Proyectos Liderados: "<<endl;
							cin>>proyectL;
							participante[i].lider_Proyectos = proyectL;
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 13:
							break;
						default:
							cout<<"valor incorrecto.."<<endl;
							break;
					}
					if (expNuevo==0) {
						participante[i].proyectos.proyectos_Finalizados = 0;
						participante[i].proyectos.proyectos_Ejecucion = 0;
					}
					
				} while(opcion!=13);

					
				
			}
		}
	}
}
	

//-----------------------FIN DE MODIFICAR PARTICIPANTES--------------------------------


//-----------------------BORRAR PARTICIPANTES--------------------------------

void eliminar_Participantes(datos_Participantes &participante, int &num_participantes) {
	int i, j;
	tcad nombre, apellido,segundoNombre;
	bool encontrado = false;
	
	if (num_participantes == 0) {
		cout << "El registro está vacIo." << endl;
	} 
	else {
		cout<<"Ingrese el nombre de la participante: "<<endl;
		fflush(stdin);
		gets(nombre);
		cout<<"Ingrese el segundo nombre de la participante: "<<endl;
		fflush(stdin);
		gets(segundoNombre);
		cout<<"Ingrese el apellido de la participante: "<<endl;
		fflush(stdin);
		gets(apellido);
		
		for (i = 0; i < num_participantes; i++) {
			if(strcmp(participante[i].apellido,apellido)==0 && strcmp(participante[i].primer_Nombre,nombre)==0 &&strcmp(participante[i].segundo_Nombre,segundoNombre)==0){
				encontrado = true;
				for (j = i; j < num_participantes - 1; j++) {
					participante[j] = participante[j + 1];
				}
				num_participantes--;
				cout << "Participante eliminado!" << endl;
			}
		}
		if (!encontrado) 
			cout << "La participante no se encontro." << endl;
	}
}

//-----------------------FIN DE BORRAR PARTICIPANTES--------------------------------



//--------------------LISTAR PARTICIPANTES--------------------------
void listar_Participantes(datos_Participantes participante, int &num_participantes){
	int i;
	if(num_participantes==0)
		cout<<"No hay participantes aun.."<<endl;
	else{
		for(i=0;i<num_participantes;i++){
			cout << "---------------------------" << endl;
			cout << "ID: " << participante[i].ID_participante << endl;
			cout << "Apellido: " << participante[i].apellido << endl;
			cout << "Primer Nombre: " << participante[i].primer_Nombre << endl;
			cout << "Segundo Nombre: " << participante[i].segundo_Nombre << endl;
			cout << "Edad: " << participante[i].edad << endl;
			cout << "Altura: " << participante[i].altura <<" mts"<< endl;
			cout << "Cantidad de Idiomas: " << participante[i].idiomas << endl;
			cout << "Continente: " << participante[i].continente << endl;
			cout << "Cantidad de Lenguajes de Programación: " << participante[i].lenguaje_PROG << endl;
			cout << "Experiencia: " << participante[i].experiencia << endl;
			cout << "Proyectos Finalizados: " << participante[i].proyectos.proyectos_Finalizados << endl;
			cout << "Proyectos en Ejecución: " << participante[i].proyectos.proyectos_Ejecucion << endl;
			cout << "Proyectos Liderados: " << participante[i].lider_Proyectos << endl;
			cout << "---------------------------" << endl;
		}
	}
}


	//--------------------FIN DE LISTAR PARTICIPANTES------------------------------------	
	
	
	
	
//--------------------GESTION DE JURADOS--------------------
void gestion_Jurados(datos_Jurados &jurados, int &num_jurados){
	int op;
	do{
		cout<<"------------Gestion de Jurados---------------"<<endl;
		cout<<"1) Registrar Jurados. "<<endl;
		cout<<"2) Consultar Jurados. "<<endl;
		cout<<"3) Modificar Jurados. "<<endl;
		cout<<"4) Elminar Jurados. "<<endl;
		cout<<"5) Listar todos los jurados. "<<endl;
		cout<<"6) Volver atras.. "<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"Digite una opcion: "<<endl;
		cin>>op;
		switch(op)
		{
		case 1:
			registrar_Jurados(jurados, num_jurados);
			break;
		case 2:
			consultar_Jurados(jurados, num_jurados);
			break;
		case 3:
			modificar_Jurados(jurados, num_jurados);
			break;
		case 4: 
			eliminar_Jurados(jurados, num_jurados);
			break;
		case 5:
			listar_Jurados(jurados, num_jurados);
			break;
		case 6:
			break;
		default:
			cout<<"Por favor, ingrese un valor valido.."<<endl;
			break;
		};
	} while(op!=6);
}

	
//----------------------FIN DE GESTION DE JURADOS------------------------
	

	
//----------------------REGISTRO DE JURADOS------------------------------
	

	void registrar_Jurados(datos_Jurados &jurados, int &num_jurados) {
		int cant= 0,i, suma_Proyectos;
		
		if(num_jurados >= MAXjurados)
			cout<<"Numero maximo de jurados alcanzado.."<<endl;
		else{
			
			cout << "Ingrese la cantidad de jurados a generar: "<<endl;
			cin >> cant;
			while(cant<3 || cant>6){
				cout<<"Tiene que ser mayor a 3 jurados, hasta 6 maximo."<<endl;
				cout << "Ingrese la cantidad de jurados a generar: "<<endl;
				cin >> cant;
			}
			
			for(i = 0; i < cant; i++){
				
				cout<<"Ingrese su apellido: "<<endl;
				fflush(stdin);
				gets(jurados[i].apellido);
				
				cout<<"Ingrese su nombre: "<<endl;
				fflush(stdin);
				gets(jurados[i].nombre);
				
				cout<<"Ingrese su empresa: "<<endl;
				fflush(stdin);
				gets(jurados[i].empresa);
				
				cout<<"Ingrese el cargo: "<<endl;
				fflush(stdin);
				gets(jurados[i].cargo);
				
				cout<<"Ingrese la cantidad de años en la industria: "<<endl;
				cin>>jurados[i].anio_Industria;

				
				bool Pduplicado = !validarDuplicadosJurado(jurados[i].apellido, jurados[i].nombre,num_jurados,jurados);
				if (Pduplicado) 
					cout << "Participante duplicado, registro cancelado." << endl;
				else {
					jurados[num_jurados] = jurados[i];
					num_jurados++;
				}
				
			}
			
		}
	}
	
	bool validarDuplicadosJurado(tcad apellido, tcad nombre,int num_jurados,datos_Jurados jurados) {
		int i;
		for (i= 0; i < num_jurados; i++) {
			if (strcmp(jurados[i].apellido, apellido) == 0 &&
				strcmp(jurados[i].nombre, nombre) == 0) {
				return false;
			}
		}
		return true;
	}
	//----------------------FIN DE REGISTRO DE JURADOS------------------------
	
	
	//----------------------CONSULTA DE JURADOS------------------------
	bool consultar_Jurados_Recursivo(datos_Jurados jurados, int i, int num_jurados,tcad nombre, tcad apellido) {

		if (i >= num_jurados) {
			return false;
		}
		else{
			if (strcmp(jurados[i].apellido, apellido) == 0 && strcmp(jurados[i].nombre, nombre) == 0) {
				cout << "---------------------------" << endl;
				cout << "Apellido: " << jurados[i].apellido << endl;
				cout << "Primer Nombre: " << jurados[i].nombre << endl;
				cout << "Empresa: " << jurados[i].empresa << endl;
				cout << "Cargo: " << jurados[i].cargo << endl;
				cout << "cantidad de años en la industria: " << jurados[i].anio_Industria << endl;
				cout << "---------------------------" << endl;
				return true;
			} else {
				return consultar_Jurados_Recursivo(jurados, i + 1, num_jurados, nombre, apellido);
			}
		}
		
	}
	
	void consultar_Jurados(datos_Jurados jurados, int num_jurados) {
		tcad nombre, apellido;
		
		if (num_jurados == 0) {
			cout << "El registro de jurados esta vacio.." << endl;
		} else {
			cout << "Ingrese el nombre del jurado: " << endl;
			fflush(stdin);
			gets(nombre);
			cout << "Ingrese el apellido del jurado: " << endl;
			fflush(stdin);
			gets(apellido);
			
			if (!consultar_Jurados_Recursivo(jurados, 0, num_jurados, nombre, apellido)) {
				cout << "El juradp: " << nombre << " " << apellido << " no se encontro." << endl;
			}
		}
	}
	
	
	//----------------------FIN DE CONSULTA DE JURADOS------------------------
	
	
	
	//----------------------MODIFICAR JURADOS------------------------
	
	void modificar_Jurados(datos_Jurados &jurados, int num_jurados) {
		
		int i,opcion,cantNueva;
		tcad nombre, apellido,apellidoNuevo,nombreNuevo,empresaNuevo,cargoNuevo;
		
		if(num_jurados==0)
			cout<<"Aun no hay jurados.."<<endl;
		else{
			cout<<"Ingrese el nombre del jurado: "<<endl;
			fflush(stdin);
			gets(nombre);
			cout<<"Ingrese el apellido del jurado: "<<endl;
			fflush(stdin);
			gets(apellido);
			
			for (i=0;i<num_jurados;i++){
				if(strcmp(jurados[i].apellido,apellido)==0 && strcmp(jurados[i].nombre,nombre)==0){
					
					do{
						cout << "-----------------------" <<endl;
						cout << "1) Apellido " <<endl;
						cout << "2) Nombre " <<endl;
						cout << "3) Empresa " <<endl;
						cout << "4) Cargo " <<endl;
						cout << "5) cantidad de años en la industria " <<endl;
						cout << "6) Volver atras..." <<endl;
						cout << "-----------------------" <<endl;
						cout << "Eliga una opcion: " <<endl;
						cin >> opcion;
						switch(opcion){
						case 1: 
							cout<<"Como sera su nuevo apellido? escriba: "<<endl;
							fflush(stdin);
							gets(apellidoNuevo);
							strcpy(jurados[i].apellido,apellidoNuevo);
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 2:
							cout<<"Como sera su nuevo nombre? escriba: "<<endl;
							fflush(stdin);
							gets(nombreNuevo);
							strcpy(jurados[i].nombre,nombreNuevo);
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 3:
							cout<<"Como sera su nueva empresa: "<<endl;
							fflush(stdin);
							gets(empresaNuevo);
							strcpy(jurados[i].empresa,empresaNuevo);
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 4:
							cout<<"Como sera su nuevo cargo: "<<endl;
							fflush(stdin);
							gets(cargoNuevo);
							strcpy(jurados[i].cargo,cargoNuevo);
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 5:
							cout<<"cantidad nueva de años en la industria: "<<endl;
							cin>>cantNueva;
							jurados[i].anio_Industria = cantNueva;
							cout<<"Modificacion hecha!"<<endl;
							break;
						case 6:
							break;
						default:
							cout<<"valor incorrecto.."<<endl;
							break;
						}
					} while(opcion!=6);
					
					
					
				}
			}
		}
	}
	
	
	
//--------------------------FIN MODIFICAR JURADOS-----------------------------
	
	
//------------------------------ELIMINAR JURADOS-----------------------------
	void eliminar_Jurados(datos_Jurados &jurados, int &num_jurados) {
		int i, j;
		tcad nombre, apellido;
		bool encontrado = false;
		
		if (num_jurados == 0) {
			cout << "El registro de jurados está vacio." << endl;
		} 
		else {
			cout << "Ingrese el nombre del jurado a eliminar: " << endl;
			fflush(stdin);
			gets(nombre);
			cout << "Ingrese el apellido del jurado a eliminar: " << endl;
			fflush(stdin);
			gets(apellido);
			
			for (i = 0; i < num_jurados; i++) {
				if (strcmp(jurados[i].apellido, apellido) == 0 && strcmp(jurados[i].nombre, nombre) == 0) {
					encontrado = true;
					for (j = i; j < num_jurados - 1; j++) {
						jurados[j] = jurados[j + 1];
					}
					num_jurados--;
					cout << "Jurado eliminado!" << endl;
				}
			}
			if (!encontrado) 
				cout << "El Jurado no se encontro." << endl;
		}
	}

//------------------------------FIN DE ELIMINAR JURADOS-----------------------------
	
	
	
//------------------------------ISTAR JURADOS-----------------------------
	void listar_Jurados(datos_Jurados jurados, int num_jurados) {
		int i;
		if(num_jurados==0)
			cout<<"No hay jurados aun.."<<endl;
		else{
			for(i=0;i<num_jurados;i++){
				cout << "---------------------------" << endl;
				cout << "Apellido: " << jurados[i].apellido << endl;
				cout << "Nombre: " << jurados[i].nombre << endl;
				cout << "Empresa: " << jurados[i].empresa << endl;
				cout << "Cargo: " << jurados[i].cargo << endl;
				cout << "Cantidad de años en la industria: " << jurados[i].anio_Industria << endl;
				cout << "---------------------------" << endl;
			}
		}
	}

	
//------------------------------FIN DE LISTAR JURADOS-----------------------------	
	
	
	
//---------------------------------PRIMERA ETAPA---------------------------------
	void primera_Etapa(datos_Participantes &participante, int &num_participantes, datos_Jurados &jurados, int &num_jurados,evaluaciones &Eval){
		int opcion;
		bool etapaCompleta = false;
		
		if(num_participantes==0 || num_jurados ==0)
			cout<<"Aun no se registraron participantes y jurados para empezar.."<<endl;
		else{
			
			do{
				cout << "---------------------------" << endl;
				cout << "--------PRIMERA ETAPA----- " << endl;
				cout << "---------------------------" << endl;
				cout << "1) Evaluar candidatas " << endl;
				cout << "2) Consultar evaluacion " << endl;
				cout << "3) Mostrar Finalistas" << endl;
				cout << "4) Salir " << endl;
				cout << "---------------------------" << endl;
				cout << "Elige una opcion: " << endl;
				cin>>opcion;
				switch(opcion){
					case 1: 
						evaluar_Candidatas(participante, num_participantes, jurados, num_jurados, Eval);
						cout << "Evaluación de candidatas completada." << endl;
						break;
					case 2:
						consultar_Evaluacion(participante, num_participantes, Eval);
						break;
					case 3:
						mostrar_Finalistas(Eval, num_participantes);
						break;
					case 4:
						etapaCompleta = true;
						break;
					default:
						cout<<"valor incorrecto.."<<endl;
						break;
					}
			} while(opcion!=4);
		}
	}

		void evaluar_Candidatas(datos_Participantes participante, int num_participantes, datos_Jurados jurados, int num_jurados, evaluaciones &Eval) {
			int i, j;
			float sumaVestuario, sumaElegancia, sumaElocuencia, sumaIdiomas;
			srand(time(0));
			
			if (num_participantes == 0 || num_jurados == 0) {
				cout << "No hay participantes o jurados registrados." << endl;
			}
			else{
				for (i = 0; i < num_participantes; i++) {
					sumaVestuario = 0, sumaElegancia = 0, sumaElocuencia = 0, sumaIdiomas = 0;
					cout << "Evaluando participante " << i + 1 << endl;
					for (j = 0; j < num_jurados; j++) {
						Eval[i].habilidades_Candidatas[j].vestuario = rand() % 101;
						Eval[i].habilidades_Candidatas[j].elegancia = rand() % 101;
						Eval[i].habilidades_Candidatas[j].elocuencia = rand() % 101;
						float n= participante[i].idiomas;
						Eval[i].habilidades_Candidatas[j].idiomas = (n/6*100);
						
						
						cout << "Jurado " << j + 1 << " evaluó con vestuario: " << Eval[i].habilidades_Candidatas[j].vestuario
							<< ", elegancia: " << Eval[i].habilidades_Candidatas[j].elegancia
							<< ", elocuencia: " << Eval[i].habilidades_Candidatas[j].elocuencia
							<< ", idiomas: " << Eval[i].habilidades_Candidatas[j].idiomas << endl;
						
						sumaVestuario += Eval[i].habilidades_Candidatas[j].vestuario;
						sumaElegancia += Eval[i].habilidades_Candidatas[j].elegancia;
						sumaElocuencia += Eval[i].habilidades_Candidatas[j].elocuencia;
						sumaIdiomas += Eval[i].habilidades_Candidatas[j].idiomas;
					}
					
					Eval[i].promedioVestuario = sumaVestuario / num_jurados;
					Eval[i].promedioElegancia = sumaElegancia / num_jurados;
					Eval[i].promedioElocuencia = sumaElocuencia / num_jurados;
					Eval[i].promedioIdiomas = sumaIdiomas / num_jurados;
					
					Eval[i].puntaje_final_primera_etapa= Eval[i].promedioVestuario +Eval[i].promedioElegancia+Eval[i].promedioElocuencia+Eval[i].promedioIdiomas;
					
					cout << "Promedios para participante " << i + 1 << ": Vestuario: " << Eval[i].promedioVestuario
						<< ", Elegancia: " << Eval[i].promedioElegancia
						<< ", Elocuencia: " << Eval[i].promedioElocuencia
						<< ", Idiomas: " << Eval[i].promedioIdiomas << endl
						<< ", Puntaje total: " << Eval[i].puntaje_final_primera_etapa << endl;
				}
			}
		
		}
		
		
	void consultar_Evaluacion(datos_Participantes participantes, int num_participantes,evaluaciones evals){
		tcad nombre, apellido,segundoNombre;
		bool cantidataEncontrada;
		int i,contCandidatas=0;
		
		cout << "Ingrese el nombre de la participante: ";
		fflush(stdin);
		gets(nombre);
		cout << "Ingrese el segundo nombre de la participante: ";
		fflush(stdin);
		gets(segundoNombre);
		cout << "Ingrese el apellido de la participante: ";
		fflush(stdin);
		gets(apellido);
		
		cantidataEncontrada=false;
		for (i = 0; i < num_participantes; i++) {
			if (strcmp(participantes[i].primer_Nombre, nombre) == 0 && strcmp(participantes[i].apellido, apellido) == 0 && strcmp(participantes[i].segundo_Nombre, segundoNombre) == 0) {
				cantidataEncontrada = true;
				cout << "Evaluación de " << nombre << " " << apellido << " es:" << endl;
				cout << "Promedio Vestuario: " << evals[i].promedioVestuario << endl;
				cout << "Promedio Elegancia: " << evals[i].promedioElegancia << endl;
				cout << "Promedio Elocuencia: " << evals[i].promedioElocuencia << endl;
				cout << "Promedio Idiomas: " << evals[i].promedioIdiomas << endl;
				
			}
			else
				contCandidatas++;
		}
		if(cantidataEncontrada==false)
			cout<<"Se busco en una cantindad de "<< contCandidatas << " candidatas y no se la encontró."<<endl;
	}
		
		
	void mostrar_Finalistas(evaluaciones eval, int num_participantes) {
		int i, j;
		evaluacion_Candidatas aux;
		
		// Ordenacion por insercion
		for (i = 1; i < num_participantes; i++) {
			aux = eval[i];
			j = i - 1;
			
			while (j >= 0 && eval[j].puntaje_final_primera_etapa < aux.puntaje_final_primera_etapa) {
				eval[j + 1] = eval[j];
				j = j - 1;
			}
			eval[j + 1] = aux;
		}
		
		// Mostrar las primeras 20 finalistas
		cout << "Finalistas:" << endl;
		for (i = 0; i < num_participantes && i < 20; i++) {
			cout << "Participante " << i + 1 << ": Vestuario: " << eval[i].promedioVestuario 
				<< ", Elegancia: " << eval[i].promedioElegancia 
				<< ", Elocuencia: " << eval[i].promedioElocuencia 
				<< ", Idiomas: " << eval[i].promedioIdiomas 
				<< ", Puntaje Final Primera Etapa: " << eval[i].puntaje_final_primera_etapa << endl;
		}
		

	}


	
//---------------------------------FIN DE LA PRIMERA ETAPA---------------------------------
		
		
//---------------------------------SEGUNDA ETAPA-------------------------------------------
		
	void segunda_Etapa(datos_Participantes participante, int num_participantes, datos_Jurados jurados, int num_jurados,evaluaciones &Eval){
		int opcion;
		bool etapaCompleta = false;
		int num_finalistas = 20;
		evaluaciones Finalistas;
		//int finalistas[20];
		if(num_participantes < num_finalistas || num_jurados == 0)
			cout<<"Aun no se han registrado suficientes participantes y jurados para la segunda etapa.."<<endl;
		else{
			// Ordenar y mostrar finalistas
			mostrar_Finalistas(Eval, num_participantes);
			

			do{
				cout<< "---------------------------" << endl;
				cout<< "--------SEGUNDA ETAPA-----" << endl;
				cout<< "---------------------------" << endl;
				cout<< "1) Evaluar candidatas. " << endl;
				cout<< "2) Consultar evaluación tecnica" << endl;
				cout<< "3) Salir" << endl;
				cout<< "---------------------------" << endl;
				cout<< "Elige una opcion: " << endl;
				cin>> opcion;
				switch(opcion){
					case 1: 
						evaluar_Tecnica(participante, num_finalistas, jurados, num_jurados, Eval);
						cout << "Evaluación técnica de candidatas completada." << endl;
						break;
					case 2:
						consultar_Evaluacion_Final(participante, num_participantes, num_finalistas,Eval);
						break;
					case 3:
						etapaCompleta = true;
						break;
					default:
						cout << "Valor incorrecto.." << endl;
						break;
				}
			} while(opcion!=3);
		}
			
	}
	
	void evaluar_Tecnica(datos_Participantes participante, int num_finalistas,datos_Jurados jurados,int  num_jurados,evaluaciones Eval){
		int i,total_proyectos,proyectosFinalizados,proyectosEjecucion;
		float porcentaje_liderados;
		
		for (i = 0; i < num_finalistas; i++) {
			float puntajeTotal=0;
			
			cout << "  "<< endl;
			cout << "--------------------------------"<< endl;
			cout << "Evaluando participante finalista n°: " << i+1 << endl;
			cout << "--------------------------------"<< endl;
			cout << "Evaluación de " << participante[i].primer_Nombre <<" "<< participante[i].segundo_Nombre  <<" "<< participante[i].apellido <<" "<< " es:" << endl;
			
			// Lenguajes de Programación
			if (participante[i].lenguaje_PROG >= 9 && participante[i].lenguaje_PROG <= 10) 
				puntajeTotal += 100;
			else{
				if (participante[i].lenguaje_PROG >= 6 && participante[i].lenguaje_PROG <= 8)
					puntajeTotal += 75;
				else{
					if (participante[i].lenguaje_PROG >= 4 && participante[i].lenguaje_PROG <= 5)
						puntajeTotal += 50;
					else{
						if (participante[i].lenguaje_PROG >= 1 && participante[i].lenguaje_PROG <= 3)
							puntajeTotal += 25;
						else
							puntajeTotal += 0;
					}
				}
			}
			cout << "Lenguajes de Programación: " << puntajeTotal << endl;
			// Experiencia
			if (participante[i].experiencia >= 16 && participante[i].experiencia <= 20) 
				puntajeTotal += 100;
			else{
				if (participante[i].experiencia >= 11 && participante[i].experiencia <= 15)
					puntajeTotal += 75;
				else{
					if (participante[i].experiencia >= 6 && participante[i].experiencia <= 10)
						puntajeTotal += 50;
					else{
						if (participante[i].experiencia >= 1 && participante[i].experiencia <= 5)
							puntajeTotal += 25;
						else
							puntajeTotal += 0;
					}
				}
			}
			cout << "Experiencia: " << puntajeTotal << endl;
			// Proyectos Finalizados
			if (participante[i].proyectos.proyectos_Finalizados >= 21 && participante[i].proyectos.proyectos_Finalizados <= 25) 
				puntajeTotal += 100;
			else{
				if (participante[i].proyectos.proyectos_Finalizados >= 13 && participante[i].proyectos.proyectos_Finalizados <= 20)
					puntajeTotal += 75;
				else{
					if (participante[i].proyectos.proyectos_Finalizados >= 7 && participante[i].proyectos.proyectos_Finalizados <= 12)
						puntajeTotal += 50;
					else{
						if (participante[i].proyectos.proyectos_Finalizados >= 1 && participante[i].proyectos.proyectos_Finalizados <= 6)
							puntajeTotal += 25;
						else
							puntajeTotal += 0;
					}
				}
			}
			cout << "Proyectos Finalizados: " << puntajeTotal << endl;
			// Proyectos en Ejecucion
			if (participante[i].proyectos.proyectos_Ejecucion ==4) 
				puntajeTotal += 100;
			else{
				if (participante[i].proyectos.proyectos_Ejecucion ==3)
					puntajeTotal += 75;
				else{
					if (participante[i].proyectos.proyectos_Ejecucion ==2)
						puntajeTotal += 50;
					else{
						if (participante[i].proyectos.proyectos_Ejecucion ==1)
							puntajeTotal += 25;
						else
							puntajeTotal += 0;
					}
				}
			}
			
			cout << "Proyectos en Ejecucion: " << puntajeTotal << endl;
			
			// Evaluar proyectos liderados
			total_proyectos = participante[i].proyectos.proyectos_Finalizados + participante[i].proyectos.proyectos_Ejecucion;
			if (total_proyectos > 0) {
				porcentaje_liderados = (participante[i].lider_Proyectos / total_proyectos) * 100;
				Eval[i].puntaje_final_segunda_etapa += porcentaje_liderados;
			} else {
				Eval[i].puntaje_final_segunda_etapa += 0;
			}
			
			Eval[i].puntaje_final_segunda_etapa += puntajeTotal;
			
			
			cout << "Proyectos liderados: " << porcentaje_liderados << endl;
			
			
		}	
	}
	

	void consultar_Evaluacion_Final(datos_Participantes participante, int num_participantes, int num_finalistas,evaluaciones evals)
	{
		tcad apellido, primer_nombre, segundo_nombre;
		cout<<"Ingrese el nombre de la participante: "<<endl;
		fflush(stdin);
		gets(primer_nombre);
		cout<<"Ingrese el segundo nombre de la participante: "<<endl;
		fflush(stdin);
		gets(segundo_nombre);
		cout<<"Ingrese el apellido de la participante: "<<endl;
		fflush(stdin);
		gets(apellido);
	
		bool encontrada = false;
		for (int i = 0; i < num_finalistas; i++) {
			if (strcmp(participante[i].apellido, apellido) == 0 &&
				strcmp(participante[i].primer_Nombre, primer_nombre) == 0 &&
				strcmp(participante[i].segundo_Nombre, segundo_nombre) == 0) {
				encontrada = true;
				cout << "Evaluacion de la participante " << primer_nombre << " " << segundo_nombre << " " << apellido << ":" << endl;
				cout << "Promedio Vestuario: " << evals[i].promedioVestuario << endl;
				cout << "Promedio Elegancia: " << evals[i].promedioElegancia << endl;
				cout << "Promedio Elocuencia: " << evals[i].promedioElocuencia << endl;
				cout << "Promedio Idiomas: " << evals[i].promedioIdiomas << endl;
				cout << "Puntaje Final Tecnico: " << evals[i].puntaje_final_segunda_etapa << endl;

			}
		}
		
		if (!encontrada) 
			cout << "No se encontro una participante con los datos proporcionados." << endl;
	}	
	

		//---------------------------------FIN DE LA SEGUNDA ETAPA-------------------------------------------	
		
		
		
		
		//---------------------------------CORONACION-------------------------------------------
	
	void coronacion(datos_Participantes participante, int num_participantes, evaluaciones &Eval) {
		// Calcular el puntaje final
		for (int i = 0; i < num_participantes; i++) {
			Eval[i].puntaje_final = Eval[i].puntaje_final_primera_etapa * 0.33 + Eval[i].puntaje_final_primera_etapa * 0.67;
		}
		
		// Ordenar participantes por puntaje final usando ordenación por inserción
		for (int i = 1; i < num_participantes; i++) {
			evaluacion_Candidatas aux = Eval[i];
			int j = i - 1;
			
			while (j >= 0 && Eval[j].puntaje_final < aux.puntaje_final) {
				Eval[j + 1] = Eval[j];
				j = j - 1;
			}
			Eval[j + 1] = aux;
		}
		
		// Mostrar las 5 semifinalistas de mayor puntaje
		cout << "Las 5 semifinalistas con mayor puntaje son:" << endl;
		for (int i = 0; i < num_participantes && i < 5; i++) {
			cout << "Participante " << i + 1 << ": " << participante[i].primer_Nombre << " " << participante[i].segundo_Nombre << " " << participante[i].apellido 
				<< " - Puntaje Final: " << Eval[i].puntaje_final << endl;
		}
		
		// Destacar a la ganadora
		cout << "La ganadora de la corona es: " << participante[0].primer_Nombre << " " << participante[0].segundo_Nombre << " " << participante[0].apellido 
			<< " con un puntaje final de: " << Eval[0].puntaje_final << endl;
	}
	
	
	
	//---------------------------------FIN CORONACION-------------------------------------------
