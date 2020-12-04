/*
 * cla_abs_abs_test.c
 *
 *  Created on: 2018��2��8��
 *      Author: pxf
 */

#include "../Rte.h"


void ClaAbsInfTest(void)
{
	Ccc ClassAbs;
	// ������ʵ��
	CN(Ccc, &ClassAbs,
			Ccc_Aaa_InfFun2,
			Ccc_Bbb_AbsFun, Ccc_Bbb_AbsFun2,
			Ccc_ClaFun2);
	if (OOPC_NULL != OPRS(ClassAbs))
	{
		;
	}
	else
	{
		;
	}

	// ��Ӧ�����
	ClassAbs.Aaa.InfFun2(&ClassAbs.Aaa);
	ClassAbs.Bbb.AbsFun();
	ClassAbs.Bbb.AbsFun2(&ClassAbs.Bbb);
	ClassAbs.ClaFun();
	ClassAbs.ClaFun2(ClassAbs.self);

	// �ͷ�����Դ
	CF(Ccc, ClassAbs.self);
	if (OOPC_NULL != OPRS(ClassAbs))
	{
		;
	}
	else
	{
		;
	}
}





