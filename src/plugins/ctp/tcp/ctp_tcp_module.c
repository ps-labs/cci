/*
 * Copyright (c) 2010 Cisco Systems, Inc.  All rights reserved.
 * Copyright © 2010-2011 UT-Battelle, LLC. All rights reserved.
 * Copyright © 2010-2011 Oak Ridge National Labs.  All rights reserved.
 *
 * See COPYING in top-level directory
 *
 * $COPYRIGHT$
 *
 */

#include "cci/private_config.h"

#include <stdio.h>

#include "cci.h"
#include "plugins/ctp/ctp.h"

#include "ctp_tcp.h"

int cci_ctp_tcp_post_load(cci_plugin_t * me)
{
	assert(me);
	debug(CCI_DB_CTP, "%s", "In tcp post_load");
	return CCI_SUCCESS;
}

int cci_ctp_tcp_pre_unload(cci_plugin_t * me)
{
	assert(me);
	debug(CCI_DB_CTP, "%s", "In tcp pre_unload");
	return CCI_SUCCESS;
}
