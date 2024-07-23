// Copyright 2008 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include <switch/kernel/shmem.h>
#include <switch/kernel/virtmem.h>
#include <sys/types.h>

namespace Common
{
class SharedMemoryManager
{
public:
  void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset);
  int munmap(void* addr, size_t length);
private:
  SharedMemory m_shared_memory;
};

class ScopedVirtualMemoryMutex
{
public:
  ScopedVirtualMemoryMutex()
  {
    virtmemLock();
  }

  ~ScopedVirtualMemoryMutex()
  {
    virtmemUnlock();
  }
};
}