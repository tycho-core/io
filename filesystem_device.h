//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 26 May 2008 10:34:11 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __FILESYSTEM_DEVICE_H_6C7B08BB_E823_4886_A84C_D9E04EA9A9E4_
#define __FILESYSTEM_DEVICE_H_6C7B08BB_E823_4886_A84C_D9E04EA9A9E4_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"
#include "io/forward_decls.h"
#include "io/device.h"
#include "io/mount_point.h"
#include <string>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace io
{

	/// connects to the regular filesystem
    class TYCHO_IO_ABI filesystem_device : public io::device
    {
    public:
		/// per mount point info
		struct mount_point : public io::mount_point
		{
			mount_point(device* d, const char* p) : 
				io::mount_point(d), 
				path(p) 
			{}			
			std::string path;
		};
    
    public:    
		/// \name io::device interface
		//@{
		stream_ptr open_stream(mount_point_ptr, const io::path& path, int flags);
		bool create_directories(mount_point_ptr mp, const io::path& path);
		//@}
		
		/// make a mount point for this device.
		mount_point_ptr make_mount_point(const char* fs_path);
    };

} // end namespace
} // end namespace

#endif // __FILESYSTEM_DEVICE_H_6C7B08BB_E823_4886_A84C_D9E04EA9A9E4_
