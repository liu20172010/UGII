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
	// create a cylinder1
	UF_FEATURE_SIGN sign_null = UF_NULLSIGN;
	double orign_cylinder1[3] = { 0, 0, 0 };
	char *heigh_cylinder1 = "10";
	char *diam_cylinder1 = "100";
	double dir_cylinder1[3] = { 0, 0, 1 };
	tag_t tag_cylinder1;
	UF_CALL(UF_MODL_create_cyl1(sign_null, orign_cylinder1, heigh_cylinder1, diam_cylinder1, dir_cylinder1, &tag_cylinder1));

	//create a cylinder2
	UF_FEATURE_SIGN sign_minus = UF_NEGATIVE;
	double orign_cylinder2[3] = { 0, 30, 10 };
	char *heigh_cylinder2 = "4";
	char *diam_cylinder2 = "10";
	double dir_cylinder2[3] = { 0, 0, -1 };
	tag_t tag_cylinder2;
	//UF_CALL(UF_MODL_create_cylinder(sign_minus, &tag_cylinder1, orign_cylinder2, heigh_cylinder2, diam_cylinder2, dir_cylinder2, &tag_cylinder2));
	UF_CALL(UF_MODL_create_cyl1(sign_minus, orign_cylinder2, heigh_cylinder2, diam_cylinder2, dir_cylinder2, &tag_cylinder2));

	//create a cone
	UF_FEATURE_SIGN sign_minus2 = UF_UNSIGNED;
	double origin_cone1[3] = { 0, 30, 6 };
	char *height_cone1 = "4";
	char *diam_cone1[2] = { "10", "6" };
	double dir_cone1[3] = { 0, 0, -1 };
	tag_t tag_cone1;
	UF_CALL(UF_MODL_create_cone1(sign_minus, origin_cone1, height_cone1, diam_cone1, dir_cone1, &tag_cone1));

	//create a list
	uf_list_p_t feature_list1;
	UF_CALL(UF_MODL_create_list(&feature_list1));
	UF_CALL(UF_MODL_put_list_item(feature_list1, tag_cylinder2));
	UF_CALL(UF_MODL_put_list_item(feature_list1, tag_cone1));

	//create circular iset
	int method_iset1 = 0;
	double location_iset1[3] = { 0, 0, 0 };
	double axis_iset1[3] = { 0, 0, 1 };
	char *number_str_iset1 = "6";
	char *angle_str_iset1 = "60";
	tag_t tag_iset1;
	UF_CALL(UF_MODL_create_circular_iset(method_iset1, location_iset1, axis_iset1, number_str_iset1, angle_str_iset1, feature_list1, &tag_iset1));

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


