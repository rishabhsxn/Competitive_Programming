#include<stdio.h>

// function that convert each passed number according to question
void update_marks(int *, int);

int main()
{
    int students;

    do
    {
      scanf("%d", &students);
    }while(students < 1 || students > 60);

    //static int marks[students];

    int marks[students];

    for(int i = 0; i < students ; i++)
    {
      scanf("%d", &marks[i]);
    }

    update_marks(marks,students);

    for(int i = 0; i< students; i++)
    {
        printf("%d\n",marks[i]);
    }

}

void update_marks(int marks[], int size)
{
    int duplicate,counter=0;
    for(int i = 0; i<size; i++)
    {
        duplicate = marks[i];
        counter = 0;

        if(marks[i]%5 != 0 && marks[i] > 37)
        {
            while(duplicate%5 != 0)
            {
                duplicate++;
                counter++;
            }

            if(counter<3)
            {
                marks[i] = duplicate;
            }
        }
    }
}
