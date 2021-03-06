#include "thread_selfid.h"
#include "../base.h"
#include "../errno.h"
#include <asm/unistd.h>

long sys_thread_selfid(void)
{
	int ret;

	ret = LINUX_SYSCALL(__NR_gettid);
	if (ret < 0)
		ret = errno_linux_to_bsd(ret);

	return ret;
}

