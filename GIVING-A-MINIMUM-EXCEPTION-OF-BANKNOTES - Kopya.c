#include <LiquidCrystal.h>

#define BUTON1 PC_5
#define BUTON2 PD_2
#define BUTON3 PD_3
#define BUTON4 PD_6
#define BUTON5 PD_7
#define RESET PF_4
#define BITIS PB_2
#define LEDY PA_7
#define LEDK PA_6

LiquidCrystal lcd(PB_0, PB_1, PB_4, PB_5, PB_6, PB_7);

char m1[20];
char m2[20];
char m3[20];
char m4[20];
char m5[20];
char m6[20];

char e1[20];
char e2[20];
char e3[20];
char e4[20];

int length,i;
int adets;
float kasatop = 0;
float para[5] = {5,10,20,50,100};
float paraustu = 0;
int ending;
int control = 0;
int moneycounts[5];
int itemc[5][4];
float bakiye=0;
float harcananpara=0;
float display = 0;
float money1 = 0, money2 = 0, money3 = 0, money4 = 0, money5 = 0;
float money11 = 0, money22 = 0, money33 = 0, money44 = 0, money55 = 0;
int proc1 = 0, proc2 = 0, proc3 = 0, proc4 = 0, proc5 = 0;
int proc11 = 0, proc22 = 0, proc33 = 0, proc44 = 0, proc55 = 0;
float items[5][4];
char UrunAd[4][20]= {"kopukleme","yikama","kurulama","cilalama"};
char * moneycount[5];
char * item[5][4];
char text[]= {'2','0',',','2','0',',','1','0',',','3','0',',','5','\n','1',',','k','o','p','u','k',',','3','0',',','1','5',' ','T','L','\n','2',',','y','i','k','a','m','a',',','5','0',',','1','0',' ','T','L','\n','3',',','k','u','r','u','l','a','m','a',',','1','0','0',',','5',' ','T','L','\n','4',',','c','i','l','a','l','a','m','a',',','2','0',',','5','0',' ','T','L',' ','\0'};
//             0  1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17    18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35  36  37  38  39  40  41  42  43  44  45  46  47  48  49  50  51  52  53  54  55    56  57  58  59  60  61  62  63  64  65  66  67  68  69  70  71  72  73  74  75  76  77  78  79  80   81   82  83  84  85  86  87  88  89
void textIsle()
{
    length = strlen(text);

    sprintf(m2,"%d",moneycounts[0]);
    sprintf(m3,"%d",moneycounts[1]);
    sprintf(m4,"%d",moneycounts[2]);
    sprintf(m5,"%d",moneycounts[3]);
    sprintf(m6,"%d",moneycounts[4]);

    sprintf(e1,"%d",itemc[0][2]);
    sprintf(e2,"%d",itemc[1][2]);
    sprintf(e3,"%d",itemc[2][2]);
    sprintf(e4,"%d",itemc[3][2]);


    text[0]=m2[0];
    text[1]=m2[1];
    text[2]=',';
    text[3]=m3[0];
    text[4]=m3[1];
    text[5]=',';
    text[6]=m4[0];
    text[7]=m4[1];
    text[8]=',';
    text[9]=m5[0];
    text[10]=m5[1];
    text[11]=',';
    text[12]=m6[0];
    text[13]=',';
    text[21]=' ';
    text[22]=e1[0];
    text[23]=e1[1];
    text[24]=',';
    text[39]=' ';
    text[40]=e2[0];
    text[41]=e2[1];
    text[42]=',';
    text[59]=' ';
    text[60]=e3[0];
    text[61]=e3[1];
    text[62]=e3[2];
    text[63]=',';
    text[79]=' ';
    text[80]=e4[0];
    text[81]=e4[1];
    text[82]=',';


    for(i=0; i<length; i++)
    {

        if(text[i-6]=='1' && text[i-5]=='0' && text[i-4]=='0' && text[i-2]=='T' && text[i-1]=='L')
        {
            text[i] = '\n';
        }
        if(text[i-5]=='5' && text[i-4]=='0' && text[i-2]=='T' && text[i-1]=='L')
        {
            text[i] = '\n';
        }
        if(text[i-5]=='2' && text[i-4]=='0' && text[i-2]=='T' && text[i-1]=='L')
        {
            text[i] = '\n';
        }
        if(text[i-5]=='1' && text[i-4]=='0' && text[i-2]=='T' && text[i-1]=='L')
        {
            text[i] = '\n';
        }
        if( text[i-4]=='5' && text[i-2]=='T' && text[i-1]=='L')
        {
            text[i] = '\n';
        }

    }

    for(i=0; i<99; i++)
    {
        Serial.print(text[i]);
    }
}

