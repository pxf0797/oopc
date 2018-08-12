/*
 * oopc.h
 *
 *  Created on: 2018��2��8��
 *      Author: pxf
 */

#ifndef OOPC_H_
#define OOPC_H_

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ͨ�ú궨��-------------------------------------------------------------------
#define OOPC_FALSE                      0
#define OOPC_TRUE                       1
#define OOPC_NULL                       ((void *)0)

// ����ѡ��---------------------------------------------------------------------
// ���ú�(��������ѡ��һ):
#define USE_STDDEF_OFFSETOF             0   // ��ʾʹ��C��׼�����offsetof
#define USE_USER_DEFINED_OFFSETOF       1   // ��ʾʹ���û��Զ����oopc_offsetof��
#define OOPC_USE_OFFSETOF               USE_USER_DEFINED_OFFSETOF

#define oopc_return_datatype            int // ���庯��������������

// OOPC���ʵ��-----------------------------------------------------------------
// ƫ�Ƶ�ַѡ��
#if (OOPC_USE_OFFSETOF == USE_STDDEF_OFFSETOF)
    #include <stddef.h>
// size_t offsetof(structName, memberName);
// ��һ�������ǽṹ������֣��ڶ��������ǽṹ���Ա�����֡�
// �ú귵�ؽṹ��structName�г�ԱmemberName��ƫ������ƫ������size_t���͵ġ�
    #define OOPC_OFFSETOF               offsetof
#else
    // ��Щ�������ܲ�֧�֣��������������μ��ٳ���
    #define OOPC_OFFSETOF(type, member) (size_t)&(((type*)0)->member)
#endif
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// �ӿڼ���ļ̳й�ϵ implement,extends------------------------------------------

// �ӿڡ���������м̳�Implement
#define IMPL(type)                      type type
// ʵ����м̳�Extends
#define EXT(type)                       h##type type

// ----------------------------------------------------------------------------
// ��ļ̳н���һ���̳У��༶�̳в��ǲ����ԣ�����c�������е���Լ����鷳

// ʵ��̳����ࣨ�̳��ָࣩ�� subordinate,self pointer---------------------------
#define SUBC(selfpointer, hselftype, childtype)                      \
h##childtype cthis = ((h##childtype)((char*)(*selfpointer) - OOPC_OFFSETOF(childtype, hselftype)))
// �������ӿڼ̳����ࣨ�̳��ָࣩ��
#define SUB(selfpointer, selftype, childtype)                        \
h##childtype cthis = ((h##childtype)((char*)selfpointer - OOPC_OFFSETOF(childtype, selftype)))

// �ڹ��캯���ж���Ĳ����������� function,setting--------------------------------
// ��һ�����������ͨ�õ����ã���ô����ʹ��FS���ڹ��캯���У�������ͨ��init����һЩ�ɱ�Ĳ���

// FunctionSetting�����ຯ��
#define FS(ClassFunction, SourceFunction) cthis->ClassFunction = SourceFunction
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// �ӿڼ���Ķ���---------------------------------------------------------------
// ������(abstract)�ͽӿ�(interface)�Ĺ��캯��û�з���ֵ�ĳɹ������Ϊ�̳�֮����ʵ��

// Interface�ӿڽ�������
#define INF(type)                                                    \
typedef struct type *h##type, type;                                  \
struct type
// AbstractClass�������������
#define AC(type)                                                     \
typedef struct type *h##type, type;                                  \
struct type
// Classʵ���������
// �������б���Ҫ����self,init�����в�������
// selfָ��������÷��ڲ����ĵ�һ����h##type self
// init�в���Ҫ���ҷ�����������ָ�룬h##type (*init)(classptr cthis,...)
// init��������ָ���������Ϊcthis�����������к��������ж���������cthis�Ĳ�������
// �ӿں����������ຯ�����Լ���������ͬһ�ļ��ڵĺ�������ͨ��init�������ν��г�ʼ��
// ��������ͬһ�ļ��ں������ͨ��FSֱ�ӽ�������
// ʾ����
// CL(Aaa)
// {
//	   hAaa self;
//	   hAaa (*init)(hAaa cthis, ...);
//	   ...
// }
#define CL(type)                                                     \
typedef struct type **hh##type, *h##type, type;                      \
h##type type##_new(void *self);                                      \
oopc_return_datatype type##_delete(h##type t);                       \
struct type
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ���캯����������������--------------------------------------------------------
// �ļ�����������ֻ��.c�ļ����������У�����ͷ�ļ��������ᱨ������

