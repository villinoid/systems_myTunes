#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "song.h"
#include "library.h"

int main(){
	/*
	struct song_node *songs=new_song("A Different Corner","George Michael");
	printf("Linked list with one song:\n");
	print_song_list(songs);
	songs=insert_front(songs,"A Hard Rain's A-Gonna Fall","Bob Dylan");
	printf("insert a song in front:\n");
	print_song_list(songs);
	songs=insert_alphabetical(songs,"Flight of Earls","Wolfe Tynes");
	printf("insert a song alphabetically:\n");
	print_song_list(songs);
	songs=insert_alphabetical(songs,"13 Wonderful Love Songs","A House");
	printf("insert a song alphabetically:\n");
	print_song_list(songs);
	songs=insert_alphabetical(songs,"Bullfrog Blues","Rory Gallagher");
	printf("insert a song alphabetically:\n");
	print_song_list(songs);
	printf("find A Hard Rain's A-Gonna Fall by Bob Dylan:\n");
	print_song(find_song(songs,"A Hard Rain's A-Gonna Fall","Bob Dylan"));
	songs=insert_alphabetical(songs,"Visions of Johanna","Bob Dylan");
	printf("find Bob Dylan:\n");
	print_song(find_artist(songs,"Bob Dylan"));
	songs=remove_song(songs,"Flight of Earls","Wolfe Tynes");
	printf("remove Flight of Earls by Wolfe Tynes:\n");
	print_song_list(songs);
	songs=free_list(songs);
	*/

	//printf("%d\n", 'A');
	//printf("%d\n", 'Z');
	//printf("%d\n", 'a');
	//printf("%d\n", 'z');


	struct song_node *song1 = new_song("Do Re Mi", "blackbear");
	struct song_node *song2 = new_song("idfc", "blackbear");

	struct song_node *song3 = new_song("Like You Do", "joji");
	struct song_node *song4 = new_song("Ew", "joji");

	struct song_node library[27] = {};

	add_song(library, song1);
	add_song(library, song2);
	add_song(library, song3);
	add_song(library, song4);

	print_library(library);

	return 0;

}
