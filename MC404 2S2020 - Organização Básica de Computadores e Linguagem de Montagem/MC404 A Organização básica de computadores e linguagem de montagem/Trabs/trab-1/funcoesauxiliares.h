#include "montador.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int hextodec(char* hex);
char * dectohex (int decInt);
char * dadotohex (Token *t, Token *n, int r, int s, int rots[1500][3], int syms[1500][2], char mapa[1024][5][4], int li, int co);