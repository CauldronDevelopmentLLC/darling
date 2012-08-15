// Copyright 2011 Shinichiro Hamaji. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   1. Redistributions of source code must retain the above copyright
//      notice, this list of  conditions and the following disclaimer.
//
//   2. Redistributions in binary form must reproduce the above
//      copyright notice, this list of conditions and the following
//      disclaimer in the documentation and/or other materials
//      provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY Shinichiro Hamaji ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Shinichiro Hamaji OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
// USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

#ifndef LOG_H_
#define LOG_H_

#include <assert.h>
#include <stdio.h>

#ifdef __cplusplus
#	include <iostream>
#endif

//#include "env_flags.h"

//DECLARE_bool(LOG);
extern bool g_loggingEnabled;
#define FLAGS_LOG g_loggingEnabled

#ifdef NOLOG
# define LOG if (0) std::cout
# define LOGF(...) if (0) fprintf(stderr, __VA_ARGS__)
#else
# define LOG if (FLAGS_LOG) std::cerr
# define LOGF(...) if (FLAGS_LOG) fprintf(stderr, __VA_ARGS__)
#endif

#define ERR cerr

#ifdef NDEBUG
// Do an extra check to avoid warning around unused local variables.
# define CHECK(r) do { if (!(r)) assert(r); } while (0)
#else
# define CHECK(r) assert(r);
#endif

#endif