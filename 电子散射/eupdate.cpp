#include <iostream>
#include<vector>
#include"eupdate.h"


using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	substrate *Subtest1;
	epos EP;
	vector<epos> *eline;

	double w,l,d,E,R;
	int c,h,o,i,j,N,NS;
	int num;

	cout<<"����ģ��__�����ӹ켣��"<<endl;
	cin>>N;
	eline=new vector<epos>[N];


	//��ʼ������
	cout<<"ģ��__����ϣ�"<<endl;
	cin>>NS;
	Subtest1=new substrate[NS];
	for(i=0;i<NS;i++)
	{
		cout<<"��ʼ����"<<i+1<<"����ʣ�"<<endl;
		cout<<"������ʲ�����ţ�"<<endl;
		cin>>num;
		Subtest1[i].type=num;
		switch(Subtest1[i].type)
		{
			//PMMA
		case 0:
			{
			cout<<"��������Ͽ�ȣ�nm������ȣ�nm�����ܶȣ�g/nm^3����"<<endl;
			cin>>w>>l>>d;
		
			cout<<"�������̽�CHOԭ�Ӹ���"<<endl;
			cin>>c>>h>>o;
			subinitialize(Subtest1[i],num,w,l,d,c,h,o);
			break;
			}
			//Si
		case 1:
			{
				cout<<"��������Ͽ�ȣ�nm������ȣ�nm��"<<endl;
				cin>>w>>l;

				subinitialize(w,l,2.33e-21,28,14,0.822,172.25,Subtest1[i]);
				break;
			}
			//Al
		case 2:
			{
				cout<<"��������Ͽ�ȣ�nm������ȣ�nm��"<<endl;
				cin>>w>>l;

				subinitialize(w,l,2.7e-21,27,13,0.815,163,Subtest1[i]);
				break;
			}
		
			//Ni
		case 3:
			{
				cout<<"��������Ͽ�ȣ�nm������ȣ�nm��"<<endl;
				cin>>w>>l;
				subinitialize(w,l,8.9e-21,58.69,28,0.83,304.499,Subtest1[i]);
				break;
			}
			//Fe
		case 4:
			{
				cout<<"��������Ͽ�ȣ�nm������ȣ�nm��"<<endl;
				cin>>w>>l;
				subinitialize(w,l,7.86e-21,56,26,0.83,285.422,Subtest1[i]);
				break;
			}
			//Cu
		case 5:
			{
				cout<<"��������Ͽ�ȣ�nm������ȣ�nm��"<<endl;
				cin>>w>>l;
				subinitialize(w,l,8.96e-21,63.546,29,0.83,314.051,Subtest1[i]);
				break;
			}
			//Ag
		case 6:
			{
				cout<<"��������Ͽ�ȣ�nm������ȣ�nm��"<<endl;
				cin>>w>>l;
				subinitialize(w,l,10.53e-21,108,47,0.852,487,Subtest1[i]);
				break;
			}
			//Au
		case 7:
			{
				cout<<"��������Ͽ�ȣ�nm������ȣ�nm��"<<endl;
				cin>>w>>l;
				subinitialize(w,l,19.32e-21,197,79,0.851,796.675,Subtest1[i]);
				break;
			}
			//SiO2
		case 8:
			{
				cout<<"��������Ͽ�ȣ�nm������ȣ�nm��"<<endl;
				cin>>w>>l;
				subinitialize(w,l,2.2e-21,20,10,0.82,115,Subtest1[i]);
			}
		default:break;
			}
		//��ʾ����
		Subtest1[i].display(Subtest1[i].type);
		
	}
	//��ʼ��������
	cout<<"�������������������(kev)��"<<endl;
	cin>>E;
	einitialize(EP,Subtest1[1],E);
	cout<<"������������뾶��"<<endl;
	cin>>R;
	
	for(i=0;i<N;i++)
	{
		cout<<"��"<<i<<"�����ӹ켣��"<<endl;
	//��ʼ����������λ��
		XYinitialize(EP,R);
		EP.display();

	//���£�ֱ��������������50ev,��������1kev
		eline[i].push_back(EP);
		for(j=1;j<=NS;j++)
		{
			while((eline[i].back().E>0.05)&&!outofrange(eline[i].back(),Subtest1[j]))
			{
			eupdate(eline[i],Subtest1[j]);
			eline[i].back().display();
			}
			if((eline[i].back().flag==1)&&(j<NS))
				BoundryDeal(eline[i],Subtest1[j],Subtest1[j+1]);
		}
	}

	delete[] eline;
	delete[] Subtest1;
	return 0;
}