void isle()
{
    Serial.println();
    Serial.print("-----Güncel Stok Durumu------");
    Serial.println();
    Serial.print("100 TL adedi : ");
    Serial.print(moneycounts[4]);
    Serial.println();
    Serial.print("50 TL adedi : ");
    Serial.print(moneycounts[3]);
    Serial.println();
    Serial.print("20 TL adedi : ");
    Serial.print(moneycounts[2]);
    Serial.println();
    Serial.print("10 TL adedi : ");
    Serial.print(moneycounts[1]);
    Serial.println();
    Serial.print("5 TL adedi : ");
    Serial.print(moneycounts[0]);
    Serial.println();
    Serial.print("kopukleme Sayısı : ");
    Serial.print(itemc[0][2]);
    Serial.println();
    Serial.print("yikama Sayısı : ");
    Serial.print(itemc[1][2]);
    Serial.println();
    Serial.print("Kululama Sayısı : ");
    Serial.print(itemc[2][2]);
    Serial.println();
    Serial.print("cilalama Sayısı : ");
    Serial.print(itemc[3][2]);
    Serial.println();
    Serial.print("------------------");
    Serial.println();
}

void reset()
{


    bakiye = 0;
    harcananpara = 0;

    proc1 = 0,   proc2 = 0;
    proc3 = 0;
    proc4 = 0;
    proc5 = 0;

    moneycounts[0] = moneycounts[0] - money11;
    moneycounts[1] = moneycounts[1] - money22;
    moneycounts[2] = moneycounts[2] - money33;
    moneycounts[3] = moneycounts[3] - money44;
    moneycounts[4] = moneycounts[4] - money55;

    money11 = 0;
    money22 = 0;
    money33 = 0, money44 = 0, money55 = 0;
    control = 0;
    isle();

}

void paraUstu()
{

    paraustu = bakiye - harcananpara;

    kasatop = moneycounts[0]*5 + moneycounts[1]*10 + moneycounts[2]*20 + moneycounts[3]*50 + moneycounts[4]*100;

    if(kasatop < paraustu)
    {


        Serial.print("Kasada yeterli");

        Serial.print("para yok !");


    }

    if(paraustu == 0)
    {


        Serial.print("Paraustu ");

        Serial.print("verilmeyecektir.");


    }
    if(bakiye < harcananpara)
    {

        Serial.print("Yetersiz bakiye!");
        bakiye = 0;
        harcananpara = 0;
        if(money11 != 0)
        {

            moneycounts[0] = moneycounts[0] - money11;
        }
        if(money22 != 0)
        {

            moneycounts[1] = moneycounts[1] - money22;
        }
        if(money33 != 0)
        {

            moneycounts[2] = moneycounts[2] - money33;
        }
        if(money44 != 0)
        {

            moneycounts[3] = moneycounts[3] - money44;
        }
        if(money55 != 0)
        {

            moneycounts[4] = moneycounts[4] - money55;
        }

    }

    if(bakiye > harcananpara)
    {

        for(i = 4 ; i >= 0 ; i--)
        {

            if(moneycounts[i]>0 && para[i]<= paraustu)
            {

                adets = paraustu/para[i];

                if(i==4 && adets>moneycounts[4])
                {

                    adets = moneycounts[4];

                }
                if(i==3 && adets>moneycounts[3])
                {

                    adets=moneycounts[3];

                }

                if(i==2 && adets>moneycounts[2])
                {

                    adets = moneycounts[2];

                }
                if(i==1 && adets>moneycounts[1])
                {

                    adets=moneycounts[1];

                }
                if(i==0 && adets>moneycounts[0])
                {

                    adets=moneycounts[0];
                }


                if(i==4)
                {

                    paraustu = paraustu-(100*adets);
                    kasatop = kasatop-(100*adets);

                }

                if(i==3)
                {

                    paraustu=paraustu-(50*adets);
                    kasatop=kasatop-(50*adets);

                }
                if(i==2)
                {

                    paraustu = paraustu-(20*adets);
                    kasatop = kasatop-(20*adets);

                }

                if(i==1)
                {

                    paraustu=paraustu-(10*adets);
                    kasatop=kasatop-(10*adets);

                }

                if(i==0)
                {

                    paraustu=paraustu-(5*adets);
                    kasatop=kasatop-(5*adets);

                }

                if(i==4)
                {


                    Serial.print(adets);
                    Serial.print(" adet 100 TL ");

                }

                if(i==3)
                {


                    Serial.print(adets);
                    Serial.print(" adet 50 TL ");

                }

                if(i==2)
                {


                    Serial.print(adets);
                    Serial.print(" adet 20 TL ");

                }

                if(i==1)
                {

                    Serial.print(adets);
                    Serial.print(" adet 10 TL ");

                }

                if(i==0)
                {


                    Serial.print(" ");
                    Serial.print(adets);
                    Serial.print(" adet 5 TL ");

                }
                moneycounts[i] = moneycounts[i]-adets;
            }
        }
    }
    money11 = 0;
    money22 = 0;
    money33 = 0;
    money44 = 0;
    money55 = 0;
}

