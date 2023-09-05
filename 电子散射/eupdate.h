#pragma once
#include<vector>
#include<cmath>
#include"formula.h"
using namespace std;

//��������仯
void transform(epos &e)
{
//����任
	int i,j;
	double lemda[3];
	for(i = 0; i<3; i++)
	    lemda[i] = e.Qn0[i][0]*e.freelength*sin(e.scatterangle)*cos(e.azimuth) + e.Qn0[i][1]*e.freelength*sin(e.scatterangle)*sin(e.azimuth) + e.Qn0[i][2]*e.freelength*cos(e.scatterangle);
	for(i = 0; i<3; i++)
		lemda[i] = e.Qn0[i][0]*lemda[0] + e.Qn0[i][1]*lemda[1] + e.Qn0[i][2]*lemda[2];
	for(i = 0; i<3; i++)
		e.coordinate[i] += lemda[i];

//����Qn0
	double Q[3][3];
	Q[0][0] = -sin(e.azimuth); Q[0][1] = -cos(e.azimuth) * cos(e.scatterangle); Q[0][2] = cos(e.azimuth) * sin(e.scatterangle);
	Q[1][0] = cos(e.azimuth) ; Q[1][1] = -sin(e.azimuth) * cos(e.scatterangle); Q[1][2] = sin(e.azimuth) * sin(e.scatterangle);
	Q[2][0] = 0        ;       Q[2][1] =            sin(e.scatterangle)     ;   Q[2][2] =           cos(e.scatterangle)     ;

	double tempQn[3][3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			tempQn[i][j]=e.Qn0[i][j];
		}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			e.Qn0[i][j] = tempQn[i][0]*Q[0][j]+ tempQn[i][1]*Q[1][j] + tempQn[i][2]*Q[2][j];
	}

}
//����eline
void eupdate(vector<epos> &eline,substrate &sub, epos &temp,int num)
{
    temp=eline.back();
	transform(temp);
	temp.flag=0;
	//����ƽ��������ʧ
	double dEds=BetheFx(temp.E,sub);
	double energyremain=EnergyRemain(temp.E,dEds,temp.freelength);
	einitialize(temp,sub,energyremain,num);

	eline.push_back(temp);
}

//�߽紦��
void BoundryDeal(vector<epos> &eline, substrate &Sub1, substrate &Sub2,epos &temp,int num)
{
		//���ճ������
		temp = eline.back();
		eline.pop_back();

		//���µ���ɢ�䵽�߽�ʱ����(���������)
		epos EposOut;
		EposOut = eline.back();
		//����ɢ�䵽�߽�·��
		EposOut.freelength = (Sub1.length-EposOut.coordinate[2])/(temp.coordinate[2]-EposOut.coordinate[2]) * EposOut.freelength;
		transform(EposOut);
		//����ɢ�䵽�߽�����
	    double dEds=BetheFx(EposOut.E,Sub1);
	    double energyremain=EnergyRemain(EposOut.E,dEds,EposOut.freelength);
		EposOut.E = energyremain;

		//�߽紦��ʽ
		double lemda1 = Sub1.A / N_A / Sub1.density / EposOut.crossection;
	    double beta = 5.43E-3 * pow(Sub2.Z, 2.0/3.0) / EposOut.E;
		double lemda2 = Sub2.A / N_A / Sub2.density / RutherfordFx(beta, EposOut.E,Sub2.Z);
		//���㴩Խ�߽��ɢ��·��
		EposOut.freelength *= (lemda2/lemda1);
		transform(EposOut);
		//����߽�ɢ�������
	    dEds=BetheFx(EposOut.E,Sub2);
	    energyremain=EnergyRemain(EposOut.E,dEds,EposOut.freelength);

		//��Խ���յ����
	    einitialize(EposOut,Sub2,energyremain,num);

	    eline.push_back(EposOut);

}
//void horizontal(vector<epos>*& eline, int& Enum, substrate*& Sub, int& subnum, deposit*& result, QLineSeries*& lineseriesr, double*& rxy)
//{
//	rxy[0] = 0;
//	rxy[1] = 0;
//	//���������
//	int i, j, k;
//	double widthMax = Sub[0].width, temp;
//	for (i = 1; i < subnum; i++)
//		if (Sub[i].width > widthMax) widthMax = Sub[i].width;
//	//nΪ����,��������
//	result = new deposit[(int)widthMax];
//
//	for (i = 0; i < (int)widthMax; i++)
//	{
//		result[i].r = i;
//		result[i].deds = 0;
//	}
//	i = 0;
//	for (j = 0; j < Enum; j++)
//	{
//		i = 0;
//		for (k = 1; (unsigned)k < eline[j].size() - 1; k++)
//		{
//			temp = sqrt(pow(eline[j][k].coordinate[0], 2) + pow(eline[j][k].coordinate[1], 2));
//			for (; i < (int)temp; i++) {
//				result[i].deds += (eline[j][k - 1].E - eline[j][k].E) / eline[j][k].freelength;
//				result[i].deds = result[i].deds / 2;
//			}
//			
//		}
//	}
//	//���
//	for (i = 0; i < widthMax; i++)
//	{
//		if (result[i].r > rxy[0])rxy[0] = result[i].r;
//		if (result[i].deds > rxy[1])rxy[1] = result[i].deds;
//		*lineseriesr << QPointF(result[i].r, result[i].deds);
//	}
//	delete[] result;
//}

//void horizontal(vector<epos>*& eline, int& Enum, substrate*& Sub, int& subnum, deposit*& result, QLineSeries*& lineseriesr, double*& rxy)
//{
//	rxy[0] = 0;
//	rxy[1] = 0;
//	//���������
//	int i, j, k;
//	double widthMax = Sub[0].width, sum;
//	for (i = 1; i < subnum; i++)
//		if (Sub[i].width > widthMax) widthMax = Sub[i].width;
//	//nΪ����,��������
//	result = new deposit[(int)widthMax];
//
//	for (i = 0; i < widthMax; i++)
//	{
//		sum = 0;
//		
//		result[i].r = i;
//		for (j = 0; j < Enum; j++)
//		{
//			if ((i * i) > (eline[j].back().coordinate[1] * eline[j].back().coordinate[1] + eline[j].back().coordinate[0] * eline[j].back().coordinate[0]))continue;
//			else
//			{
//				for (k = 0; (unsigned)k < eline[j].size(); k++)
//				{
//					if ((sqrt(pow(eline[j][k].coordinate[0], 2) + pow(eline[j][k].coordinate[1], 2)) < i + 1) && (sqrt(pow(eline[j][k].coordinate[0], 2) + pow(eline[j][k].coordinate[1], 2)) >= i))
//					{
//						sum += eline[j][k].E;
//						
//						break;
//					}
//				}
//			}
//		}
//		
//		result[i].energy = sum;
//		if (i > 0) {
//			result[i].deds = (result[i].energy - result[i - 1].energy);
//			if (result[i].deds > rxy[1])rxy[1] = result[i].deds;
//		}
//		if (result[i].r > rxy[0] )rxy[0] = result[i].r;
//	}
//	//���
//	for (i = 0; i < widthMax; i++)
//	{
//		*lineseriesr << QPointF(result[i].r, result[i].deds);
//	}
//	delete[] result;
//}