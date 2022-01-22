#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
  char fname[100];
  char lname[100];
  int  year;
  int  age;
};

struct student class[]={
  "Sean","Penn",2,21,
  "Sean","Connery",4,25,
  "Angelina","Jolie",3,22,
  "Meryl","Streep",4,29,
  "Robin","Williams",3,32,
  "Bill","Gates",3,17,
  "Jodie","Foster",4,25,
  "John","Travolta",1,17,
  "Isaac","Newton",2,19,
  "Sarah","Palin",2,19
};


int compare_first_name(const void* a,const void* b)
{
  struct student* sa=(struct student *)a;
  struct student* sb=(struct student *)b;
  return strcmp(sa->fname , sb->fname);
}

/*
  TODO
  @function compare_last_name
  @desc     compares last name of two records.
*/
int compare_last_name(const void* a,const void* b)
{

    struct student* sa=(struct student *)a;
    struct student* sb=(struct student *)b;
    size_t max_length;
    size_t sa_len = strlen(sa->lname);
    size_t sb_len = strlen(sb->lname);
    if(sa_len>sb_len)
      max_length = sa_len;
    else
      max_length = sb_len;

    for(int i = 0; i < max_length; i++)
      if(sa->lname[i]>sb->lname[i]){
        return 1;
      }
      else if(sa->lname[i]==sb->lname[i])
      {
        return 0;
      }
      else
      {
        return -1;
      }
    }

/*!
  @function apply
  @desc     applies
 */
void apply(struct student* sarr,int nrec,void (*fp)(void* prec,void* arg),void* arg)
{
  int i=0;
  for(i=0;i<nrec;i++)
    {
      /*callback*/
      fp(&sarr[i],arg);
    }
}

/*
  @function printrec
  @desc     prints student record
*/
void printrec(void* prec,void* arg)
{
  struct student* pstud=(struct student*)prec;
  printf("%-20s %-20s %2d %2d\n",pstud->fname,pstud->lname,pstud->year,pstud->age);
}


/*
  @function isolder
  @desc     prints student record onlyl if the student is older than *((int*)arg)
  NOTE: use the same format as
*/
void isolder(void* prec,void* arg)
{
  int* age=(int *) arg;
  struct student * pstud=(struct student *) prec ;
  if (pstud->age < *age)
  	return ;/*do nothin */
  else
  printf ( "%-20s %-20s %2d %2d\n" , pstud->fname , pstud->lname , pstud->year , pstud->age );
}

int main()
{
   int size = sizeof(struct student);
   int nstudents=sizeof(class)/size;

//   puts("Raw records:");
//   puts("-------------------------------");
//   apply(class,nstudents,printrec,NULL);

//   /*sort based on first name*/
//   puts("Sorted by first name:");
//   puts("-------------------------------");
//  //  TODO
//  // @function qsort sort on first_name

//   apply(class,nstudents,printrec,NULL);
  puts("Before sorting:");
  puts("-------------------------------");
  /*sort based on last name*/
    //  TODO
  // @function qsort sort on last_name
  size_t one_class_size = sizeof (class[0]);
  size_t class_size = sizeof (class) / one_class_size;

  printf("%d %d\n", one_class_size, class_size);

  for(int i=0; i<10; i++)
    printf("%s\n",class[i].lname);
  puts("");
  qsort(class,class_size,one_class_size,compare_last_name);

  puts("Sorted by last name:");
  puts("-------------------------------");
  
  for(int i=0; i<10; i++)
    printf("%s\n",class[i].lname);

//   apply(class,nstudents,printrec,NULL);

//   /*print people older than 20*/
//   puts("People older than 20:");
//   puts("-------------------------------");
//   age=20;
//   apply(class,nstudents,isolder,&age);
  return 0;
}

