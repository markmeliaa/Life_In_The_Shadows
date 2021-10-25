#include <nds.h>
#include <stdio.h>
#include <time.h>
#include "Titlescreen.h"
#include "GameOver.h"
#include "WinScreen.h"

//Teselas
u8 t_pared[64] =
{
	1,0,1,1,0,1,1,0,
	1,0,1,1,0,1,1,0,
	0,0,0,0,0,0,0,0,
	1,1,0,1,1,0,1,1,
	1,1,0,1,1,0,1,1,
	0,0,0,0,0,0,0,0,
	1,0,1,1,0,1,1,0,
	1,0,1,1,0,1,1,0,
};

u8 t_suelo[64] =
{
	2,2,2,2,2,2,2,2,
	2,0,2,2,2,2,2,2,
	2,2,2,2,2,2,0,2,
	2,2,2,0,2,2,2,2,
	2,2,2,2,2,2,2,2,
	2,2,0,2,2,2,2,2,
	2,0,2,2,2,0,2,2,
	2,2,2,2,2,2,2,0,
};

u8 t_idle[64] =
{
	2,2,2,0,0,0,0,2,
	2,6,2,3,3,3,3,2,
	2,6,2,0,3,3,0,2,
	2,6,2,3,3,3,3,2,
	2,6,2,2,5,5,2,2,
	2,7,3,3,4,4,3,2,
	2,6,2,2,4,4,3,2,
	2,2,2,2,3,3,2,2,
};

u8 t_arana[64] =
{
	2,2,2,2,2,2,2,2,
	2,2,4,2,4,2,2,2,
	0,2,0,2,0,2,0,2,
	0,0,0,0,0,0,0,2,
	2,2,0,0,0,2,2,2,
	2,0,0,0,0,0,2,2,
	2,0,2,2,2,0,2,2,
	2,2,2,2,2,2,2,2,
};

u8 t_alcalde[64] =
{
	2,2,5,5,5,2,2,2,
	2,5,3,3,3,5,2,4,
	2,2,0,3,0,2,0,4,
	2,2,3,3,3,0,0,4,
	2,2,6,6,6,2,2,4,
	2,3,0,0,0,3,3,7,
	2,3,0,0,0,0,2,4,
	2,2,2,2,2,2,2,2,
};

u8 t_ataque[64] =
{
	0,0,0,2,2,2,2,2,
	0,4,0,0,2,2,2,2,
	0,0,4,0,0,2,0,2,
	2,0,0,4,0,0,2,2,
	2,2,0,0,4,0,0,2,
	2,2,2,0,0,4,0,0,
	2,2,2,2,0,0,4,0,
	2,2,2,2,2,0,0,0,
};

u8 t_negro[64] =
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};

u8 t_puertaroja[64] =
{
	0,0,0,0,0,0,0,0,
	0,4,4,0,0,4,4,0,
	0,4,4,0,0,4,4,0,
	0,4,4,0,0,4,4,0,
	0,4,7,0,0,7,4,0,
	0,4,4,0,0,4,4,0,
	0,4,4,0,0,4,4,0,
	0,4,4,0,0,4,4,0,
};

u8 t_puertaama[64] =
{
	0,0,0,0,0,0,0,0,
	0,7,7,0,0,7,7,0,
	0,7,7,0,0,7,7,0,
	0,7,7,0,0,7,7,0,
	0,7,4,0,0,4,7,0,
	0,7,7,0,0,7,7,0,
	0,7,7,0,0,7,7,0,
	0,7,7,0,0,7,7,0,
};

u8 t_puertaverde[64] =
{
	0,0,0,0,0,0,0,0,
	0,8,8,0,0,8,8,0,
	0,8,8,0,0,8,8,0,
	0,8,8,0,0,8,8,0,
	0,8,7,0,0,7,8,0,
	0,8,8,0,0,8,8,0,
	0,8,8,0,0,8,8,0,
	0,8,8,0,0,8,8,0,
};

u8 t_puertanegra[64] =
{
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,4,0,0,4,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,
};

u8 t_puertablanca[64] =
{
	0,0,0,0,0,0,0,0,
	0,5,5,0,0,5,5,0,
	0,5,5,0,0,5,5,0,
	0,5,5,0,0,5,5,0,
	0,5,4,0,0,4,5,0,
	0,5,5,0,0,5,5,0,
	0,5,5,0,0,5,5,0,
	0,5,5,0,0,5,5,0,
};

u8 t_llaveroja[64] =
{
	2,2,5,4,4,5,2,2,
	2,2,4,2,2,4,2,2,
	2,2,4,2,2,4,2,2,
	2,2,5,4,4,5,2,2,
	2,2,2,2,4,2,2,2,
	2,2,4,4,4,2,2,2,
	2,2,2,2,4,2,2,2,
	2,2,4,4,5,2,2,2,
};

u8 t_llaveverde[64] =
{
	2,2,5,8,8,5,2,2,
	2,2,8,2,2,8,2,2,
	2,2,8,2,2,8,2,2,
	2,2,5,8,8,5,2,2,
	2,2,2,2,8,2,2,2,
	2,2,8,8,8,2,2,2,
	2,2,2,2,8,2,2,2,
	2,2,8,8,5,2,2,2,
};

u8 t_llavenegra[64] =
{
	2,2,5,0,0,5,2,2,
	2,2,0,2,2,0,2,2,
	2,2,0,2,2,0,2,2,
	2,2,5,0,0,5,2,2,
	2,2,2,2,0,2,2,2,
	2,2,0,0,0,2,2,2,
	2,2,2,2,0,2,2,2,
	2,2,0,0,5,2,2,2,
};

u8 t_enemigo1[64] =
{
	2,2,7,7,7,7,2,2,
	2,2,3,3,3,3,2,6,
	2,2,4,3,3,4,2,6,
	2,2,5,3,3,5,2,6,
	2,2,4,0,0,4,2,6,
	2,3,4,0,0,4,3,7,
	2,3,4,0,0,4,2,6,
	2,2,2,3,3,2,2,2,
};

