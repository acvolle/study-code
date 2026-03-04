#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

/* === Unit-tests === */

// example unit test
void test_init_playlist(void)
{
    Playlist *p = init_playlist();
    

    assert(p->first == NULL);
    //assert(p.size == 0);
}


void test_add_song(){
    Playlist *p = init_playlist();
    assert(add_song(NULL, "Lied", "Darsteller") == 0);
    assert(add_song(p, NULL, "Darsteller") == 0);
    assert(add_song(p, "Lied", NULL) == 0);
    assert(add_song(p, "/0", "D") == 1);
    assert(add_song(p, "Lied", "Darsteller") == 1);

}

void test_delete_firstSong(){
    Playlist *p = init_playlist();
    add_song(p, "Lied", "Saenger");

    assert(delete_firstSong(NULL) == -1);
    assert(delete_firstSong(p) == 1);
    assert(delete_firstSong(p) == 1);
}


/* === Test-Runner === */

int main(void)
{
    test_init_playlist();
    test_add_song();
    test_delete_firstSong();
    /*
    test_delete_firstSong_empty(); // what happens if we delete first song from empty playlist
    test_delete_playlist();
    test_max_songs_limit(); // verify if the limit will be not be surpassed

    printf("Alle Playlist-Tests erfolgreich bestanden.\n"); */
    return 0;
}