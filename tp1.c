#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define CORAJE "- Coraje -"
#define JOHNNY "- Johnny Bravo -"
#define POLLITO "- Pollito -"
#define PURO_HUESO "- Puro Hueso -"
#define BELLOTA "- Bellota -"
#define BLUE "- Blue -"

const char DULCE = 'D';
const char SALADO = 'S';
const char AMARGO = 'A';

const char INICIAL_CORAJE = 'C';
const char INICIAL_JOHNNY = 'J';
const char INICIAL_POLLITO = 'P';
const char INICIAL_PURO_HUESO = 'H';
const char INICIAL_BELLOTA = 'S';
const char INICIAL_BLUE = 'B';

const char AZUL = 'A';
const char AMARILLO = 'Y';
const char VERDE = 'V';
const char NEGRO = 'N';
const char BLANCO = 'B';
const char ROSA = 'R';

const int PUNTOS_SALADO = 5;
const int PUNTOS_DULCE = 15;
const int PUNTOS_AMARGO = 20;

const int PUNTOS_ROSA = 5;
const int PUNTOS_AMARILLO = 5;
const int PUNTOS_NEGRO = 15;
const int PUNTOS_BLANCO = 15;
const int PUNTOS_AZUL = 20;
const int PUNTOS_VERDE = 20;

const int NO_USA_ZAPAS = 0;
const int TALLA_1 = 33;
const int TALLA_2 = 37;
const int TALLA_3 = 38;
const int TALLA_4 = 42;
const int TALLA_5 = 43;
const int TALLA_6 = 47;

const int MULTIPLICADOR_1 = 1;
const int MULTIPLICADOR_2 = 2;
const int MULTIPLICADOR_3 = 3;
const int MULTIPLICADOR_4 = 4;

const int ALTURA_MINIMA = 10;
const int ALTURA_MAXIMA = 250;

const int FECHA_MAS_ANTIGUA = 1988;
const int FECHA_MAS_RECIENTE = 2008;

const int MODULO_FECHA_20 = 20;
const int SUMAR_ANIO = 1;

const int ALTURA_JOHNNY = 180;
const int ALTURA_BELLOTA = 120;
const int ALTURA_POLLITO = 50;
const int ALTURA_BLUE = 140;
const int ALTURA_HUESO = 200;
const int ALTURA_CORAJE = 30;

const int PTS_MIN_JHONNY_CORAJE = 1;
const int PTS_MAX_JHONNY_CORAJE = 80;
const int PTS_MIN_HUESO_POLLITO = 81;
const int PTS_MAX_HUESO_POLLITO = 160;
const int PTS_MIN_BLUE_BELLOTA = 161;
const int PTS_MAX_BLUE_BELLOTA = 240;

/*
/POST: Chequea que la fecha sea invalida.
*/
bool es_fecha_invalida(int fecha){
	
	return (((fecha) < FECHA_MAS_ANTIGUA) || ((fecha) > FECHA_MAS_RECIENTE));
}

/*
/PRE: Debe ser una fecha valida.
/POST: La fecha que se obtiene está entre FECHA_MAS_ANTIGUA y FECHA_MAS_RECIENTE (inclusive).
*/
void preguntar_fecha_nacimiento(int* fecha){
	printf("Bienvenido, identifiquese respondiendo las siguientes preguntas.\n¿Cuál es su fecha de nacimiento? Tiene que ser entre %i y %i:\n", FECHA_MAS_ANTIGUA, FECHA_MAS_RECIENTE);
	scanf("%i", fecha);

	while((es_fecha_invalida(*fecha))){
		printf("Fecha inválida, ingrese una fecha entre %i y %i:\n",FECHA_MAS_ANTIGUA, FECHA_MAS_RECIENTE);
		scanf("%i", fecha);
	}
}

/*
/POST: Chequea que el sabor sea valido.
*/
bool es_sabor_valido(char sabor){
	
	return ((sabor) == DULCE) || ((sabor) == SALADO) || ((sabor) == AMARGO);
}

void mostrar_convencion_sabores(){
	
	printf("D: DULCE - S: SALADO - A: AMARGO\n");
}

