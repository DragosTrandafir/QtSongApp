#pragma once
#include"SongRepo.h"
#include<Qvector>

class SongController {
private:
	SongRepo& repo;
public:
	SongController(SongRepo& prepo) :repo{ prepo } {};
	void add(string title, string artist, float duration, string mediaPath);
	void add_playlist(string title, string artist, float duration, string mediaPath);
	void remove(string title, string artist);
};