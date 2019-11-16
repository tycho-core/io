//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Thursday, 1 May 2008 10:11:10 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __FILE_H_BFDCD7E4_2F0C_4E7C_BA20_603DF35754D4_
#define __FILE_H_BFDCD7E4_2F0C_4E7C_BA20_603DF35754D4_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"
#include "io/file.h"
#include <stdio.h>

#if defined(linux)
#	undef linux
#endif

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////


namespace tycho
{
namespace io
{
namespace linux
{

    class TYCHO_IO_ABI file : public io::file
    {
    public:
		file();
		~file();
		
		/// \name core::file interface
		//@{
		virtual bool open(const char*, int);
		virtual bool close();
		virtual core::int64 size() const;
		virtual int  read(char* buffer, int size);
		virtual bool write(const char* buffer, int size);
		virtual bool flush();
		virtual bool seek_set(core::int64);
		virtual bool seek_end(core::int64);
		virtual core::int64 tell();
		virtual bool eof();		
		//@}
    
    private:
		FILE* m_f;
		core::int64 m_size;
    };
    
} // end namespace
} // end namespace
} // end namespace


#endif // __FILE_H_BFDCD7E4_2F0C_4E7C_BA20_603DF35754D4_
