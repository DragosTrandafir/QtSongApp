#pragma once
#include<string>
#include<fstream>
#include<iostream>
using std::istream;
using std::string;
class Song
{
private:
	string title;
	string artist;
	float duration;
	string mediaPath;
public:
	Song() = default;
	Song(string ptitle, string partist, float pduration, string pmediaPath) :title{ ptitle }, artist{ partist }, duration{ pduration }, mediaPath{ pmediaPath } {};
	string getTitle() const;
	string getArtist() const;
	float getDuration() const;
	string getMediaPath() const;
	friend istream& operator>>(istream& is, Song& s) {
		is >> s.artist >> s.title>>s.duration>>s.mediaPath;
		return is;
	}
};

