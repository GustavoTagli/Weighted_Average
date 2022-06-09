#include <iostream>
#include <stdio.h>
#include <locale.h>

/*=========================================================
Nomes: Guilherme Maciel Fagundes, Gustavo Taglianetti Souza
Professora: Patricia
Atividade: Projeto para entrega dia 08/06/2022
=========================================================*/

float calcularMedia(float p1, float p2, float trab1, float trab2, float pi){
   float media;
   
   media = p1 + p2 + trab1 + trab2 + pi;

   return media;
}

int main(void){
   setlocale(LC_ALL, "Portuguese");
   system("cls");

   int qtdAlunos;
   printf("Qual a quantidade de alunos?\n");
   scanf("%d", &qtdAlunos);
   system("cls");

/*=========================================================================================================
                                       Declaração de Variaveis
=========================================================================================================*/
   int opcao, alunoSel;
   char nmAlunos[qtdAlunos][50];
   float p1[qtdAlunos], p2[qtdAlunos], pi[qtdAlunos], trab1[qtdAlunos], trab2[qtdAlunos],
   notaP1[qtdAlunos], notaP2[qtdAlunos], notaPi[qtdAlunos], notaTrab1[qtdAlunos], notaTrab2[qtdAlunos],
   media[qtdAlunos], turmaP1 = 0, turmaP2 = 0, turmaTrab1 = 0, turmaTrab2 = 0, turmaPi = 0, mediaGeral = 0;
//=========================================================================================================

   do{
      printf("========================================\n");
      printf("[1] Cadastrar alunos\n");
      printf("[2] Lançar notas\n");
      printf("[3] Consultar boletim\n");
      printf("[4] Consultar boletim de todos os alunos\n");
      printf("[5] Calcular média geral da turma\n");
      printf("[6] Sair\n");
      printf("========================================\n");

      scanf("%d", &opcao);
      system("cls");
      
      //CADASTRO DE ALUNOS
      if(opcao == 1)
      {
         for(int i = 0; i < qtdAlunos; i++)
         {
            printf("Qual o nome do %d° Aluno?\n", i+1);
            scanf("%s", nmAlunos[i]);
         }
         printf("\n~ALUNO(S) CADASTRADO(S) COM SUCESSO!~\n");
         system("pause");
         system("cls");
      }

      //LANÇAR NOTAS
      if(opcao == 2)
      {
         for(int i = 0; i < qtdAlunos; i++)
         {
            printf("================================\n");
            printf("            %s                  \n", nmAlunos[i]);
            printf("================================\n");
            printf("Nota da P1: ");
            scanf("%f", &p1[i]);
            printf("Nota da P2: ");
            scanf("%f", &p2[i]);
            printf("Nota da Trabalho1: ");
            scanf("%f", &trab1[i]);
            printf("Nota da Trabalho2: ");
            scanf("%f", &trab2[i]);
            printf("Nota da PI: ");
            scanf("%f", &pi[i]);

            notaP1[i] = p1[i] * 0.15;
            notaP2[i] = p2[i] * 0.15;
            notaTrab1[i] = trab1[i] * 0.10;
            notaTrab2[i] = trab2[i] * 0.10;
            notaPi[i] = pi[i] * 0.5;

            media[i] = calcularMedia(notaP1[i], notaP2[i], notaTrab1[i], notaTrab2[i], notaPi[i]);

            mediaGeral += media[i];
				turmaTrab1 += notaTrab1[i];
				turmaTrab2 += notaTrab2[i];
				turmaP1 += notaP1[i];				
				turmaP2 += notaP2[i];
				turmaPi += notaPi[i];


            system("cls");
         }
         turmaP1 = turmaP1 / qtdAlunos;
         turmaP2 = turmaP2 / qtdAlunos;
         turmaTrab1 = turmaTrab1 / qtdAlunos;
         turmaTrab2 = turmaTrab2 / qtdAlunos;
         turmaPi = turmaPi / qtdAlunos;
         mediaGeral = mediaGeral / qtdAlunos;

         printf("~TODAS AS NOTAS FORAM CADASTRADAS~\n");
         system("pause");
         system("cls");
      }

      //CONSULTAR BOLETIM
      if(opcao == 3)
      {
         printf("==========================================\n");
         printf("  Qual Aluno deseja consultar o Boletim?  \n");
         printf("..........................................\n");
         for(int i = 0; i < qtdAlunos; i++)
         {
            printf("[%d] %s\n", i+1, nmAlunos[i]);
         }
         printf("==========================================\n");
         scanf("%d", &alunoSel);
         alunoSel = alunoSel - 1;

         printf("\n===============================================================\n");
         printf("                      Boletim do %s                            \n", nmAlunos[alunoSel]);
         printf("===============================================================\n");
         printf("  P1  ||  P2  ||  Trablho1  ||  Trabalho2  ||  PI  ||   Média\n");
         printf(" %.1f  || %.1f  ||    %.1f     ||     %.1f     || %.1f  ||    %.1f\n",
         notaP1[alunoSel], notaP2[alunoSel], notaTrab1[alunoSel], notaTrab2[alunoSel], notaPi[alunoSel], media[alunoSel]);

         system("pause");
         system("cls");
      }

      //CONSULTAR TODOS OS BOLETINS
      if(opcao == 4)
      {
         for(int i = 0; i < qtdAlunos; i++)
         {

            printf("===============================================================\n");
            printf("                    Boletim do(a) %s                           \n", nmAlunos[i]);
            printf("===============================================================\n");
            printf("  P1  ||  P2  ||  Trablho1  ||  Trabalho2  ||  PI  ||   Média\n");
            printf(" %.1f  || %.1f  ||    %.1f     ||     %.1f     || %.1f  ||    %.1f\n\n",
            notaP1[i], notaP2[i], notaTrab1[i], notaTrab2[i], notaPi[i], media[i]);
         }

         system("pause");
         system("cls");
      }

      //MÉDIA GERAL DA TURMA
      if(opcao == 5)
      {
         printf("===============================================================\n");
         printf("                    Média Geral da Turma                       \n");
         printf("===============================================================\n");
         printf("  P1  ||  P2  ||  Trablho1  ||  Trabalho2  ||  PI  ||   Média\n");
         printf(" %.1f  || %.1f  ||    %.1f     ||     %.1f     || %.1f  ||    %.1f\n\n",
         turmaP1, turmaP2, turmaTrab1, turmaTrab2, turmaPi, mediaGeral);
      }

   } while(opcao != 6);

   return 0;
}