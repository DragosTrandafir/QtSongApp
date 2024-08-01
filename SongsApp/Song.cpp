#include "Song.h"

string Song::getTitle() const
{
    return title;
}

string Song::getArtist() const
{
    return artist;
}

float Song::getDuration() const
{
    return duration;
}

string Song::getMediaPath() const
{
    return mediaPath;
}
