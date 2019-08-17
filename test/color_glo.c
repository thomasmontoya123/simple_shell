#include <stdio.h>

void set_font_red(void)
{
    printf("[0;31m");
}

void set_font_red_b(void)
{
    printf("[1;31m");
}

void set_font_green(void)
{
    printf("[0;32m");
}

void set_font_green_b(void)
{
    printf("[1;32m");
}

void set_font_yellow(void)
{
    printf("[0;33m");
}

void set_font_yellow_b(void)
{
    printf("[01;33m");
}

void set_font_blue(void)
{
    printf("[0;34m");
}

void set_font_blue_b(void)
{
    printf("[1;34m");
}

void set_font_magenta(void)
{
    printf("[0;35m");
}

void set_font_magenta_b(void)
{
    printf("[1;35m");
}

void set_font_cyan(void)
{
    printf("[0;36m");
}

void set_font_cyan_b(void)
{
    printf("[1;36m");
}

void reset_font_color(void)
{
    printf("[0m");
}