//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Thursday, 1 May 2008 10:11:11 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "file.h"
#include "core/debug/assert.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{

namespace io
{

	//------------------------------------------------------------------------------------

	/// create the platform specific instance of this object
	file_ptr file::create()
	{
		return file_ptr(new pc::file());
	}

	//------------------------------------------------------------------------------------

namespace pc
{

	//------------------------------------------------------------------------------------

	file::file() :
		m_f(0)
	{}
		
	//------------------------------------------------------------------------------------

	file::~file()
	{
		close();
	}
	
	//------------------------------------------------------------------------------------

	bool file::open(const char* path, int flags)
	{
		char mode[4] = { 0} ;
		if(flags & io::open_flag_read)
			mode[0] = 'r';
		else if(flags & io::open_flag_write)
			mode[0] = 'w';
		else if(flags & io::open_flag_append)
			mode[0] = 'a';

		TYCHO_ASSERT_MSG(mode[0], "Mode not specified");
		if(mode[0] == 0)
			return false;

		if(flags & io::open_flag_create)
		{
			mode[1] = '+';
			mode[2] = 'b';
		}
		else
		{
			mode[1] = 'b';
		}
		
		m_f = ::fopen(path, mode);

		if(m_f)
		{		
			seek_end(0);
			m_size = tell();
			seek_set(0);			
		}
		return m_f != 0;
	}
	
	//------------------------------------------------------------------------------------

	bool file::close()
	{
		if(m_f)
		{
			::fclose(m_f);
			m_f = 0;
			return true;
		}
		return false;
	}
	
	//------------------------------------------------------------------------------------

	core::int64 file::size() const
	{
		return m_size;
	}
		
	//------------------------------------------------------------------------------------

	int file::read(char* buffer, int size)
	{
		if(!m_f)
			return false;
		return static_cast<int>(::fread(buffer, 1, size, m_f));
	}
	
	//------------------------------------------------------------------------------------

	bool file::write(const char* buffer, int size)
	{
		if(!m_f)
			return false;
		return ::fwrite(buffer, size, 1, m_f) == 1;
	}

	//------------------------------------------------------------------------------------

	bool file::flush()
	{
		if(!m_f)
			return false;
		return ::fflush(m_f) == 0;	
	}

	//------------------------------------------------------------------------------------

	bool file::seek_set(core::int64 pos)
	{
		if(!m_f)
			return false;
		return (::_fseeki64(m_f, pos, SEEK_SET) == 0) ? true : false;
	}
	
	//------------------------------------------------------------------------------------

	bool file::seek_end(core::int64 pos)
	{
		if(!m_f)
			return false;
		return (::_fseeki64(m_f, pos, SEEK_END) == 0) ? true : false;
	}

	//------------------------------------------------------------------------------------

	core::int64 file::tell()
	{
		if(!m_f)
			return -1;
		return ::_ftelli64(m_f);
	}
	
	//------------------------------------------------------------------------------------

	bool file::eof()
	{
		TYCHO_ASSERT(m_f);		
		return ::feof(m_f) > 0;
	}

	//------------------------------------------------------------------------------------
	
} // end namespace
} // end namespace
} // end namespace
