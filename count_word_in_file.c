int count_word_file(char* file, char* word)
{
	int c=0;
	char s[20];
	FILE* fp=fopen(file,"r");

    if (fp == NULL)
    {
        perror("Error opening file");
        return 0;
    }

	while(fscanf(fp,"%s",s)!=EOF)
	{
		if(strcmp(word,s)==0)
			c++;
	}
	fclose(fp);
	return c;
}

