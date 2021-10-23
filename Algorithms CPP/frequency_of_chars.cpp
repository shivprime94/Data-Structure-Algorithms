#include<stdio.h>
#include<conio.h>
#include<string.h>
main()
{
	int ch,i,j,k,l,fc[50][2],flag;
	char line[50],fw[50][50];
	clrscr();
	do
	{
		printf("\n<1> Input a line");
		printf("\n<2> Number of characters");
		printf("\n<3> Number of words");
		printf("\n<4> Number of vowals");
		printf("\n<5> Frequency of characters");
		printf("\n<6> Frequency of words");
		printf("\n<7> Exit\n");
		do
		{
			printf("\n enter your choice ");
			scanf("%d",&ch);
		}while(ch>7 || ch<1);
		switch (ch)
		{
			case 1:		//input a line
				printf("\n Enter a line ");
				scanf("\n%[^\n]",line);
				break;
			case 2:		//number of characters
				j=0;
				for(i=0;i<strlen(line);++i)
				{
					if(line[i]>64 && line[i]<93)
						++j;
					else
						if(line[i]>96 && line[i]<123)
							++j;
				}
				printf("total number of characters are %d",j);
				break;
			case 3:		//number of words
				j=0;
				for(i=0;i<strlen(line);++i)
				{
					if(line[i]==' ' || line[i]=='\t')
						continue;
					else
					{
						for(k=i;k<strlen(line);++k)
						{
							if(line[k]==' ' || line[k]=='\t')
								break;
							else
								++i;
						}
					}
					++j;
				}
				printf("\n total number of words are %d",j);
				break;
			case 4:		//number of vowels
				j=0;
				for(i=0;i<strlen(line);++i)
				{
					if(line[i]=='a' || line[i]=='e' || line[i]=='i' || line[i]=='o' || line[i]=='u')
						++j;
					else
						if(line[i]=='A' || line[i]=='E' || line[i]=='I' || line[i]=='O' || line[i]=='U')
							++j;
				}
				printf("total number of vowels are %d",j);
				break;
			case 5:		//frequency of characters
				for(i=0;i<strlen(line);++i)
				{
					fc[i][1]=0;
					flag=0;
					for(j=0;j<strlen(line);++j)
					{
						if(line[i]==fc[j][0])
						{
							fc[j][0]=line[i];
							++fc[j][1];
							flag=1;
							break;
						}
					}
					if(flag==0)
						fc[i][0]=line[i],fc[i][1]=1;
				}
				printf("\n Frequency of each characters");
				for(i=0;i<strlen(line);++i)
					if(fc[i][1]!=0)
						printf("\n%c %d",fc[i][0],fc[i][1]);
				break;
			case 6:		//frequency of words
				j=0;
				for(i=0;i<strlen(line);++i)
				{
					if(line[i]==' ' || line[i]=='\t')
						continue;
					else
					{
						l=0;
						for(k=i;k<strlen(line);++k)
						{
							if(line[k]==' ' || line[k]=='\t')
								break;
							else
							{
								fw[j][l]=line[k],fw[j][++l]='\0';
								++i;
							}
						}
					}
					++j;
				}
				for(i=0;i<j;++i)
				{
					fc[0][0]=0;
					for(k=i;k<j;++k)
					{
						flag=1;
						for(l=0;l<j;++l)
							if(fw[i][l]!=fw[k][l])
								flag=0;
						if(flag==1)
						{
							++fc[0][0];
							if(fc[0][0]>1)
								fw[k][0]='\0';
						}
					}
					if(fc[0][0]>0)
					{
						flag=0;
						do
						{
							printf("%c",fw[i][flag]);
						} while(fw[i][flag++]!='\0');
						if(fw[i][0]!='\0')
							printf("%d\n",fc[0][0]);
					}
					fc[0][0]=0;
				}
				break;
		}
	}while(ch!=7);
	printf("\n\n i will wait for your mails ");
	getch();
	return ;
}
