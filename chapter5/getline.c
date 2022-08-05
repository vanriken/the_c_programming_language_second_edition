/* getline: read a line into s, return lengthgth of the line */
int getline(char line[], int max_input_size)
{
    int c, i;
    for (i = 0; i<max_input_size-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    // '\0' is used to mark the end of the character array
    line[i] = '\0';

    // print the correct line length for lines that are longer than MAX_INPUT_SIZE
    while(c != EOF && c != '\n')
    {
        ++i;
        c = getchar();
    }

    return i;
}
