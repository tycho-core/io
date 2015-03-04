//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Thursday, 1 May 2008 11:34:54 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __STREAM_H_8AB14FE5_E31F_4AAC_BF53_98AF90E64298_
#define __STREAM_H_8AB14FE5_E31F_4AAC_BF53_98AF90E64298_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"
#include "core/string.h"
#include "core/debug/assert.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace io
{

	/// abstracts access to a sequence of bytes
    class TYCHO_IO_ABI stream
    {
    public:
		enum stream_state
		{
			stream_state_error,
			stream_state_ok,
			stream_state_eof
		};
		
    public:
		/// default constructor
		stream() : m_state(stream_state_error) {}
		
		/// destructor
		virtual ~stream() {};
		
		/// Read a chunk of bytes from the stream
		virtual int read(char* buffer, int length) = 0;
		
		/// Write a chunk of bytes to the stream
		virtual bool write(const char* buffer, int length) = 0;
		
		/// Write any buffered data to the device
		virtual bool flush() = 0;
		
		/// Read the entire stream into a buffer
		virtual bool read_all(std::vector<char>&) = 0;
		
		/// seek to a specific position from the front of the stream.
		/// \warning This may not be available depending on the concrete stream
		virtual bool seek_set(core::int64) { return false; }
		
		/// seek to a specific position from the end of the file
		/// \warning This may not be available depending on the concrete stream
		virtual bool seek_end(core::int64) { return false; }
		
		/// \returns the error status of the stream
		virtual stream_state state() const
			{ return m_state; }
		
		/// \returns true if end-of-file has been reached
		bool eof() const
			{ return state() == stream_state_eof; }
			
		/// \returns true if the stream is in an error state
		bool fail() const
			{ return state() == stream_state_error; }

		/// Print a string to the stream
		bool printf(const char* format, ...)
		{
			const int BufLen = 1024;
			char buf[BufLen];
			va_list args;
			va_start(args, format);
			int nc = core::vsnprintf(buf, BufLen, format, args);
			va_end(args);
			TYCHO_ASSERT(nc < BufLen && nc >= 0);
			if(nc == BufLen || nc < 0)
				return false;
			return write(buf, nc);
		}


			
	protected:
		void set_state(stream_state s) 
			{ m_state = s; }
			
	private: 
		stream_state m_state;
    };

} // end namespace
} // end namespace

#endif // __STREAM_H_8AB14FE5_E31F_4AAC_BF53_98AF90E64298_