u16 mapData[768] =
{
	1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
	1,1,2,2,2,4,2,2, 2,2,12,2,2,2,2,2,  2,2,2,2,2,1,15,2, 2,2,2,2,2,2,1,1,
	1,1,2,2,2,2,2,2, 4,2,12,2,2,2,2,2,  2,2,2,2,2,1,2,2, 2,2,2,2,4,2,1,1,
	1,1,2,2,1,1,1,1, 1,1,1,2,2,2,2,2,  16,2,2,2,2,1,2,2, 2,2,2,2,2,2,1,1,

	1,1,2,2,1,2,2,2, 2,2,1,2,2,2,2,2,  2,2,2,2,2,1,1,1, 1,2,2,1,1,1,1,1,
	1,1,2,4,11,2,4,2, 2,2,1,2,2,2,2,2,  2,2,2,2,2,1,2,2, 1,2,2,1,2,14,1,1,
	1,1,2,2,11,2,2,2, 2,4,1,2,2,2,2,2,  2,2,2,2,2,1,2,4, 1,4,2,1,2,2,1,1,
	1,1,2,2,1,2,2,2, 2,2,1,1,1,1,1,1,  1,1,1,1,1,1,2,2, 1,2,2,1,2,2,1,1,

	1,1,2,2,1,2,2,2, 2,2,1,2,2,2,2,2,  2,2,2,2,2,1,2,2, 1,2,2,1,2,2,1,1,
	1,1,2,2,1,2,4,2, 2,4,1,2,2,2,4,2,  2,2,2,4,2,1,2,2, 1,10,10,1,2,2,1,1,
	1,1,2,2,1,1,1,1, 1,1,1,2,4,2,2,2,  2,4,2,2,2,2,2,2, 2,2,2,2,2,4,1,1,
	1,1,2,4,2,2,2,2, 2,2,2,2,2,2,2,2,  2,2,2,2,2,2,4,2, 2,2,2,2,2,2,1,1,

	1,1,2,2,2,2,2,2, 2,2,2,2,2,2,2,2,  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
	1,1,1,1,1,1,1,1, 1,1,1,1,1,1,2,2,  1,2,2,2,2,2,2,2, 2,2,4,2,2,2,1,1,
	1,1,2,2,2,4,2,2, 2,4,2,2,2,2,2,2,  1,2,2,2,4,2,2,2, 2,2,2,2,2,2,1,1,
	1,1,2,2,2,2,2,2, 2,2,2,2,2,2,2,2,  1,2,2,2,2,1,2,2, 1,2,2,2,4,2,1,1,

	1,1,1,1,1,1,1,1, 1,1,1,1,1,1,8,8,  1,1,1,1,1,1,2,2, 1,2,2,2,2,2,1,1,
	1,1,2,2,2,2,2,2, 2,2,2,2,4,2,2,2,  2,9,2,2,4,2,2,2, 1,2,4,2,2,2,1,1,
	1,1,2,2,4,2,2,2, 2,2,2,2,2,2,2,2,  4,9,2,2,2,2,2,2, 1,2,2,2,2,2,1,1,
	1,1,2,2,1,1,1,1, 1,1,1,1,1,1,2,2,  2,1,1,1,1,1,2,2, 1,1,1,2,2,1,1,1,

	1,1,2,2,2,2,2,2, 2,2,2,2,2,1,2,2,  2,1,2,2,2,2,2,2, 1,2,2,2,2,2,1,1,
	1,1,2,4,2,2,2,2, 2,2,2,2,4,1,2,2,  2,1,2,4,2,2,2,2, 1,2,2,4,2,2,1,1,
	1,1,2,2,2,2,2,2, 2,2,2,2,2,1,2,2,  2,1,2,2,2,2,2,2, 1,2,2,2,2,13,1,1,
	1,1,1,1,1,1,1,1, 1,1,1,1,1,1,2,2,  2,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,
};

//Métodos
void ModoFramebuffer();
void DetectarBotones();
void InicializarPartida();
void ConfigurarInterrupciones();
void BorrarPantallaSuperior();
void MoverPersonaje(int);
void ModoTeselas();
void ConstruirMapaInferior();
void Timer();
void Timer2();
void Timer3();
void AtacarPersonaje(int);
void EliminarPuertas();
int  ComprobarGanador(int posicion_caballos[]);
double closed_interval_rand(double x0, double x1){
	return x0 + (x1-x0) * rand() / ((double) RAND_MAX);
}
void Objetivos();

//Variables
int imagenActual; // Si es igual a 0 será la TitleScrren, igual a 1 GAME OVER y igual a 2 WIN
int estadoJuego; // Será 0 si no estás jugando y 1 si estás jugando
int per_fila;	// Fila del personaje
int per_columna;	// Columna del personaje
int tipo_mapa;
int gameOver;
int hasGanado;
static u8*  tileMemory;
static u16* mapMemory;
int vidas;
int izquierda;	// Para saber si las arañas van a la izquierda o a la derecha
int direccion;
int enemigosMuertos;
int llaveRoja;
int llaveVerde;
int llaveNegra;
int vidasBoss;

// Bucle principal y objetivos que se nos muestran que tenemos que seguir
int main(void) {
	srand(time(NULL));
	imagenActual = 0;
	
	// Iniciamos el juego
	ModoFramebuffer();
	REG_DISPCNT = MODE_FB0;
	
	// Inicializamoss las variables
	estadoJuego = -1;
	per_fila = 24;
	per_columna = 15;
	gameOver = 0;
	hasGanado = 0;
	vidas = 5;
	izquierda = 0;
	direccion = 0;
	enemigosMuertos = 0;
	llaveRoja = 2;
	llaveVerde = 2;
	llaveNegra = 2;
	vidasBoss = 3;
	
	//Configuramos las interrupciones
	ConfigurarInterrupciones();

	while(1)
	{
		// Mientras estás jugando
		if(estadoJuego == 1){
			EliminarPuertas();
			BorrarPantallaSuperior();
			iprintf("\x1b[7;3HOBJETIVO:");
			Objetivos();				
		}
		
		// Game Over
		if(estadoJuego == 0){
			imagenActual = 1;

			REG_DISPCNT = MODE_FB1;
			ModoFramebuffer();
			
		}
		
		// Victoria
		if(estadoJuego == 2){
			imagenActual = 2;
			REG_DISPCNT = MODE_FB3;
			ModoFramebuffer();
		}
		swiWaitForVBlank();
	}
}

// Aplicación del Framebuffer
void ModoFramebuffer() {
	REG_POWERCNT = POWER_LCD | POWER_2D_A;

	// Pantalla de título = FB0
	VRAM_A_CR = VRAM_ENABLE | VRAM_A_LCD;
	dmaCopy (TitleScreenBitmap, VRAM_A , 256*192*2);
	
	// Pantalla de GAME OVER = FB1
	VRAM_B_CR = VRAM_ENABLE | VRAM_B_LCD;
	dmaCopy (GameOverBitmap, VRAM_B , 256*192*2);
	
	// Pantalla de WIN = FB3
	VRAM_D_CR = VRAM_ENABLE | VRAM_D_LCD;
	dmaCopy (WinScreenBitmap, VRAM_D , 256*192*2);

	
	if(imagenActual == 0){
		//Inicializamos el texto de la pantalla superior
		consoleDemoInit();
		printf("\x1b[4;13HHOLA");
		printf("\x1b[5;9,5HBIENVENIDO A");
		printf("\x1b[6;6HLIFE IN THE SHADOWS");
		
		printf("\x1b[10;9H TE VES CAPAZ");
		printf("\x1b[11;6HDE AFRONTAR EL RETO?");
		
		printf("\x1b[18;7HPULSA A PARA JUGAR");
	}
	
	if(imagenActual == 1){
		consoleDemoInit();
		printf("\x1b[11;9HHAS PERDIDO :(");
		printf("\x1b[15;4HTE HAS QUEDADO SIN VIDAS");
		printf("\x1b[20;5HPULSA A PARA REINTENTAR");
	}
	
	if(imagenActual == 2){
		consoleDemoInit();
		printf("\x1b[12;9HHAS GANADO :D");
		printf("\x1b[16;9HTE HAS PASADO");
		printf("\x1b[17;7HLIFE IN THE SHADOWS");
		printf("\x1b[20;3HPULSA A PARA VOLVER A JUGAR");
	}
}

