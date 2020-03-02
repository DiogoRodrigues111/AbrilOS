/*  Abril Operating System
    Desenvolvido por Diogo Rodrigues Roessler - 2020
*/

//----------------- Defines ----------------------------------------

// Define uma entrada para um parametro
#define IN

// Input de parametros com valor especificado.
#define __In__				// Sem Implementa��o ainda

// Input & Output de parametros com valor especificado.
#define __In_out__			// Sem Implementa��o ainda

// Input & Output & OPTIONAL de parametros com valor especificado.
#define __In_Out_Op__		// Sem Implementa��o ainda

// Define um parametro Opcional, sem necessidade de aten��o
#define OPTIONAL			__attribute__((unused))

// Define Uma Sa�da para um parametro
#define OUT					// Valor default

// Define PARAMETRO como IN
#define PARAM				IN

// Define KERNEL STATUS
#define KERNEL
#define KSTATUS

// Output de parametros com valor especificado.
#define __Out__				// Sem Implementa��o ainda

// volatile keyword
#define VOLATILE			volatile

// Define nullable
#define __null              ((PVOID)0)
#define null                ((pvoid)0)

#define FRMWORK             