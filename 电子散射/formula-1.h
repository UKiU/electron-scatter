#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <QtCharts>

#define N_A 6.02E23              //阿伏伽德罗常数
#define PI acos((double)-1)    //圆周率
using namespace std;
using namespace QtCharts;

//生成0-1之间的一个随机数
double rand01()
{
	int temp = rand();
	double result = double(temp%100000)/100000.0;
	return result;
}


//基底材料类（光刻胶）
class substrate
{
	friend class epos;
public:
	double width,length,density;//材料宽度，厚度，密度
	int C,H,O;//碳氢氧三种元素原子个数
	double A, Z;//原子量、原子序数(取平均值)
	double J,k; //平均电离能，修正系数k
	int type;//对应不同材料
	void display(int n)
	{
		if(n==0)
		{
		cout<<"___________________________________"<<endl;
		cout<<"材料序号："<<type<<endl;
		cout<<"宽度，厚度："<<width<<" nm "<<length<<" nm "<<endl;
		cout<<"密度："<<density<<" g/nm^3"<<endl;
		cout<<"分子式： C"<<C<<"H"<<H<<"O"<<O<<endl;
		cout<<"平均原子量："<<A<<" 平均原子序数： "<<Z<<endl;
		cout<<"平均电离能："<<J<<endl;
		cout<<"___________________________________"<<endl;
		}
		else
		{
		cout<<"___________________________________"<<endl;
		cout<<"材料序号："<<type<<endl;
		cout<<"宽度，厚度："<<width<<" nm "<<length<<" nm "<<endl;
		cout<<"密度："<<density<<" g/nm^3"<<endl;
		cout<<"平均原子量："<<A<<" 平均原子序数： "<<Z<<endl;
		cout<<"平均电离能："<<J<<endl;
		cout<<"___________________________________"<<endl;
		}
	}
	substrate()
	{
		width=0;length=0;density=0;
		C=0;H=0;O=0;
		A=0;Z=0;
		J=0;k=0;
		type=-1;
	}
};


//电子位置类
class epos
{
	
public:
	double E,crossection;//能量,弹性截面
	double beta;//原子屏蔽参量
	double freelength;//散射自由程
	double coordinate[3];//电子位置坐标
	double scatterangle;//散射角
	double azimuth;//方位角
	double Qn0[3][3];
	bool flag;//默认为0表示正常，为1表示需要特殊处理

	void display()
	{
		
		cout<<"电子能量："<<E<<"kev"<<endl;
		//cout<<"原子屏蔽参量："<<beta<<endl;
		cout<<"散射自由程："<<freelength<<endl;
		cout<<"散射截面："<<crossection<<endl;
		cout<<"坐标：("<<coordinate[0]<<","<<coordinate[1]<<","<<coordinate[2]<<")"<<endl;
		cout<<"散射角："<<scatterangle<<endl;
		cout<<"方位角："<<azimuth<<endl;
		cout<<endl;
	}

	epos()
	{
		E=0;
		crossection=0;
		beta=0;
		freelength=0;
		coordinate[0]=0;
		coordinate[1]=0;
		coordinate[2]=0;
		scatterangle=0;
		azimuth=0;
		flag=0;

		//初始化随动矩阵
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				if(i==j)Qn0[i][j]=1;
				else Qn0[i][j]=0;
			}
	}

};



//散射自由程
double ScatterFR(double A, double St, double D){
	double average, result;
	average = A / N_A / D / St;
	double temp;
	temp=rand01();
	result = -1.0 * average * log(temp);
	return result;
}//计算结果为nm
//方位角
double Azimuth(){
	double result;
	double temp=rand01();
	result = temp * 2 * PI;
	return result;
}
//修正bethe公式计算平均能量损失率
double BetheFx(double E, substrate Sub)
{
	double result, temp;
	temp = log (( 1.166 * E + Sub.k*Sub.J*1e-3)/(Sub.J*1e-3)  ) ;
	result = 7.85E4 * Sub.density * 1e21*Sub.Z / Sub.A / E * temp;
	return result;
}//结果为Kev/cm

//散射后剩余能量
double EnergyRemain(double E, double dEds, double FRn){
	double result;
	result = E - (dEds * FRn*1e-7);
	return result;
}
//高能电子Rutherford公式计算散射截面
double RutherfordFx(double beta, double E, double Z)
{
	double result;
	result = (PI*pow(1.44,2)*Z*(Z+1)*(1e-6))/(4 * E * E * beta * (beta + 1));//计算结果为nm^2
	return result;
}

//求散射角
class ftheta
{
public:
	double zz,ee;
	ftheta()
	{
		zz=0;
		ee=0;
	}
	ftheta(double Z,double E)
	{
		zz=Z;
		ee=E;
	}

	double fun(double t)
	{
		double result;
		result=(zz*(zz+1)*1.44*1.44*sin(t)*1e-6)/(4*ee*ee*(1-cos(t)+2*(5.43e-3*pow(zz,0.667)/ee))*(1-cos(t)+2*(5.43e-3*pow(zz,0.667)/ee)));
		return result;
	}
};
template<typename T>
class integer
{public:
	double a,b,step,result;
	int n;
	T cf;

	integer(double aa=0,double bb=0,int nn=100,double E=0,double Z=0)
	{
		result=0;
		a=aa;
		b=bb;
		n=nn;
		cf.ee=E;
		cf.zz=Z;
		integrate();
	}