/*
/PRE: Recibe una variable que debe ser valida D: DULCE - S: SALADO - A: AMARGO.
/POST: El sabor que se obtiene sera DULCE, SALADO o AMARGO.
*/
void preguntar_sabor(char* sabor){
	printf("¿Cuál es su sabor favorito?\n");
	mostrar_convencion_sabores();
	scanf(" %c", sabor);

	while(!(es_sabor_valido(*sabor))){
		printf("Ingrese un sabor válido\n");
		mostrar_convencion_sabores();
		scanf(" %c", sabor);
	}
}

/*
/POST: Chequea que la talla sea invalida.
*/
bool es_talla_invalida(int talla){

	return (((talla) != NO_USA_ZAPAS) && (talla) < TALLA_1) || ((talla) > TALLA_6);
}

void mostrar_tallas(){
	
	printf("Las tallas validas estan entre %i y %i, en caso de no usar zapatos ingrese %i:\n", TALLA_1, TALLA_6, NO_USA_ZAPAS);
}

/*
/PRE: Recibe una variable que debe ser valida en un rango.
/POST: La talla que se obtiene debe ser NO_USA_ZAPAS o debe estar entre TALLA_1 y TALLA_6 (inclusive).
*/
void preguntar_talla(int* talla){
	printf("¿Cuál es su talla de zapatos?\n");
	mostrar_tallas();
	scanf("%i", talla);

	while(es_talla_invalida(*talla)){
			printf("Ingrese una talla válida\n");
			mostrar_tallas();
			scanf("%i", talla);
		}
}

/*
/POST: Chequea que el color sea valido.
*/
bool es_color_valido(char color){

	return (color == AZUL || color == AMARILLO || color == VERDE || color == NEGRO || color == BLANCO || color == ROSA);
}

void mostrar_convecion_colores(){
	
	printf("AZUL = A - AMARILLO = Y - VERDE = V - NEGRO = N - BLANCO = B - ROSA = R\n");
}

/*
/PRE: Recibe una variable que debe ser AZUL = A - AMARILLO = Y - VERDE = V - NEGRO = N - BLANCO = B - ROSA = R
/POST: El color que se obtiene sera AZUL, AMARILLO, VERDE, NEGRO, BLANCO o ROSA.
*/
void preguntar_color(char* color){
	printf("¿Cuál es su color favorito?\n");
	mostrar_convecion_colores();
	scanf(" %c", color);

	while(!(es_color_valido(*color))){
		printf("Ingresó un color invalido, por favor ingrese un color válido:\n");
		mostrar_convecion_colores();
		scanf(" %c", color);
	}
}

/*
/POST: Chequea que la altura es invalida.
*/
bool es_altura_invalida(int altura){
	
	return (((altura) < ALTURA_MINIMA) || ((altura) > ALTURA_MAXIMA));
}		

/*
/PRE: Debe ser una altura que debe estar entre ALTURA_MINIMA y ALTURA_MAXIMA.
/POST: La altura que se obtiene está entre AlTURA_MINIMA y ALTURA_MAXIMA (inclusive).
*/
void preguntar_altura(int* altura){
	printf("¿Cuál es su altura en cm? debe ser entre %icm y %icm:\n", ALTURA_MINIMA, ALTURA_MAXIMA);
	scanf("%i", altura);

	while(es_altura_invalida(*altura)){
		printf("Altura inválida, ingrese una altura entre %icm y %icm:\n", ALTURA_MINIMA, ALTURA_MAXIMA);
		scanf("%i", altura);
	}
}

/*
/POST: Muestra por pantalla las preguntas y respuestas del usuario.
*/
void preguntar_datos(int* fecha, int* talla, int* altura, char* color, char* sabor){
	preguntar_fecha_nacimiento(fecha);
	preguntar_sabor(sabor);
	preguntar_talla(talla);
	preguntar_color(color);
	preguntar_altura(altura);
}

