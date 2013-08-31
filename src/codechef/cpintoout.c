# include    <stdio.h>
  main()
   {
      int c;
           printf("vale of EOF %u",EOF);
        while((c=getchar())!=EOF)
          putchar(c);
    }
