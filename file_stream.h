//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Thursday, 1 May 2008 11:35:41 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __FILE_STREAM_H_CB134584_8927_4D2B_8A94_7535A7A43951_
#define __FILE_STREAM_H_CB134584_8927_4D2B_8A94_7535A7A43951_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"
#include "io/forward_decls.h"
#include "io/stream.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace io
{

    class TYCHO_IO_ABI file_stream : public stream
    {
    public:    
		file_stream(file_ptr f);
		~file_stream();
		virtual int read(char* buffer, int length);
		virtual bool read_all(std::vector<char>&);
		virtual bool write(const char* buffer, int length);
		virtual bool flush();		
		virtual bool seek_set(core::int64);
		virtual bool seek_end(core::int64);
		
	private:
		file_ptr m_file;
    };

} // end namespace
} // end namespace

#endif // __FILE_STREAM_H_CB134584_8927_4D2B_8A94_7535A7A43951_
