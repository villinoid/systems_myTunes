#ifndef SONG_H
#define SONG_H

struct song_node{
	char name[100];
	char artist[100];
	struct song_node *next;
};

struct song_node *new_song(char *, char*);
struct song_node *insert_front(struct song_node *,struct song_node *);
int song_compare(struct song_node *, struct song_node *);
struct song_node *insert_alphabetical(struct song_node *, struct song_node *);
void print_song(struct song_node *);
void print_song_list(struct song_node *);
struct song_node *find_song(struct song_node *,  char *, char *);
struct song_node *find_artist(struct song_node *, char *);
struct song_node *random_song(struct song_node *);
struct song_node *remove_song(struct song_node *, char *, char *);
struct song_node * free_list(struct song_node *);
int list_size(struct song_node *);

#endif