// Generación de teselas
void ModoTeselas() {
	
	// Inicialización del motor de gráficos
	REG_POWERCNT = POWER_ALL_2D;
	REG_DISPCNT  = MODE_0_2D | DISPLAY_BG0_ACTIVE ;
	VRAM_A_CR    = VRAM_ENABLE | VRAM_A_MAIN_BG ;
	BGCTRL [0]   = BG_32x32 | BG_COLOR_256 | BG_MAP_BASE(0) | BG_TILE_BASE(1);

	tileMemory = (u8*)  BG_TILE_RAM(1);
	mapMemory  = (u16*) BG_MAP_RAM(0);

	// Inicializamos los colores
	BG_PALETTE[0] = RGB15(0,0,0); // Negro
	BG_PALETTE[1] = RGB15(0,0,20); // Azul Oscuro
	BG_PALETTE[2] = RGB15(8, 5, 0); // Marrón
	BG_PALETTE[3] = RGB15(25, 19, 13); // Carne
	BG_PALETTE[4] = RGB15(20, 2, 2); // Granate
	BG_PALETTE[5] = RGB15(31,31,31); // Blanco
	BG_PALETTE[6] = RGB15(15, 15, 15); // Gris
	BG_PALETTE[7] = RGB15(31, 25, 1); // Amarillo
	BG_PALETTE[8] = RGB15(5,15,0); // Verde

	// Inicializamos las teselas
	dmaCopy(t_pared, tileMemory + 64, sizeof(t_pared)); // 1
	dmaCopy(t_suelo, tileMemory + 128, sizeof(t_suelo)); // 2
	dmaCopy(t_idle, tileMemory + 192, sizeof(t_idle)); // 3
	dmaCopy(t_arana, tileMemory + 256, sizeof(t_arana)); // 4
	dmaCopy(t_alcalde, tileMemory + 320, sizeof(t_alcalde)); // 5
	dmaCopy(t_ataque, tileMemory + 384, sizeof(t_ataque)); // 6
	dmaCopy(t_negro, tileMemory + 448, sizeof(t_negro)); // 7
	dmaCopy(t_puertaroja, tileMemory + 512, sizeof(t_puertaroja)); // 8
	dmaCopy(t_puertaama, tileMemory + 576, sizeof(t_puertaama)); // 9
	dmaCopy(t_puertaverde, tileMemory + 640, sizeof(t_puertaverde)); // 10
	dmaCopy(t_puertanegra, tileMemory + 704, sizeof(t_puertanegra)); // 11
	dmaCopy(t_puertablanca, tileMemory + 768, sizeof(t_puertablanca)); // 12
	dmaCopy(t_llaveroja, tileMemory + 832, sizeof(t_llaveroja)); // 13
	dmaCopy(t_llaveverde, tileMemory + 896, sizeof(t_llaveverde)); // 14
	dmaCopy(t_llavenegra, tileMemory + 960, sizeof(t_llavenegra)); // 15
	dmaCopy(t_enemigo1, tileMemory + 1024, sizeof(t_enemigo1)); // 16
}

// Inicializamos todos los voids necesarios para comenzar a jugar
void InicializarPartida() {
	estadoJuego = 1;
	per_fila = 24;
	per_columna = 15;
	gameOver = 0;
	hasGanado = 0;
	vidas = 5;
	izquierda = 0;
	direccion = 0;
	enemigosMuertos = 0;
	llaveRoja = 2;
	llaveVerde = 2;
	llaveNegra = 2;
	vidasBoss = 3;
	BorrarPantallaSuperior();
	ModoTeselas();
	ConstruirMapaInferior();
}

void ConfigurarInterrupciones() {
	irqSet(IRQ_KEYS, DetectarBotones);
	irqEnable(IRQ_KEYS);
	
	irqEnable(IRQ_TIMER0);
	irqEnable(IRQ_TIMER1);
	irqEnable(IRQ_TIMER2);
	
	irqSet(IRQ_TIMER0, Timer);
	irqSet(IRQ_TIMER1, Timer2);
	irqSet(IRQ_TIMER2, Timer3);

	REG_KEYCNT = 0x40F3;
	
	//Contador cada segundo
	TIMER_DATA(0) = 32768;
	TIMER_CR(0) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ;
	
	//Contador cada dos segundos
	TIMER_DATA(1) = 0;
	TIMER_CR(1) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ;
	
	TIMER_DATA(2) = 35000;
	TIMER_CR(2) = TIMER_DIV_1024 | TIMER_ENABLE | TIMER_IRQ_REQ;
}

void DetectarBotones() {
	if (estadoJuego == 1){
		if (REG_KEYINPUT == 0x3bf && (per_fila>0)){
			direccion = 0;
			MoverPersonaje(direccion);	
		} 
		else if (REG_KEYINPUT == 0x37f && (per_fila<23)){
			direccion = 1;
			MoverPersonaje(direccion);	
		}
		else if (REG_KEYINPUT == 0x3ef && (per_columna<31)){
			direccion = 2;
			MoverPersonaje(direccion);
		}
		else if (REG_KEYINPUT == 0x3df && (per_columna>0)){
			direccion = 3;
			MoverPersonaje(direccion);
		}
		if(REG_KEYINPUT == 0x03FD) AtacarPersonaje(direccion);
	}
	
	else if (estadoJuego == -1 && REG_KEYINPUT == 0x3fe){
		estadoJuego = 1;
		InicializarPartida();
	}
	
	else if ((estadoJuego == 2 || estadoJuego == 0) && REG_KEYINPUT == 0x3fe){
		estadoJuego = 1;
		InicializarPartida();
	}
}

// Borramos el texto de la pantalla superior
void BorrarPantallaSuperior() {
	for (int i=0;i<24;i++)
		iprintf("\x1b[%d;1H                                             ",i);
}