// ��������๹�캯������Ҫ����ֵcthis/OOPC_NULL
#define ACC(type)                                                    \
static inline h##type type##_ctor(h##type cthis);                    \
static inline h##type type##_ctor(h##type cthis)
// ���������������������Ҫ����ֵOOPC_TRUE/OOPC_FALSE
#define ACD(type)                                                    \
static inline oopc_return_datatype type##_dtor(h##type cthis);       \
static inline oopc_return_datatype type##_dtor(h##type cthis)
// ����ʵ�๹�캯������Ҫ����ֵcthis/OOPC_NULL
#define CC(type)                                                     \
static inline h##type type##_ctor(h##type cthis);                    \
h##type type##_new(void *self){                                      \
    h##type cthis = (h##type)self;                                   \
    h##type Rtv = OOPC_NULL;                                         \
    if (OOPC_NULL != cthis){                                         \
        cthis->self = cthis;                                         \
        if (OOPC_NULL == type##_ctor(cthis)){                        \
            cthis->self = OOPC_NULL;                                 \
            Rtv = OOPC_NULL;                                         \
        } else {                                                     \
            Rtv = cthis;                                             \
        }                                                            \
    } else {                                                         \
    	Rtv = OOPC_NULL;                                             \
    }                                                                \
    return Rtv;                                                      \
    /* ��ǰ��ȥ��ȡ�ڴ棬ֻ�Դ���������ڴ�������� */                  \
}                                                                    \
static inline h##type type##_ctor(h##type cthis)
// ����ʵ��������������Ҫ����ֵOOPC_TRUE/OOPC_FALSE
#define CD(type)                                                     \
static inline oopc_return_datatype type##_dtor(h##type cthis);       \
oopc_return_datatype type##_delete(h##type cthis){                   \
	oopc_return_datatype Rtv = OOPC_FALSE;                           \
	if (OOPC_NULL != cthis){                                         \
		cthis->self = OOPC_NULL;                                     \
	    if (OOPC_TRUE == type##_dtor(cthis)){                        \
            Rtv = OOPC_TRUE;                                         \
        } else {                                                     \
            Rtv = OOPC_FALSE;                                        \
        }                                                            \
	} else {                                                         \
		Rtv = OOPC_FALSE;                                            \
	}                                                                \
	return Rtv;                                                      \
	/* ��ǰ��ȥ�ͷ��ڴ棬ֻ�Դ���������ڴ�������� */                  \
}                                                                    \
static inline oopc_return_datatype type##_dtor(h##type cthis)
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ��ʵ����ʱ�����켰��������----------------------------------------------------

// ���ó����๹�캯�����з���ֵcthis/OOPC_NULL
#define _ACC(father)                    father##_ctor(&(cthis->father))
// ���ó����������������з���ֵOOPC_TRUE/OOPC_FALSE
#define _ACD(father)                    father##_dtor(&(cthis->father))

// ����ʵ�๹�졢��������
// �����๹�캯�����з���ֵcthis/OOPC_NULL
// ������˹��캯�������cthis->father�����жϣ���Ϊ��ǰ���캯������û�з���ֵ
#define _CC(father, fatherptr, ...)                                  \
do{                                                                  \
    cthis->father = father##_new((void *)(fatherptr));               \
    if (OOPC_NULL != cthis->father){                                 \
        if (OOPC_NULL == cthis->father->init(cthis->father, __VA_ARGS__)){ \
        	if (OOPC_TRUE == father##_delete(cthis->father)){        \
        		;                                                    \
        	} else {                                                 \
        		;                                                    \
        	}                                                        \
        	cthis->father = OOPC_NULL;                               \
        } else {                                                     \
        	;                                                        \
        }                                                            \
    } else {                                                         \
    	;                                                            \
    }                                                                \
} while (0)
// �����������������з���ֵOOPC_TRUE/OOPC_FALSE
#define _CD(father)                     father##_delete((cthis->father))
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// ���ʼ���궨�壬������������--------------------------------------------------
// ����Ķ���������ɱ��̳����ʼ���������������� class,new
// ClassNew������г�ʼ��
#define CN(type, classptr, ...)                                      \
do{                                                                  \
    if (OOPC_NULL != type##_new((void *)(classptr))){                \
		if (OOPC_NULL == (classptr)->init((classptr), __VA_ARGS__)){ \
        	if (OOPC_TRUE == type##_delete(classptr)){               \
        		;                                                    \
        	} else {                                                 \
        		;                                                    \
        	}                                                        \
        } else {                                                     \
        	;                                                        \
        }                                                            \
    } else {                                                         \
        ;                                                            \
    }                                                                \
} while (0)
// ClassFree������Դ�����ͷ�
#define CF(type, classptr)                                           \
do{                                                                  \
	if (OOPC_NULL != (classptr)){                                    \
		if (OOPC_TRUE == type##_delete(classptr)){                   \
            ;                                                        \
        } else {                                                     \
        	;                                                        \
        }                                                            \
	} else {                                                         \
		;                                                            \
	}                                                                \
} while (0)
// ����CN/CF/_CC���ú�û�з���ֵ��ͨ�����º�鿴�������operation result��self/OOPC_NULL
#define OPRS(class)                     (class).self
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

#endif /* OOPC_H_ */
