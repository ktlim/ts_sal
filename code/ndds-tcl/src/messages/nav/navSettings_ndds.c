/*
 * Please so not edit this file by hand!
 * This file was automatically generated by: nddsgen
 */

#include <rpc/types.h>
#include <rpc/xdr.h>
#include "navSettings.h"


bool_t
xdr_navSettingsStruct(XDR *xdrs, navSettingsStruct *objp)
{
	if (!xdr_int(xdrs, &objp->data)) {
		return (FALSE);
	}
	if (!xdr_char(xdrs, &objp->command)) {
		return (FALSE);
	}
	return (TRUE);
}