// Movimiento del personaje e iluminación de las teselas que lo rodean
void MoverPersonaje(int direccion) {
	int pos_memory;
	
	if (direccion == 0) {
		// Para que choque con las paredes y las puertas
		if (mapMemory[(per_fila - 1)*32+per_columna] == 2 || mapMemory[(per_fila - 1)*32+per_columna] == 6 || mapMemory[(per_fila - 1)*32+per_columna] == 13 || mapMemory[(per_fila - 1)*32+per_columna] == 14 || mapMemory[(per_fila - 1)*32+per_columna] == 15){
			
			// Oscurecemos las antiguas teselas
			// Fila central
			mapMemory[per_fila*32 + (per_columna + 1)] = 7;
			mapMemory[per_fila*32 + (per_columna - 1)] = 7;
			mapMemory[per_fila*32 + (per_columna + 2)] = 7;
			mapMemory[per_fila*32 + (per_columna - 2)] = 7;
			// Filas superiores	
			mapMemory[(per_fila - 1)*32 + per_columna] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna + 2)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna - 1)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna - 2)] = 7;
			mapMemory[(per_fila - 2)*32 + per_columna] = 7;
			mapMemory[(per_fila - 2)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila - 2)*32 + (per_columna - 1)] = 7;
			// Filas inferiores
			mapMemory[(per_fila + 1)*32 + per_columna] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna + 2)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna - 1)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna - 2)] = 7;
			mapMemory[(per_fila + 2)*32 + per_columna] = 7;
			mapMemory[(per_fila + 2)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila + 2)*32 + (per_columna - 1)] = 7;

			pos_memory = per_fila*32+per_columna;
			mapMemory[pos_memory] = 2;
			mapData[pos_memory] = 2;

			per_fila = per_fila - 1;
			pos_memory = per_fila*32+per_columna;
			
			if(mapData[pos_memory] == 13)
				llaveRoja = 1;
			
			if(mapData[pos_memory] == 14)
				llaveVerde = 1;
			
			if(mapData[pos_memory] == 15)
				llaveNegra = 1;
			
			mapMemory[pos_memory] = 3;
			
			// Iluminamos las nuevas teselas
			// Fila central
			mapMemory[per_fila*32 + (per_columna + 1)] = mapData[per_fila*32 + (per_columna + 1)];
			mapMemory[per_fila*32 + (per_columna - 1)] = mapData[per_fila*32 + (per_columna - 1)];
			mapMemory[per_fila*32 + (per_columna + 2)] = mapData[per_fila*32 + (per_columna + 2)];
			mapMemory[per_fila*32 + (per_columna - 2)] = mapData[per_fila*32 + (per_columna - 2)];
			// Filas superiores	
			mapMemory[(per_fila - 1)*32 + per_columna] = mapData[(per_fila - 1)*32 + per_columna];
			mapMemory[(per_fila - 1)*32 + (per_columna + 1)] = mapData[(per_fila - 1)*32 + (per_columna + 1)];
			mapMemory[(per_fila - 1)*32 + (per_columna + 2)] = mapData[(per_fila - 1)*32 + (per_columna + 2)];
			mapMemory[(per_fila - 1)*32 + (per_columna - 1)] = mapData[(per_fila - 1)*32 + (per_columna - 1)];
			mapMemory[(per_fila - 1)*32 + (per_columna - 2)] = mapData[(per_fila - 1)*32 + (per_columna - 2)];
			mapMemory[(per_fila - 2)*32 + per_columna] = mapData[(per_fila - 2)*32 + per_columna];
			mapMemory[(per_fila - 2)*32 + (per_columna + 1)] = mapData[(per_fila - 2)*32 + (per_columna + 1)];
			mapMemory[(per_fila - 2)*32 + (per_columna - 1)] = mapData[(per_fila - 2)*32 + (per_columna - 1)];
			// Filas inferiores
			mapMemory[(per_fila + 1)*32 + per_columna] = mapData[(per_fila + 1)*32 + per_columna];
			mapMemory[(per_fila + 1)*32 + (per_columna + 1)] = mapData[(per_fila + 1)*32 + (per_columna + 1)];
			mapMemory[(per_fila + 1)*32 + (per_columna + 2)] = mapData[(per_fila + 1)*32 + (per_columna + 2)];
			mapMemory[(per_fila + 1)*32 + (per_columna - 1)] = mapData[(per_fila + 1)*32 + (per_columna - 1)];
			mapMemory[(per_fila + 1)*32 + (per_columna - 2)] = mapData[(per_fila + 1)*32 + (per_columna - 2)];
			mapMemory[(per_fila + 2)*32 + per_columna] = mapData[(per_fila + 2)*32 + per_columna];
			mapMemory[(per_fila + 2)*32 + (per_columna + 1)] = mapData[(per_fila + 2)*32 + (per_columna + 1)];
			mapMemory[(per_fila + 2)*32 + (per_columna - 1)] = mapData[(per_fila + 2)*32 + (per_columna - 1)];
		}
	}
	
	else if (direccion == 1) {
		// Para que choque con las paredes y las puertas
		if (mapMemory[(per_fila + 1)*32+per_columna] == 2 || mapMemory[(per_fila + 1)*32+per_columna] == 6 || mapMemory[(per_fila + 1)*32+per_columna] == 13 || mapMemory[(per_fila + 1)*32+per_columna] == 14 || mapMemory[(per_fila + 1)*32+per_columna] == 15){
			
			// Oscurecemos las antiguas teselas
			// Fila central
			mapMemory[per_fila*32 + (per_columna + 1)] = 7;
			mapMemory[per_fila*32 + (per_columna - 1)] = 7;
			mapMemory[per_fila*32 + (per_columna + 2)] = 7;
			mapMemory[per_fila*32 + (per_columna - 2)] = 7;
			// Filas superiores	
			mapMemory[(per_fila - 1)*32 + per_columna] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna + 2)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna - 1)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna - 2)] = 7;
			mapMemory[(per_fila - 2)*32 + per_columna] = 7;
			mapMemory[(per_fila - 2)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila - 2)*32 + (per_columna - 1)] = 7;
			// Filas inferiores
			mapMemory[(per_fila + 1)*32 + per_columna] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna + 2)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna - 1)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna - 2)] = 7;
			mapMemory[(per_fila + 2)*32 + per_columna] = 7;
			mapMemory[(per_fila + 2)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila + 2)*32 + (per_columna - 1)] = 7;
			
			pos_memory = per_fila*32+per_columna;
			mapMemory[pos_memory] = 2;
			mapData[pos_memory] = 2;

			per_fila = per_fila + 1;
			pos_memory = per_fila*32+per_columna;
			
			if(mapData[pos_memory] == 13)
				llaveRoja = 1;
			
			if(mapData[pos_memory] == 14)
				llaveVerde = 1;
			
			if(mapData[pos_memory] == 15)
				llaveNegra = 1;
			
			mapMemory[pos_memory] = 3;
			
			// Iluminamos las nuevas teselas
			// Fila central
			mapMemory[per_fila*32 + (per_columna + 1)] = mapData[per_fila*32 + (per_columna + 1)];
			mapMemory[per_fila*32 + (per_columna - 1)] = mapData[per_fila*32 + (per_columna - 1)];
			mapMemory[per_fila*32 + (per_columna + 2)] = mapData[per_fila*32 + (per_columna + 2)];
			mapMemory[per_fila*32 + (per_columna - 2)] = mapData[per_fila*32 + (per_columna - 2)];
			// Filas superiores	
			mapMemory[(per_fila - 1)*32 + per_columna] = mapData[(per_fila - 1)*32 + per_columna];
			mapMemory[(per_fila - 1)*32 + (per_columna + 1)] = mapData[(per_fila - 1)*32 + (per_columna + 1)];
			mapMemory[(per_fila - 1)*32 + (per_columna + 2)] = mapData[(per_fila - 1)*32 + (per_columna + 2)];
			mapMemory[(per_fila - 1)*32 + (per_columna - 1)] = mapData[(per_fila - 1)*32 + (per_columna - 1)];
			mapMemory[(per_fila - 1)*32 + (per_columna - 2)] = mapData[(per_fila - 1)*32 + (per_columna - 2)];
			mapMemory[(per_fila - 2)*32 + per_columna] = mapData[(per_fila - 2)*32 + per_columna];
			mapMemory[(per_fila - 2)*32 + (per_columna + 1)] = mapData[(per_fila - 2)*32 + (per_columna + 1)];
			mapMemory[(per_fila - 2)*32 + (per_columna - 1)] = mapData[(per_fila - 2)*32 + (per_columna - 1)];
			// Filas inferiores
			mapMemory[(per_fila + 1)*32 + per_columna] = mapData[(per_fila + 1)*32 + per_columna];
			mapMemory[(per_fila + 1)*32 + (per_columna + 1)] = mapData[(per_fila + 1)*32 + (per_columna + 1)];
			mapMemory[(per_fila + 1)*32 + (per_columna + 2)] = mapData[(per_fila + 1)*32 + (per_columna + 2)];
			mapMemory[(per_fila + 1)*32 + (per_columna - 1)] = mapData[(per_fila + 1)*32 + (per_columna - 1)];
			mapMemory[(per_fila + 1)*32 + (per_columna - 2)] = mapData[(per_fila + 1)*32 + (per_columna - 2)];
			mapMemory[(per_fila + 2)*32 + per_columna] = mapData[(per_fila + 2)*32 + per_columna];
			mapMemory[(per_fila + 2)*32 + (per_columna + 1)] = mapData[(per_fila + 2)*32 + (per_columna + 1)];
			mapMemory[(per_fila + 2)*32 + (per_columna - 1)] = mapData[(per_fila + 2)*32 + (per_columna - 1)];
		}
	}
	
	else if (direccion == 2) {
		// Para que choque con las paredes y las puertas
		if (mapMemory[per_fila*32+(per_columna + 1)] == 2 || mapMemory[per_fila*32+(per_columna + 1)] == 6 || mapMemory[per_fila*32+(per_columna + 1)] == 13 || mapMemory[per_fila*32+(per_columna + 1)] == 14 || mapMemory[per_fila*32+(per_columna + 1)] == 15){
			
			// Oscurecemos las antiguas teselas
			// Fila central
			mapMemory[per_fila*32 + (per_columna + 1)] = 7;
			mapMemory[per_fila*32 + (per_columna - 1)] = 7;
			mapMemory[per_fila*32 + (per_columna + 2)] = 7;
			mapMemory[per_fila*32 + (per_columna - 2)] = 7;
			// Filas superiores	
			mapMemory[(per_fila - 1)*32 + per_columna] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna + 2)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna - 1)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna - 2)] = 7;
			mapMemory[(per_fila - 2)*32 + per_columna] = 7;
			mapMemory[(per_fila - 2)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila - 2)*32 + (per_columna - 1)] = 7;
			// Filas inferiores
			mapMemory[(per_fila + 1)*32 + per_columna] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna + 2)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna - 1)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna - 2)] = 7;
			mapMemory[(per_fila + 2)*32 + per_columna] = 7;
			mapMemory[(per_fila + 2)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila + 2)*32 + (per_columna - 1)] = 7;
			
			pos_memory = per_fila*32+per_columna;
			mapMemory[pos_memory] = 2;
			mapData[pos_memory] = 2;
			
			per_columna = per_columna + 1;
			pos_memory = per_fila*32+per_columna;
			
			if(mapData[pos_memory] == 13)
				llaveRoja = 1;
			
			if(mapData[pos_memory] == 14)
				llaveVerde = 1;
			
			if(mapData[pos_memory] == 15)
				llaveNegra = 1;
			
			mapMemory[pos_memory] = 3;
			
			// Iluminamos las nuevas teselas
			// Fila central
			mapMemory[per_fila*32 + (per_columna + 1)] = mapData[per_fila*32 + (per_columna + 1)];
			mapMemory[per_fila*32 + (per_columna - 1)] = mapData[per_fila*32 + (per_columna - 1)];
			mapMemory[per_fila*32 + (per_columna + 2)] = mapData[per_fila*32 + (per_columna + 2)];
			mapMemory[per_fila*32 + (per_columna - 2)] = mapData[per_fila*32 + (per_columna - 2)];
			// Filas superiores	
			mapMemory[(per_fila - 1)*32 + per_columna] = mapData[(per_fila - 1)*32 + per_columna];
			mapMemory[(per_fila - 1)*32 + (per_columna + 1)] = mapData[(per_fila - 1)*32 + (per_columna + 1)];
			mapMemory[(per_fila - 1)*32 + (per_columna + 2)] = mapData[(per_fila - 1)*32 + (per_columna + 2)];
			mapMemory[(per_fila - 1)*32 + (per_columna - 1)] = mapData[(per_fila - 1)*32 + (per_columna - 1)];
			mapMemory[(per_fila - 1)*32 + (per_columna - 2)] = mapData[(per_fila - 1)*32 + (per_columna - 2)];
			mapMemory[(per_fila - 2)*32 + per_columna] = mapData[(per_fila - 2)*32 + per_columna];
			mapMemory[(per_fila - 2)*32 + (per_columna + 1)] = mapData[(per_fila - 2)*32 + (per_columna + 1)];
			mapMemory[(per_fila - 2)*32 + (per_columna - 1)] = mapData[(per_fila - 2)*32 + (per_columna - 1)];
			// Filas inferiores
			mapMemory[(per_fila + 1)*32 + per_columna] = mapData[(per_fila + 1)*32 + per_columna];
			mapMemory[(per_fila + 1)*32 + (per_columna + 1)] = mapData[(per_fila + 1)*32 + (per_columna + 1)];
			mapMemory[(per_fila + 1)*32 + (per_columna + 2)] = mapData[(per_fila + 1)*32 + (per_columna + 2)];
			mapMemory[(per_fila + 1)*32 + (per_columna - 1)] = mapData[(per_fila + 1)*32 + (per_columna - 1)];
			mapMemory[(per_fila + 1)*32 + (per_columna - 2)] = mapData[(per_fila + 1)*32 + (per_columna - 2)];
			mapMemory[(per_fila + 2)*32 + per_columna] = mapData[(per_fila + 2)*32 + per_columna];
			mapMemory[(per_fila + 2)*32 + (per_columna + 1)] = mapData[(per_fila + 2)*32 + (per_columna + 1)];
			mapMemory[(per_fila + 2)*32 + (per_columna - 1)] = mapData[(per_fila + 2)*32 + (per_columna - 1)];
		}
	}
	
	else {
		// Para que choque con las paredes y las puertas
		if (mapMemory[per_fila*32+(per_columna - 1)] == 2 || mapMemory[per_fila*32+(per_columna - 1)] == 6 || mapMemory[per_fila*32+(per_columna - 1)] == 13 || mapMemory[per_fila*32+(per_columna - 1)] == 14 || mapMemory[per_fila*32+(per_columna - 1)] == 15){
		
			// Oscurecemos las antiguas teselas
			// Fila central
			mapMemory[per_fila*32 + (per_columna + 1)] = 7;
			mapMemory[per_fila*32 + (per_columna - 1)] = 7;
			mapMemory[per_fila*32 + (per_columna + 2)] = 7;
			mapMemory[per_fila*32 + (per_columna - 2)] = 7;
			// Filas superiores	
			mapMemory[(per_fila - 1)*32 + per_columna] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna + 2)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna - 1)] = 7;
			mapMemory[(per_fila - 1)*32 + (per_columna - 2)] = 7;
			mapMemory[(per_fila - 2)*32 + per_columna] = 7;
			mapMemory[(per_fila - 2)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila - 2)*32 + (per_columna - 1)] = 7;
			// Filas inferiores
			mapMemory[(per_fila + 1)*32 + per_columna] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna + 2)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna - 1)] = 7;
			mapMemory[(per_fila + 1)*32 + (per_columna - 2)] = 7;
			mapMemory[(per_fila + 2)*32 + per_columna] = 7;
			mapMemory[(per_fila + 2)*32 + (per_columna + 1)] = 7;
			mapMemory[(per_fila + 2)*32 + (per_columna - 1)] = 7;
			
			pos_memory = per_fila*32+per_columna;
			mapMemory[pos_memory] = 2;
			mapData[pos_memory] = 2;

			per_columna = per_columna - 1;
			pos_memory = per_fila*32+per_columna;
			
			if(mapData[pos_memory] == 13)
				llaveRoja = 1;
			
			if(mapData[pos_memory] == 14)
				llaveVerde = 1;
			
			if(mapData[pos_memory] == 15)
				llaveNegra = 1;
			
			mapMemory[pos_memory] = 3;
			
			// Iluminamos las nuevas teselas
			// Fila central
			mapMemory[per_fila*32 + (per_columna + 1)] = mapData[per_fila*32 + (per_columna + 1)];
			mapMemory[per_fila*32 + (per_columna - 1)] = mapData[per_fila*32 + (per_columna - 1)];
			mapMemory[per_fila*32 + (per_columna + 2)] = mapData[per_fila*32 + (per_columna + 2)];
			mapMemory[per_fila*32 + (per_columna - 2)] = mapData[per_fila*32 + (per_columna - 2)];
			// Filas superiores	
			mapMemory[(per_fila - 1)*32 + per_columna] = mapData[(per_fila - 1)*32 + per_columna];
			mapMemory[(per_fila - 1)*32 + (per_columna + 1)] = mapData[(per_fila - 1)*32 + (per_columna + 1)];
			mapMemory[(per_fila - 1)*32 + (per_columna + 2)] = mapData[(per_fila - 1)*32 + (per_columna + 2)];
			mapMemory[(per_fila - 1)*32 + (per_columna - 1)] = mapData[(per_fila - 1)*32 + (per_columna - 1)];
			mapMemory[(per_fila - 1)*32 + (per_columna - 2)] = mapData[(per_fila - 1)*32 + (per_columna - 2)];
			mapMemory[(per_fila - 2)*32 + per_columna] = mapData[(per_fila - 2)*32 + per_columna];
			mapMemory[(per_fila - 2)*32 + (per_columna + 1)] = mapData[(per_fila - 2)*32 + (per_columna + 1)];
			mapMemory[(per_fila - 2)*32 + (per_columna - 1)] = mapData[(per_fila - 2)*32 + (per_columna - 1)];
			// Filas inferiores
			mapMemory[(per_fila + 1)*32 + per_columna] = mapData[(per_fila + 1)*32 + per_columna];
			mapMemory[(per_fila + 1)*32 + (per_columna + 1)] = mapData[(per_fila + 1)*32 + (per_columna + 1)];
			mapMemory[(per_fila + 1)*32 + (per_columna + 2)] = mapData[(per_fila + 1)*32 + (per_columna + 2)];
			mapMemory[(per_fila + 1)*32 + (per_columna - 1)] = mapData[(per_fila + 1)*32 + (per_columna - 1)];
			mapMemory[(per_fila + 1)*32 + (per_columna - 2)] = mapData[(per_fila + 1)*32 + (per_columna - 2)];
			mapMemory[(per_fila + 2)*32 + per_columna] = mapData[(per_fila + 2)*32 + per_columna];
			mapMemory[(per_fila + 2)*32 + (per_columna + 1)] = mapData[(per_fila + 2)*32 + (per_columna + 1)];
			mapMemory[(per_fila + 2)*32 + (per_columna - 1)] = mapData[(per_fila + 2)*32 + (per_columna - 1)];
		}
	}
}

