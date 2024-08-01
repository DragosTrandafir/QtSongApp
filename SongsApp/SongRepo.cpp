#include "SongRepo.h"
#include<stdexcept>

void SongRepo::add(const Song& song)
{
	songs.emplace_back(song);
}

void SongRepo::add_playlist(const Song& song)
{
	songs_playlist.emplace_back(song);
}

void SongRepo::remove(const Song& song)
{
	auto it = std::find_if(songs.begin(), songs.end(), [song](const Song& s) {
		return (song.getArtist() == s.getArtist() && song.getTitle() == s.getTitle() );
		});
	//if (it == songs.end())
	//	throw std::runtime_error("Song not found!");
	if (it != songs.end())
		songs.erase(it);

	auto it2 = std::find_if(songs_playlist.begin(), songs_playlist.end(), [song](const Song& s) {
		return (song.getArtist() == s.getArtist() && song.getTitle() == s.getTitle() );
		});
	//if (it2 == songs_playlist.end())
	//	throw std::runtime_error("Song not found!");
	if (it2 != songs_playlist.end())
		songs_playlist.erase(it2);
}
