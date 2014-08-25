/*
 * Please so not edit this file by hand!
 * This file was automatically generated by: nddsgen
 */

#include <rpc/types.h>
#include <rpc/xdr.h>
#include "gpsDerivedState.h"


bool_t
xdr_gpsDerivedStateStruct(XDR *xdrs, gpsDerivedStateStruct *objp)
{
	if (!xdr_long(xdrs, &objp->msecOfGPSWeek)) {
		return (FALSE);
	}
	if (!xdr_int(xdrs, &objp->GPSWeek)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->numSVSTracked)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->numSVSVisible)) {
		return (FALSE);
	}
	if (!xdr_double(xdrs, &objp->userDatumNorthOrX)) {
		return (FALSE);
	}
	if (!xdr_double(xdrs, &objp->userDatumEastOrY)) {
		return (FALSE);
	}
	if (!xdr_double(xdrs, &objp->userDatumUporZ)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->velocityFlags)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->horizVelocity)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->heading)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->positionRMSError)) {
		return (FALSE);
	}
	if (!xdr_double(xdrs, &objp->positionDOP)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->sigmaEast)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->sigmaNorth)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->eastNorthCovar)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->sigmaUp)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->sigmaOrientation)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->unitVariance)) {
		return (FALSE);
	}
	if (!xdr_int(xdrs, &objp->numEpochs)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->msecs)) {
		return (FALSE);
	}
	if (!xdr_u_int(xdrs, &objp->week)) {
		return (FALSE);
	}
	return (TRUE);
}

