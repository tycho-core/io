//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Wednesday, 26 March 2008 12:15:59 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __FILE_H_23ECC279_CB18_4652_9805_2AEBD187DE59_
#define __FILE_H_23ECC279_CB18_4652_9805_2AEBD187DE59_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"
#include "core/forward_decls.h"
#include "io/forward_decls.h"
#include "io/types.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace io
{
	/// file interface
    class TYCHO_IO_ABI file
    {
    public:
		/// destructor
		virtual ~file() {}
		
		/// open an existing file
		virtual bool open(const char*, int) = 0;
				
		/// close the file
		virtual bool close() = 0;
		
		/// get the size of the file
		virtual core::int64 size() const = 0;
		
		/// read a number of bytes from the file
		/// \returns the number of bytes read in the call, may be less than asked for 
		///          if there wasn't any data, 0 if eof has been read or -1 if an error
		///          occurred.
		virtual int read(char* buffer, int size) = 0;
		
		/// write n bytes to the file
		virtual bool write(const char* buffer, int size) = 0;
		
		/// flush the file to disk
		virtual bool flush() = 0;
		
		/// seek to a specific position from the front of the file
		virtual bool seek_set(core::int64) = 0;
		
		/// seek to a specific position from the end of the file
		virtual bool seek_end(core::int64) = 0;
		
		/// \returns the current position in the file
		virtual core::int64 tell() = 0;
		
		/// \returns true if eof has been reached
		virtual bool eof() = 0;		
		
		/// create the platform specific instance of this object
		static file_ptr create();
		
	protected:
		file() {}
    };
	
} // end namespace
} // end namespace

#endif // __FILE_H_23ECC279_CB18_4652_9805_2AEBD187DE59_