void setup()
{

    Serial.begin(9600);

    pinMode(BUTON1,INPUT_PULLUP);
    pinMode(BUTON2,INPUT_PULLUP);
    pinMode(BUTON3,INPUT_PULLUP);
    pinMode(BUTON4,INPUT_PULLUP);
    pinMode(BUTON5,INPUT_PULLUP);
    pinMode(RESET,INPUT_PULLUP);
    pinMode(BITIS, INPUT_PULLUP);
    pinMode(LEDY,OUTPUT);
    pinMode(LEDK,OUTPUT);
    digitalWrite(LEDY,HIGH);
    digitalWrite(LEDK,HIGH);


    length=strlen(text);
    moneycount[0]=strtok(text,",");
    moneycount[1]=strtok(NULL,",");
    moneycount[2]=strtok(NULL,",");
    moneycount[3]=strtok(NULL,",");
    moneycount[4]=strtok(NULL,"\n");
    for(i=0; i<5; i++)
    {
        moneycounts[i] = atof(moneycount[i]);
    }

    item[0][0]=strtok(NULL," ,");
    item[0][1]=strtok(NULL," ,");
    item[0][2]=strtok(NULL," ,");
    itemc[0][2]=atoi(item[0][2]);
    item[0][3]=strtok(NULL,"\n");

    item[1][0]=strtok(NULL,",");
    item[1][1]=strtok(NULL,",");
    item[1][2]=strtok(NULL,",");
    itemc[1][2]=atoi(item[1][2]);
    item[1][3]=strtok(NULL,"\n");

    item[2][0]=strtok(NULL,",");
    item[2][1]=strtok(NULL,",");
    item[2][2]=strtok(NULL,",");
    itemc[2][2]=atoi(item[2][2]);
    item[2][3]=strtok(NULL,"\n");

    item[3][0]=strtok(NULL,",");
    item[3][1]=strtok(NULL,",");
    item[3][2]=strtok(NULL,",");
    itemc[3][2]=atoi(item[3][2]);
    item[3][3]=strtok(NULL,"\n");




    for(i=0; i<5; i++)
    {
        for(int j=0; j<4; j++)
        {
            items[i][j]=atof(item[i][j]);
            if(i==0 && j==3)
            {
                items[i][j]=1;
            }

        }
    }
}

