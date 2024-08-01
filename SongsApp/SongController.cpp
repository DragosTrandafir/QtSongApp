#include "SongController.h"

void SongController::add(string title, string artist, float duration, string mediaPath)
{
	Song s1{ title,artist,duration,mediaPath };
	repo.add(s1);
}

void SongController::add_playlist(string title, string artist, float duration, string mediaPath)
{
	Song s1{ title,artist,duration,mediaPath };
	repo.add_playlist(s1);
}

void SongController::remove(string title, string artist)
{
	Song s1{ title,artist,0,""};
	repo.remove(s1);
}
