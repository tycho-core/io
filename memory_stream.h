//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Friday, 2 May 2008 1:21:27 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MEMORY_STREAM_H_D3C65D91_9F9C_4600_9BA3_E4FAD1BC3410_
#define __MEMORY_STREAM_H_D3C65D91_9F9C_4600_9BA3_E4FAD1BC3410_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"
#include "io/stream.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace io
{

	/// stream interface for a raw chunk of memory
    class TYCHO_IO_ABI memory_stream : public stream
    {
    public:
		memory_stream(char* buf, int size);		    
		memory_stream(const char* buf, int size);		    

		virtual int read(char* buffer, int length);
		virtual bool read_all(std::vector<char>&);
		virtual bool write(const char* buffer, int length);
		virtual bool flush();    
		virtual bool seek_set(core::int64);
		virtual bool seek_end(core::int64);
		
	private:
		int m_cursor;
		char* m_buf;
		int   m_size;
		bool  m_read_only;
    };

} // end namespace
} // end namespace

#endif // __MEMORY_STREAM_H_D3C65D91_9F9C_4600_9BA3_E4FAD1BC3410_