// Ataque del personaje
void AtacarPersonaje(int direccion) {
	if (direccion == 0) {
		if (mapMemory[(per_fila - 1)*32+per_columna] == 4){
			mapMemory[(per_fila - 1)*32+per_columna] = 6;
			mapData[(per_fila - 1)*32+per_columna] = 2;
			enemigosMuertos++;
		}
		
		else if(mapMemory[(per_fila - 1)*32+per_columna] == 16){
			mapMemory[(per_fila - 1)*32+per_columna] = 6;
			vidasBoss--;
		}
	}
	
	else if (direccion == 1) {
		if (mapMemory[(per_fila + 1)*32+per_columna] == 4){
			mapMemory[(per_fila + 1)*32+per_columna] = 6;
			mapData[(per_fila + 1)*32+per_columna] = 2;
			enemigosMuertos++;			
		}
		
		else if(mapMemory[(per_fila + 1)*32+per_columna] == 16){
			mapMemory[(per_fila + 1)*32+per_columna] = 6;
			vidasBoss--;
		}
	}
	
	else if (direccion == 2) {
		if (mapMemory[per_fila*32+(per_columna + 1)] == 4){
			mapMemory[per_fila*32+(per_columna + 1)] = 6;
			mapData[per_fila*32+(per_columna + 1)] = 2;
			enemigosMuertos++;		
		}
		
		else if(mapMemory[per_fila*32+(per_columna + 1)] == 16){
			mapMemory[per_fila*32+(per_columna + 1)] = 6;
			vidasBoss--;
		}
	}
	
	else {
		if (mapMemory[per_fila*32+(per_columna - 1)] == 4){
			mapMemory[per_fila*32+(per_columna - 1)] = 6;
			mapData[per_fila*32+(per_columna - 1)] = 2;
			enemigosMuertos++;
		}
		
		else if(mapMemory[per_fila*32+(per_columna - 1)] == 16){
			mapMemory[per_fila*32+(per_columna - 1)] = 6;
			vidasBoss--;
		}
	}	
}

