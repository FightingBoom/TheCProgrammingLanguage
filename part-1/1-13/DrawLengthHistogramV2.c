#include <stdio.h>

#define MAXHIST     15      // 直方图最大长度
#define MAXWORD     11      // 一个单词最大长度
#define WORD_BEGIN  1       // 单词起始符
#define WORD_END    0       // 单词结束符

int main()
{
    int iCurrentCharacter;
    _Bool bState = WORD_END;    // bool，编译器原因，替换为了 _Bool
    while ((iCurrentCharacter = getchar()) != EOF)
    {
        if (iCurrentCharacter == ' '
            || iCurrentCharacter == '\n'
            || iCurrentCharacter == '\t')   // 输出单词结尾字符
        {
            if(bState == WORD_BEGIN)
            {
                putchar('\n');
                bState = WORD_END;
            }
        }
        else if (bState == WORD_END)        // 输出单词起始字符
        {
            putchar(iCurrentCharacter);
            bState = WORD_BEGIN;
        }
        else                                // 输出单词中间字符
        {
            putchar(iCurrentCharacter);
        }
    }
}