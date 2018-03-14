/******************************************************************************
Copyright (c) 1999 - 2001 Unigraphics Solutions, Inc.
Unpublished - All Rights Reserved

*******************************************************************************/
/*

This example requires an open part. The code creates a unit block
and a 4-sided polygon which is extruded and unioned to the bottom
of the block.

*/

#include <stdlib.h>
#include <stdio.h>
#include <uf_curve.h>
#include <math.h>
#include <uf_modl.h>
#include <uf.h>
#define EPSILON (double)1.0e-7
#define UF_CALL(X) (report( __FILE__, __LINE__, #X, (X)))
static int report(char *file, int line, char *call, int irc)
{
	if (irc)
	{
		char    messg[133];
		printf("%s, line %d:  %s\n", file, line, call);
		(UF_get_fail_message(irc, messg)) ?
			printf("    returned a %d\n", irc) :
			printf("    returned error %d:  %s\n", irc, messg);
	}
	return(irc);
}
static void do_ugopen_api(void)
{

	UF_FEATURE_SIGN sign_null = UF_NULLSIGN;
	UF_FEATURE_SIGN sign_minus = UF_NEGATIVE;
	tag_t tag_sphere0 = NULL, tag_cylinder0 = NULL;
	double center_sphere[3] = { 0, 0, 0 };
	double origin_cylinder1[3] = { 0, 0, 50 };
	double origin_cylinder2[3] = { 0, 50, 0 };
	double origin_cylinder3[3] = { 50, 0, 0 };
	char *diam_sphere = "100";
	char *height_cylinder = "200";
	char *diam_cylinder = "30";
	double dir_cylinder1[3] = { 0, 0, -1 };
	double dir_cylinder2[3] = { 0, -1, 0 };
	double dir_cylinder3[3] = { -1, 0, 0 };
	tag_t tag_cylinder1, tag_cylinder2, tag_cylinder3;
	tag_t tag_sphere1;

	UF_CALL(UF_MODL_create_sphere(sign_null, tag_sphere0, center_sphere, diam_sphere, &tag_sphere1));
	//UF_CALL(UF_MODL_create_cylinder(sign_minus, tag_sphere1, origin_cylinder1, height_cylinder, diam_cylinder, dir_cylinder1, &tag_cylinder1));
	UF_CALL(UF_MODL_create_cyl1(sign_minus, origin_cylinder1, height_cylinder, diam_cylinder, dir_cylinder1, &tag_cylinder1));
	UF_CALL(UF_MODL_create_cyl1(sign_minus, origin_cylinder2, height_cylinder, diam_cylinder, dir_cylinder2, &tag_cylinder2));
	UF_CALL(UF_MODL_create_cyl1(sign_minus, origin_cylinder3, height_cylinder, diam_cylinder, dir_cylinder3, &tag_cylinder3));


}
/*ARGSUSED*/
void ufusr(char *param, int *retcode, int param_len)
{
	if (!UF_CALL(UF_initialize()))
	{
		do_ugopen_api();
		UF_CALL(UF_terminate());
	}
}
int ufusr_ask_unload(void)
{
	return (UF_UNLOAD_IMMEDIATELY);
}


