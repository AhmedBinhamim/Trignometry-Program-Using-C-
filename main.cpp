/********************************************
Course : TCP1101 Programming Fundamentals
Session: Trimester 2, 2020/21
Name: Ahmed Hassan Mohammed Salem
ID : 1191102340
Lecture Section : TC1V
Tutorial Section: TT4V
Assignment: 1
Email: 1191102340@student.mmu.edu.my
Phone: 0173480200
********************************************/





#include<iostream>
#include<string>
#include<iomanip>
#include <cstdlib>
#include<limits>
#include<conio.h>
using namespace std;

char WelcomeScreen(string,long int);
void TrigoCalculations(long double,long double,long int);
void MoreInfo();
void Get_Angle(string,long double,long int);
void precision_selector(long int &precision_decimal,long double &p);
void Area_Calculator(double,int);
long double power(long double,int);
long double factorial(int);
long double absolute(long double);
long double precision_converter(int);
long double converter360(long double);
long double cos(long double,long double,int);
long double sin(long double,long double,int);
string mode_selector(string);
long double pi = 3.14159265358979323846264338327950288419716;


// ############  START OF MAIN FUNCTION #################
int main()
{
    long double p = 0.00000000001; // p is the initial precision
    string mode="degree";long int precision_decimal=10;
    char choice,ch;


    while (true)
        {
        choice=WelcomeScreen(mode,precision_decimal);

        if(choice=='1')
           mode = mode_selector(mode);
        else if(choice=='2')
            precision_selector(precision_decimal,p);
        else if (choice =='3')
            Get_Angle(mode,p,precision_decimal);
        else if(choice=='4')
            Area_Calculator(p,precision_decimal);
        else if(choice=='5')
            MoreInfo();
        else if(choice=='Q' || choice =='q')
            {
            cout<<"Thank you for using MMU trigonometric Calculator"<<endl;
            exit(0);
            }
        else
            {cout<<"INVALID TRY AGAIN!...."<<endl;}
        cout<<"Press any key to continue..."<<endl;
        while(!kbhit());
        cin.clear();
        cin.ignore(1000,'\n');
        system("CLS");
        }

}

// ################## END OF MAIN FUNCTION ###############

char WelcomeScreen(string mode,long int precision_decimal)
{
    char choice;
    cout<<"+---------------------------------+"<<endl;
    cout<<"|  Trigonometry program           |"<<endl;
    cout<<"+---------------------------------+"<<endl;
    cout<<"Mode(Degree or radian?) = "<<mode<<endl;
    cout<<"Precision = "<<precision_decimal<<endl;
    cout<<"+---------------------------------+"<<endl;
    cout<<"| Select:                         |"<<endl;
    cout<<"|  1 => Switch Degree/Radian mode |"<<endl;
    cout<<"|  2 => Set decimal precision     |"<<endl;
    cout<<"|  3 => Display results           |"<<endl;
    cout<<"|  4 => Triangle Area Calculator  |"<<endl;
    cout<<"|  5=>  More info                 |"<<endl;
    cout<<"|  Q => Quit                      |"<<endl;
    cout<<"+---------------------------------+"<<endl;
    cout<<endl;
    cout<<"Choice => ";
    cin.get(choice).ignore(1000,'\n');

    return choice;

}

string mode_selector(string mode)
{

    while(true)
    {
        cout<<"Mode(Degree or radian?) = ";cin>>mode;cin.ignore(1000,'\n');
        if ((mode=="degree")||(mode=="radian"))
            break;
        else if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Mode(Degree or radian?) = ";cin>>mode;cin.ignore(1000,'\n');
        }
    }
    return mode; // the mode of the the calculator whether degree or radian will be updated!
}

void precision_selector(long int &precision_decimal,long double &p) // as the user might want to change the value
                                                                    // of precision decimal , i made those parameters
                                                                    // as reference to the variables in the main
                                                                    // to trigger the change of both precision and precision decimal
                                                                    // through this FUNCTION.
{
        while(true)
            {
                cout<<"decimal precision => ";(cin>>precision_decimal);cin.ignore(1000,'\n');
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<<"ERROR! PRECISION MUST be a number! TRY AGAIN!"<<endl;
                    cout<<"decimal precision => ";(cin>>precision_decimal);cin.ignore(1000,'\n');
                }
                if(!cin.fail())
                    break;
            }
        p = precision_converter(precision_decimal); // here the precision in form of decimal received
                                                    // will be converted to precision to be used in sine/cosine computation......

}

