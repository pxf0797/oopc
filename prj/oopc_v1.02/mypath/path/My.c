/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : My.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/01/12 21:28:37
* Description  : 
* Others       : 
* History      : 190112 pxf ������
***************************************************************************/

#include "My.h"

/***********************************************************
* My�ඨ��
***********************************************************/
/*���� : My_func(hMy t)
* ���� : t - My��ָ��
* ��� : ��
* ���� : My�๦�ܺ���
***********************************************/
void My_func(hMy t){
    //TODO
}

/*���� : My_second(hMy t)
* ���� : t - My��ָ��
* ��� : ��
* ���� : My�๦�ܺ���
***********************************************/
void My_second(hMy t){
    //TODO
}

/*���� : My_third(hMy t)
* ���� : t - My��ָ��
* ��� : ��
* ���� : My�๦�ܺ���
***********************************************/
void My_third(hMy t){
    //TODO
}

/*���� : hMy My_init(hMy cthis)
* ���� : cthis - My��ָ��
* ��� : hMy - cthis/OOPC_NULL
* ���� : My���ʼ������
***********************************************/
hMy My_init(hMy cthis){
    // ���ܺ�������
    //cthis->func = My_func;
    //TODO

    // ��������
    //TODO

    return cthis;
}

/*���� : hMy My_ctor(hMy cthis)
* ���� : cthis - My��ָ��
* ��� : hMy - cthis/OOPC_NULL
* ���� : My�๹�캯��
***********************************************/
CC(My){
    cthis->init = My_init;
    cthis->func = My_func;
    cthis->second = My_second;
    cthis->third = My_third;
    //TODO

    // ��������
    //TODO
    return cthis;
}

/*���� : hMy My_dtor(hMy cthis)
* ���� : cthis - My��ָ��
* ��� : OOPC_RETURN_DATATYPE - OOPC_TRUE/OOPC_FALSE
* ���� : My����������
***********************************************/
CD(My){
    return OOPC_TRUE;
}

/**************************** Copyright(C) pxf ****************************/
