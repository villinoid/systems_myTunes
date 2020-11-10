#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"
#include "song.h"

struct song_node *add_song(struct song_node *arr, struct song_node *song) {
	int letter = song->artist[0];

	// lower case
	if (letter >= 97) {
		arr[letter-97] = *insert_front(song, song->name, song->artist); // i dont know what to do here
	}
	// upper case
	else {
		arr[letter-65] = *insert_front(song, song->name, song->artist); // same here, i need to fix this up
	}

	return &arr[0];
}

struct song_node *library_find_song(struct song_node *arr, struct song_node *song) {

}

void print_library(struct song_node *arr) {
	int i;
	for (i=0;i<27;i++) {
		print_song_list(&arr[i]);
		printf("\n");
	}
}