void loop()
{

    if((digitalRead(BUTON1)==0))
    {
        if(control%2 == 0)
        {
            money1 = money1 + 1;
            bakiye = bakiye + 5;

            Serial.print(bakiye);
            Serial.print(" TL atildi");
            Serial.println();
        }

        if(control%2 == 1)
        {


            Serial.print(proc1+1);
            Serial.print(" adet kopukleme alindi.");
            Serial.println();
            delay(200);
            proc1 = proc1 + 1;

        }
        while(digitalRead(BUTON1==0))
        {

        }
        delay(200);

    }

    if((digitalRead(BUTON2)==0))
    {
        if(control%2 == 0)
        {
            money2 = money2 + 1;
            bakiye = bakiye + 10;

            Serial.print(bakiye);
            Serial.print(" TL atildi");
            Serial.println();

        }
        if(control%2 == 1)
        {


            Serial.print(proc2+1);
            Serial.print(" adet ");
            Serial.print("yikama alindi.");
            Serial.println();
            delay(200);
            proc2 = proc2 + 1;

        }

        while(digitalRead(BUTON2==0))
        {

        }

        delay(200);
    }

    if((digitalRead(BUTON3)==0))
    {

        if(control%2 == 0)
        {

            money3 = money3 + 1;
            bakiye = bakiye + 20;

            Serial.print(bakiye);
            Serial.print(" TL atildi");
            Serial.println();

        }

        if(control%2 == 1)
        {

            Serial.print(proc3+1);
            Serial.print(" adet ");
            Serial.print("kurulama alindi.");
            Serial.println();
            delay(200);
            proc3 = proc3 + 1;

        }

        while(digitalRead(BUTON3==0))
        {

        }

        delay(200);
    }

    if((digitalRead(BUTON4)==0))
    {
        if(control%2 == 0)
        {
            money4 = money4 + 1;
            bakiye = bakiye + 50;

            Serial.print(bakiye);
            Serial.print(" TL atildi");
            Serial.println();
        }

        if(control%2 == 1)
        {


            Serial.print(proc4+1);
            Serial.print(" adet cilalama alindi.");
            Serial.println();
            delay(200);
            proc4 = proc4 + 1;

        }
        while(digitalRead(BUTON1==0))
        {

        }
        delay(200);

    }

    if((digitalRead(BUTON5)==0))
    {
        if(control%2 == 0)
        {
            money5 = money5 + 1;
            bakiye = bakiye + 100;

            Serial.print(bakiye);
            Serial.print(" TL atildi");
            Serial.println();
        }

        if(control%2 == 1)
        {

        }
        while(digitalRead(BUTON1==0))
        {

        }
        delay(200);

    }

    if(digitalRead(RESET) == 0)
    {
RESET:

        reset();


        Serial.print("RESETLENDI");
        Serial.println();
        delay(1000);


        while(digitalRead(RESET==0))
        {

        }
        delay(200);
    }



    if((digitalRead(BITIS)==0))
    {
        ending = 1+rand()%4;


        if(ending == 2 && control%2 == 1 )
        {

            digitalWrite(LEDK,LOW);
            delay(300);
            digitalWrite(LEDK,HIGH);


            Serial.print("Para sikisti");

            proc1 = 0,   proc2 = 0;
            proc3 = 0;
            proc4 = 0;
            proc5 = 0;

            control=0;
            goto RESET;
        }
        if(control%2 == 0)
        {

            digitalWrite(LEDY,LOW);
            delay(300);
            digitalWrite(LEDY,HIGH);

            bakiye = 0;
            bakiye = bakiye  + money1*5 + money2*10 + money3*20+ money4*50 + money5*100;

            moneycounts[0] = moneycounts[0] + money1;
            moneycounts[1] = moneycounts[1] + money2;
            moneycounts[2] = moneycounts[2] + money3;
            moneycounts[3] = moneycounts[3] + money4;
            moneycounts[4] = moneycounts[4] + money5;

            display = money1*5 + money2*10 + money3*20+ money4*50 + money5*100;

            Serial.print(display);
            Serial.print(" TL yuklendi.");
            Serial.println();

            money11 = money1, money22 = money2, money33 = money3, money44 = money4, money55 = money5;
            money1 = 0;
            money2 = 0;
            money3 = 0;
            money4 = 0;
            money5 = 0;
        }
        if(control%2 == 1)
        {

            digitalWrite(LEDY,LOW);
            delay(300);
            digitalWrite(LEDY,HIGH);

            itemc[0][2] = itemc[0][2] - proc1;
            itemc[1][2] = itemc[1][2] - proc2;
            itemc[2][2] = itemc[2][2] - proc3;
            itemc[3][2] = itemc[3][2] - proc4;


            harcananpara = harcananpara + proc1*items[0][3] + proc2*items[1][3] + proc3*items[2][3] + proc4*items[3][3];

            proc11 = proc1, proc22 = proc2, proc33 = proc3, proc44 = proc4, proc55 = proc5;
            proc1 = 0,   proc2 = 0;
            proc3 = 0;
            proc4 = 0;
            proc5 = 0;

            paraUstu();
            bakiye = 0;
            isle();
            textIsle();
        }

        while(digitalRead(BITIS==0))
        {

        }
        control++;

        delay(200);
    }



}
