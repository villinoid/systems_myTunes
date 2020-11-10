#ifndef LIBRARY_H
#define LIBRARY_H

struct song_node *add_song(struct song_node *arr, struct song_node *song);
struct song_node *library_find_song();
/*
struct song_node *library_find_artist();
void print_library_letter();
void print_library_artist();
*/
void print_library(struct song_node *arr);
/*
void print_shuffle_library();
struct song_node *library_remove_song();
struct song_node * free_library();
*/

#endif