/*
/PRE: Recibe una variable que es AZUL = A - AMARILLO = Y - VERDE = V - NEGRO = N - BLANCO = B - ROSA = R.
/POST: Suma a *puntos la cantidad correspondiente a cada color.
*/
void calcular_puntos_color(int* puntos, char color){
	if (color == AZUL){
		(*puntos) +=PUNTOS_AZUL;
	}
	if (color == AMARILLO){
		(*puntos) +=PUNTOS_AMARILLO;
	}
	if (color == VERDE){
		(*puntos) +=PUNTOS_VERDE;
	}
	if (color == NEGRO){
		(*puntos) +=PUNTOS_NEGRO;
	}
	if (color == BLANCO){
		(*puntos) +=PUNTOS_BLANCO;
	}
	if (color == ROSA){
		(*puntos) +=PUNTOS_ROSA;
	}
}

/*
/PRE: Recibe una variable que es D: DULCE - S: SALADO - A: AMARGO
/POST: Suma a *puntos la cantidad correspondiente a cada sabor.
*/
void calcular_puntos_sabor(int* puntos, char sabor){
	if (sabor == DULCE){
		(*puntos) +=PUNTOS_DULCE;
	}
	if (sabor == SALADO){
		(*puntos) +=PUNTOS_SALADO;
	}
	if (sabor == AMARGO){
		(*puntos) +=PUNTOS_AMARGO;
	}
}

/*
/PRE: Recibe una variable que debe ser valida entre FECHA_MAS_ANTIGUA y FECHA_MAS_RECIENTE (inclusive).
/POST: Suma a *puntos la cantidad correspondiente a la fecha de nacimiento.
*/
void calcular_puntos_fecha_nacimiento(int* puntos, int fecha){
	(*puntos) += (fecha%MODULO_FECHA_20) + SUMAR_ANIO; 
}

/*
/PRE: Recibe una talla valida que sea NO_USA_ZAPAS o que este entre TALLA_1 y TALLA_6 (inclusive)
/POST: Multiplica a *puntos por la cantidad correspondiente a cada talla.
*/
void multiplicar_puntos_talla(int* puntos, int talla){
	if (talla == NO_USA_ZAPAS){
		(*puntos) *= MULTIPLICADOR_1;
	}
	if ((talla >= TALLA_1) && (talla <= TALLA_2)){
		(*puntos) *= MULTIPLICADOR_2;
	}
	if ((talla >= TALLA_3) && (talla <= TALLA_4)){
		(*puntos) *= MULTIPLICADOR_3;
	}
	if ((talla >= TALLA_5) && (talla <= TALLA_6)){
		(*puntos) *= MULTIPLICADOR_4;
	}
}

/*
/POST: Calcula la cantidad de puntos totales (Puntos color + Puntos sabor + Puntos fecha)* Puntos talla.
*/

void calcular_puntos_totales(int* puntos, int talla, int fecha, char sabor, char color){
	calcular_puntos_color(puntos, color);
	calcular_puntos_sabor(puntos, sabor);
	calcular_puntos_fecha_nacimiento(puntos, fecha);
	multiplicar_puntos_talla(puntos, talla);
}

/*
/PRE: la variable está entre AlTURA_MINIMA y ALTURA_MAXIMA (inclusive).
/POST: Muestra por pantalla quien es el personaje detectado, que deberan ser CORAJE o JOHNNY
dependiendo de la comparacion entre diferencia_altura_1 y diferencia_altura_2.
*/
void detectar_coraje_o_johnny(int* altura, int* diferencia_altura_1, int* diferencia_altura_2, int resultado, char* inicial){
		(*diferencia_altura_1) = abs(ALTURA_JOHNNY - (*altura));
		(*diferencia_altura_2) = abs(ALTURA_CORAJE - (*altura));
			if ((*diferencia_altura_1) > (*diferencia_altura_2)){
				(resultado) = (*diferencia_altura_2);
					printf("Intruso detectado: %s.\n", CORAJE);
					(*inicial) = INICIAL_CORAJE;				
				}
				else{
					(resultado) = (*diferencia_altura_1);
						printf("Intruso detectado: %s.\n", JOHNNY);
						(*inicial) = INICIAL_JOHNNY;
				}
}

