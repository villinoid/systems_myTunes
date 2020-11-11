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
		arr[letter-val] = insert_alphabetical(arr[letter-val], song);
	}

	return arr;
}

struct song_node *library_find_song(struct song_node **arr, char *n, char* a) {
	int letter = a[0];
	int val = 0;
	
	if (letter >= 97)
		val = 97; // lower case
	else
		val = 65; // upper case

	return find_song(arr[letter-val], n, a);
}

struct song_node *library_find_artist(struct song_node **arr, char *a) {
	int letter = a[0];
	int val = 0;
	
	if (letter >= 97)
		val = 97; // lower case
	else
		val = 65; // upper case

	return find_artist(arr[letter-val], a);
}

void print_library_letter(struct song_node **arr, char *l) {
	int letter = l[0];
	int val = 0;
	
	if (letter >= 97)
		val = 97; // lower case
	else
		val = 65; // upper case

	print_song_list(arr[letter-val]);

}

void print_library_artist(struct song_node **arr, char *a) {
	int letter = a[0];
	int val = 0;
	
	if (letter >= 97)
		val = 97; // lower case
	else
		val = 65; // upper case

	struct song_node *node = arr[letter-val];

	while(node){

		if (!strcmp(a, node->artist)) {
			print_song(node);
			node=node->next;
		}

		else
			node=node->next;
	}
}

void print_library(struct song_node **arr) {
	int i;
	for (i=0;i<27;i++) {
		print_song_list(arr[i]);
		printf("\n");
	}
}

void print_shuffle_library(struct song_node **arr) {
	
}

struct song_node *library_remove_song(struct song_node **arr, char *n) {

}

struct song_node *free_library(struct song_node **arr) {
	int i;
	for(i=0;i<27;i++) {
		free_list(arr[i]);
	}

	return 0;
}
