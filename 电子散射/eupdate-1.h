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
void eupdate(vector<epos> &eline,substrate sub)
{
	
	epos temp=eline.back();
	transform(temp);

	//����ƽ��������ʧ
	double dEds=BetheFx(temp.E,sub);
	double energyremain=EnergyRemain(temp.E,dEds,temp.freelength);
	einitialize(temp,sub,energyremain);

	eline.push_back(temp);
}

//�߽紦��
void BoundryDeal(vector<epos> &eline, substrate Sub1, substrate Sub2)
{
	if(outofrange(eline.back(),Sub1))
	{
		//���ճ������
		epos temp = eline.back();
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
	    einitialize(EposOut,Sub2,energyremain);

	    eline.push_back(EposOut);
	}
	else ;
}

void horizontal(vector<epos>* eline,double Enum, substrate* Sub, double subnum, deposit* &result, QLineSeries* &lineseriesr)
{
	//���������
	double widthMax = Sub[0].width;
	for(int i = 1;i < subnum; i++)
		if(Sub[i].width > widthMax) widthMax = Sub[i].width;
	//nΪ����,��������
	double n = 1;
	widthMax = widthMax / n;
	result = new deposit[(int)widthMax];
	//��ʼ������
	for(int i = 0;i < (int)widthMax;i++)
	{
		result[i].r = i;
		result[i].energy = 0;
	}
	
	//�����ܺ�
	for(int i = 0; i<Enum;i++)
	{

		for(int j = 0;(unsigned)j<eline[i].size();j++)
		{
			double distance;
			distance = sqrt(eline[i][j].coordinate[0]*eline[i][j].coordinate[0] + eline[i][j].coordinate[1]*eline[i][j].coordinate[1]);
			result[(int)distance].energy += eline[i][j].E;
		}
	}

	//�����ֵ
	for(int i = 0; i<widthMax - 1; i++)
		result[i].deds = result[i].energy - result[i+1].energy;

	result[(int)widthMax - 1].deds = 0;
	//���
	for( int i=0;i < (int)widthMax;i++)
	{
		*lineseriesr << QPointF(result[i].r, result[i].deds);
	}
	delete[] result;
}