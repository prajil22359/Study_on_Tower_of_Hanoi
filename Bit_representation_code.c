#include <stdio.h>

void tower(int total);

int increment(int bitStrings[])
{
    int i = 0;

    while (bitStrings[i] == 1)
    {
        bitStrings[i] = 0;
        i++;
    }

    bitStrings[i] = 1;

    return i + 1;
}

void tower(int total)
{
    int from, to, disk, temp, i;
    int bitStrings[10], hold[10];
    char place[3][7] = {"START", "BUFFER", "FINISH"};

    for (i = 0; i < 10; i++)
    {
        bitStrings[i] = 0;
        hold[i] = 1;
    }

    temp = 3 - total % 2;

    for (i = 1; i < (1 << total); i++)
    {
        disk = increment(bitStrings);

        if (disk == 1)
        {
            from = hold[1];
            to = 6 - from - temp;
            temp = from;
        }
        else
        {
            from = hold[disk];
            to = 6 - hold[1] - hold[disk];
        }

        printf("MOVE DISK %d TO %s\n", disk, place[to - 1]);
        hold[disk] = to;
    }

    printf("FINISH\n");
}



int main()
{
    int disks;
    printf("ENTER NUMBER OF DISKS WANTED\n");
    scanf("%d", &disks);

    if (disks > 0)
    {
        tower(disks);
    }

    if (disks <= 0)
    {
        goto finish;
    }

finish:
    return 0;
}
