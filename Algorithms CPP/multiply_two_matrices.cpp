# include <iostream.h>
# include <stdlib.h>
# include <conio.h>



 class Matrix
 {
    private:
       float matrix_a[3][3];
       float matrix_b[3][3];
       float matrix_c[3][3];

    public:
       Matrix( );

       void get_matrix_a( );
       void get_matrix_b( );
       void multiply_matrices( );
       void show_result_Matrix( );
 };




 Matrix::Matrix( )
 {
    for(int i=0;i<3;i++)
    {
       for(int j=0;j<3;j++)
       {
	  matrix_a[i][j]=0;
	  matrix_b[i][j]=0;
	  matrix_c[i][j]=0;
       }
    }

    gotoxy(1,1);
    cout<<"*********************************************"<<endl;
    cout<<" * * * * * * * * * * * * * *  Matrix  Multiplication  * * * * ** * * * * * * *"<<endl;
    cout<<"********************************************"<<endl;

    gotoxy(1,25);
    cout<<"*****************************************************";
 }



 void Matrix::get_matrix_a( )
 {
    gotoxy(1,6);
    cout<<" Enter the values of the Matrix A row by row :
 "<<endl;

    cout<<"			 Ú               ¿"<<endl;
    cout<<"			 ³               ³"<<endl;
    cout<<"			 ³               ³"<<endl;
    cout<<"			 ³               ³"<<endl;
    cout<<"			 À               Ù"<<endl;

    gotoxy(18,10);
    cout<<" A  = "<<endl;

    int x=28;
    int y=9;

    for(int i=0;i<3;i++)
    {
       for(int j=0;j<3;j++)
       {
	  gotoxy(x,y);
	  cin>>matrix_a[i][j];

	  x+=5;
       }

       x=28;
       y++;
    }
 }




 void Matrix::get_matrix_b( )
 {
    gotoxy(1,15);
    cout<<" Enter the values of the Matrix B row by row :
 "<<endl;

    cout<<"			 Ú               ¿"<<endl;
    cout<<"			 ³               ³"<<endl;
    cout<<"			 ³               ³"<<endl;
    cout<<"			 ³               ³"<<endl;
    cout<<"			 À               Ù"<<endl;

    gotoxy(18,19);
    cout<<" B  = "<<endl;

    int x=28;
    int y=18;

    for(int i=0;i<3;i++)
    {
       for(int j=0;j<3;j++)
       {
	  gotoxy(x,y);
	  cin>>matrix_b[i][j];

	  x+=5;
       }

       x=28;
       y++;
    }
 }




 void Matrix::multiply_matrices( )
 {
    for(int i=0;i<3;i++)
    {
       for(int j=0;j<3;j++)
       {
	  float value=0;
	  float sum=0;

	  for(int k=0;k<3;k++)
	  {
	     value=matrix_a[j][k]*matrix_b[k][j];
	     sum+=value;
	  }

	  matrix_c[i][j]=sum;
       }
    }
 }



 void Matrix::show_result_Matrix( )
 {
    clrscr( );

    gotoxy(1,1);
    cout<<"*********************************************************"<<endl;
    cout<<" * * * * * * * * * * * * * *  Matrix  Multiplication  * * * * ** * * * * * * *"<<endl;
    cout<<"*************************************************************"<<endl;

    gotoxy(1,6);
    cout<<" The values of Matrix A and B are :"<<endl;

    cout<<"		 Ú               ¿  	            Ú               
¿"<<endl;
    cout<<"		 ³               ³   	            ³               
³"<<endl;
    cout<<"		 ³               ³   	            ³               
³"<<endl;
    cout<<"		 ³               ³  	            ³               
³"<<endl;
    cout<<"		 À               Ù 		    À               Ù"<<endl;

    gotoxy(45,9);
    cout<<" B  = "<<endl;

    gotoxy(10,9);
    cout<<" A  = "<<endl;

    gotoxy(1,15);
    cout<<" The Product of Matrix A and B is :
 "<<endl;

    cout<<"			 Ú               ¿"<<endl;
    cout<<"			 ³               ³"<<endl;
    cout<<"			 ³               ³"<<endl;
    cout<<"			 ³               ³"<<endl;
    cout<<"			 À               Ù"<<endl;

    gotoxy(13,19);
    cout<<" A * B  = "<<endl;

    int x_1=20;
    int y_1=8;

    int x_2=55;
    int y_2=8;

    int x_3=28;
    int y_3=18;

    for(int i=0;i<3;i++)
    {
       for(int j=0;j<3;j++)
       {
	  gotoxy(x_1,y_1);
	  cout<<matrix_a[i][j];

	  gotoxy(x_2,y_2);
	  cout<<matrix_b[i][j];

	  gotoxy(x_3,y_3);
	  cout<<matrix_c[i][j];

	  x_1+=5;
	  x_2+=5;
	  x_3+=5;
       }

       x_1=20;
       y_1++;

       x_2=55;
       y_2++;

       x_3=28;
       y_3++;
    }

    gotoxy(1,25);
    cout<<"*********************************************";
 }




 int main( )
 {
    textmode(BW80);
    clrscr( );

    Matrix Obj;

    Obj.get_matrix_a( );
    Obj.get_matrix_b( );
    Obj.multiply_matrices( );
    Obj.show_result_Matrix( );

    getch( );
    return 0;
 }
