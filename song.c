#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "song.h"

struct song_node *new_song(char *n, char* a) {

	struct song_node *ns;

	ns = malloc( sizeof(struct song_node) );

	strncpy(ns->name, n, sizeof(ns->name)-1);
	strncpy(ns->artist, a, sizeof(ns->name)-1);
	ns->next= 0;

	return ns;
}


struct song_node *insert_front(struct song_node *node,struct song_node *f){
	f->next=node;
	return f;
}

int song_compare(struct song_node *n1, struct song_node *n2){
	if (strcmp(n1->name,n2->name)){
		return strcmp(n1->name,n2->name);
	}
	return strcmp(n1->artist,n2->artist);
}

struct song_node *insert_alphabetical(struct song_node *front, struct song_node *new){
	struct song_node *node=front;
	if (song_compare(new,node)<0){
		new->next=node;
		return new;
	}
	
	while (node->next){
		if (song_compare(new,node->next)<0){
			new->next=node->next;
			node->next=new;
			return front;

		}
		node=node->next;
	}
	
	node->next=new;
	return front;
}
void print_song(struct song_node *node){
	printf("%s: %s\n", node->artist, node->name);
}

void print_song_list(struct song_node *node){
	while(node){
		print_song(node);
		node=node->next;
	}
}

struct song_node *find_song(struct song_node *node,  char *n, char * a){
	while(node){
		if (!(strcmp(n,node->name)||strcmp(a,node->artist))){
			return node;
		}
		node=node->next;
	}
	return node;
}

struct song_node *find_artist(struct song_node *node, char * a){
	while(node){
		if (!(strcmp(a,node->artist))){
			return node;
		}
		node=node->next;
	}
	return node;
}

struct song_node *remove_song(struct song_node *front, char *n, char * a){
	struct song_node *new=new_song(n,a);
	struct song_node *node=front;
	if (song_compare(new,node)<0){
		node=node->next;
		free(front);
		return node;
	}
	
	while (node->next){
		if (song_compare(new,node->next)==0){
			free(node->next);
			node->next=node->next->next;
			return front;

		}
		node=node->next;
	}
	return front;
}

struct song_node * free_list(struct song_node *node){
	while(node){
		printf("Freeing node: %s - %s\n", node->artist, node->name);
		free(node);
		node=node->next;
	}
	return 0;
}