long double precision_converter(int n)
{   int counter= 1;
    long double num= 0.1;
    while (counter <= (n))
        {num = num * 0.1;
        counter= counter + 1;}
    return num ;
}

void Get_Angle(string mode,long double p,long int precision_decimal)
{
    long double x,x2;  // x is the angle entered in degree/radians.If user input in degrees , x2 will store
                       // the value in degrees without changing it for user reference.

    if (mode =="radian")
    {
        cout<<"Angle value in radians => ";cin>>x;cin.ignore(1000,'\n');
        while(true)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); // you might notice that i use this function whenever i validate
                                                                    // the input , this is to ignore the whatever in the stream left
                                                                    // over from the previous cin process.
                cout<<"ERROR! RADIANS MUST be a number! TRY AGAIN!"<<endl;
                cout<<"Angle value in radians => ";cin>>x;cin.ignore(1000,'\n');
            }
            if(!cin.fail())
                break;
        }
    }
    else if (mode =="degree")
    {
        cout<<"Angle value in degree => ";cin>>x;cin.ignore(1000,'\n');
        while(true)
        {
        if(cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"ERROR! Degree MUST be a number! TRY AGAIN!"<<endl;
        cout<<"Angle value in degree => ";cin>>x;cin.ignore(1000,'\n');
        }
        if(!cin.fail())
            break;
        }
        x2=x;
        x = x*(pi/180);
        cout<<endl;
        cout<<int(x2)<< " degree = "<<setprecision(10)<<showpoint<<x<<" radians"<<endl;
        cout<<endl;
    }
    if ((x>(2*pi))||(x<-(2*pi))) // this if condition acts as a filter , if angle greater than 360 or
            x=converter360(x);   // lesser than -360 then angle is converted to a smaller angle by converter360 function

    TrigoCalculations(x,p,precision_decimal); // after all values are collected for caclulations , the trigonometric
                                              // calculations will be carried out by this function!
}
void TrigoCalculations(long double x,long double p,long int precision_decimal)
{
    long double sine,cosine,tangent;
    sine = sin(x,p,precision_decimal);
    cosine =cos(x,p,precision_decimal);
    cout<<"RESULTS: "<<endl;
    cout<<setprecision(precision_decimal)<<fixed<<showpoint<<"      x  = "<<x<<endl;
    cout<<setprecision(precision_decimal)<<fixed<<showpoint<<"  sin(x) = "<<sine<<endl;
    cout<<setprecision(precision_decimal)<<fixed<<showpoint<<"  cos(x) = "<<cosine<<endl;
    p = precision_converter(precision_decimal);
    if(cosine-p<0) // for some angles. tan will be undefined because cos is 0
        cosine=0;  // so if cosine subtracted from precision is less than 0 then the cosine
                   // is considered as 0 and the other points are neglectable, thus tan is UNDEFINED.
    tangent = sine/cosine;
    cout<<setprecision(precision_decimal)<<fixed<<showpoint<<"  tan(x) = "<<tangent<<endl;
}

long double sin(long double x,long double p,int precision_decimal)
{
    long double termOld,result,termNew,abs_termOld,abs_termNew,x1,difference,abs_difference,f,precision = p;
    int c,sign,j=1;
    termOld = x;  // x is angle in radians form.
    result = x;
    c = 3;    //counter (c) is set to 3 because my calculations starts from the 2nd term.
    sign = -1;
    cout<<"computing sine.."<<endl;
    cout<<endl;
    while (true)
    {
        f = factorial(c);
        termNew = power(x,c)/f;
        abs_termOld = absolute(termOld);
        abs_termNew = absolute(termNew);
        difference = abs_termOld - abs_termNew;
        result = result+(termNew*sign);
        termOld = termNew;
        cout<<j<<" =>    "<<setprecision(precision_decimal)<<showpoint<<result<<endl;
        abs_difference = absolute(difference);
        if (abs_difference<precision)
            break;
        else
        {
            sign = sign*-1;
            j=j+1;
            c=c+2;
        }
    }
    return result;
}

