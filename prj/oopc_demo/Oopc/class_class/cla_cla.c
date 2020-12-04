/*
 * cla_cla.c
 *
 *  Created on: 2018��2��8��
 *      Author: pxf
 */

#include "../Rte.h"

// �����������

/*
 * �ӿ�ֻ����̳���Ĺ��ܣ���ֻ�Լ̳����������
 * �໹�м̳в��������������ò���
 * */

void ClaFaInfFun(hClaFaInf t)
{
	SUB(t, ClaFaInf, ClaFa);
	cthis->ClaFaParam++;
}

// ���赱ǰ���������������ļ�
void ClaFaFun(hClaFa t)
{
	t->ClaFaParam2++;
}

// ����ɲ�������Ĺ��ܺ���
// ���ຯ�������ٶ��壬�Ͼ�����ֱ��ʹ������ֱ�ӽ��в���
void ClaFaFun2(hhClaFa t)
{
	SUBC(t, ClaFa, Cla);
	cthis->ClaParam2++;
}

hClaFa ClaFa_init(hClaFa cthis,
		void ClaFaInfFun(hClaFaInf t1),
		void (*ClaFaFun)(hClaFa t2),
		void (*ClaFaFun2)(hhClaFa t3))
{
	hClaFa Rtv = OOPC_NULL;
	if (OOPC_NULL != cthis)
	{
		cthis->ClaFaInf.CFInf = ClaFaInfFun;
		cthis->ClaFaFun = ClaFaFun;
		cthis->ClaFaFun2 = ClaFaFun2;
		Rtv = cthis;
	}
	else
	{
		Rtv = OOPC_NULL;
	}

	return Rtv;
}


CC(ClaFa)
{
	FS(init, ClaFa_init);

	cthis->ClaFaParam = 0;
	cthis->ClaFaParam2 = 0;
	cthis->ClaFaParam3 = 0;

	return cthis;
}

CD(ClaFa)
{
	cthis->ClaFaParam = 0;
	cthis->ClaFaParam2 = 0;
	cthis->ClaFaParam3 = 0;

	return OOPC_TRUE;
}



// �����������

void ClaInfFun(hClaInf t)
{
	SUB(t, ClaInf, Cla);
	cthis->ClaParam++;
}

void ClaFun(hCla t)
{
	t->ClaParam3++;
}

/*
 * �̳и������ͨ��init���д�������
 * ��Ϊ������ʱ���໹δ����ʵ����
 * �����������Ϊcthis
 * */
hCla Cla_init(hCla cthis,
		void ClaInfFun(hClaInf t2),
		void (*ClaFun)(hCla t3),
		hClaFa ClaFaaa,
		void ClaFaInfFun(hClaFaInf t4),
		void ClaFaFun(hClaFa t5),
		void ClaFaFun2(hhClaFa t6))
{
	hCla Rtv = OOPC_NULL;
	if (OOPC_NULL != cthis)
	{
		cthis->ClaInf.CInf = ClaInfFun;
		cthis->ClaFun = ClaFun;

		// �������ø���
		cthis->ClaFa = ClaFaaa;
		CCC(ClaFa, ClaFaaa, ClaFaInfFun, ClaFaFun, ClaFaFun2);
		if (OOPC_NULL == OPRS(*ClaFaaa))
		{
			if (OOPC_TRUE == CCD(ClaFa))
			{
				;
			}
			else
			{
				;
			}

			Rtv = OOPC_NULL;
		}
		else
		{
			Rtv = cthis;
		}
	}
	else
	{
		Rtv = OOPC_NULL;
	}

	return Rtv;
}


CC(Cla)
{
	FS(init, Cla_init);

	cthis->ClaParam = 0;
	cthis->ClaParam2 = 0;
	cthis->ClaParam3 = 0;

	return cthis;
}

CD(Cla)
{
	int Rtv = OOPC_FALSE;
	if (OOPC_NULL != cthis->ClaFa)
	{
		if (OOPC_TRUE == CCD(ClaFa))
		{
			cthis->ClaParam = 0;
			cthis->ClaParam2 = 0;
			cthis->ClaParam3 = 0;
			Rtv = OOPC_TRUE;
		}
		else
		{
			Rtv = OOPC_FALSE;
		}
	}
	else
	{
		Rtv = OOPC_FALSE;
	}

	return Rtv;
}

/*
 * �����Ǹ��໹�����඼�÷ֱ���г�ʼ��
 * ��ʼ����˳��������Ƚ��������ٽ��и����
 *
 * */































