/*
 * Please so not edit this file by hand!
 * This file was automatically generated by: nddsgen
 */

#include <rpc/types.h>
#include <rpc/xdr.h>
#include "hiResImageReqRad.h"


bool_t
xdr_hiResImageReqRadStruct(XDR *xdrs, hiResImageReqRadStruct *objp)
{
	if (!xdr_float(xdrs, &objp->relativePan)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->relativeTilt)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->relativeZoomFactor)) {
		return (FALSE);
	}
	return (TRUE);
}

