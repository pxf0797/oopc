/**************************************************************************
* Copyright    : Copyright(C), 2019, pxf, person.
* File name    : My.c
* Author       : pxf
* Version      : v1.0
* Created on   : 2019/01/12 21:28:37
* Description  : 
* Others       : 
* History      : 190112 pxf 初建立
***************************************************************************/

#include "My.h"

/***********************************************************
* My类定义
***********************************************************/
/*名称 : My_func(hMy t)
* 输入 : t - My类指针
* 输出 : 无
* 其他 : My类功能函数
***********************************************/
void My_func(hMy t){
    //TODO
}

/*名称 : My_second(hMy t)
* 输入 : t - My类指针
* 输出 : 无
* 其他 : My类功能函数
***********************************************/
void My_second(hMy t){
    //TODO
}

/*名称 : My_third(hMy t)
* 输入 : t - My类指针
* 输出 : 无
* 其他 : My类功能函数
***********************************************/
void My_third(hMy t){
    //TODO
}

/*名称 : hMy My_init(hMy cthis)
* 输入 : cthis - My类指针
* 输出 : hMy - cthis/OOPC_NULL
* 其他 : My类初始化函数
***********************************************/
hMy My_init(hMy cthis){
    // 功能函数配置
    //cthis->func = My_func;
    //TODO

    // 参数配置
    //TODO

    return cthis;
}

/*名称 : hMy My_ctor(hMy cthis)
* 输入 : cthis - My类指针
* 输出 : hMy - cthis/OOPC_NULL
* 其他 : My类构造函数
***********************************************/
CC(My){
    cthis->init = My_init;
    cthis->func = My_func;
    cthis->second = My_second;
    cthis->third = My_third;
    //TODO

    // 参数配置
    //TODO
    return cthis;
}

/*名称 : hMy My_dtor(hMy cthis)
* 输入 : cthis - My类指针
* 输出 : OOPC_RETURN_DATATYPE - OOPC_TRUE/OOPC_FALSE
* 其他 : My类析构函数
***********************************************/
CD(My){
    return OOPC_TRUE;
}

/**************************** Copyright(C) pxf ****************************/
