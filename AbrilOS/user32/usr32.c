/*  Abril Operating System
    Desenvolvido por Diogo Rodrigues Roessler - 2020
*/

#include "usr32.h"

/*
-------------------------------------------------------------
\FILE : Proposito do arquivo.
-------------------------------------------------------------
    \FILE
        Destina-se a checagem do kernel e também o 
            carregamento do Desktop.
------------------------------------------------------------- 
 */

/* Entrada do Usuário, para o Ambiente */
BOOLEAN FRMWORK 
OpenDesktop(IN struct open_desktop * desktop, IN ULONG oldRecebe)
/* 
-------------------------------------------------------------
\COMMENT : Deixe somente comentarios a respeito da rotina.
\RETURN  : Deixa comentarios sobre retornos da rotina. 
-------------------------------------------------------------
    \COMMENT:
        Inicia o funcionamento do sistema por completo.
        
        Se não houver errors GRAVES ou Pior então inicia.
    
    \RETURN
        Obtém o resultado final do processo de init.
        Se houver errors imediatamente recebe um BSOD.
------------------------------------------------------------- 
 */
{
    return false;
}

/* Check e manda informação a respeito do sistema e do kernel */
BOOLEAN FRMWORK 
LoadAbrilKernelSuccess(
    IN struct open_desktop * desktop,
    IN struct check_kernel_success * kernel, 
    IN struct load_abril_success *load, 
    OUT enum funcionamento_correto_do_sistema * newSis)
/* 
-------------------------------------------------------------
\COMMENT : Deixe somente comentarios a respeito da rotina.
\RETURN  : Deixa comentarios sobre retornos da rotina. 
-------------------------------------------------------------
    \COMMENT:
        É o Load Abril OS Successfully

        Faz uma checagem no Kernel 
            e depois no Abril Open Desktop.
        
        Caso esteja tudo CORRETO(enum) então carrega o
            OpenDesktop(rotina).
    
    \RETURN
        Retorna a checagem do Kernel caso CORRETO(enum)
            o usuário pode proseguit.
        
        Caso o Kernel estiver CORRETO(enum) o sistema ops
            carrega as funcionalidades do Abril por completo.

------------------------------------------------------------- 
 */
{
    return false;
}