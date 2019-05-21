#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct file_s
{
    char name[20];
    char content[20][20];
    int line;
};

struct dic_sort
{
    char name[20];
    int len;
};

void interface(struct file_s*,struct dic_sort*);
void vimFile(struct file_s*);
int dictionary_sort(struct file_s*,struct dic_sort*,int);
int searchFile(struct dic_sort,char*);
void output(struct file_s,char*,int);

int main(void)
{
    struct file_s fileDetail[20];
    struct dic_sort dicSort[20];
    interface(fileDetail,dicSort);
    return 0;
}

void interface(struct file_s *fileDetail,struct dic_sort *dicSort)
{
    int touch_num=0,i,sort_len=0;
    char name[10],command[10],*p,s[50];
    while(1)
    {
        scanf("%s",command);getchar();
        if(strcmp(command,"touch")==0)      //建立檔案
        {
            scanf("%[^\n]",s);getchar();
            p=strtok(s," ");
            while(p!=NULL)
            {
                strcpy(fileDetail[touch_num].name,p);
                touch_num++;
                p=strtok(NULL," ");
            }
        }//
        else if(strcmp(command,"vim")==0)   //修改檔案(覆蓋)
        {
            int j;
            scanf("%s",name);getchar();
            for(i=0;i<touch_num;i++)
            {
                //printf("%s<=>%s\n",name,fileDetail[i].name);
                if(strcmp(name,fileDetail[i].name)==0)
                {
                    vimFile(&fileDetail[i]);
                    break;
                }
            }
        }//
        else if(strcmp(command,"cat")==0)   //查看檔案
        {
            int z=0;
            scanf("%[^\n]",s);getchar();
            p=strtok(s," ");
            while(p!=NULL)
            {
                for(z=0;z<sort_len;z++)
                {
                    if(searchFile(dicSort[z],p)==1)
                    {
                        //printf("%s search True\n",dicSort[z].name);
                        for(i=0;i<touch_num;i++)
                        {
                            if(strcmp(dicSort[z].name,fileDetail[i].name)==0)
                            {
                                output(fileDetail[i],command,-1);
                            }
                        }
                    }
                }
                p=strtok(NULL," ");
            }
        }//
        else if(strcmp(command,"head")==0)  //從頭查看檔案
        {
            int line=0,z=0;
            scanf("%[^\n]",s);getchar();
            p=strtok(s," ");
            while(p!=NULL)
            {
                if(strcmp("-n",p)==0)
                {
                    p=strtok(NULL," ");
                    line=atoi(p);
                }
                else
                {
                    for(z=0;z<sort_len;z++)
                        if(searchFile(dicSort[z],p)==1)
                        {
                            for(i=0;i<touch_num;i++)
                            {
                                if(strcmp(dicSort[z].name,fileDetail[i].name)==0)
                                    output(fileDetail[i],command,line);
                            }
                        }
                }
                p=strtok(NULL," ");
            }
        }//
        else if(strcmp(command,"tail")==0)  //從尾巴查看檔案
        {
            int line=0,z=0;
            scanf("%[^\n]",s);getchar();
            p=strtok(s," ");
            while(p!=NULL)
            {
                if(strcmp("-n",p)==0)
                {
                    p=strtok(NULL," ");
                    line=atoi(p);
                }
                else
                {
                    for(z=0;z<sort_len;z++)
                        if(searchFile(dicSort[z],p)==1)
                        {
                            for(i=0;i<touch_num;i++)
                            {
                                if(strcmp(dicSort[z].name,fileDetail[i].name)==0)
                                    output(fileDetail[i],command,line);
                            }
                        }
                }
                p=strtok(NULL," ");
            }
        }//
        else if(strcmp(command,"rm")==0)    //移除檔案
        {
            int z=0;
            scanf("%[^\n]",s);getchar();
            p=strtok(s," ");
            while(p!=NULL)
            {
                for(z=0;z<sort_len;z++)
                    if(searchFile(dicSort[z],p)==1)
                    {
                        for(i=0;i<touch_num;i++)
                        {
                            if(strcmp(dicSort[z].name,fileDetail[i].name)==0)
                            {
                                strcpy(fileDetail[i].name,"remove");
                                break;
                            }
                        }
                    }
                p=strtok(NULL," ");
            }
        }
        else if(strcmp(command,"ls")==0)    //顯示所有檔案
        {
            for(i=0;i<touch_num;i++)
            {
                if(strcmp(fileDetail[i].name,"remove")!=0)
                    printf("%s ",fileDetail[i].name);
            }
            puts("");
        }
        else if(strcmp(command,"exit")==0)
            break;
        sort_len=dictionary_sort(fileDetail,dicSort,touch_num);
    }
    /*for(i=0;i<sort_len;i++)
        printf("%s\n",dicSort[i].name);*/
    return;
}

