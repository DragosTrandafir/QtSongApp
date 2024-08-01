#pragma once
#include"Song.h"
#include<Qvector>
class SongRepo
{
private:
	QVector<Song> songs;
	QVector<Song> songs_playlist;
public:
	SongRepo() = default;
	void add(const Song& song);
	void add_playlist(const Song& song);
	void remove(const Song& song);
};

