//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 26 May 2008 8:10:27 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __DEVICE_H_5026AB64_61BD_4EB4_A1C5_F84FC6FFCC0A_
#define __DEVICE_H_5026AB64_61BD_4EB4_A1C5_F84FC6FFCC0A_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "io/io_abi.h"
#include "core/noncopyable.h"
#include "io/forward_decls.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace io
{

	/// A device is an abstract interface to a filesystem. These are mounted on
	/// the filesystem and will be used to service all requests for paths in the
	/// directory it is mounted at. To store per mount point information each device
	/// should derived a class from \ref ui::mount_point which will get passed back to
	/// it when a stream is opened in that mount point.
    class TYCHO_IO_ABI device : core::noncopyable
    {
    public:
		/// destructor
		virtual ~device() {}
		
		/// open the stream as specified by the path.
		/// \param mp        mount_point created by the device
		/// \param path      path to stream to open.
		/// \returns stream_ptr() on error.
		virtual stream_ptr open_stream(mount_point_ptr mp, const io::path& path, int flags) = 0;    

		/// create a directory and all its parents if they do not exist
		/// \param mp        mount_point created by the device
		/// \param path      path to directory to create.
		virtual bool create_directories(mount_point_ptr mp, const io::path& path) = 0;
    };

} // end namespace
} // end namespace


#endif // __DEVICE_H_5026AB64_61BD_4EB4_A1C5_F84FC6FFCC0A_
