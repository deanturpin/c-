#ifndef RIFF_RIFF_H
#define RIFF_RIFF_H

// RIFF header
namespace riff
{
	struct chunk
	{
		unsigned int id;
		unsigned int size;
	};

	struct header
	{
		chunk riff;
		unsigned int wave_tag;
		chunk format;
		unsigned short format_tag;
		unsigned short channels;
		unsigned int sample_rate;
		unsigned int bytes_per_second;
		unsigned short block_align;
		chunk data;
	};
}

#endif
