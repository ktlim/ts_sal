/*
 * Please so not edit this file by hand!
 * This file was automatically generated by: nddsgen
 */

#include <rpc/types.h>
#include <rpc/xdr.h>
#include "hiResImage.h"


bool_t
xdr_hiResImageStruct(XDR *xdrs, hiResImageStruct *objp)
{
	if (!xdr_int(xdrs, &objp->targetID)) {
		return (FALSE);
	}
	if (!xdr_vector(xdrs, (char *)objp->filename, 128, sizeof(char), xdr_char)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->ptuAzimuth)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->ptuElevation)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->robot_dx)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->robot_dy)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->robot_dz)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->robotAzimuth)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->robotPitch)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->robotRoll)) {
		return (FALSE);
	}
	if (!xdr_int(xdrs, &objp->GPS_msecs)) {
		return (FALSE);
	}
	if (!xdr_int(xdrs, &objp->GPS_week)) {
		return (FALSE);
	}
	return (TRUE);
}

