/*  Abril Operating System
    Desenvolvido por Diogo Rodrigues Roessler - 2020
*/

#include "types/define.h"
#include "types/types.h"

// Endereço
#define BSOD_ADDRESS 0xB8000

// tamanho
#define BUFSIZE 2200

// Guarda em Buffer
word_t* bsod_buffer;

// BSOD bordas
#define BSOD_MAX_WIDTH 80
#define BSOD_MAX_HEIGHT 25

// Bordas
#define BOX_MAX_WIDTH 78
#define BOX_MAX_HEIGHT 23

// Linhas
#define BOX_SINGLELINE 1
#define BOX_DOUBLELINE 2

// BSOD tipos de cores
enum bsod_color {
    PRETO               =   0,  /* default */
    AZUL                =   1,
    VERDE               =   2,
    CYAN                =   3,
    VERMELHO            =   4,
    MAGENTA             =   5,
    MARROM              =   6,
    CINZA               =   7,
    CINZA_ESCURO        =   8,
    AZUL_BRILHANTE      =   9,
    VERDE_BRILHANTE     =   10,
    BRIGHT_CYAN         =   11,
    VERMELHO_BRILHANTE  =   12,
    BRIGHT_MAGENTA      =   13,
    AMARELO             =   14,
    BRANCO              =   15
};