void vimFile(struct file_s *file)
{
    int time=0,i,isWrite=0;
    char fileContent[20][20],check[20]="",c;
    scanf("%[a] ",&c);
    while(1)
    {
        scanf("%[^\n]",check);getchar();
        if(isWrite==1 && strcmp(":q",check)!=0) isWrite=0;
        if(strcmp(check,":w")==0)
        {
            isWrite=1;
            for(i=0;i<time;i++)
                strcpy(file->content[i],fileContent[i]);
            file->line=time;
        }
        else if(strcmp(check,":q")==0)
        {
            if(isWrite!=1)
                printf("error\n");
            break;
        }
        else if(strcmp(check,":q!")==0) break;
        else if(strcmp(check,":wq")==0)
        {
            for(i=0;i<time;i++)
                strcpy(file->content[i],fileContent[i]);
            file->line=time;
            break;
        }
        if(isWrite==0)
        {
            strcpy(fileContent[time++],check);
            //printf("%s\n",fileContent[time++]);
        }
    }
    /*for(i=0;i<time;i++)
        printf("%s\n",file.content[i]);*/
    return;
}

int dictionary_sort(struct file_s *fileDetail,struct dic_sort *dicSort,int len)
{
    int i,j,time=0,is=0;
    char temp[20];
    for(i=0;i<len;i++)
    {
        if(strcmp(fileDetail[i].name,"remove")!=0)
            strcpy(dicSort[time++].name,fileDetail[i].name);
    }
    i=0;
    if(time==0) return 0;
    while(1)
    {
        strcpy(temp,dicSort[i].name);
        is=1;
        for(j=0;j<time;j++)
        {
            if(strcmp(dicSort[j].name,temp)>0)
            {
                strcpy(dicSort[i].name,dicSort[j].name);
                strcpy(dicSort[j].name,temp);
                is=0;
                break;
            }
        }
        if(is)i++;
        if(i==time)break;
    }
    for(i=0;i<time;i++)
        dicSort[i].len=strlen(dicSort[i].name);
    return time;
}//

int searchFile(struct dic_sort dicSort,char *format)
{
    int i,fromback=0;
    int flen=strlen(format);
    if(flen>dicSort.len) return -1;
    for(i=0;i<flen;i++)
    {
        if(i==0 && *(format+i)=='*') fromback=1;
        if(fromback)
        {
            if(i==flen-1) return 1;
            if(*(format+flen-i-1)!=*(dicSort.name+dicSort.len-i-1)) return -1;
        }
        else
        {
            if(*(format+i)=='*') return 1;
            else if(*(format +i)!=*(dicSort.name+i)) return -1;
        }
    }
    return 1;
}

void output(struct file_s fileDetail,char *command,int line)
{
    //printf("output\n");
    int i;
    if(line==0) line=10;
    line=line>fileDetail.line?fileDetail.line:line;
    if(strcmp(command,"head")==0)
    {
        for(i=0;i<line;i++)
            printf("%s\n",fileDetail.content[i]);
        return;
    }
    else if(strcmp(command,"tail")==0)
    {
        for(i=fileDetail.line-line;i<fileDetail.line;i++)
            printf("%s\n",fileDetail.content[i]);
        return;
    }
    else
    {
        for(i=0;i<fileDetail.line;i++)
            printf("%s\n",fileDetail.content[i]);
    }
    return;
}//


