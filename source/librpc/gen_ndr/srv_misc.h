#include "bin/default/librpc/gen_ndr/ndr_misc.h"
#ifndef __SRV_MISC__
#define __SRV_MISC__
const struct api_struct *misc_get_pipe_fns(int *n_fns);
struct rpc_srv_callbacks;
NTSTATUS rpc_misc_init(const struct rpc_srv_callbacks *rpc_srv_cb);
NTSTATUS rpc_misc_shutdown(void);
#endif /* __SRV_MISC__ */
