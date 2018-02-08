//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Tuesday, 20 May 2008 1:26:33 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/path.h"
#include "core/debug/assert.h"


//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace io
{

	//------------------------------------------------------------------------------------

	path::path(const char* p)
	{
		if(p)
		{
			TYCHO_ASSERT(validate(p));
			m_path = p;
		}
	}
		
	//------------------------------------------------------------------------------------

	void path::append(const char* p)
	{
		m_path += p;
	}
	
	//------------------------------------------------------------------------------------

	std::string path::get_filename() const
	{
		size_t pos = m_path.rfind('/');
		size_t len = m_path.length();
		if(pos == len)
			return "";
		return m_path.substr(pos+1, (len - (pos+1)));
	}
	
	//------------------------------------------------------------------------------------

	path path::get_directory() const
	{
		size_t pos = m_path.rfind('/');
		return m_path.substr(0, pos+1).c_str();
	}
	
	//------------------------------------------------------------------------------------

	bool path::starts_with(const path& p) const
	{
		return m_path.find(p.m_path) == 0;
	}
	
	//------------------------------------------------------------------------------------

	int path::length() const
	{
		return static_cast<int>(m_path.length());
	}
		
	//------------------------------------------------------------------------------------

	path& path::swap(path &p)
	{
		m_path.swap(p.m_path);
		return *this;
	}
	
	//------------------------------------------------------------------------------------

	io::path path::make_relative(const io::path& p) const
	{
		size_t pos = p.m_path.find(m_path);
		if(pos != 0)
			return io::path();
		size_t start = length();
		size_t count = p.length() - length();
		return p.m_path.substr(start, count).c_str();
	}		
	
	//------------------------------------------------------------------------------------

	bool path::validate(const char* p)
	{
		if(!p)	
			return false;
			
		// valid characters
		for(const char* cp = p; *cp; ++cp)
		{
			const char c = *cp;
			bool vc = (c >= 'a' && c <= 'z') ||
			          (c >= 'A' && c <= 'Z') ||
			          (c >= '0' && c <= '9') ||
			          (c == '.') ||
			          (c == '_') ||
			          (c == '-') ||
			          (c == '/');
			if(!vc)
				return false;			        
		}
		return true;
	}

	//------------------------------------------------------------------------------------

} // end namespace
} // end namespace
