//////////////////////////////////////////////////////////////////////
//
// MutexInteger.h: interface for the CMutexInteger class.
// ʵ�����Զ�����������������������
// �� �� ��:CVorxMutex CAutuMutex CMutexInteger CVorxEvent
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MUTEXOBJECT_H__7CC50D8D_A571_414F_AC1A_A82D574A4489__INCLUDED_)
#define AFX_MUTEXOBJECT_H__7CC50D8D_A571_414F_AC1A_A82D574A4489__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef WIN32
#include <pthread.h>
#endif
#include "MacroDefine.h"



	/////////////////////////////////////////////////////////////////////
	//���������
	class CVorxMutex
	{
#ifdef WIN32
	private:
		HANDLE m_hObject;
	public:
		void Lock(){WaitForSingleObject(m_hObject,INFINITE);}
		void Unlock(){ReleaseMutex(m_hObject);}
		
		CVorxMutex(){m_hObject = CreateMutex(NULL,FALSE,NULL);}
		virtual ~CVorxMutex(){CloseHandle(m_hObject);}
#else
	private:
		pthread_mutex_t m_hObject;
	public:
		void Lock(){pthread_mutex_lock(&m_hObject);}
		void Unlock(){pthread_mutex_unlock(&m_hObject);}
		
		CVorxMutex(){pthread_mutex_init(&m_hObject, NULL);}
		virtual ~CVorxMutex(){pthread_mutex_destroy(&m_hObject);}
#endif
	};
	
	/////////////////////////////////////////////////////////////////////
	//�Զ�������
	class CAutoMutex
	{
	private:
		CVorxMutex* m_pMutex;
		
	public:
		CAutoMutex(CVorxMutex* p){m_pMutex=p;m_pMutex->Lock();}
		virtual ~CAutoMutex(){m_pMutex->Unlock();}
	};
	
	/////////////////////////////////////////////////////////////////////
	//����������
	class CMutexInteger
	{
	private:
		int m_nValue;
		CVorxMutex m_mutex;
		
	public:
		void operator&=(int nParam);
		int  operator&(int nParam);
		void operator|=(int nParam);
		int  operator|(int nParam);
		void operator=(int nParam);
		void operator=(const CMutexInteger& nParam);
		void operator+=(int nParam);
		void operator++();
		void operator--();
		int  operator+(int nParam);
		void operator-=(int nParam);
		int  operator-(int nParam);
		bool operator==(int nParam);
		bool operator!();
		bool operator>(int nParam);
		bool operator>=(int nParam);
		bool operator<(int nParam);
		bool operator<=(int nParam);
		bool operator!=(int nParam);
		operator int();
		int GetAndSetValue(int nVal);
		CMutexInteger();
		CMutexInteger(const CMutexInteger &ref);
		virtual ~CMutexInteger();
	};

	/////////////////////////////////////////////////////////////////////
	//�¼�������
	class CVorxEvent
	{
	private:
#ifndef USE_CHECK_EVENT

#ifdef WIN32
		HANDLE m_hEvent;
#else
		pthread_cond_t  m_hEvent;
		pthread_mutex_t m_mutex;
#endif

#else
		BOOL m_bSignal;
		CVorxMutex m_mutex;
#endif

	public:
		BOOL WaitForSignal(int nTimeOut);	//��λ:ms,���غ��Զ���Ϊ���ź�
		void Signal();						//����Ϊ���ź�
		CVorxEvent();						//��ʼ״̬Ϊ���ź�״̬
		virtual ~CVorxEvent();
	};
	

#endif // !defined(AFX_MUTEXOBJECT_H__7CC50D8D_A571_414F_AC1A_A82D574A4489__INCLUDED_)