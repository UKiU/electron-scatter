#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#define N_A 6.02E23              //����٤���޳���
#define PI 3.1415926    //Բ����
using namespace std;

//����0-1֮���һ�������
double rand01()
{
	return rand()/double(RAND_MAX);
}


//���ײ����ࣨ��̽���
class substrate
{
public:
	double width,length,density;//���Ͽ�ȣ���ȣ��ܶ�
	int C,H,O;//̼��������Ԫ��ԭ�Ӹ���
	double A, Z;//ԭ������ԭ������(ȡƽ��ֵ)
	double J,k; //ƽ�������ܣ�����ϵ��k
	int type;//��Ӧ��ͬ����
	void display(int n)
	{
		if(n==0)
		{
		cout<<"___________________________________"<<endl;
		cout<<"������ţ�"<<type<<endl;
		cout<<"��ȣ���ȣ�"<<width<<" nm "<<length<<" nm "<<endl;
		cout<<"�ܶȣ�"<<density<<" g/nm^3"<<endl;
		cout<<"����ʽ�� C"<<C<<"H"<<H<<"O"<<O<<endl;
		cout<<"ƽ��ԭ������"<<A<<" ƽ��ԭ�������� "<<Z<<endl;
		cout<<"ƽ�������ܣ�"<<J<<endl;
		cout<<"___________________________________"<<endl;
		}
		else
		{
		cout<<"___________________________________"<<endl;
		cout<<"������ţ�"<<type<<endl;
		cout<<"��ȣ���ȣ�"<<width<<" nm "<<length<<" nm "<<endl;
		cout<<"�ܶȣ�"<<density<<" g/nm^3"<<endl;
		cout<<"ƽ��ԭ������"<<A<<" ƽ��ԭ�������� "<<Z<<endl;
		cout<<"ƽ�������ܣ�"<<J<<endl;
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


//����λ����
class epos
{
	
public:
	double E,crossection;//����,���Խ���
	double beta;//ԭ�����β���
	double freelength;//ɢ�����ɳ�
	double coordinate[3];//����λ������
	double scatterangle;//ɢ���
	double azimuth;//��λ��
	double Qn0[3][3];
	bool flag;//Ĭ��Ϊ0��ʾ������Ϊ1��ʾ��Ҫ���⴦��

	void display()
	{
		
		cout<<"����������"<<E<<"kev"<<endl;
		//cout<<"ԭ�����β�����"<<beta<<endl;
		cout<<"ɢ�����ɳ̣�"<<freelength<<endl;
		cout<<"ɢ����棺"<<crossection<<endl;
		cout<<"���꣺("<<coordinate[0]<<","<<coordinate[1]<<","<<coordinate[2]<<")"<<endl;
		cout<<"ɢ��ǣ�"<<scatterangle<<endl;
		cout<<"��λ�ǣ�"<<azimuth<<endl;
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

		//��ʼ���涯����
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				if(i==j)Qn0[i][j]=1;
				else Qn0[i][j]=0;
			}
	}

};



//ɢ�����ɳ�
double ScatterFR(double A, double St, double D){
	double average, result;
	average = A / N_A / D / St;
	double temp;
	temp=rand01();
	result = -1.0 * average * log(temp);
	return result;
}//������Ϊnm
//��λ��
double Azimuth(){
	double result;
	double temp=rand01();
	result = temp * 2 * PI;
	return result;
}
//����bethe��ʽ����ƽ��������ʧ��
double BetheFx(double E, substrate &Sub)
{
	double result, temp;
	temp = log (( 1.166 * (E + Sub.k*Sub.J*1e-3))/(Sub.J*1e-3)  ) ;
	result = 7.85E4 * Sub.density * 1e21*Sub.Z / Sub.A / E * temp;
	return result;
}//���ΪKev/cm

//ɢ���ʣ������
double EnergyRemain(double E, double dEds, double FRn){
	double result;
	result = E - (dEds * FRn*1e-7);
	return result;
}
//���ܵ���Rutherford��ʽ����ɢ�����
double RutherfordFx(double beta, double E, double Z)
{
	double result;
	result = (PI*pow(1.44,2)*Z*(Z+1)*(1e-6))/(4 * E * E * beta * (beta + 1));//������Ϊnm^2
	return result;
}

//��ɢ���
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
		cout<<"������ֵΪ��"<<result<<endl;
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
double scatterang(double Z,double E,int num)
{
	int i;
	double step=PI/100000,R,division,alfa=0;
	R=rand01();
	if(num==0)
	{
		
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
	if(num==1)
	{
		alfa=3.4e-3*pow(Z,0.67)/E;
		division=1-2*alfa*R*R/(1+alfa-R);
		return(acos(division));
	}
}





 //��ʼ�����ײ��ϣ���̽���
void subinitialize(substrate &Sub,int nn, double Width, double Length, double Density, int Cnum, int Hnum, int Onum)      
{
	Sub.type=nn;

	//��ȡ����ȡ��ܶ�
	Sub.width = Width;
	Sub.length = Length;
	Sub.density = Density;

	//C��H��Oԭ�Ӹ���
	Sub.C = Cnum;
	Sub.H = Hnum;
	Sub.O = Onum;

	//ƽ��ԭ����
	double Ac = 12, Ah = 1, Ao = 16;
	double M=(Ac*Cnum)+(Ah*Hnum)+(Ao*Onum);
	double Cc=Ac*Cnum/M,Ch=Hnum/M,Co=Ao*Onum/M;
	double down = (Cc / Ac) + (Ch / Ah) + (Co / Ao);
	Sub.A = 1.0 / down;

	//ƽ��ԭ������
	double Zc = 6, Zh = 1, Zo = 8;
	double up = (Cc * Zc / Ac) + (Ch * Zh / Ah) + (Co * Zo / Ao);
	Sub.Z = up / down;

	//���ƽ��������(��λev)
	double Jc = 78, Jh = 18.7, Jo = 89;
	double upp = (Cc * Zc / Ac) * log(Jc) + (Ch * Zh / Ah) * log(Jh) + (Co * Zo / Ao) * log(Jo);
	Sub.J = exp(upp / up);

	//�������ϵ��k
	double KAl = 0.815, Kc = 0.77, ZAl = 13;
	Sub.k = Kc - ((KAl - Kc) * (Zc - Sub.Z)) / (ZAl - Zc);
}

//���غ����������趨���ֳĵ�
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
//��ʼ������
void einitialize(epos &Epos, substrate &Sub, double Enegry,int num)          
{
	//����
	Epos.E = Enegry;

	//ԭ�����β���
	Epos.beta = 5.43E-3 * pow(Sub.Z, 2.0/3.0) / Enegry;

	//ɢ�����
	Epos.crossection = RutherfordFx(Epos.beta, Enegry, Sub.Z);

	//ɢ�����ɳ�
	Epos.freelength = ScatterFR(Sub.A, Epos.crossection, Sub.density);

	//ɢ���
	Epos.scatterangle=scatterang(Sub.Z,Enegry,num);

	//��λ��
	Epos.azimuth=Azimuth();
}
//��ʼ��������
void XYinitialize(epos &Epos, double R)
{
	double R1 = rand01();
	double R2 = rand01();
	double temp = pow(-log(R1),0.5);
	Epos.coordinate[0] = R * temp * cos(2 * PI * R2);
	Epos.coordinate[1]= R * temp * sin(2 * PI * R2);
	Epos.coordinate[2]=0;
}
//��λΪnm

//�жϳ��纯��
bool outofrange(epos &Epos,substrate &sub)
{
	Epos.flag=0;
	if(Epos.coordinate[2]>sub.length)Epos.flag=1;//������¶˳��������⴦��
	if((Epos.coordinate[0]*Epos.coordinate[0]+Epos.coordinate[1]*Epos.coordinate[1]>sub.width*sub.width)||(fabs(Epos.coordinate[2])>sub.length))return 1;
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
//
//void vertical(vector<epos>*& eline, int& N, substrate*& sub, int& subN, deposit*& chart, QLineSeries*& lineseriesz, double*& zxy)
//{
//	zxy[0] = 0;
//	zxy[1] = 0;
//	int i, j, k;
//	double length = 0, temp;
//	length = sub[subN - 1].length;
//	chart = new deposit[(int)length];
//	for (i = 0; i < (int)length; i++)
//	{
//		chart[i].z = i;
//		chart[i].deds = 0;
//	}
//	i = 0;
//	for (j = 0; j < N; j++)
//	{
//		i = 0;
//		for (k = 1; (unsigned)k < eline[j].size() - 1; k++)
//		{
//			temp = eline[j][k].coordinate[2];
//			for (; i < (int)temp; i++) {
//				chart[i].deds += (eline[j][k - 1].E - eline[j][k].E) / eline[j][k].freelength;
//				chart[i].deds = chart[i].deds / 2;
//			}
//		}
//	}
//
//	//���
//	for (i = 0; i < length; i++)
//	{	
//		if (chart[i].z > zxy[0])zxy[0] = chart[i].z;
//		if (chart[i].deds > zxy[1])zxy[1] = chart[i].deds;
//		*lineseriesz << QPointF(chart[i].z, chart[i].deds);
//	}
//	delete[] chart;
//}

void vertical(vector<epos>*& eline, int& N, substrate*& sub, int& subN, deposit*& chart, QLineSeries*& lineseriesz, double*& zxy)
{
	zxy[0] = 0;
	zxy[1] = 0;
	int i, j, k;
	double length = 0, sum;
	length = sub[subN - 1].length;
	chart = new deposit[(int)length];
	for (i = 0; i < length; i++)
	{
		sum = 0;
		chart[i].z = i;
		for (j = 0; j < N; j++)
		{
			if (i > eline[j].back().coordinate[2])continue;
			else
			{
				for (k = 1; k < eline[j].size(); k++)
				{
					if ((eline[j][k].coordinate[2] < i + 1) && (eline[j][k].coordinate[2] >= i))
					{
						sum += eline[j][k].E;
						break;
					}
				}
			}
		}
		chart[i].energy = sum;

	}
	//���
	for (i = 0; i < length; i++)
	{
		if (chart[i].z > zxy[0])zxy[0] = chart[i].z;
		if (chart[i].energy > zxy[1])zxy[1] = chart[i].energy;
		*lineseriesz << QPointF(chart[i].z, chart[i].energy);
	}
	delete[] chart;
}

void horizontal(vector<epos>*& eline, int& Enum, substrate*& Sub, int& subnum, deposit*& result, QLineSeries*& lineseriesr, double*& rxy)
{
	rxy[0] = 0;
	rxy[1] = 0;
	//���������
	int i, j, k;
	double widthMax = Sub[0].width, sum;
	for (i = 1; i < subnum; i++)
		if (Sub[i].width > widthMax) widthMax = Sub[i].width;
	//nΪ����,��������
	result = new deposit[(int)widthMax];

	for (i = 0; i < widthMax; i++)
	{
		sum = 0;
		result[i].r = i;
		for (j = 0; j < Enum; j++)
		{
			if ((i * i) > (eline[j].back().coordinate[1] * eline[j].back().coordinate[1] + eline[j].back().coordinate[0] * eline[j].back().coordinate[0]))continue;
			else
			{
				for (k = 1; k < eline[j].size(); k++)
				{
					if ((sqrt(pow(eline[j][k].coordinate[0], 2) + pow(eline[j][k].coordinate[1], 2)) < i + 1) && (sqrt(pow(eline[j][k].coordinate[0], 2) + pow(eline[j][k].coordinate[1], 2)) >= i))
					{
						sum += eline[j][k].E;
						break;
					}
				}
			}
		}

		result[i].energy = sum;
	}
	//���
	for (i = 0; i < widthMax; i++)
	{
		if (result[i].r > rxy[0])rxy[0] = result[i].r;
		if (result[i].energy > rxy[1])rxy[1] = result[i].energy;
		*lineseriesr << QPointF(result[i].r, result[i].energy);
	}
	delete[] result;
}


//void vertical(vector<epos>*& eline, int& N, substrate*& sub, int& subN, deposit*& chart, QLineSeries*& lineseriesz, double*& zxy)
//{
//	zxy[0] = 0;
//	zxy[1] = 0;
//	int j, k;
//	double i, length = 0, sum, jd;
//	length = sub[subN - 1].length;
//	jd = length / 100.0;
//	chart = new deposit[100];
//	for (i = 0; i < length; i += jd)
//	{
//		sum = 0;
//		chart[int(i / jd)].z = int(i / jd) * jd;
//		for (j = 0; j < N; j++)
//		{
//			if (i > eline[j].back().coordinate[2])continue;
//			else
//			{
//				for (k = 1; k < eline[j].size(); k++)
//				{
//					if ((eline[j][k].coordinate[2] < i + jd) && (eline[j][k].coordinate[2] >= i))
//					{
//						sum += eline[j][k].E;
//						break;
//					}
//				}
//			}
//		}
//		chart[int(i / jd)].energy = sum;
//		if (i / jd > 0)chart[int(i / jd)].deds = (chart[int(i / jd)].energy - chart[int(i / jd) - 1].energy) / jd;
//	}
//	//���
//	for (i = 0; i < length; i += jd)
//	{
//		if (chart[(int)(i/jd)].z > zxy[0])zxy[0] = chart[(int)(i / jd)].z;
//		if (chart[(int)(i / jd)].deds > zxy[1])zxy[1] = chart[(int)(i / jd)].deds;
//		*lineseriesz << QPointF(chart[(int)(i / jd)].z, chart[(int)(i / jd)].deds);
//	}
//	delete[] chart;
//}
//void horizontal(vector<epos>*& eline, int& Enum, substrate*& Sub, int& subnum, deposit*& result, QLineSeries*& lineseriesr, double*& rxy)
//{
//	rxy[0] = 0;
//	rxy[1] = 0;
//
//	//���������
//	int j, k;
//	double widthMax = Sub[0].width, sum, i, jd;
//	for (j = 1; j < subnum; j++)
//		if (Sub[j].width > widthMax) widthMax = Sub[j].width;
//	//nΪ����,��������
//	jd = widthMax / 100.0;
//	result = new deposit[100];
//
//	for (i = 0; i < widthMax; i += jd)
//	{
//		sum = 0;
//		result[int(i / jd)].r = int(i / jd) * jd;
//		for (j = 0; j < Enum; j++)
//		{
//			if ((i * i) > (eline[j].back().coordinate[1] * eline[j].back().coordinate[1] + eline[j].back().coordinate[0] * eline[j].back().coordinate[0]))continue;
//			else
//			{
//				for (k = 1; k < eline[j].size(); k++)
//				{
//					if ((sqrt(pow(eline[j][k].coordinate[0], 2) + pow(eline[j][k].coordinate[1], 2)) < i + jd) && (sqrt(pow(eline[j][k].coordinate[0], 2) + pow(eline[j][k].coordinate[1], 2)) >= i))
//					{
//						sum += eline[j][k].E;
//						break;
//					}
//				}
//			}
//		}
//
//		result[int(i / jd)].energy = sum;
//		if (i > 0)
//			result[int(i / jd)].deds = (result[int(i / jd)].energy - result[int(i / jd) - 1].energy);
//	}
//	//���
//	for (i = 0; i < widthMax; i += jd)
//	{
//		if (result[(int)(i/jd)].r > rxy[0])rxy[0] = result[(int)(i / jd)].z;
//		if (result[(int)(i / jd)].deds > rxy[1])rxy[1] = result[(int)(i / jd)].deds;
//		*lineseriesr << QPointF(result[(int)(i / jd)].r, result[(int)(i / jd)].deds);
//	}
//	delete[] result;
//}

//void vertical(vector<epos>*& eline, int& N, substrate*& sub, int& subN, deposit*& chart, QLineSeries*& lineseriesz, double*& zxy)
//{
//	zxy[0] = 0;
//	zxy[1] = 0;	
//	int i, j, k,nn=0;
//	double length = 0, sum;
//	length = sub[subN - 1].length;
//	chart = new deposit[(int)length];
//	for (i = 0; i < length; i++)
//	{
//		nn = 0;
//		sum = 0;
//		chart[i].z = i;
//		for (j = 0; j < N; j++)
//		{
//			if (i > eline[j].back().coordinate[2])continue;
//			else
//			{
//				for (k = 1; k < eline[j].size(); k++)
//				{
//					if ((eline[j][k].coordinate[2] < i + 1) && (eline[j][k].coordinate[2] >= i))
//					{
//						sum += eline[j][k].E;
//						nn++;
//						break;
//					}
//				}
//			}
//		}
//		if (nn = 0)chart[i].energy = 0;
//		else chart[i].energy = sum/(nn*1.0);
//		if (i > 0)chart[i].deds = (chart[i].energy - chart[i - 1].energy);
//	}
//	//���
//	for (i = 0; i < length; i++)
//	{
//		if (chart[i].z > zxy[0])zxy[0] = chart[i].z;
//		if (chart[i].deds > zxy[1])zxy[1] = chart[i].deds;
//
//		*lineseriesz << QPointF(chart[i].z, chart[i].deds);
//	}
//	delete[] chart;
//}
//void horizontal(vector<epos>*& eline, int& Enum, substrate*& Sub, int& subnum, deposit*& result, QLineSeries*& lineseriesr, double*& rxy)
//{
//	rxy[0] = 0;
//	rxy[1] = 0;
//	//���������
//	int i, j, k,nn;
//	double widthMax = Sub[0].width, sum;
//	for (i = 1; i < subnum; i++)
//		if (Sub[i].width > widthMax) widthMax = Sub[i].width;
//	//nΪ����,��������
//	result = new deposit[(int)widthMax];
//
//	for (i = 0; i < widthMax; i++)
//	{
//		sum = 0;
//		nn = 0;
//		result[i].r = i;
//		for (j = 0; j < Enum; j++)
//		{
//			if ((i * i) > (eline[j].back().coordinate[1] * eline[j].back().coordinate[1] + eline[j].back().coordinate[0] * eline[j].back().coordinate[0]))continue;
//			else
//			{
//				for (k = 1; k < eline[j].size(); k++)
//				{
//					if ((sqrt(pow(eline[j][k].coordinate[0], 2) + pow(eline[j][k].coordinate[1], 2)) < i + 1) && (sqrt(pow(eline[j][k].coordinate[0], 2) + pow(eline[j][k].coordinate[1], 2)) >= i))
//					{
//						sum += eline[j][k].E;
//						nn++;
//						break;
//					}
//				}
//			}
//		}
//
//		if (nn = 0) result[i].energy = 0;
//			else result[i].energy = sum/(nn*1.0);
//		if (i > 0)
//			result[i].deds = (result[i].energy - result[i - 1].energy);
//	}
//	//���
//	for (i = 0; i < widthMax; i++)
//	{
//		if (result[i].r > rxy[0])rxy[0] = result[i].z;
//		if (result[i].deds > rxy[1])rxy[1] = result[i].deds;
//		*lineseriesr << QPointF(result[i].r, result[i].deds);
//	}
//	delete[] result;
//}
//void vertical(vector<epos> *&eline,int &N,substrate *&sub,int &subN,deposit* &chart, QLineSeries*& lineseriesz, double*& zxy)
//{
//	zxy[0] = 0;
//	zxy[1] = 0;
//	int i,j,k;
//	double length=0,sum;
//	length=sub[subN-1].length;
//	chart = new deposit[(int)length];
//	for(i=0;i<length;i++)
//	{
//		sum=0;
//		chart[i].z=i;
//		for(j=0;j<N;j++)
//		{
//			if(i>eline[j].back().coordinate[2])continue;
//			else
//			{
//				for(k=0;(unsigned)k<eline[j].size();k++)
//				{
//					if((eline[j][k].coordinate[2]<i+1)&&(eline[j][k].coordinate[2]>=i))
//					{
//						sum+=eline[j][k].E;
//						break;
//					}
//				}
//			}
//		}
//		chart[i].energy=sum;
//		if (i > 0) {
//			chart[i].deds = (chart[i].energy - chart[i - 1].energy);
//			if (chart[i].deds > zxy[1])zxy[1] = chart[i].deds;
//		}
//	}
//	for (i = 0; i < length; i++) {
//		if (chart[i].z > zxy[0])zxy[0] = chart[i].z;
//	}
//	//���
//	for(i=0;i<length;i++)
//	{
//		*lineseriesz << QPointF(chart[i].z, chart[i].deds);
//	}
//	delete[] chart;
//}

//vector����
void ClearVector(vector<epos>& vt)
{
	vector<epos> vtTemp;
	vtTemp.swap(vt);
}

int avescatter(vector<epos>* &eline,int Enum)
{
	int i, sum=0;
	for(i=0;i<Enum;i++)
	{
		sum+=eline[i].size();
	}
	return sum/Enum;
}

int avedepth(vector<epos>* &eline,int Enum)
{
	int i;double sum=0;
	for(i=0;i<Enum;i++)
	{
		sum+=eline[i].back().coordinate[2];
	}
	return sum/(Enum*1.0);
}