/*
/PRE: la variable está entre AlTURA_MINIMA y ALTURA_MAXIMA (inclusive).
/POST: Muestra por pantalla quien es el personaje detectado, que deberan ser POLLITO o PURO_HUESO
 dependiendo de la comparacion de diferencia_altura_1 y diferencia_altura_2.
*/
void detectar_pollito_o_hueso(int* altura, int* diferencia_altura_1, int* diferencia_altura_2, int resultado, char* inicial){
		(*diferencia_altura_1) = abs(ALTURA_HUESO - (*altura));
		(*diferencia_altura_2) = abs(ALTURA_POLLITO - (*altura));
			if ((*diferencia_altura_1) > (*diferencia_altura_2)){
				(resultado) = (*diferencia_altura_2);
					printf("Intruso detectado: %s.\n", POLLITO);
					(*inicial) = INICIAL_POLLITO;
				}
				else{
					(resultado) = (*diferencia_altura_1);
						printf("Intruso detectado: %s.\n", PURO_HUESO);
						(*inicial) = INICIAL_PURO_HUESO;
				}	
}

/*
/PRE: la variable está entre AlTURA_MINIMA y ALTURA_MAXIMA (inclusive).
/POST: Muestra por pantalla quien es el personaje detectado, que deberan ser BLUE o BELLOTA
 dependiendo de la comparacion de diferencia_altura_1 y diferencia_altura_2.
*/
void detectar_bellota_o_blue(int* altura, int* diferencia_altura_1, int* diferencia_altura_2, int resultado, char* inicial){
		(*diferencia_altura_1) = abs(ALTURA_BLUE - (*altura));
		(*diferencia_altura_2) = abs(ALTURA_BELLOTA - (*altura));
			if ((*diferencia_altura_1) > (*diferencia_altura_2)){
				(resultado) = (*diferencia_altura_2);
					printf("Intruso detectado: %s.\n", BELLOTA);
					(*inicial) = INICIAL_BELLOTA;
					
				}
				else{
					(resultado) = (*diferencia_altura_1);
						printf("Intruso detectado: %s.\n", BLUE);
						(*inicial) = INICIAL_BLUE;
				}		
}

/*
/PRE: puntos debe estar entre PTS_MIN_JHONNY_CORAJE y PTS_MAX_JHONNY_CORAJE para el primer caso.
							  PTS_MIN_HUESO_POLLITO y PTS_MAX_HUESO_POLLITO para el segundo caso.
							  PTS_MIN_BLUE_BELLOTA y PTS_MAX_BLUE_BELLOTA para el tercer caso.
/POST: Detecta al personaje en base a los puntos obtenidos.
*/
void detectar_personajes(int* puntos,int* altura, int* diferencia_altura_1, int* diferencia_altura_2, int resultado,char* inicial){
	if ((*puntos) >= PTS_MIN_JHONNY_CORAJE && (*puntos) <= PTS_MAX_JHONNY_CORAJE){
		detectar_coraje_o_johnny(altura, diferencia_altura_1, diferencia_altura_2, resultado, inicial);
	}
	if ((*puntos) >= PTS_MIN_HUESO_POLLITO && (*puntos) <= PTS_MAX_HUESO_POLLITO){
		detectar_pollito_o_hueso(altura, diferencia_altura_1, diferencia_altura_2, resultado,inicial);
	}	
	if ((*puntos) >= PTS_MIN_BLUE_BELLOTA && (*puntos) <= PTS_MAX_BLUE_BELLOTA){
		detectar_bellota_o_blue(altura, diferencia_altura_1, diferencia_altura_2, resultado,inicial);
	}	
}

int main(){

	char sabor, color, inicial;

	int fecha, talla, altura;
	int puntos = 0;
	int resultado = 0;
	int diferencia_altura_1 = 0;
	int diferencia_altura_2 = 0;
	
	preguntar_datos(&fecha, &talla, &altura, &color, &sabor);

	calcular_puntos_totales(&puntos, talla, fecha, sabor, color);

	detectar_personajes(&puntos,&altura,&diferencia_altura_1,&diferencia_altura_2,resultado,&inicial);

	return 0;
}