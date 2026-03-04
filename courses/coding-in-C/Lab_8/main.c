#include "include/playlist.h"

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