// Movimiento hacia la izquierda de las arañas
void Timer() {
	if (estadoJuego == 1){
		for(int i = 0; i < 23; i++){
			for(int j = 0; j < 32; j++){
				int fila = i;
				int columna = j;
				int actual = 4;
				int pos_memory;
				pos_memory = fila*32+columna;
				if(mapMemory[pos_memory] == 4 && izquierda == 0 && (mapMemory[fila*32+(columna - 1)] == 3 || mapMemory[fila*32+(columna - 1)] == 2)){
					mapMemory[pos_memory] = 2;
					mapData[pos_memory] = 2;
					columna = columna - 1;
					pos_memory = fila*32+columna;
					if (mapMemory[pos_memory] == 3){
						vidas--;
						enemigosMuertos++;
						actual = 3;
						if(vidas == 0){
							gameOver = 1;
							estadoJuego = 0;
						}
					}
					if (actual == 3)
						mapMemory[pos_memory] = actual;
					
					else{
						mapMemory[pos_memory] = actual;
						mapData[pos_memory] = actual;
					}
				}
			}
		}
		izquierda = 1;
	}
}

// Movimiento hacia la derecha de las arañas
void Timer2() {
	if (estadoJuego == 1){
		for(int i = 0; i < 23; i++){
			for(int j = 31; j >= 0; j--){
				int fila = i;
				int columna = j;
				int actual = 4;
				int pos_memory;
				pos_memory = fila*32+columna;
				if(mapMemory[pos_memory] == 4 && izquierda == 1 && (mapMemory[fila*32+(columna + 1)] == 2 || mapMemory[fila*32+(columna + 1)] == 3)){
					mapMemory[pos_memory] = 2;
					mapData[pos_memory] = 2;
					columna = columna + 1;
					pos_memory = fila*32+columna;
					if (mapMemory[pos_memory] == 3){
						vidas--;
						enemigosMuertos++;
						actual = 3;
						if(vidas == 0){
							gameOver = 1;
							estadoJuego = 0;
						}
					}
					
					if (actual == 3)
						mapMemory[pos_memory] = actual;
					
					else{
						mapMemory[pos_memory] = actual;
						mapData[pos_memory] = actual;
					}
				}
			}
		}
		izquierda = 0;
	}	
}

