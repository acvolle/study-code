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

// Returns pointer to playlist, p1 is NULL if error, otherwise a pointer
Playlist *init_playlist()
{
    Playlist *p1 = malloc(sizeof(*p1));
    if (p1 == NULL)
    {
        printf("init_playlist(): Failed\n");
        return p1;
    }
    p1->first = NULL;
    return p1;
}

// return 0 if unsuccesful,o otherwise 1
int add_song(Playlist *plist, char sname[], char sartist[])
{
    Song *psong = malloc(sizeof(*psong));
    if (psong == NULL)
    {
        printf("add_song(): Failed to create new song\n");
        return 0;
    }
    psong->next = NULL;
    psong->name = strdup(sname);
    if (psong->name == NULL)
    {
        printf("add_song: Failed to add name\n");
        free(psong);
        return 0;
    }
    psong->artist = strdup(sartist);
    if (psong->artist == NULL)
    {
        printf("add_song: Failed to add name\n");
        free(psong);
        return 0;
    }

    if (plist->first == NULL)
    {
        plist->first = psong;
    }
    else
    {
        Song *counter = plist->first;
        while (counter->next != NULL)
        {
            counter = counter->next;
        }

        counter->next = psong;
    }
    return 1;
}

// return 0 if nothing to remove, return 1 if song removed, -1 if error
int delete_firstSong(Playlist *plist)
{
    if (plist->first != NULL)
    {
        Song *removed = plist->first;
        plist->first = plist->first->next;
        free(removed->name);
        free(removed->artist);
        free(removed);
        return 1;
    }
    else
    {
        return 0;
    }
}

int delete_playlist(Playlist *plist)
{
    if (plist == NULL)
    {
        return 0;
    }
    while (delete_firstSong(plist))
    {
    }
    free(plist);

    return 1;
}

int print_playlist(Playlist *plist)
{
    if (plist == NULL)
    {
        printf("print_playlist(): Not a playlist!");
        return 0;
    }
    Song *counter = plist->first;
    while (counter != NULL)
    {
        if (counter->name == NULL || (counter->artist == NULL))
        {
            printf("print_playlist(): No data");
            return 0;
        }
        printf("Title: ");
        printf("%s,", counter->name);
        printf("Artist: ");
        printf("%s ", counter->artist);
        counter = counter->next;
    }
    printf("\n");
    return 1;
}

int main()
{

    Playlist *p = init_playlist();
    if (!add_song(p, "Hallo", "Georg"))
    {
        printf("main couldn't add song");
        return -1;
    }
    if (!add_song(p, "1&1-Song", "Marcel Davis"))
    {
        printf("main couldn't add song");
        return -1;
    }
    if (!add_song(p, "Happy Bithday", "Anonymous"))
    {
        printf("main couldn't add song");
        return -1;
    }
    if (!add_song(p, "C++", "Bjarne Strastroup"))
    {
        printf("main couldn't add song");
        return -1;
    }
    if (!print_playlist(p))
    {
        printf("main couldn't print");

        return -1;
    }
    if (!delete_firstSong(p))
    {
        return -1;
    }
    if (!print_playlist(p))
    {
        printf("main couldn't print");
        return -1;
    }
    if (!delete_playlist(p))
    {
        return -1;
    }

    return 0;
}