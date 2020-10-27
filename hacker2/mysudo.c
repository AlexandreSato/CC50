#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <shadow.h>

/* [mysudo.c]
 * Esse programa simula o comportamento do sudo.
 * Ele basicamente autentica um usuário para
 * depois executar comandos como root.
 *
 * Atenção: Esse é um programa didático, criado
 * somente para propósitos educacionais.
 *
 * [Autor]
 * Marcos Paulo Ferreira (Daemonio)
 * undefinido gmail com
 * https://daemoniolabs.wordpress.com
 *
 * [Como compilar]
 * Como root:
 * # gcc -o mysudo mysudo.c -lcrypt
 *
 * Em seguida, ative o suid bit:
 * # chmod +s mysudo
 *
 * [Como executar]
 * Como usuário qualquer:
 * $ ./mysudo <comando> [argumentos do comando]
 * OBS: <comando> deve ser indicado com o caminho completo.
 *
 * [Exemplo]
 * $ ./mysudo /bin/cat /etc/shadow
 *
 * [+] Versão 1.0, by daemonio @ Dom Ago 21 00:48:30 BRT 2011
 * [+] Versão 1.1, by daemonio @ Wed Jun 13 04:00:42 BRT 2012
 *     - Acentuação e organização dos comentários.
 *     - Retirada da função setreuid(). Ela só fazia sentido
 *       se o comando fosse executado via system().
 *       Utilizando execve(), ela não é mais necessária.
 */

int main(int argc, char **argv, char **env) {
    /* Estrutura do arquivo /etc/passwd. */
    struct passwd *usuario ;
    /* Estrutura do arquivo /etc/shadow. */
    struct spwd *hum ; 
    /* Senha digitada pelo usuário. */
    char *typedpass ;
    /* Hash da senha digitada. */
    char *cryptpass ;
    /* Controlador da quantidade de
     * vezes que se pode errar a senha. */
    char count ;
    /* Usada para mostrar o prompt de
     * senha. */
    char mysudo_prompt[101] ;

    /* Testa linha de comando. */
    if ( argc == 1 ) {
        printf("[uso] %s <comando> [<argumentos do comando>]\n", argv[0]) ;
        return -1 ;
    }

    /* Como acessamos os campos do arquivo
     * /etc/shadow, devemos ter privilégios de
     * super usuário. */
    if ( geteuid() != 0 ) {
        printf("Esse programa nao tem privilegios de root.\n") ;
        return -1 ;
    }

    /* Obtém o nome do usuário através do UID. */
    usuario = getpwuid(getuid()) ;

    /* Obtém as informações no arquivo shadow. */
    hum = getspnam(usuario->pw_name) ;

    /* Testamos a saída a função, só por segurança... */
    if ( hum == NULL ) {
        printf("Usuario nao encontrado: %s\n", argv[1]) ;
        return -1;
    }

    /* Prompt. */
    sprintf(mysudo_prompt, "[mysudo] password for %s:", usuario->pw_name) ;

    count = 0 ;
    while ( count < 3 ) {
        /* Obtém a senha digitada. */
        typedpass = (char *)getpass(mysudo_prompt) ;

        /* Calcula o hash da senha usando crypt(). */
        cryptpass = (char *)crypt(typedpass, hum->sp_pwdp) ;

        /* Se os hashes são iguais, finaliza o loop. */
        if ( ! strcmp(cryptpass, hum->sp_pwdp) ) break ;

        sleep(2) ;
        printf("Sorry, try again.\n") ;
        count++ ;
    }

    /* 3 tentativas erradas. */
    if ( count == 3 ) {
        /* Aqui poderíamos colocar um syslog()
         * para alertar o administrador sobre
         * tentativas fracassadas de autenticação.
         */
        return -1 ;
    }

    /* Por segurança, limpa-se a senha na memória. */
    memset(typedpass, 0x0, strlen(typedpass)) ;

    /* Executa o comando com seus argumentos. */
    if ( execve(argv[1], &argv[1], env) < 0 ) {
        printf("%s: comando `%s' nao encontrado.\n", argv[0], argv[1]) ;
        return -1 ;
    }

    return 0 ;
}
/* EOF */
