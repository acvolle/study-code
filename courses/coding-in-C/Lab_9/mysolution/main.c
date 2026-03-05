#include "include/playlist.h"

int main()
{

    //initialize new playlist
    Playlist *p = init_playlist();

    //
    if (!add_song(p, "Hallo", "Georg"))
    {
        printf("main couldn't add song");
        return -1;
    }
    if (!add_song(p, "A&1-Song", "Marcel Davis"))
    {
        printf("main couldn't add song");
        return -1;
    }
    if (!add_song(p, "Happy Bithday", "Anonymous"))
    {
        printf("main couldn't add song");
        return -1;
    }
    if (!add_song(p, "C++", "Christan Lindner"))
    {
        printf("main couldn't add song");
        return -1;
    }

    //print playlist
    if (!print_playlist(p))
    {
        printf("main couldn't print");

        return -1;
    }
  
    //find Song "C++" by title -> will be found
    Song *s = find_song_by_title(p, "C++");
    if (s == NULL){
        printf("coudn't find song C++\n");
    }else{
        printf("Found %s by %s\n", s->name, s->artist);
    }

    //find Song Python by title -->won't be found
    s = find_song_by_title(p, "Python");
    if (s == NULL){
        printf("coudn't find song Python\n");
    }else{
        printf("Found %s by %s\n", s->name, s->artist);
    }
    
    //count number of songs and print
    printf("%i", count_songs_recursive(p->first));
    printf("\n");
    
    //sort playlist and print
    sort_playlist_by_title(p);
    print_playlist(p);
   

    if (!delete_playlist(p))
    {
        return -1;
    }

    return 0;
}