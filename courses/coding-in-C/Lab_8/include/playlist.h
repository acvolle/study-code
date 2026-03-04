#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song
{
    char *name;
    char *artist;
    struct Song *next;
} Song;

typedef struct Playlist
{
    Song *first;
} Playlist;

Playlist *init_playlist();

int add_song(Playlist *plist, char sname[], char sartist[]);

int delete_firstSong(Playlist *plist);

int delete_playlist(Playlist *plist);

int print_playlist(Playlist *plist);
#endif