/*
*	mp3.h
*	
*	CISC361 Project 1
*		Author: Hannah Bridge
*/

typedef struct mp3 mp3_t;
mp3_t* createNewMp3(char* name, char* title, int year, int time);
void addMp3ToTail(char* name, char*title, int year, int time);
void printMp3(mp3_t *entry);
void printMp3DLL();
void reversePrintMp3DLL();
void getUserInput();
void deleteSong(mp3_t* mp3ToDelete);
void deleteAllSongsByArtist(mp3_t** head);
void displayMenu();


