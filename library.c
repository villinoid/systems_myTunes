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

    struct song_node *search = find_song(arr[letter-val], n, a);

    // printf("Looking for [%s: %s]...\n", a, n);

    if (!(search==0)) {
        printf("Song found!  ");
        print_song(search);
    }

    else
        printf("Song not found!");
    
    return find_song(arr[letter-val], n, a);
}

struct song_node *library_find_artist(struct song_node **arr, char *a) {
    int letter = a[0];
    int val = 0;
    
    if (letter >= 97)
        val = 97; // lower case
    else
        val = 65; // upper case

    struct song_node *search = find_artist(arr[letter-val], a);

    // printf("Looking for  [%s]...\n", a);

    if (!(search==0)) {
        printf("Artist found!\n");
        print_song_list(find_artist(arr[letter-val], a));
    }
    
    else
        printf("Artist not found!");

    return find_artist(arr[letter-val], a);
}

void print_library_letter(struct song_node **arr, char *l) {
    int letter = l[0];
    int val = 0;
    
    if (letter >= 97)
        val = 97; // lower case
    else
        val = 65; // upper case

	printf("%c list\n------\n", letter);
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

    printf("Printing [%s]...\n", a);

    while(node){
        if (!strcmp(a, node->artist))
            print_song(node);
        node=node->next;
    }
}

void print_library(struct song_node **arr) {
    int i;
    for (i=0;i<26;i++) {
        if (arr[i]!=0) {
            printf("%c list\n-------\n", i+97);
            print_song_list(arr[i]);
            printf("\n");
        }
    }
}

int library_size(struct song_node **arr){
    int i;
    int size=0;
    for(i=0;i<26;i++){
        size+=list_size(arr[i]);
    }
    return size;
}

struct song_node *random_library_song(struct song_node **arr){
    int size=library_size(arr);
    if (size){
        int random=rand()%size;
        //printf("r:%d\n",random);
        int i=0;
        while(list_size(arr[i])<=random){
            random-=list_size(arr[i]);
            i++;
        }
        return random_song(arr[i]);
    }
    return 0;
}
    

void print_shuffle_library(struct song_node **arr) {
    int n = rand() % library_size(arr); //insert the code to get a random number of songs here
    int i;
    for(int i=0;i<n;i++){
        print_song(random_library_song(arr));
    }

}

void library_remove_song(struct song_node **arr, char *n, char *a) {
    int letter = a[0];
    int val = 0;
    
    if (letter >= 97)
        val = 97; // lower case
    else
        val = 65; // upper case
    
    int index = letter - val;
    
    arr[index] = remove_song(arr[index], n, a);

}

struct song_node *free_library(struct song_node **arr) {

    int i;
    for(i=0;i<26;i++) {
        arr[i] = free_list(arr[i]);
    }
    return 0;
}
