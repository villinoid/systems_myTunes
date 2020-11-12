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
    
    srand(time(NULL));
    
    printf("LINKED LIST TESTS:\n===============================\n");
    
    printf("Testing new_song(), insert_front():\n===============================\n");
    struct song_node *playlist = NULL;
    
    struct song_node *s1 = new_song("Bullfrog Blues", "Rory Gallagher");
    struct song_node *s2 = new_song("Paris in the Rain", "Lauv");
    struct song_node *s3 = new_song("A Hard Rain's A-Gonna Fall", "Bob Dylan");
    struct song_node *s4 = new_song("Kokobop", "EXO");
    struct song_node *s5 = new_song("Flight of Earls", "Wolfe Tynes");
    struct song_node *s6 = new_song("SSFW", "LOEY");
    struct song_node *s7 = new_song("A Different Corner", "George Michael");
    struct song_node *s8 = new_song("Sweet Night", "V");
    struct song_node *s9 = new_song("Lost Stars", "Adam Levine");
    struct song_node *s0 = new_song("Run Away", "MINO");

    playlist = insert_front(playlist, s1);
    playlist = insert_front(playlist, s2);
    playlist = insert_front(playlist, s3);
    playlist = insert_front(playlist, s4);
    playlist = insert_front(playlist, s5);
    playlist = insert_front(playlist, s6);
    
    printf("Testing print_song_list():\n===============================\n");
    print_song_list(playlist);
    printf("\n");
    
    printf("Testing print_song():\n===============================\n");
    print_song(playlist);
    printf("\n");
    
    printf("Testing find_song():\n===============================\n");
    struct song_node *find = find_song(playlist, "A Hard Rain's A-Gonna Fall", "Bob Dylan");
    if (find) {
          printf("Song found!  ");
          print_song(find);
    }
    else
        printf("Song not found!");
    struct song_node *find2 = find_song(playlist, "Beautiful Goodbye", "Chen");
    if (find2) {
          printf("Song found!  ");
          print_song(find2);
    }
    else
        printf("Song not found!");
    printf("\n");
    
    printf("Testing find_artist():\n===============================\n");
    struct song_node *find3 = find_artist(playlist, "Lauv");
    if (find3) {
          printf("Artist found!  ");
          print_song(find3);
    }
    else
        printf("Artist not found!");
    struct song_node *find4 = find_artist(playlist, "Taylor Swift");
    if (find4) {
          printf("Artist found!  ");
          print_song(find4);
    }
    else
        printf("Artist not found!");
    printf("\n");
    
    printf("Testing song_compare() (helper function):\n===============================\n");
    printf("Comparing [Wolfe Tynes: Flight of Earls] to [Wolfe Tynes: Flight of Earls]\n ");
    printf("%d\n", song_compare(s3, s3));
    printf("Comparing [EXO: Kokobop] to [LOEY: SSFW]\n ");
    printf("%d\n", song_compare(s4, s6));
    printf("\n");
    
    printf("Testing random:");
    printf("\n==============================\n");
    print_song(random_song(playlist));
    print_song(random_song(playlist));
    print_song(random_song(playlist));
    printf("\n");
    
    printf("Testing remove_song():\n===============================\n");
    playlist = remove_song(playlist, "SSFW", "LOEY");
    print_song_list(playlist);
    printf("\n");
    
    printf("Testing free_list():\n===============================\n");
    free_list(playlist);
    printf("\n");

    printf("MUSIC LIBRARY TESTS:\n===============================\n");

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

    printf("Testing print_library():\n===============================\n");
    print_library(library);

    printf("Testing print_library_letter():");
    printf("\n================================\n");
    print_library_letter(library, "j");
    printf("\n");

    printf("Testing library_find_song():");
    printf("\n================================\n");
    library_find_song(library, "Do Re Mi", "blackbear");
    printf("\n");
    library_find_song(library, "Cosmic Railway", "EXO");
    printf("\n");
    printf("\n");

    printf("Testing library_find_artist():");
    printf("\n================================\n");
    library_find_artist(library, "Sub Urban");
    printf("\n");
    library_find_artist(library, "BTS");
    printf("\n");
    printf("\n");
    
    printf("Testing library_remove_song():");
    printf("\n================================\n");
    library_remove_song(library, "Cradles", "Sub Urban");
    print_library(library);
    printf("\n");

    printf("Testing free_library():");
    printf("\n================================\n");
    free_library(library);
    printf("\n");

    printf("Library after clear:");
    printf("\n================================\n");
    print_library(library);
    printf("\n");

    printf("Adding songs to empty library():");
    printf("\n================================\n");
    add_song(library, song7);
    add_song(library, song8);
    add_song(library, song9);
    add_song(library, song0);
    print_library(library);

    printf("Testing print_artist():");
    printf("\n===============================\n");
    print_library_artist(library, "Bazzi");
    printf("\n");
    print_library_artist(library, "Juice WRLD");
    printf("\n");

    printf("print_shuffle_library():");
    printf("\n===============================\n");
    print_shuffle_library(library);
    printf("\n");

    
    return 0;

}