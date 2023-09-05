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

	cout<<"本次模拟__个电子轨迹："<<endl;
	cin>>N;
	eline=new vector<epos>[N];


	//初始化材料
	cout<<"模拟__层材料："<<endl;
	cin>>NS;
	Subtest1=new substrate[NS];
	for(i=0;i<NS;i++)
	{
		cout<<"初始化第"<<i+1<<"层介质："<<endl;
		cout<<"输入介质材料序号："<<endl;
		cin>>num;
		Subtest1[i].type=num;
		switch(Subtest1[i].type)
		{
			//PMMA
		case 0:
			{
			cout<<"请输入材料宽度（nm），厚度（nm），密度（g/nm^3）："<<endl;
			cin>>w>>l>>d;
		
			cout<<"请输入光刻胶CHO原子个数"<<endl;
			cin>>c>>h>>o;
			subinitialize(Subtest1[i],num,w,l,d,c,h,o);
			break;
			}
			//Si
		case 1:
			{
				cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
				cin>>w>>l;

				subinitialize(w,l,2.33e-21,28,14,0.822,172.25,Subtest1[i]);
				break;
			}
			//Al
		case 2:
			{
				cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
				cin>>w>>l;

				subinitialize(w,l,2.7e-21,27,13,0.815,163,Subtest1[i]);
				break;
			}
		
			//Ni
		case 3:
			{
				cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
				cin>>w>>l;
				subinitialize(w,l,8.9e-21,58.69,28,0.83,304.499,Subtest1[i]);
				break;
			}
			//Fe
		case 4:
			{
				cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
				cin>>w>>l;
				subinitialize(w,l,7.86e-21,56,26,0.83,285.422,Subtest1[i]);
				break;
			}
			//Cu
		case 5:
			{
				cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
				cin>>w>>l;
				subinitialize(w,l,8.96e-21,63.546,29,0.83,314.051,Subtest1[i]);
				break;
			}
			//Ag
		case 6:
			{
				cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
				cin>>w>>l;
				subinitialize(w,l,10.53e-21,108,47,0.852,487,Subtest1[i]);
				break;
			}
			//Au
		case 7:
			{
				cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
				cin>>w>>l;
				subinitialize(w,l,19.32e-21,197,79,0.851,796.675,Subtest1[i]);
				break;
			}
			//SiO2
		case 8:
			{
				cout<<"请输入材料宽度（nm），厚度（nm）"<<endl;
				cin>>w>>l;
				subinitialize(w,l,2.2e-21,20,10,0.82,115,Subtest1[i]);
			}
		default:break;
			}
		//显示材料
		Subtest1[i].display(Subtest1[i].type);
		
	}
	//初始化电子束
	cout<<"请输入电子束入射能量(kev)："<<endl;
	cin>>E;
	einitialize(EP,Subtest1[1],E);
	cout<<"请输入电子束半径："<<endl;
	cin>>R;
	
	for(i=0;i<N;i++)
	{
		cout<<"第"<<i<<"个电子轨迹："<<endl;
	//初始化电子入射位置
		XYinitialize(EP,R);
		EP.display();

	//更新，直到电子能量降到50ev,测试先用1kev
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