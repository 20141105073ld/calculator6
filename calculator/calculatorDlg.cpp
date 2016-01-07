
// calculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg 对话框




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	c=180;
	a=174;
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_0, &CcalculatorDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_1, &CcalculatorDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CcalculatorDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CcalculatorDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CcalculatorDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CcalculatorDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CcalculatorDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CcalculatorDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CcalculatorDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CcalculatorDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_POINT, &CcalculatorDlg::OnBnClickedPoint)
	ON_BN_CLICKED(IDC_DEL, &CcalculatorDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_ADD, &CcalculatorDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEC, &CcalculatorDlg::OnBnClickedDec)
	ON_BN_CLICKED(IDC_MNL, &CcalculatorDlg::OnBnClickedMnl)
	ON_BN_CLICKED(IDC_DIVIDE, &CcalculatorDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_CAL, &CcalculatorDlg::OnBnClickedCal)
	ON_BN_CLICKED(IDC_BACK, &CcalculatorDlg::OnBnClickedBack)
	ON_BN_CLICKED(IDC_BEAR, &CcalculatorDlg::OnBnClickedBear)
	ON_BN_CLICKED(IDC_RAD, &CcalculatorDlg::OnBnClickedRad)
	ON_BN_CLICKED(IDC_COS, &CcalculatorDlg::OnBnClickedCos)
	ON_BN_CLICKED(IDC_TAN, &CcalculatorDlg::OnBnClickedTan)
	ON_BN_CLICKED(IDC_sin, &CcalculatorDlg::OnBnClickedsin)
	ON_BN_CLICKED(IDC_sqare, &CcalculatorDlg::OnBnClickedsqare)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_PERCENT, &CcalculatorDlg::OnBnClickedPercent)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1,1000,NULL);
	SetTimer(2,60000,NULL);
	SetTimer(3,360000,NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedPoint()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(m_str.Find(L".")==-1)
	m_str=m_str+L".";
	UpdateData(false);
}





void CcalculatorDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
    UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDec()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
    UpdateData(false);
}


void CcalculatorDlg::OnBnClickedMnl()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
    UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDivide()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
    UpdateData(false);
}
void CcalculatorDlg::OnBnClickedBack()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
    m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码
	m_str="";
	UpdateData(false);
}






void CcalculatorDlg::OnBnClickedBear()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=L"-"+m_str;
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedRad()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=sqrt(temp);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);

}



void CcalculatorDlg::OnBnClickedsin()
{
	// TODO: 在此添加控件通知处理程序代码
		double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=sin(temp);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedCos()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=cos(temp);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedTan()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=tan(temp);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}



void CcalculatorDlg::OnBnClickedCal()
{
	// TODO: 在此添加控件通知处理程序代码
	TRACE(L"flag=%d",flag);
	UpdateData(true);
	if(flag==1)
	{
		temp=temp+_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==2)
	{
		temp=temp-_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==3)
	{
		temp=temp*_ttof(m_str);
		m_str.Format(L"%lf",temp);
	}
	if(flag==4)
	{
		if(_ttof(m_str)==0)
		{
			m_str.Format(L"error");
		}
		else
		{
			temp=temp/_ttof(m_str);
		    m_str.Format(L"%lf",temp);
		}
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}






void CcalculatorDlg::OnBnClickedsqare()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=pow(temp,2);
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	
}


void CcalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str.Format(L"%lf",temp);
	if(temp==0)
	{
		m_str.Format(L"error");
	}
	else
	{
		temp=1/temp;
		m_str.Format(L"%lf",temp);
	}
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);

}


void CcalculatorDlg::OnBnClickedPercent()
{
	double temp;
	UpdateData(true);
	temp=_ttof(m_str);
	temp=temp/100;
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
	// TODO: 在此添加控件通知处理程序代码
}


void CcalculatorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialogEx::OnTimer(nIDEvent);
	int  x,y,x1,y1,x2,y2,x3,y3,x4,y4,x5,y5,ox=450,oy=200;
	if(nIDEvent==1)
	{
	    int r=70;
		CDC *pDC;
	    CPen newpen,*oldpen;
	    newpen.CreatePen(PS_SOLID,1,RGB(240,240,240));
	    pDC=GetDC();
	    oldpen=pDC->SelectObject(&newpen);
	    x=ox+r*sin(c*3.1415926/180);
	    y=oy+r*cos(c*3.1415926/180);
	    pDC->MoveTo(ox,oy);
	    pDC->LineTo(x,y);
	    c=c-6;
	    CDC *pDC1;
	    CPen newpen1,*oldpen1;
	    newpen1.CreatePen(PS_SOLID,1,RGB(0,0,0));
	    pDC1=GetDC();
	    oldpen1=pDC1->SelectObject(&newpen1);
	    x1=ox+r*sin(a*3.1415926/180);
	    y1=oy+r*cos(a*3.1415926/180);
	    pDC1->MoveTo(ox,oy);
	    pDC1->LineTo(x1,y1);
	    a=a-6;
	}
	if(nIDEvent==2)
	{   int r1=50;
		CDC *pDC3;
	    CPen newpen3,*oldpen3;
	    newpen3.CreatePen(PS_SOLID,10,RGB(240,240,240));
	    pDC3=GetDC();
	    oldpen3=pDC3->SelectObject(&newpen3);
	    x2=ox+r1*sin(c*3.1415926/180);
	    y2=oy+r1*cos(c*3.1415926/180);
	    pDC3->MoveTo(ox,oy);
	    pDC3->LineTo(x2,y2);
	    c=c-6;
		CDC *pDC4;
	    CPen newpen4,*oldpen4;
	    newpen4.CreatePen(PS_SOLID,10,RGB(150,150,150));
	    pDC4=GetDC();
	    oldpen4=pDC4->SelectObject(&newpen4);
	    x3=ox+r1*sin(a*3.1415926/180);
	    y3=oy+r1*cos(a*3.1415926/180);
	    pDC4->MoveTo(ox,oy);
	    pDC4->LineTo(x3,y3);
	    a=a-6;
	}
	if(nIDEvent==3)
	{   
		int r2=40;
		CDC *pDC5;
	    CPen newpen5,*oldpen5;
	    newpen5.CreatePen(PS_SOLID,1,RGB(240,240,240));
	    pDC5=GetDC();
	    oldpen5=pDC5->SelectObject(&newpen5);
	    x4=ox+r2*sin(c*3.1415926/180);
	    y4=oy+r2*cos(c*3.1415926/180);
	    pDC5->MoveTo(ox,oy);
	    pDC5->LineTo(x4,y4);
	    c=c-6;
		CDC *pDC6;
	    CPen newpen6,*oldpen6;
	    newpen6.CreatePen(PS_SOLID,1,RGB(100,100,100));
	    pDC6=GetDC();
	    oldpen6=pDC6->SelectObject(&newpen6);
	    x5=ox+r2*sin(a*3.1415926/180);
	    y5=oy+r2*cos(a*3.1415926/180);
	    pDC6->MoveTo(ox,oy);
	    pDC6->LineTo(x5,y5);
	    a=a-6;
	}


}