	void integrate();
	void print()
	{
		cout<<"定积分值为："<<result<<endl;
	}
};
template<typename T>
void integer<T>::integrate()
{
	step=(b-a)/n;
	result=(cf.fun(a)+cf.fun(b))/2;
	for(int i=1;i<n;i++)
	{
		result+=cf.fun(a+i*step);
	}
	result*=step;
}
double scatterang(double Z,double E)
{
	int i;
	double step=PI/100000,R,division;
	R=rand01();
	integer<ftheta>
		integerdown(0.0,PI,100000,E,Z);
	integer<ftheta>
		integerup(0.0,0.0,100000,E,Z);

	for(i=1;i<integerup.n;i++)
	{
		integerup.result+=integerup.cf.fun(integerup.a+i*step)*step;
		division=integerup.result/integerdown.result;
		//cout<<division<<endl;
		if((fabs(division-R)/R)<0.0001||(division>R))
		break;
	}
	return(i*step);
}





 //初始化基底材料（光刻胶）
void subinitialize(substrate &Sub,int nn, double Width, double Length, double Density, int Cnum, int Hnum, int Onum)      
{
	Sub.type=nn;

	//宽度、长度、密度
	Sub.width = Width;
	Sub.length = Length;
	Sub.density = Density;

	//C、H、O原子个数
	Sub.C = Cnum;
	Sub.H = Hnum;
	Sub.O = Onum;

	//平均原子量
	double Ac = 12, Ah = 1, Ao = 16;
	double M=(Ac*Cnum)+(Ah*Hnum)+(Ao*Onum);
	double Cc=Ac*Cnum/M,Ch=Hnum/M,Co=Ao*Onum/M;
	double down = (Cc / Ac) + (Ch / Ah) + (Co / Ao);
	Sub.A = 1.0 / down;

	//平均原子序数
	double Zc = 6, Zh = 1, Zo = 8;
	double up = (Cc * Zc / Ac) + (Ch * Zh / Ah) + (Co * Zo / Ao);
	Sub.Z = up / down;

	//添加平均电离能(单位ev)
	double Jc = 78, Jh = 18.7, Jo = 89;
	double upp = (Cc * Zc / Ac) * log(Jc) + (Ch * Zh / Ah) * log(Jh) + (Co * Zo / Ao) * log(Jo);
	Sub.J = exp(upp / up);

	//添加修正系数k
	double KAl = 0.815, Kc = 0.77, ZAl = 13;
	Sub.k = Kc - ((KAl - Kc) * (Zc - Sub.Z)) / (ZAl - Zc);
}

//重载函数，用于设定各种衬底
void subinitialize(double Width,double Length,double Density,double aA,double zZ,double kK,double jJ,substrate &Sub)
{
	Sub.width = Width;
	Sub.length = Length;
	Sub.density = Density;

	Sub.A=aA;
	Sub.Z=zZ;
	Sub.k=kK;
	Sub.J=jJ;
}
//初始化电子
void einitialize(epos &Epos, substrate Sub, double Enegry)          
{
	//能量
	Epos.E = Enegry;

	//原子屏蔽参量
	Epos.beta = 5.43E-3 * pow(Sub.Z, 2.0/3.0) / Enegry;

	//散射截面
	Epos.crossection = RutherfordFx(Epos.beta, Enegry, Sub.Z);

	//散射自由程
	Epos.freelength = ScatterFR(Sub.A, Epos.crossection, Sub.density);

	//散射角
	Epos.scatterangle=scatterang(Sub.Z,Enegry);

	//方位角
	Epos.azimuth=Azimuth();
}
//初始电子坐标
void XYinitialize(epos &Epos, double R)
{
	double R1 = rand01();
	double R2 = rand01();
	double temp = sqrt(-1 * log(R1));
	Epos.coordinate[0] = R * temp * cos(2 * PI * R2);
	Epos.coordinate[1]= R * temp * sin(2 * PI * R2);
	Epos.coordinate[2]=0;
}
//单位为nm

//判断出界函数
bool outofrange(epos &Epos,substrate sub)
{
	Epos.flag=0;
	if(Epos.coordinate[2]>sub.length)Epos.flag=1;//如果是下端出界则特殊处理
	if((Epos.coordinate[0]>sub.width)||(fabs(Epos.coordinate[1])>sub.width)||(fabs(Epos.coordinate[2])>sub.length))return 1;
	else return 0;
}

class deposit
{
public:
	double z, r;
	double energy;
	double deds;
	deposit()
	{
		z=0;energy=0;deds=0;r=0;
	}
};
void vertical(vector<epos> *eline,int N,substrate *sub,int subN,deposit* &chart, QLineSeries* &lineseriesz)
{
	int i,j,k;
	double length=0,sum;
	for(i=0;i<subN;i++)
	{
		length+=sub[i].length;
	}
	chart = new deposit[(int)length];
	for(i=0;i<length;i++)
	{
		sum=0;
		chart[i].z=i;
		for(j=0;j<N;j++)
		{
			if(i>eline[j].back().coordinate[2])continue;
			else
			{
				for(k=0;(unsigned)k<eline[j].size();k++)
				{
					if((eline[j][k].coordinate[2]<i+1)&&(eline[j][k].coordinate[2]>=i))
					{
						sum+=eline[j][k].E;
						break;
					}
				}
			}
		}
		chart[i].energy=sum;
		if(i>0)chart[i].deds=(chart[i].energy-chart[i-1].energy);
	}

	//输出
	for(i=0;i<length;i++)
	{
		*lineseriesz << QPointF(chart[i].z, chart[i].deds);
	}
	delete[] chart;
}

//vector析构
void ClearVector(vector<epos>& vt)
{
	vector<epos> vtTemp;
	vtTemp.swap(vt);
}
