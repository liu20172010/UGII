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

	//create a block
	UF_FEATURE_SIGN sign_null = UF_NULLSIGN;
	double corner_block1[3] = { -50, 0, 0 };
	char *length_block1[3] = { "100", "80", "30" };
	tag_t tag_block1;
	UF_CALL(UF_MODL_create_block1(sign_null, corner_block1, length_block1, &tag_block1));

	// create a cylinder1
	UF_FEATURE_SIGN sign_plus = UF_POSITIVE;
	double orign_cylinder1[3] = { -50, 25, 0 };
	char *heigh_cylinder1 = "30";
	char *diam_cylinder1 = "80";
	double dir_cylinder1[3] = { 0, 0, 1 };
	tag_t tag_cylinder1;
	UF_CALL(UF_MODL_create_cyl1(sign_plus, orign_cylinder1, heigh_cylinder1, diam_cylinder1, dir_cylinder1, &tag_cylinder1));

	// create a cylinder2
	double orign_cylinder2[3] = { -50, 25, 30 };
	char *heigh_cylinder2 = "10";
	char *diam_cylinder2 = "30";
	double dir_cylinder2[3] = { 0, 0, 1 };
	tag_t tag_cylinder2;
	UF_CALL(UF_MODL_create_cyl1(sign_plus, orign_cylinder2, heigh_cylinder2, diam_cylinder2, dir_cylinder2, &tag_cylinder2));

	// create a cylinder3
	UF_FEATURE_SIGN sign_minus = UF_NEGATIVE;
	double orign_cylinder3[3] = { -50, 25, 40 };
	char *heigh_cylinder3 = "40";
	char *diam_cylinder3 = "20";
	double dir_cylinder3[3] = { 0, 0, -1 };
	tag_t tag_cylinder3;
	UF_CALL(UF_MODL_create_cyl1(sign_minus, orign_cylinder3, heigh_cylinder3, diam_cylinder3, dir_cylinder3, &tag_cylinder3));


	// create a cylinder4
	double orign_cylinder4[3] = { 50, 25, 0 };
	char *heigh_cylinder4 = "30";
	char *diam_cylinder4 = "80";
	double dir_cylinder4[3] = { 0, 0, 1 };
	tag_t tag_cylinder4;
	UF_CALL(UF_MODL_create_cyl1(sign_plus, orign_cylinder4, heigh_cylinder4, diam_cylinder4, dir_cylinder4, &tag_cylinder4));

	// create a cylinder5
	double orign_cylinder5[3] = { 50, 25, 30 };
	char *heigh_cylinder5 = "10";
	char *diam_cylinder5 = "30";
	double dir_cylinder5[3] = { 0, 0, 1 };
	tag_t tag_cylinder5;
	UF_CALL(UF_MODL_create_cyl1(sign_plus, orign_cylinder5, heigh_cylinder5, diam_cylinder5, dir_cylinder5, &tag_cylinder5));

	// create a cylinder6
	double orign_cylinder6[3] = { 50, 25, 40 };
	char *heigh_cylinder6 = "40";
	char *diam_cylinder6 = "20";
	double dir_cylinder6[3] = { 0, 0, -1 };
	tag_t tag_cylinder6;
	UF_CALL(UF_MODL_create_cyl1(sign_minus, orign_cylinder6, heigh_cylinder6, diam_cylinder6, dir_cylinder6, &tag_cylinder6));


	//create a block2
	double corner_block2[3] = { -30, 50, 20 };
	char *length_block2[3] = { "60", "20", "10" };
	tag_t tag_block2;
	UF_CALL(UF_MODL_create_block1(sign_minus, corner_block2, length_block2, &tag_block2));

	// create a cylinder7
	double orign_cylinder7[3] = { -30, 60, 30 };
	char *heigh_cylinder7 = "10";
	char *diam_cylinder7 = "20";
	double dir_cylinder7[3] = { 0, 0, -1 };
	tag_t tag_cylinder7;
	UF_CALL(UF_MODL_create_cyl1(sign_minus, orign_cylinder7, heigh_cylinder7, diam_cylinder7, dir_cylinder7, &tag_cylinder7));

	// create a cylinder8
	double orign_cylinder8[3] = { 30, 60, 30 };
	char *heigh_cylinder8 = "10";
	char *diam_cylinder8 = "20";
	double dir_cylinder8[3] = { 0, 0, -1 };
	tag_t tag_cylinder8;
	UF_CALL(UF_MODL_create_cyl1(sign_minus, orign_cylinder8, heigh_cylinder8, diam_cylinder8, dir_cylinder8, &tag_cylinder8));




	//UF_FEATURE_SIGN sign_null = UF_NULLSIGN;
	//UF_FEATURE_SIGN sign_minus = UF_NEGATIVE;
	//tag_t tag_sphere0 = NULL, tag_cylinder0 = NULL;
	//double center_sphere[3] = { 0, 0, 0 };
	//double origin_cylinder1[3] = { 0, 0, 50 };
	//double origin_cylinder2[3] = { 0, 50, 0 };
	//double origin_cylinder3[3] = { 50, 0, 0 };
	//char *diam_sphere = "100";
	//char *height_cylinder = "200";
	//char *diam_cylinder = "30";
	//double dir_cylinder1[3] = { 0, 0, -1 };
	//double dir_cylinder2[3] = { 0, -1, 0 };
	//double dir_cylinder3[3] = { -1, 0, 0 };
	//tag_t tag_cylinder1, tag_cylinder2, tag_cylinder3;
	//tag_t tag_sphere1;

	//UF_CALL(UF_MODL_create_sphere(sign_null, tag_sphere0, center_sphere, diam_sphere, &tag_sphere1));
	////UF_CALL(UF_MODL_create_cylinder(sign_minus, tag_sphere1, origin_cylinder1, height_cylinder, diam_cylinder, dir_cylinder1, &tag_cylinder1));
	//UF_CALL(UF_MODL_create_cyl1(sign_minus, origin_cylinder1, height_cylinder, diam_cylinder, dir_cylinder1, &tag_cylinder1));
	//UF_CALL(UF_MODL_create_cyl1(sign_minus, origin_cylinder2, height_cylinder, diam_cylinder, dir_cylinder2, &tag_cylinder2));
	//UF_CALL(UF_MODL_create_cyl1(sign_minus, origin_cylinder3, height_cylinder, diam_cylinder, dir_cylinder3, &tag_cylinder3));







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


