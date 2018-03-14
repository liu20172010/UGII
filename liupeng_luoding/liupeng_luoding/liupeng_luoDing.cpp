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
	// create a prism
	double center_prism1[3] = { 0, 0, 0 };
	double diam_prism1 = 30;
	double height_prism1 = 10;
	double dir_prism1[3] = { 0, 0, 1 };
	int number_prism1 = 6;
	tag_t tag_prism1;
	uf6505(center_prism1, &diam_prism1, &height_prism1, &number_prism1, dir_prism1, &tag_prism1);

	//create a cone
	UF_FEATURE_SIGN sign_minus = UF_UNSIGNED;
	tag_t tag_cone1;
	double origin_cone1[3] = { 0, 0, 10 };
	char *height_cone1 = "10";
	char *diam_cone1[2] = { "64.64", "30" };
	double dir_cone1[3] = { 0, 0, -1 };
	UF_CALL(UF_MODL_create_cone(sign_minus, tag_prism1, origin_cone1, height_cone1, diam_cone1, dir_cone1, &tag_cone1));
	//UF_CALL(UF_MODL_create_cone1(sign_minus, origin_cone1, height_cone1, diam_cone1, dir_cone1, &tag_cone1));

	// create a cylinder1
	UF_FEATURE_SIGN sign_null = UF_POSITIVE;
	double orign_cylinder1[3] = { 0, 0, 10 };
	char *heigh_cylinder1 = "80";
	char *diam_cylinder1 = "18";
	double dir_cylinder1[3] = { 0, 0, 1 };
	tag_t tag_cylinder1;
	UF_CALL(UF_MODL_create_cyl1(sign_null, orign_cylinder1, heigh_cylinder1, diam_cylinder1, dir_cylinder1, &tag_cylinder1));



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


