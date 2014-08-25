/*
 * Please so not edit this file by hand!
 * This file was automatically generated by: nddsgen
 */

#include <rpc/types.h>
#include <rpc/xdr.h>
#include "panoramicImage.h"


bool_t
xdr_panoramicImageStruct(XDR *xdrs, panoramicImageStruct *objp)
{
	if (!xdr_vector(xdrs, (char *)objp->filename, 128, sizeof(char), xdr_char)) {
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
	if (!xdr_float(xdrs, &objp->GPS_msecs)) {
		return (FALSE);
	}
	if (!xdr_float(xdrs, &objp->GPS_week)) {
		return (FALSE);
	}
	return (TRUE);
}

