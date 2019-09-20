#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 128

typedef struct mp3{
	char *artistName;
	char *songTitle;
	int yearReleased;
	int runTime;
	struct mp3 *prev;
	struct mp3 *next;
}mp3_t;

mp3_t* head = NULL;
mp3_t* tail = NULL;

mp3_t* createNewMp3(char* name, char* title, int year, int time){
	mp3_t* newMp3 = (struct mp3*)malloc(sizeof(struct mp3));
	
	int nameLen, songLen;
	
  	nameLen = (int) strlen(name);
  	name[nameLen - 1] = '\0';
  	newMp3->artistName = (char *) malloc(nameLen);
  	strcpy(newMp3->artistName, name);

  	songLen = (int) strlen(title);
  	title[songLen - 1] = '\0';
  	newMp3->songTitle = (char *) malloc(songLen);
	strcpy(newMp3->songTitle, title);

	newMp3->yearReleased = year;
	newMp3->runTime = time;
	newMp3->prev = NULL;
	newMp3->next = NULL; 	

	return newMp3;
}

void addMp3ToTail(char* name, char* title, int year, int time){
	mp3_t* temp = head;
	mp3_t* mp3ToAdd = createNewMp3(name, title, year, time);

	if(head == NULL){
		head = mp3ToAdd;
		return;
	}
	while(temp->next != NULL){
		temp = temp->next;
	}

	temp->next = mp3ToAdd;
	mp3ToAdd->prev = temp;
	tail = mp3ToAdd;
}

void printMp3(mp3_t *entry){
        printf("Artist name: %s\n", entry->artistName);
        printf("Song title: %s\n", entry->songTitle);
        printf("Run time (in seconds): %d\n", entry->runTime);
        printf("Year released: %d\n", entry->yearReleased);
}

void printMp3DLL(){
        mp3_t* temp = head;
        while(temp != NULL){
                printMp3(temp);
                printf("\n");
                temp = temp->next;
        }
}

void reversePrintMp3DLL(){
        mp3_t* temp = tail;
        while(temp != NULL){
                printMp3(temp);
                printf("\n");
                temp = temp->prev;
        }
}
void getUserInput(){
	char artist[BUFFERSIZE], song[BUFFERSIZE];
	int songYear, songTime;

	printf("Enter artist's name: ");
        fgets(artist, BUFFERSIZE, stdin);
        printf("Enter song title: ");
       	fgets(song, BUFFERSIZE, stdin);
	printf("Enter the year the song is from: ");
        scanf("%d", &songYear);
	printf("Enter song's run time (in seconds): ");
        scanf("%d", &songTime);

        addMp3ToTail(artist, song, songYear, songTime);
}

void deleteSong(mp3_t* mp3ToDelete){
	if(mp3ToDelete == NULL || head == NULL)
		return;	
	if(head == mp3ToDelete)
		head = mp3ToDelete->next;
	if(mp3ToDelete->next != NULL)
		mp3ToDelete->next->prev = mp3ToDelete->prev;
	if(mp3ToDelete->prev != NULL)
                mp3ToDelete->prev->next = mp3ToDelete->next;
	free(mp3ToDelete);
}

void deleteAllSongsByArtist(mp3_t** head){
	char artistToDelete[BUFFERSIZE];
	int len;
	char *artist;

	printf("Enter the artist's name of whose song(s) you would like to delete: ");
        if(fgets(artistToDelete, BUFFERSIZE, stdin) != NULL){
		len = (int)strlen(artistToDelete);
		artistToDelete[len-1] = '\0';
		artist = (char *)malloc(len);
		strcpy(artist, artistToDelete);	
	}
	
	if((*head) == NULL)
		return;

	mp3_t* current = *head;
	mp3_t* next;
	
	while(current != NULL){
		if(strcmp(current->artistName, artist) == 0){
			next = current->next;
			deleteSong(current);
			current = next;
		}
		else
			current = current->next;
	}

	printf("\n");
	printf("DLL AFTER REMOVING ARTIST: \n");
	printMp3DLL();
}

void displayMenu(){
	printf("*************MENU*************\n");
    	printf("*Press a number for selection*\n");
    	printf("1. Add an MP3 to the list \n");
    	printf("2. Delete MP3(s) from the list\n");
    	printf("3. Print the list from beginning to end\n");
    	printf("4. Print the list from end to beginning\n");
    	printf("5. Exit the program\n");
    	printf("******************************\n");
}

void freeEverything(mp3_t** head, mp3_t** tail){
	mp3_t* temp = *head;
	while(temp != NULL){
		free(temp->artistName);
		free(temp->songTitle);
		free(temp);
		temp = temp->next;
	}
	free(head);
	free(tail);
}

int main(){
	char enter[BUFFERSIZE];
	int userPick;

	while(userPick != 5){
		displayMenu();
        	scanf("%d", &userPick);
        	fgets(enter, BUFFERSIZE, stdin);
			switch(userPick){
				case 1:
					getUserInput();
					break;
				case 2:
					deleteAllSongsByArtist(&head);
					break;
				case 3:
					printMp3DLL();
					break;
				case 4:
					reversePrintMp3DLL();
					break;
				case 5:
					printf("Exiting program\n");
					break;
				default:
					printf("Wrong input. Please select a different number\n");
					break;
		}
	}

	freeEverything(&head, &tail);

	return 0;
}
