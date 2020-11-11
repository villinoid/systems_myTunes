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

	struct song_node *library[27] = {};

	struct song_node *song1 = new_song("Do Re Mi", "blackbear");
	struct song_node *song2 = new_song("julia", "jeremy zucker");
	struct song_node *song3 = new_song("Like You Do", "joji");
	struct song_node *song4 = new_song("Ew", "joji");
	struct song_node *song5 = new_song("idfc", "blackbear");
	struct song_node *song6 = new_song("Cradles", "Sub Urban");
	struct song_node *song7 = new_song("Crazy", "Bazzi");
	struct song_node *song8 = new_song("Diamonds", "Sam Smith");
	struct song_node *song9 = new_song("Righteous", "Juice WRLD");
	struct song_node *song0 = new_song("Mine", "Bazzi");

	add_song(library, song1);
	add_song(library, song2);
	add_song(library, song3);
	add_song(library, song4);
	add_song(library, song5);
	add_song(library, song6);

	printf("Testing print_library():\n========================\n");
	print_library(library);

	printf("Testing print_library_letter():");
	printf("\n===============================\n");
	print_library_letter(library, "j");
	printf("\n");

	printf("Testing library_find_song():");
	printf("\n============================\n");
	library_find_song(library, "Do Re Mi", "blackbear");
	library_find_song(library, "corrupted song", "blackbear");
	printf("\n\n");

	printf("Testing library_find_artist():");
	printf("\n==============================\n");
	library_find_artist(library, "joji");
	library_find_artist(library, "corrupted artist");
	printf("\n\n");

	printf("Testing library_remove_song():");
	printf("\n==============================\n");
	// more tests go here
	// print_library(library);
	printf("\n");

	printf("Testing free_library():");
	printf("\n=======================\n");
	free_library(library);
	printf("\n");

	printf("Library after clear:");
	printf("\n====================\n");
	print_library(library);
	printf("\n");

	printf("Adding songs to empty library():");
	printf("\n================================\n");
	add_song(library, song7);
	add_song(library, song8);
	add_song(library, song9);
	add_song(library, song0);
	print_library(library);

	printf("Testing print_library_artist():");
	printf("\n===============================\n");
	print_library_artist(library, "Bazzi");
	print_library_artist(library, "Juice WRLD");
	printf("\n");

	printf("print_shuffle_library():");
	printf("\n========================\n");
	// tests
	printf("\n");

	return 0;

}
