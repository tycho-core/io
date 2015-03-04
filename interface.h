//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Friday, 2 May 2008 12:35:31 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __INTERFACE_H_23B1CD1F_6F53_4F86_ABFE_5F501904FF78_
#define __INTERFACE_H_23B1CD1F_6F53_4F86_ABFE_5F501904FF78_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"
#include "io/forward_decls.h"
#include "io/types.h"
#include "io/path.h"
#include "io/device.h"
#include "core/noncopyable.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace io
{
	class filesystem;
	
	/// Main filesystem interface. This provides services for getting data streams using
	/// unified path names. It supports unix style mount points allowing different filesystem
	/// handlers to service requests in a transparent and platform independent way. All paths 
	/// requested must be absolute, there is no concept of a relative path and so must begin
	/// with a leading /, see tycho::io::path for more information on valid paths.
    class TYCHO_IO_ABI interface : core::noncopyable
    {
    public:
		/// destructor
		~interface();
		
		/// add a device 
		void add_device(device_ptr);
		
		/// mount a filesystem handler at a specific directory
		bool mount(const io::path& dir, mount_point_ptr);
		
		/// unmount a filesystem from the directory
		bool unmount(const io::path& dir);
		
		/// open a stream to the specified resource
		stream_ptr open_stream(const io::path&, int);				
		
		/// create direcotry and all its parents if they do not exist
		bool create_directories(const io::path&);

		/// Remove all providers
		void clear();
    
    private:
		struct mount_point_entry
		{
			path		dir;
			mount_point_ptr device_mp;
			bool operator==(const path& dir_) const { return dir == dir_; }
		};

		/// find the closest mount point to the specified resource
		/// \returns 0 if the there is no mount for the path.
		mount_point_entry* find_mount_point(const io::path& path);
		
    private:
		typedef std::vector<mount_point_entry> mount_points;
		typedef std::vector<device_ptr> devices;
		devices		 m_devices;
		mount_points m_mount_points;
    };

} // end namespace
} // end namespace

#endif // __INTERFACE_H_23B1CD1F_6F53_4F86_ABFE_5F501904FF78_
