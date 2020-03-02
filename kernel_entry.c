/*  Abril Operating System
    Desenvolvido por Diogo Rodrigues Roessler - 2020
*/

#include "bsod.h"
#include "utils/utils.h"
#include "types/define.h"
#include "types/types.h"

/* Entrada do kernel */
KSTATUS
VOID kernel_entry(void)
/* 
-------------------------------------------------------------
\COMMENT : Deixe somente comentarios a respeito da rotina.
\RETURN  : Deixa comentarios sobre retornos da rotina. 
-------------------------------------------------------------
    \COMMENT:
        Entrada do Kernel
    
    \RETURN
        Obtém a execução do sistema
-------------------------------------------------------------
*/
{
    
}

struct multiboot_header {
    /* Must be MULTIBOOT_MAGIC - see above.  */
  UINT MAGIC;

  /* Feature flags.  */
  UINT FLAGS;

  /* The above fields plus this one must equal 0 mod 2^32. */
  UINT CHECKSUM;

} __attribute__((section(".multiboot")));