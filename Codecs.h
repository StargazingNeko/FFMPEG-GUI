#pragma once
#include <vector>
#include <string>

class Codecs
{
public:
	static inline std::vector<std::string> MP4 = { "libx264", "libx265", "copy" };
	static inline std::vector<std::string> WEBM = { "libvpx", "libvpx-vp9", "copy" };
	static inline std::vector<std::string> MP3 = { "libmp3lame", "copy" };
};