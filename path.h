//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Tuesday, 20 May 2008 1:26:32 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __PATH_H_EEB6C713_A658_41CE_97CF_9F5E8F2D22A1_
#define __PATH_H_EEB6C713_A658_41CE_97CF_9F5E8F2D22A1_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"
#include <string>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace io
{

	/// io path class, this is used by all functions and classes that interact with
	/// the file system. It uses an idealized path form for platform independence with
	/// forward slashes as the path separator and a restricted allowed character for
	/// portability and ease of handling. All paths must be absolute, no relative forms
	/// are valid.
	///
	/// Allowed characters
	/// ------------------
	/// A - Z, a - z, 0 - 9, '.', '_'		
	class TYCHO_IO_ABI path
    {
    public:
		/// constructor
		path(const char* p = 0);

		/// append a section to the path
		void append(const char*);
						
		/// \returns the base name of the path, i.e. /game/foo.png -> foo.png
		std::string get_filename() const;
		
		/// \returns the base path of the path, i.e. /game/foo.png -> game
		path get_directory() const;				
		
		/// \returns true if the path start with the passed directory
		bool starts_with(const path&) const;
		
		/// \returns the length of the path
		int length() const;
		
		/// swap the contents with the other path
		path& swap(path &p);
		
		/// returns a path relative to this path
		io::path make_relative(const io::path& p) const;
		
		/// comparison operator
		bool operator==(const path& rhs) const 
			{ return m_path == rhs.m_path; }

		/// less than operator
		bool operator<(const path& rhs) const
			{ return m_path < rhs.m_path; }
			
		/// validate the path is in the correct format
		static bool validate(const char*);
		
		/// \returns path as a null terminated string
		const char* string() const
			{ return m_path.c_str(); }

    private:
		std::string m_path;    
    };
    
} // end namespace
} // end namespace

#endif // __PATH_H_EEB6C713_A658_41CE_97CF_9F5E8F2D22A1_
