#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "library.h"
#include "song.h"

struct song_node **add_song(struct song_node **arr, struct song_node *song) {

	int letter = song->artist[0];
	int val = 0;
	
	if (letter >= 97)
		val = 97; // lower case
	else
		val = 65; // upper case

	if (arr[letter-val]==0) {
		arr[letter-val] = song;
	}

	else {
		arr[letter-val] = insert_alphabetical(arr[letter-val], song->name, song->artist);	// something here is not working
	}

	return arr;
}

struct song_node *library_find_song(struct song_node *arr, struct song_node *song) {

}

void print_library(struct song_node **arr) {
	int i;
	for (i=0;i<27;i++) {
		print_song_list(arr[i]);
		printf("\n");
	}
}