// Movimiento random del enemigo principal
void Timer3() {
	if(estadoJuego == 1 && vidasBoss > 0){
		for(int i = 0; i < 23; i++){
			for(int j = 31; j >= 0; j--){
				int fila = i;
				int columna = j;
				int pos_memory;
				pos_memory = fila*32+columna;
				if(mapMemory[pos_memory] == 16){
					double numero = closed_interval_rand(0.0,2.0);
					double alfa = 0.5;
					double beta = 1.0;
					double omega = 1.5;
					if(numero < alfa && (mapMemory[(fila - 1)*32+columna] == 2  || mapMemory[(fila - 1)*32+columna] == 3)){
						mapMemory[pos_memory] = 2;
						mapData[pos_memory] = 2;
						
						mapMemory[(fila - 1)*32+columna] = 16;
						mapData[(fila - 1)*32+columna] = 16;
						if(mapMemory[(fila - 2)*32+columna] == 1){
							mapMemory[(fila - 1)*32+columna] = 2;
							mapData[(fila - 1)*32+columna] = 2;
							
							mapMemory[(fila + 4)*32+columna] = 16;
							mapData[(fila + 4)*32+columna] = 16;
						}
						
						if (mapMemory[pos_memory] == 3){
							vidas--;
							vidasBoss--;
							if(vidas == 0){
								gameOver = 1;
								estadoJuego = 0;
							}
							
							if(mapMemory[(fila + 1)*32+columna] == 1){
								mapMemory[(fila - 1)*32+columna] = 16;
								mapData[(fila - 1)*32+columna] = 16;
							}
							
							else{
								mapMemory[(fila + 1)*32+columna] = 16;
								mapData[(fila + 1)*32+columna] = 16;
							}
						}	
					}
					
					else if(alfa < numero && numero < beta && (mapMemory[(fila + 1)*32+columna] == 2  || mapMemory[(fila + 1)*32+columna] == 3)){
						mapMemory[pos_memory] = 2;
						mapData[pos_memory] = 2;
						
						mapMemory[(fila + 1)*32+columna] = 16;
						mapData[(fila + 1)*32+columna] = 16;
						
						if(mapMemory[(fila + 2)*32+columna] == 1){
							mapMemory[(fila + 1)*32+columna] = 2;
							mapData[(fila + 1)*32+columna] = 2;
							
							mapMemory[(fila - 4)*32+columna] = 16;
							mapData[(fila - 4)*32+columna] = 16;
						}
						
						if (mapMemory[pos_memory] == 3){
							vidas--;
							vidasBoss--;
							if(vidas == 0){
								gameOver = 1;
								estadoJuego = 0;
							}
							
							if(mapMemory[(fila + 1)*32+columna] == 1){
								mapMemory[(fila - 1)*32+columna] = 16;
								mapData[(fila - 1)*32+columna] = 16;
							}
							
							else{
								mapMemory[(fila + 1)*32+columna] = 16;
								mapData[(fila + 1)*32+columna] = 16;
							}
							
						}
					}
					
					else if(beta < numero && omega < beta && (mapMemory[fila*32+(columna - 1)] == 2  || mapMemory[fila*32+(columna - 1)] == 3)){
						mapMemory[pos_memory] = 2;
						mapData[pos_memory] = 2;
						
						mapMemory[fila*32+(columna - 1)] = 16;
						mapData[fila*32+(columna - 1)] = 16;
						
						if(mapMemory[fila*32+(columna - 2)] == 1){
							mapMemory[fila*32+(columna - 1)] = 2;
							mapData[fila*32+(columna - 1)] = 2;
							
							mapMemory[fila*32+(columna + 7)] = 16;
							mapData[fila*32+(columna + 7)] = 16;
						}
						
						if (mapMemory[pos_memory] == 3){
							vidas--;
							vidasBoss--;
							if(vidas == 0){
								gameOver = 1;
								estadoJuego = 0;
							}
							
							if(mapMemory[(fila + 1)*32+columna] == 1){
								mapMemory[(fila - 1)*32+columna] = 16;
								mapData[(fila - 1)*32+columna] = 16;
							}
							
							else{
								mapMemory[(fila + 1)*32+columna] = 16;
								mapData[(fila + 1)*32+columna] = 16;
							}
						}
					}
					
					else if(omega < numero && (mapMemory[fila*32+(columna + 1)] == 2  || mapMemory[fila*32+(columna + 1)] == 3)){
						mapMemory[pos_memory] = 2;
						mapData[pos_memory] = 2;
						
						mapMemory[fila*32+(columna + 1)] = 16;
						mapData[fila*32+(columna + 1)] = 16;
						
						if(mapMemory[fila*32+(columna + 2)] == 1){
							mapMemory[fila*32+(columna + 1)] = 2;
							mapData[fila*32+(columna + 1)] = 2;
							
							mapMemory[fila*32+(columna - 7)] = 16;
							mapData[fila*32+(columna - 7)] = 16;
						}
						
						if (mapMemory[pos_memory] == 3){
							vidas--;
							vidasBoss--;
							if(vidas == 0){
								gameOver = 1;
								estadoJuego = 0;
							}
						}
					}
				}
			}
		}
	}
	
	else if(vidasBoss <= 0){
		estadoJuego = 2;
		hasGanado = 1;
	}
}

