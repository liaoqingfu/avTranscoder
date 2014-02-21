#ifndef _AV_TRANSCODER_DATA_AUDIO_FRAME_HPP_
#define _AV_TRANSCODER_DATA_AUDIO_FRAME_HPP_

#include <AvTranscoder/common.hpp>

extern "C" {
#ifndef __STDC_CONSTANT_MACROS
	#define __STDC_CONSTANT_MACROS
#endif
#ifndef INT64_C
	#define INT64_C(c) (c ## LL)
	#define UINT64_C(c) (c ## ULL)
#endif
#include <libavcodec/avcodec.h>
}

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

//#include "Sample.hpp"

namespace avtranscoder
{

typedef std::vector< unsigned char > DataBuffer;

class AudioFrameDesc
{
public:
	AudioFrameDesc()
	{};

	size_t getDataSize() const
	{
		size_t size = 0;
		return size;
	}

private:
};

class AudioFrame
{
public:
	AudioFrame( const AudioFrameDesc& ref )
		: m_dataBuffer( ref.getDataSize(), 0 )
		, m_audioFrameDesc( ref )
	{ }

	const AudioFrameDesc& desc() const    { return m_audioFrameDesc; }
	DataBuffer&           getBuffer()     { return m_dataBuffer; }
	unsigned char*        getPtr()        { return &m_dataBuffer[0]; }
#ifndef SWIG
	const unsigned char*  getPtr()  const { return &m_dataBuffer[0]; }
#endif
	size_t                getSize() const { return m_dataBuffer.size(); }

private:
	DataBuffer m_dataBuffer;
	const AudioFrameDesc m_audioFrameDesc;
};

}

#endif