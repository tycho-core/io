//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Thursday, 1 May 2008 11:35:41 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/file_stream.h"
#include "io/file.h"
#include "core/debug/assert.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace io
{

	//------------------------------------------------------------------------------------

	file_stream::file_stream(file_ptr f) :
		m_file(f)
	{
		if(f)
			set_state(stream_state_ok);
	}

	//------------------------------------------------------------------------------------
	
	file_stream::~file_stream()
	{
	
	}

	//------------------------------------------------------------------------------------
			
	int file_stream::read(char* buffer, int length)
	{
		if(length == 0)
			return 0;
		if(!m_file || state() != stream_state_ok)
			return -1;
		int res = m_file->read(&buffer[0], length);
		if(res == -1)
		{
			set_state(stream_state_error);
			return -1;
		}
		else if(res == 0)
			set_state(stream_state_eof);
		return res;
	}

	//------------------------------------------------------------------------------------
	
	bool file_stream::read_all(std::vector<char>& buffer)
	{
		if(!m_file || state() != stream_state_ok)
			return false;
		buffer.resize((size_t)m_file->size());
		return read(&buffer[0], (int)m_file->size()) > 0;
	}
	
	//------------------------------------------------------------------------------------

	bool file_stream::write(const char* buffer, int length)
	{
		if(!m_file || state() != stream_state_ok)
			return false;
		int res = m_file->write(buffer, length);
		TYCHO_ASSERT(res != 0);
		if(res == -1)
		{
			set_state(stream_state_error);
			return false;
		}
		return true;
	}
	
	//------------------------------------------------------------------------------------

	bool file_stream::flush()
	{
		if(!m_file->flush())
		{
			set_state(stream_state_error);
			return false;
		}
		return true;
	}

	//------------------------------------------------------------------------------------

	bool file_stream::seek_set(core::int64 offset)
	{
		if(!m_file || state() == stream_state_error)
			return false;
		if(m_file->seek_set(offset))
		{
			if(offset == m_file->size())
				set_state(stream_state_eof);
			else
				set_state(stream_state_ok);
			return true;
		}
		return false;
	}
	
	//------------------------------------------------------------------------------------

	bool file_stream::seek_end(core::int64 offset)
	{
		if(!m_file || state() == stream_state_error)
			return false;
		if(m_file->seek_end(offset))
		{
			if(offset == m_file->size())
				set_state(stream_state_eof);
			else
				set_state(stream_state_ok);
			return true;
		}
		return false;
	}

	//------------------------------------------------------------------------------------
		
} // end namespace
} // end namespace
