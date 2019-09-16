#include <stdio.h>

typedef struct mp3{
	char *name;
	char *title;
	int *runTime;
	int *yearReleased;
	struct mp3 *next;
	struct mp3 *prev;
} mp3_t;


