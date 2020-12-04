/*
 * cla_abs_inf.c
 *
 *  Created on: 2018��2��8��
 *      Author: pxf
 */

#include "../Rte.h"

ACC(Bbb)
{
	// �����Ҫ�����һЩ����Ĳ���������ֱ�ӷ���cthis����
	// ������ĺ���һ����ʵ���ʼ��ʱ���г�ʼ������Ϊ�����������ǵ�ʵ��
	cthis->AbsParam = 0;
	return cthis;
}
ACD(Bbb)
{
	// �����Ҫ�����һЩ����Ĳ���������ֱ�ӷ���OOPC_TRUE����
	cthis->AbsParam = 0;
	return OOPC_TRUE;
}

// �ӿڡ������ຯ������������Ҫ�ĺ������ж���
//void Ccc_Aaa_InfFun(void)
//{
//	;
//}
void Ccc_Aaa_InfFun2(hAaa t)
{
	SUB(t, Aaa, Ccc);
	cthis->ClaParam++;
}

void Ccc_Bbb_AbsFun(void)
{
	;
}
void Ccc_Bbb_AbsFun2(hBbb t)
{
	SUB(t, Bbb, Ccc);
	cthis->ClaParam2++;
}

void Ccc_ClaFun(void)
{
	;
}
// �ɶ��嵽�����ļ���ͨ��������ʽ���г�ʼ��
void Ccc_ClaFun2(hCcc t)
{
	t->ClaParam3++;
}

/*
 * �ӿڡ������ຯ�����Զ��嵽�����ļ�����Ϊʵ������ʼ������ͨ��init������ʽ���е���
 * ʵ�ຯ��Ҳ���Զ��嵽�����ļ���ͨ��init���ν��г�ʼ��
 * ʵ�ຯ�����嵽�빹�캯��ͬһ�ļ��ڵĺ������ʹ��FS��ʽ�������ã��Ա����Ż�
 * init����������ʵ�๹�캯�����嵽ͬһ�ļ��ڣ�����ʹ��FS��������
 * */


/*
 * ʵ���ʼ����������ֻ����һЩ���ε����ò���
 * ʵ������һЩ���������ڹ��캯���н��в���
 * */
hCcc Ccc_init(hCcc cthis,
		void (*AaaInf)(hAaa t2),
		void (*BbbFun)(void),
		void (*BbbFun2)(hBbb t3),
		void (*CccFun2)(hCcc t4))
{
	hCcc Rtv = OOPC_NULL;
	if (OOPC_NULL != cthis)
	{
		cthis->Aaa.InfFun2 = AaaInf;
		cthis->Bbb.AbsFun = BbbFun;
		cthis->Bbb.AbsFun2 = BbbFun2;
		cthis->ClaFun2 = CccFun2;
		Rtv = cthis;
	}
	else
	{
		Rtv = OOPC_NULL;
	}
	return Rtv;
}

// �����ʵ��ǰ�������ȰѰ���Ҫ�Ľӿڡ������ຯ������������Ҫ�ĺ����ȶ������
CC(Ccc)
{
	hCcc Rtv = OOPC_NULL;
	if (OOPC_NULL != CACC(Bbb))
	{
		FS(init, Ccc_init);
		FS(ClaFun, Ccc_ClaFun);
		//FS(ClaFun2, Ccc_ClaFun2); // �ڶ���Ϊͬһ�ļ���Ӧʹ��FS����

		cthis->ClaParam = 0;
		cthis->ClaParam2 = 0;
		cthis->ClaParam3 = 0;

		Rtv = cthis;
	}
	else
	{
		Rtv = OOPC_NULL;
	}

	return Rtv;
}

CD(Ccc)
{
	int Rtv = OOPC_FALSE;
	if (OOPC_FALSE != CACD(Bbb))
	{
		Rtv = OOPC_TRUE;
	}
	else
	{
		Rtv = OOPC_FALSE;
	}

	return Rtv;
}






















