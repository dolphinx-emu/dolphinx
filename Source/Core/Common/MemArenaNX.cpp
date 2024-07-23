// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "Common/MemArena.h"

#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <set>
#include <string>

#include <Common/NXUtil.h>
#include <fmt/format.h>

#include <fcntl.h>
#include <switch/result.h>
#include <switch/kernel/svc.h>
#include <unistd.h>

#include "Common/Assert.h"
#include "Common/CommonFuncs.h"
#include "Common/CommonTypes.h"
#include "Common/Logging/Log.h"
#include "Common/MsgHandler.h"
#include "Common/StringUtil.h"

namespace Common
{
MemArena::MemArena() = default;
MemArena::~MemArena() = default;

void MemArena::GrabSHMSegment(size_t size, std::string_view)
{
  bool succeeded = R_SUCCEEDED(shmemCreate(&m_shmem, size, Perm_Rw, Perm_Rw));
  if(!succeeded)
  {
    ERROR_LOG_FMT(MEMMAP, "shm_open failed: {}", strerror(errno));
  }
}

void MemArena::ReleaseSHMSegment()
{
  shmemClose(&m_shmem);
}

void* MemArena::CreateView(s64 offset, size_t size)
{

}

void MemArena::ReleaseView(void* view, size_t size)
{

}

u8* MemArena::ReserveMemoryRegion(size_t memory_size)
{
  ScopedVirtualMemoryMutex m;
  void* base = virtmemFindAslr(memory_size, 0);
  if(!base)
  {
    PanicAlertFmt("Failed to find G.P. memory space: {}", LastStrerrorString());
    return nullptr;
  }

  m_reserved_region = virtmemAddReservation(base, memory_size);

  if(!m_reserved_region)
  {
    PanicAlertFmt("Failed to reserve memory space: {}", LastStrerrorString());
    return nullptr;
  }

  return static_cast<u8*>(base);
}

void MemArena::ReleaseMemoryRegion()
{
  if(m_reserved_region)
  {
    ScopedVirtualMemoryMutex m;
    virtmemRemoveReservation(m_reserved_region);
  }
}

void* MemArena::MapInMemoryRegion(s64 offset, size_t size, void* base)
{
}

void MemArena::UnmapFromMemoryRegion(void* view, size_t size)
{

}

LazyMemoryRegion::LazyMemoryRegion() = default;

LazyMemoryRegion::~LazyMemoryRegion()
{
  Release();
}

#if !defined MAP_NORESERVE && (defined __FreeBSD__ || defined __OpenBSD__ || defined __NetBSD__)
// BSD does not implement MAP_NORESERVE, so define the flag to nothing.
// See https://reviews.freebsd.org/rS273250
#define MAP_NORESERVE 0
#endif

void* LazyMemoryRegion::Create(size_t size)
{

}

void LazyMemoryRegion::Clear()
{

}

void LazyMemoryRegion::Release()
{

}

}  // namespace Common
