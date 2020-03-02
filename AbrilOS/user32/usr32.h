/*  Abril Operating System
    Desenvolvido por Diogo Rodrigues Roessler - 2020
*/

#include "../kernel/types/types.h"
#include "../kernel/types/define.h"

/*** Diagrama esquemático do funcionamento do programa     
                                    ----------------------              ----------------------
                                    |                   |               |                   |
                                    |                   |               |                   |
    --------                        |                   |               |                   |                                                                   
    |       |                       |      KERNEL       |    LOADING    |   USER DESKTOP    |                           
    | BOOT  |        --->           |                   |     -->       |                   |                                 
    |       |                       |                   |               |                   |                           
    |       |                       |                   |               |                   |                           
    --------                        |                   |               |                   | 
                                    ---------------------               --------------------
 */

/* 
-------------------------------------------------------------
\COMMENT : Deixe somente comentarios a respeito da rotina.
\RETURN  : Deixa comentarios sobre retornos da rotina. 
-------------------------------------------------------------
    \COMMENT:
        A struct carrega a interface
    
    \RETURN
        Obtém acesso a interface
------------------------------------------------------------- 
 */
struct open_desktop {
    long_t obtem;
    uint_t recebe;
    DWORD new_value;
    wchar_pt name;
};

/* 
-------------------------------------------------------------
\COMMENT : Deixe somente comentarios a respeito da rotina.
\RETURN  : Deixa comentarios sobre retornos da rotina. 
-------------------------------------------------------------
    \COMMENT:
        Obtém uma checagem rapida se o kernel foi carregado
            corretamente, para chamar a proxima struct.
    
    \RETURN
        Obtém uma checagem do kernel status
------------------------------------------------------------- 
 */
struct check_kernel_success {
    LONG Return;
    dword_t status;
};

/* 
-------------------------------------------------------------
\COMMENT : Deixe somente comentarios a respeito da rotina.
\RETURN  : Deixa comentarios sobre retornos da rotina. 
-------------------------------------------------------------
    \COMMENT:
        Depois que tudo foi checado, então executa os
            processos do sistema operacional.
    
    \RETURN
        Obtém o carregamento do sistema operacional.
------------------------------------------------------------- 
 */
struct load_abril_success {
    word_t check;
    uint_t recebe_e_envia;
    dword_t manda_exec;
};

/* 
-------------------------------------------------------------
\COMMENT : Deixe somente comentarios a respeito da rotina.
\RETURN  : Deixa comentarios sobre retornos da rotina. 
-------------------------------------------------------------
    \COMMENT:
        Se houver error gravissimos, retorna BSOD do
            carregamento do abril os por completo.
    
    \RETURN
        Obtém errors do carregamento do sistema operacional.
------------------------------------------------------------- 
 */
struct load_abril_error {
    SHORT check;
    USHORT manda;
    DWORD status;
};

/* 
-------------------------------------------------------------
\COMMENT : Deixe somente comentarios a respeito da rotina.
\RETURN  : Deixa comentarios sobre retornos da rotina. 
-------------------------------------------------------------
    \COMMENT:
        Emite um error de BSOD caso o kernel entre em Panico.
    
    \RETURN
        Obtém errors de kernel gravissimos que empedem o
            funcionamento do sistema.
------------------------------------------------------------- 
 */
struct kernel_error_panic_bsod {
    SHORT check;
    USHORT manda;
    DWORD status;
};

/* 
-------------------------------------------------------------
\COMMENT : Deixe somente comentarios a respeito da rotina.
\RETURN  : Deixa comentarios sobre retornos da rotina. 
-------------------------------------------------------------
    \COMMENT:
        Recebe BSOD caso não o kernel não consiga acessar o
            local do User Desktop.
    
    \RETURN
        Obtém BSOD do User 32 Open Desktop.
------------------------------------------------------------- 
 */
struct open_desktop_error_bsod {
    SHORT check;
    USHORT manda;
    DWORD status;
};

/* 
-------------------------------------------------------------
\COMMENT : Deixe somente comentarios a respeito da rotina.
\RETURN  : Deixa comentarios sobre retornos da rotina. 
-------------------------------------------------------------
    \COMMENT:
        Varia os errors conforme o nível de gravidade feita
            pelo usuário.
    
    \RETURN
        CORRETO, Normal.
        MEDIO, Se Recupera
        GRAVE, Se recupera mais tem necessidade de reiniciar.
        ERROR, Sistema falhado necessidade de reinicio.
------------------------------------------------------------- 
 */
enum funcionamento_correto_do_sistema {
    CORRETO = 0x0000,
    MEDIO   = 0x00FF,
    GRAVE   = 0x0FFF,
    ERROR   = 0xFFFF    // BSOD
};

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
BOOLEAN FRMWORK 
OpenDesktop(IN struct open_desktop * desktop, IN ULONG oldRecebe);

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
BOOLEAN FRMWORK 
LoadAbrilKernelSuccess(
    IN struct open_desktop * desktop,
    IN struct check_kernel_success * kernel, 
    IN struct load_abril_success *load, 
    OUT enum funcionamento_correto_do_sistema * newSis);