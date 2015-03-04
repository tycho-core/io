//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Thursday, 1 May 2008 11:18:35 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __TYPES_H_E82978CF_E820_487B_823E_1F78A22C37E8_
#define __TYPES_H_E82978CF_E820_487B_823E_1F78A22C37E8_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace io
{
	typedef const char* path_type;

	enum open_flags
	{
		open_flag_invalid = 0,
		
		/// open the file for reading
		open_flag_read = 1,

		/// open the file for writing
		open_flag_write = 2,
		
		/// open the file for reading and appending data.
		open_flag_append = 4,
		
		/// use with either open_flag_write or open_flag_append to create the file if it doesn't exist
		/// or truncate its contents if it does exist.
		open_flag_create = 8
	};
		
} // end namespace
} // end namespace

#endif // __TYPES_H_E82978CF_E820_487B_823E_1F78A22C37E8_
