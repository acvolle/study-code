#include "../include/playlist.h"
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
    if (plist == NULL)
    {
        return 0;
    }
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
    if (plist == NULL)
    {
        return -1;
    }
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
        printf("%s;\n", counter->artist);
        counter = counter->next;
    }
    printf("\n");
    return 1;
}

Song *find_song_by_title(Playlist *playlist, const char *title)
{
    if (playlist == NULL || (title == NULL))
    {
        return NULL;
    }
    if (!strcmp(playlist->first->name, title))
    {
        
        return playlist->first;
    }
    Song *temp = playlist->first;
    while (temp != NULL)
    {
        if (!strcmp(temp->name, title))
        {
            return temp;
        }
        if (temp->next == NULL)
        {
            return NULL;
        }
        temp = temp->next;
    }
    return NULL;
}

int count_songs_recursive(const Song *current)
{
    if (current->next == NULL)
    {
        return 1;
    }
    int count = count_songs_recursive(current->next) + 1;
    return count;
}

void sort_playlist_by_title(Playlist *playlist)
{
    if (playlist == NULL || (playlist->first == NULL) || (playlist->first->next == NULL))
    {
        return;
    }
    else
    {

        Song *key = playlist->first;
        Song *counter = playlist->first;
        char *tempname = counter->name;
        char *tempartist = counter->artist;
        while (key->next != NULL)
        {
            
            counter = key;
            // counter = current->next;
            while (counter->next != NULL)
            {
                if (_stricmp(counter->name, counter->next->name) > 0)
                {
                    tempname = counter->name;
                    tempartist = counter->artist;
                    counter->name = counter->next->name;
                    counter->artist = counter->next->artist;
                    counter->next->name = tempname;
                    counter->next->artist = tempartist;
                }
                counter = counter->next;
            }
            key = key->next;
        }
    }
}
