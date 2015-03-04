//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 26 May 2008 10:34:12 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/filesystem_device.h"
#include "io/file_stream.h"
#include "io/file.h"
#include "io/path.h"
#include "core/debug/assert.h"
#include "core/string.h"
#include "core/platform.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace io
{
	
	//------------------------------------------------------------------------------------

	mount_point_ptr filesystem_device::make_mount_point(const char* fs_path)
	{
		TYCHO_ASSERT(fs_path);
		/// \todo validate local filesystem path
		return mount_point_ptr(new filesystem_device::mount_point(this, fs_path));					
	}
	
	//------------------------------------------------------------------------------------

	stream_ptr filesystem_device::open_stream(mount_point_ptr mp_, const io::path& path, int flags)
	{
		// construct actual path on the filesystem
		const int MaxPath = 256;
		char fs_path[MaxPath] = { 0 };
		filesystem_device::mount_point* mp = static_cast<filesystem_device::mount_point*>(mp_.get());
		core::snprintf(fs_path, MaxPath, "%s/%s", mp->path.c_str(), path.string());
 		io::file_ptr f = io::file::create();
 		if(f->open(fs_path, flags))
 			return file_stream_ptr(new file_stream(f));
		return file_stream_ptr();
	}

	//------------------------------------------------------------------------------------

	bool filesystem_device::create_directories(mount_point_ptr mp_, const io::path& path)
	{
		// construct actual path on the filesystem
		const int MaxPath = 256;
		char fs_path[MaxPath] = { 0 };
		filesystem_device::mount_point* mp = static_cast<filesystem_device::mount_point*>(mp_.get());
		core::snprintf(fs_path, MaxPath, "%s/%s", mp->path.c_str(), path.string());

		// split path into sections and create from root to leaf
		return core::create_directories(fs_path);
	}

	//------------------------------------------------------------------------------------

} // end namespace
} // end namespace

