#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>


char ** parse_args( char * line ) {

  char ** args = ( char ** )calloc( 10, sizeof( char * ) );
  
  int i;
  for ( i = 0; line; i++ ) {
    args[i] = strsep( &line, " " );
  }
  args[i] = 0;

  return args;
  
}

int main () {

  // Part I: Testing STRSEP()
  /*
  char line[100] = "wow-this-is-cool";
  char * s1 = line;
  printf( "[%s]\n", strsep( &s1, "-" ) );
  printf( "[%s]\n", s1 );
  */

  // Part II:

  char line[256] = "ls -a -l";
  printf( "\n=================================\nParsing \"%s\"...", line );
  
  char ** args = parse_args( line );
  
  execvp( args[0], args );
  

  return 0;
}
