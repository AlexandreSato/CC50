//ASCII Generator by:Alexandre Nobuharu Sato in 21/12/2020 http://www.network-science.de/ascii/

#include <stdio.h>


char *string[] ={
			"  _________       __          \n",
			" /   _____/____ _/  |_  ____  \n",
			" \\_____  \\\\__  \\\\   __\\/  _ \\\n",
			" /        \\/ __ \\|  | (  <_> )\n",
			"/_______  (____  /__|  \\____/ \n",
			"        \\/     \\/             \n",
		};

int n_string = sizeof (string) / sizeof(char *);

void
main(void)
{
	for ( int i = 0; i < n_string; i++ )
		printf ("%s", string[i]);
}


