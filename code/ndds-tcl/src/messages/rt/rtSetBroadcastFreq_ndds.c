/*
 * Please so not edit this file by hand!
 * This file was automatically generated by: nddsgen
 */

#include <rpc/types.h>
#include <rpc/xdr.h>
#include "rtSetBroadcastFreq.h"


bool_t
xdr_rtSetBroadcastFreqStruct(XDR *xdrs, rtSetBroadcastFreqStruct *objp)
{
	if (!xdr_int(xdrs, &objp->sourceId)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->freq)) {
		return (FALSE);
	}
	return (TRUE);
}

