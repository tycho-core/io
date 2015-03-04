//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2013 Martin Slater
// Created : Thursday, 31 October 2013 11:42:29 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef _FORWARD_DECLS_H_76C3FD85_EEB2_41DF_BD1F_4FFB5C68CF19
#define _FORWARD_DECLS_H_76C3FD85_EEB2_41DF_BD1F_4FFB5C68CF19

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"
#include "core/shared_ptr.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace io
{

	class interface;
	class path;
	TYCHO_DECLARE_SHARED_PTR(TYCHO_IO_ABI, file);
	TYCHO_DECLARE_SHARED_PTR(TYCHO_IO_ABI, filesystem);
	TYCHO_DECLARE_SHARED_PTR(TYCHO_IO_ABI, stream);
	TYCHO_DECLARE_SHARED_PTR(TYCHO_IO_ABI, memory_stream);
	TYCHO_DECLARE_SHARED_PTR(TYCHO_IO_ABI, file_stream);
	TYCHO_DECLARE_SHARED_PTR(TYCHO_IO_ABI, normal_filesystem);
	TYCHO_DECLARE_SHARED_PTR(TYCHO_IO_ABI, device);
	TYCHO_DECLARE_SHARED_PTR(TYCHO_IO_ABI, mount_point);
	TYCHO_DECLARE_SHARED_PTR(TYCHO_IO_ABI, filesystem_device);
	
} // end namespace
} // end namespace

#endif // _FORWARD_DECLS_H_76C3FD85_EEB2_41DF_BD1F_4FFB5C68CF19
