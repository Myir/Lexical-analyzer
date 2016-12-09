#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
int Index(char S[], char T[], int s);
int FB(char ch[], int i);
int FBM(char ch[], int i);
int FBx(char ch[], int i);
int FD(char ch[], int i);
int FDM(char ch[], int i);
int main()
{
	int x;
	FILE *fp;
	char ch[100];
	if ((fp = fopen("E:\\math.c", "r")) == NULL) /* 打开一个文件*/
	{
		printf("can't open the file!");
		exit(0);
	}
	int sy1 = 0, sy2 = 0, sy3 = 0, sy4 = 0, sy5 = 0, sy6 = 0, sy7 = 0, sy8 = 0, sy9 = 0, sy10 = 0, sy11 = 0, sy12 = 0, sy13 = 0, sy14 = 0, sy15 = 0, sy16 = 0, sy17 = 0, sy18 = 0, sy19 = 0, sy20 = 0, sy21 = 0, sya = 0, syg = 0, syh = 0, syi = 0, syj = 0, syk = 0;
	char A[N] = "\"";
	char B[N] = " int";
	char C[N] = " float";
	char D[N] = " for";
	char E[N] = " if";
	char F[N] = " while";
	char G[N] = "(";
	char H[N] = ".";
	char I[N] = ">=";
	char J[N] = "<=";
	char K[N] = "=";
	char NUM1[N] = "1", NUM2[N] = "2", NUM3[N] = "3", NUM4[N] = "4", NUM5[N] = "5", NUM6[N] = "6", NUM7[N] = "7", NUM8[N] = "8", NUM9[N] = "9", NUM0[N] = "0";
	char SB1[N] = "#", SB2[N] = "$", SB3[N] = "%", SB4[N] = "&", SB5[N] = "'", SB6[N] = ")", SB7[N] = "*", SB8[N] = "+", SB9[N] = ",", SB10[N] = "-";
	char SB11[N] = "/", SB12[N] = ":", SB13[N] = ";", SB14[N] = "<", SB15[N] = ">", SB16[N] = "++", SB17[N] = "--", SB18[N] = "==", SB19[N] = "!=", SB20[N] = "+=", SB21[N] = "-=";


	/*对字符串常量的识别*/
	printf("字符串常量:\n");
	
	while ((fgets(ch, 99, fp)) != NULL)
	{
			 if (Index(ch, A, 0) != Index(ch, A, Index(ch, A, 0) + 1))
			{
				for (x = Index(ch, A, 0) + 1; x < Index(ch, A, Index(ch, A, 0) + 1); x++)
				{
					printf("%c", ch[x]);
				}
				printf("\n");
			}
	}


	fp = fopen("E:\\math.c", "r");
	/*对关键字的识别*/
	printf("\n关键字:\n");
	while ((fgets(ch, 99, fp)) != NULL)
	{

		if (Index(ch, B, 0) > 0)
			printf("%s\t", B);
		if (Index(ch, C, 0) > 0)
			printf("%s\t", C);
		if (Index(ch, D, 0) > 0)
			printf("%s\t", D);
		if (Index(ch, E, 0) > 0)
			printf("%s\t", E);
		if (Index(ch, F, 0) > 0)
			printf("%s\t", F);
	}
	printf("\n");


	fp = fopen("E:\\math.c", "r");
	/*对标识符的识别*/
	printf("\n标识符:\n");
	while ((fgets(ch, 99, fp)) != NULL)
	{
		if (Index(ch, B, 0) > 0)
		{
			int i = Index(ch, B, 0) + 4;
			while (i < strlen(ch) - 2)
			{
				if (ch[i] >= 'A'&&ch[i] <= 'Z' || ch[i] >= 'a'&&ch[i] <= 'z')
				{
					printf("%c", ch[i]);

					FB(ch, i);
					printf("\t");
					i = FBx(ch, i);
				}
				else
					i++;
			}
		}
		if (Index(ch, C, 0) > 0)
		{
			int i = Index(ch, C, 0) + 6;
			while (i < strlen(ch) - 2)
			{
				if (ch[i] >= 'A'&&ch[i] <= 'Z' || ch[i] >= 'a'&&ch[i] <= 'z')
				{
					printf("%c", ch[i]);

					FB(ch, i);
					printf("\t");
					i = FBx(ch, i);
				}
				else
					i++;
			}
		}
		if (Index(ch, G, 0) > 0 && Index(ch, D, 0) == 0)
		{

			int j = Index(ch, G, 0);

			for (j = FBM(ch, j) + 1; j < Index(ch, G, 0); j++)
				printf("%c", ch[j]);
		}

		printf("  ");

	}
	printf("\n");


	fp = fopen("E:\\math.c", "r");
	/*对整数的识别*/
	printf("\n整数:\n");
	while ((fgets(ch, 99, fp)) != NULL)
	{
		if (Index(ch, NUM1, 0) > 0 || Index(ch, NUM2, 0) > 0 || Index(ch, NUM3, 0) > 0 || Index(ch, NUM4, 0) > 0 || Index(ch, NUM5, 0) > 0 || Index(ch, NUM6, 0) > 0 || Index(ch, NUM7, 0) > 0 || Index(ch, NUM8, 0) > 0 || Index(ch, NUM9, 0) > 0 || Index(ch, NUM0, 0) > 0)
		{
			int i = 0;
			while (i < strlen(ch) - 2)
			{
				if (ch[i] >= '0'&&ch[i] <= '9' && ch[i - 1] < 'A' &&ch[i - 1] != '.')
				{


					int x = i;
					int y = FD(ch, i);

					while (x < y)
					{
						printf("%c", ch[x]);
						x++;
					}
					printf("\t");
					i = y;


				}
				else
					i++;
			}
		}


	}
	printf("\n");


	fp = fopen("E:\\math.c", "r");
	/*对浮点数的识别*/
	printf("\n浮点数:\n");
	while ((fgets(ch, 99, fp)) != NULL)
	{
		int i = 0;
		while (i < strlen(ch))
		{
			if (Index(ch, H, i) > 0)
			{
				i = Index(ch, H, 0);
				if (FDM(ch, i) + 1 != i)
				{
					int x = i;
					int y = FD(ch, i);
					int z = FDM(ch, i);
					while (z < x)
					{
						z++;
						printf("%c", ch[z]);

					}
					while (x < y - 1)
					{
						x++;
						printf("%c", ch[x]);
					}
					printf("\t");
				}
				i++;
			}
			else
				i++;
		}


	}
	printf("\n");


	fp = fopen("E:\\math.c", "r");
	/*对符号的识别*/
	printf("\n符号:\n");
	while ((fgets(ch, 99, fp)) != NULL)
	{
		if (Index(ch, SB1, 0) > 0)
			sy1++;
		if (Index(ch, SB2, 0) > 0)
			sy2++;
		if (Index(ch, SB3, 0) > 0)
			sy3++;
		if (Index(ch, SB4, 0) > 0)
			sy4++;
		if (Index(ch, SB5, 0) > 0)
			sy5++;
		if (Index(ch, SB6, 0) > 0)
			sy6++;
		if (Index(ch, SB7, 0) > 0)
			sy7++;
		if (Index(ch, SB8, 0) > 0)
			sy8++;
		if (Index(ch, SB9, 0) > 0)
			sy9++;
		if (Index(ch, SB10, 0) > 0)
			sy10++;
		if (Index(ch, SB11, 0) > 0)
			sy11++;
		if (Index(ch, SB12, 0) > 0)
			sy12++;
		if (Index(ch, SB13, 0) > 0)
			sy13++;
		if (Index(ch, SB14, 0) > 0)
			sy14++;
		if (Index(ch, SB15, 0) > 0)
			sy15++;
		if (Index(ch, SB16, 0) > 0)
			sy16++;
		if (Index(ch, SB17, 0) > 0)
			sy17++;
		if (Index(ch, SB18, 0) > 0)
			sy18++;
		if (Index(ch, SB19, 0) > 0)
			sy19++;
		if (Index(ch, SB20, 0) > 0)
			sy20++;
		if (Index(ch, SB21, 0) > 0)
			sy21++;
		if (Index(ch, A, 0) > 0)
			sya++;
		if (Index(ch, G, 0) > 0)
			syg++;
		if (Index(ch, H, 0) > 0)
			syh++;
		if (Index(ch, I, 0) > 0)
			syi++;
		if (Index(ch, J, 0) > 0)
			syj++;
		if (Index(ch, K, 0) > 0)
			syk++;
	}
	if (sy1 > 0)
		printf("%c  ", SB1[0]);
	if (sy2 > 0)
		printf("%c  ", SB2[0]);
	if (sy3 > 0)
		printf("%c  ", SB3[0]);
	if (sy4 > 0)
		printf("%c  ", SB4[0]);
	if (sy5 > 0)
		printf("%c  ", SB5[0]);
	if (sy6 > 0)
		printf("%c  ", SB6[0]);
	if (sy7 > 0)
		printf("%c  ", SB7[0]);
	if (sy8 > 0)
		printf("%c  ", SB8[0]);
	if (sy9 > 0)
		printf("%c  ", SB9[0]);
	if (sy10 > 0)
		printf("%c  ", SB10[0]);
	if (sy11 > 0)
		printf("%c  ", SB11[0]);
	if (sy12 > 0)
		printf("%c  ", SB12[0]);
	if (sy13 > 0)
		printf("%c  ", SB13[0]);
	if (sy14 > 0)
		printf("%c  ", SB14[0]);
	if (sy15 > 0)
		printf("%c  ", SB15[0]);
	if (sy16 > 0)
		printf("%c%c  ", SB16[0], SB16[1]);
	if (sy17 > 0)
		printf("%c%c  ", SB17[0], SB17[1]);
	if (sy18 > 0)
		printf("%c%c  ", SB18[0], SB18[1]);
	if (sy19 > 0)
		printf("%c%c  ", SB19[0], SB19[1]);
	if (sy20 > 0)
		printf("%c%c  ", SB20[0], SB20[1]);
	if (sy21 > 0)
		printf("%c%c  ", SB21[0], SB20[1]);
	if (sya > 0)
		printf("%c  ", A[0]);
	if (syg > 0)
		printf("%c  ", G[0]);
	if (syh > 0)
		printf("%c  ", H[0]);
	if (syi > 0)
		printf("%c%c  ", I[0], I[1]);
	if (syj > 0)
		printf("%c%c  ", J[0], J[1]);
	if (syk > 0)
		printf("%c  ", K[0]);
	printf("\n");
}
int Index(char S[], char T[], int s)
/* 返回子串T在主串S中第i个字符之后的位置。若不存在，则函数值为0。 */
{

	int m, n;
	m = strlen(S);
	n = strlen(T);

	for (int i = s; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (S[i + j] != T[j])
				break;
			if (j == n - 1)
			{
				return i;
			}
		}
	}
	return 0;
}
int FB(char ch[], int i)
{
	i++;
	if (ch[i] >= 'A'&&ch[i] <= 'Z' || ch[i] >= 'a'&&ch[i] <= 'z' || ch[i] >= '0'&&ch[i] <= '9')
	{
		printf("%c", ch[i]);

		FB(ch, i);

	}
	else
		return i;
}
int FBM(char ch[], int i)
{
	i--;
	if (ch[i] >= 'A'&&ch[i] <= 'Z' || ch[i] >= 'a'&&ch[i] <= 'z' || ch[i] >= '0'&&ch[i] <= '9')
	{
		FBM(ch, i);

	}
	else
		return i;
}
int FBx(char ch[], int i)
{
	i++;
	if (ch[i] >= 'A'&&ch[i] <= 'Z' || ch[i] >= 'a'&&ch[i] <= 'z' || ch[i] >= '0'&&ch[i] <= '9')
	{


		FBx(ch, i);

	}
	else
		return i;
}
int FD(char ch[], int i)
{
	i++;
	if (ch[i] >= '0'&&ch[i] <= '9')
	{
		FD(ch, i);
	}
	else if (ch[i] == '.')
	{
		return -1;
	}
	else
		return i;
}
int FDM(char ch[], int i)
{
	i--;
	if (ch[i] >= '0'&&ch[i] <= '9')
	{
		FDM(ch, i);
	}
	else
		return i;
}


