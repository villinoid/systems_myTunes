#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "song.h"

void main(){
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
}

	