long double cos(long double x,long double p,int precision_decimal)
{
    long double termOld,abs_termOld,result,termNew,abs_termNew,x1,difference,abs_difference,f,precision=p;
    int c,sign,j=1;
    termOld = 1;
    result = 1;
    c = 2;      // as am starting my calculations from 2nd term then counter set to 2.
    sign = -1;
    cout<<endl;
    cout<<"computing cosine.."<<endl;
    cout<<endl;
    while (true)
    {
        f = factorial(c);
        termNew = power(x,c)/f;
        abs_termOld = absolute(termOld);
        abs_termNew = absolute(termNew);
        difference = abs_termOld-abs_termNew;
        result = result+(termNew*sign);
        termOld = termNew;
        cout<<j<<" =>    "<<setprecision(precision_decimal)<<showpoint<<result<<endl;
        abs_difference = absolute(difference);
        if (abs_difference<precision)
            break;
        else
        {
            sign = sign*-1;
            j=j+1;
            c = c + 2;
        }
    }

    return result;
}
long double factorial(int N)
{
    int i = 1; long double f = 1;

    while (i <= N)
    {
        f = f * i;
        i = i + 1;
    }
    return f;
}
long double power(long double y, int N)
{   int i = 1;
    long double product = y;
    while (i<N)
    {
        product = product * y;
        i = i +1;
    }
    return  product;
}
long double absolute(long double n)
{
    if (n<0)
        n = n*-1;
    return n;
}
long double converter360(long double N)
{
    long double rad = N;    // this function converts angle to less than 360 or more than -360.
                            // Because in the program calculates based on this range. There is no point
                            // of going to higher numbers when we will get same result , thus this make the
                            // calculations more efficient , as the program will always be converted to this range.
    if (rad>= 0)
        while (rad>2*pi)
            {   rad = rad -(2*pi);
                if (rad < 0)
                    rad = rad*-1;
            }
    else if (rad<0)
         while (rad<-2*pi)
            {   rad = rad +2*pi;
                if (rad > 0)
                    rad = rad*-1;
            }
    return rad;
}

void Area_Calculator(double p,int precision_decimal)
{
 long double hypotenuse,adjacent,opposite,x,area,sine;

     cout<<"-----Area Caclulator-----";
     cout<<endl;
     cout<<"Hypotenuse => : ";
     cin>>hypotenuse;cin.ignore(1000,'\n');
     while(true)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"ERROR! Hypotenuse MUST be a number! TRY AGAIN!"<<endl;
                cout<<"Hypotenuse =>";cin>>hypotenuse;cin.ignore(1000,'\n');
            }
            else if(!cin.fail())
                break;
        }
     cout<<"Adjacent   => : ";
     cin>>adjacent;cin.ignore(1000,'\n');
     while(true)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"ERROR! adjacent MUST be a number! TRY AGAIN!"<<endl;
                cout<<"adjacent =>";cin>>adjacent;cin.ignore(1000,'\n');
            }
            else if(!cin.fail())
                break;
        }
     cout<<"Opposite   => : ";
     cin>>opposite;cin.ignore(1000,'\n');
     while(true)
        {
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"ERROR! opposite MUST be a number! TRY AGAIN!"<<endl;
                cout<<"opposite =>";cin>>hypotenuse;cin.ignore(1000,'\n');
            }
            else if(!cin.fail())
                break;
        }


     x=opposite*(pi/180);
     cout<<"Value of sine is needed to calculate area..."<<endl;
     sine=sin(x,p,precision_decimal);  //  sine is  needed because the program uses the formula 1/2*a*b*sin(c)
                                       // to compute the area of triangle.
     area=(0.5)*adjacent*hypotenuse*sine;
     cout<<"Area is: "<<setprecision(precision_decimal)<<showpoint<<area<<" cm^2"<<endl;
}

void MoreInfo()
{
    cout<<endl;
    cout<<"#########################################################################"<<endl;
    cout<<endl;
    cout<<"----------------MMU TRIGRNOMETRY CALCULATOR-----------------------------"<<endl;
    cout<<"Year Developed: 2021"<<endl;
    cout<<"Developer: Ahmed Hassan Mohammed Salem"<<endl;
    cout<<"Country of origin: Yemen."<<endl;
    cout<<"Resident in Jeddah,Ksa"<<endl;
    cout<<"Telephone number: 0173480200"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"All rights reserved @Copyrights 2021"<<endl;
    cout<<"Developed under the supervision and assistance of Mr.Sharaf"<<endl;
    cout<<endl;
    cout<<"#########################################################################"<<endl;

}




