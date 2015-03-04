//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Friday, 2 May 2008 1:21:28 AM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "memory_stream.h"
#include "core/memory.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace io
{

	//------------------------------------------------------------------------------------

	memory_stream::memory_stream(char* buf, int size) :
		m_cursor(0),
        m_buf(buf),
        m_size(size),
		m_read_only(false)
    {
		if(buf)
			set_state(stream_state_ok);
		else
			set_state(stream_state_error);
	}

	//------------------------------------------------------------------------------------

	memory_stream::memory_stream(const char* buf, int size) :
		m_cursor(0),
		m_buf(const_cast<char*>(buf)),
		m_size(size),
		m_read_only(true)
	{
		if(buf)
			set_state(stream_state_ok);
		else
			set_state(stream_state_error);
	}

	//------------------------------------------------------------------------------------
	
	int memory_stream::read(char* buffer, int length)
	{
		if(state() == stream_state_error)
			return -1;
		if(!buffer || !m_buf || !m_size)
			return -1;						
		// clamp length to available
		if((m_cursor + length) > m_size)
			length = m_size - m_cursor;
		core::mem_cpy(buffer, &m_buf[m_cursor], length);
		m_cursor += length;
		if(m_cursor == m_size)
			set_state(stream_state_eof);
		return length;
	}

	//------------------------------------------------------------------------------------
		
	bool memory_stream::read_all(std::vector<char>& buffer)
	{
		if(state() == stream_state_error)
			return false;
		buffer.resize(m_size);
		return read(&buffer[0], m_size) == m_size;
	}
	
	//------------------------------------------------------------------------------------

	bool memory_stream::write(const char* buffer, int length)
	{
		TYCHO_ASSERT(!m_read_only);

		if(m_read_only)
			return false;
		if(state() == stream_state_error)
			return false;	
		if(!buffer || !m_buf || !m_size)
			return false;			
		if((m_cursor + length) > m_size)
			return false;
			
		core::mem_cpy(&m_buf[m_cursor], buffer, length);
		m_cursor += length;
		return true;
	}
	
	//------------------------------------------------------------------------------------

	bool memory_stream::flush()
	{
		if(state() == stream_state_error)
			return false;
		return true;
	}

	//------------------------------------------------------------------------------------

	bool memory_stream::seek_set(core::int64 offset)
	{
		if(state() == stream_state_error || offset < 0 || offset > m_size)
			return false;
	
		m_cursor = (int)offset;
		return true;
	}
	
	//------------------------------------------------------------------------------------

	bool memory_stream::seek_end(core::int64 offset)
	{
		if(state() == stream_state_error || offset < 0 || offset > m_size)
			return false;
	
		m_cursor = (int)(m_size - offset);
		return true;	
	}

	//------------------------------------------------------------------------------------

} // end namespace
} // end namespace