// Construimos el mapa inferior oscuro y iluminamos lo necesario
void ConstruirMapaInferior() {
	int pos_mapData = 0;
	
	for(int fila=0;fila<24;fila++)
	{
		for(int columna=0;columna<32;columna++)
		{
			int pos_mapMemory = fila*32+columna;
			mapMemory[pos_mapMemory] = 7;
			pos_mapData++;
		}
	}
	
	// Iluminamos las teselas de alrededor del personaje
	// Fila central
	mapMemory[per_fila*32 + per_columna] = mapData[per_fila*32 + per_columna];
	mapMemory[per_fila*32 + (per_columna + 1)] = mapData[per_fila*32 + (per_columna + 1)];
	mapMemory[per_fila*32 + (per_columna - 1)] = mapData[per_fila*32 + (per_columna - 1)];
	mapMemory[per_fila*32 + (per_columna + 2)] = mapData[per_fila*32 + (per_columna + 2)];
	mapMemory[per_fila*32 + (per_columna - 2)] = mapData[per_fila*32 + (per_columna - 2)];
	
	// Filas superiores	
	mapMemory[(per_fila - 1)*32 + per_columna] = mapData[(per_fila - 1)*32 + per_columna];
	mapMemory[(per_fila - 1)*32 + (per_columna + 1)] = mapData[(per_fila - 1)*32 + (per_columna + 1)];
	mapMemory[(per_fila - 1)*32 + (per_columna + 2)] = mapData[(per_fila - 1)*32 + (per_columna + 2)];
	mapMemory[(per_fila - 1)*32 + (per_columna - 1)] = mapData[(per_fila - 1)*32 + (per_columna - 1)];
	mapMemory[(per_fila - 1)*32 + (per_columna - 2)] = mapData[(per_fila - 1)*32 + (per_columna - 2)];
	mapMemory[(per_fila - 2)*32 + per_columna] = mapData[(per_fila - 2)*32 + per_columna];
	mapMemory[(per_fila - 2)*32 + (per_columna + 1)] = mapData[(per_fila - 2)*32 + (per_columna + 1)];
	mapMemory[(per_fila - 2)*32 + (per_columna - 1)] = mapData[(per_fila - 2)*32 + (per_columna - 1)];
	
	// Filas inferiores
	mapMemory[(per_fila + 1)*32 + per_columna] = mapData[(per_fila + 1)*32 + per_columna];
	mapMemory[(per_fila + 1)*32 + (per_columna + 1)] = mapData[(per_fila + 1)*32 + (per_columna + 1)];
	mapMemory[(per_fila + 1)*32 + (per_columna + 2)] = mapData[(per_fila + 1)*32 + (per_columna + 2)];
	mapMemory[(per_fila + 1)*32 + (per_columna - 1)] = mapData[(per_fila + 1)*32 + (per_columna - 1)];
	mapMemory[(per_fila + 1)*32 + (per_columna - 2)] = mapData[(per_fila + 1)*32 + (per_columna - 2)];
	mapMemory[(per_fila + 2)*32 + per_columna] = mapData[(per_fila + 2)*32 + per_columna];
	mapMemory[(per_fila + 2)*32 + (per_columna + 1)] = mapData[(per_fila + 2)*32 + (per_columna + 1)];
	mapMemory[(per_fila + 2)*32 + (per_columna - 1)] = mapData[(per_fila + 2)*32 + (per_columna - 1)];
}

// Eliminamos las puertas al conseguir los objetivos
void EliminarPuertas() {
	
	// Abrir puerta amarilla
	if(enemigosMuertos == 5){
		for(int fila=0;fila<24;fila++)
		{
			for(int columna=0;columna<32;columna++)
			{
				int pos_mapMemory = fila*32+columna;
				if(mapMemory[pos_mapMemory] == 9){
					mapMemory[pos_mapMemory] = 2;
					mapData[pos_mapMemory] = 2;
				}
			}
		}
	}
	
	// Abrir puerta roja
	else if(enemigosMuertos == 12 && llaveRoja == 1){
		for(int fila=0;fila<24;fila++)
		{
			for(int columna=0;columna<32;columna++)
			{
				int pos_mapMemory = fila*32+columna;
				if(mapMemory[pos_mapMemory] == 8){
					mapMemory[pos_mapMemory] = 2;
					mapData[pos_mapMemory] = 2;
				}			
			}
		}
	}
	
	// Abrir puerta verde
	else if(enemigosMuertos == 25 && llaveVerde == 1){
		for(int fila=0;fila<24;fila++)
		{
			for(int columna=0;columna<32;columna++)
			{
				int pos_mapMemory = fila*32+columna;
				if(mapMemory[pos_mapMemory] == 10){
					mapMemory[pos_mapMemory] = 2;
					mapData[pos_mapMemory] = 2;
				}			
			}
		}
	}
	
	// Abrir puerta negra
	else if(enemigosMuertos == 27 && llaveNegra == 1){
		for(int fila=0;fila<24;fila++)
		{
			for(int columna=0;columna<32;columna++)
			{
				int pos_mapMemory = fila*32+columna;
				if(mapMemory[pos_mapMemory] == 11){
					mapMemory[pos_mapMemory] = 2;
					mapData[pos_mapMemory] = 2;
				}			
			}
		}
	}
	
	// Abrir puerta blanca
	else if(enemigosMuertos == 31){
		for(int fila=0;fila<24;fila++)
		{
			for(int columna=0;columna<32;columna++)
			{
				int pos_mapMemory = fila*32+columna;
				if(mapMemory[pos_mapMemory] == 12){
					mapMemory[pos_mapMemory] = 2;
					mapData[pos_mapMemory] = 2;
				}			
			}
		}
	}
}

void Objetivos() {
	// Objetivos puerta amarilla
	if(enemigosMuertos <= 5){
		iprintf("\x1b[9;6HDerrota a %d enemigos", 5 - enemigosMuertos);
	
				
		if(enemigosMuertos == 5)
			llaveRoja = 0;	
	}
			
	// Objetivos puerta roja
	if((enemigosMuertos >= 5 && enemigosMuertos <= 12) || llaveRoja == 0){
		if(enemigosMuertos == 12)
			iprintf("\x1b[9;6HENEMIGOS DERROTADOS              ");
				
		else
			iprintf("\x1b[9;6HDerrota a %d enemigos", 12 - enemigosMuertos);
				
		if(llaveRoja == 1)
			iprintf("\x1b[11;5H  LLAVE ENCONTRADA        ");
				
		else
			iprintf("\x1b[11;5HEncuentra la llave roja");	
				
		if(enemigosMuertos == 12 && llaveRoja == 1)
			llaveVerde = 0;
	}
			
	// Objetivos puerta verde
	if((enemigosMuertos >= 12 && enemigosMuertos <= 25 && llaveRoja == 1) || (llaveVerde == 0 && llaveRoja == 1)){
		if(enemigosMuertos == 25)
			iprintf("\x1b[9;6HENEMIGOS DERROTADOS              ");
		
		else
			iprintf("\x1b[9;6HDerrota a %d enemigos", 25 - enemigosMuertos);
		
		if(llaveVerde == 1)
			iprintf("\x1b[11;5H  LLAVE ENCONTRADA        ");					
		
		else
			iprintf("\x1b[11;5HEncuentra la llave verde");
		
		if(enemigosMuertos == 25 && llaveVerde == 1)
			llaveNegra = 0;
	}
	
	// Objetivos puerta negra
	if((enemigosMuertos >= 25 && enemigosMuertos <= 27 && llaveVerde == 1) || (llaveNegra == 0 && llaveVerde == 1)){
		if(enemigosMuertos == 27)
			iprintf("\x1b[9;6HENEMIGOS DERROTADOS              ");
		
		else
			iprintf("\x1b[9;6HDerrota a %d enemigos", 27 - enemigosMuertos);
		
		if(llaveNegra == 1)
			iprintf("\x1b[11;5H  LLAVE ENCONTRADA        ");
		
		else
			iprintf("\x1b[11;5HEncuentra la llave negra");
	}
	
	// Objetivos puerta blanca
	if(enemigosMuertos >= 27 && llaveNegra && enemigosMuertos < 31 && llaveNegra == 1){
		iprintf("\x1b[9;6HDerrota a %d enemigos", 31 - enemigosMuertos);
		iprintf("\x1b[11;5H                                          ");
	}
	
	if(enemigosMuertos == 31 && llaveNegra == 1){
		iprintf("\x1b[9;6H                                           ");
		iprintf("\x1b[9;6HParece que tu amigo");
		iprintf("\x1b[11;6Hha sido poseido");
		iprintf("\x1b[13;6HTIENES QUE SALVARLE!");
	}
	
	// Vidas
	if(vidas > 1)
		iprintf("\x1b[18;11HVIDAS: %d", vidas);
	else if (vidas == 1){
		iprintf("\x1b[18;7HTE QUEDA %d VIDA!!", vidas);		
	}
}


